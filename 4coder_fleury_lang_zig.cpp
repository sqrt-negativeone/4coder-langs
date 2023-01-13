

internal void
F4_Zig_SkipToOpenBraces(F4_Index_ParseCtx *ctx)
{
  for(;!ctx->done;)
  {
    if (F4_Index_PeekToken(ctx, S8Lit("{")))
    {
      break;
    }
    
    Token *token = token_it_read(&ctx->it);
    if(token->kind == TokenBaseKind_ScopeClose ||
       token->sub_kind == TokenOdinKind_ParenCl)
    {
      break;
    }
    F4_Index_ParseCtx_Inc(ctx, F4_Index_TokenSkipFlag_SkipWhitespace);
  }
}


internal void
F4_Zig_ParseDeclSet(F4_Index_ParseCtx *ctx, F4_Index_Note *parent)
{
  F4_Index_Note *old_active_parent = F4_Index_PushParent(ctx, parent);
  for(;!ctx->done;)
  {
    Token *name = 0;
    
    if(F4_Index_RequireTokenKind(ctx, TokenBaseKind_Identifier, &name, F4_Index_TokenSkipFlag_SkipWhitespace) &&
       F4_Index_RequireToken(ctx, S8Lit(":"), F4_Index_TokenSkipFlag_SkipWhitespace))
    {
      F4_Index_MakeNote(ctx, Ii64(name), F4_Index_NoteKind_Decl, 0);
      
      for(;!ctx->done;)
      {
        Token *token = token_it_read(&ctx->it);
        if(token->sub_kind == TokenZigKind_Comma)
        {
          F4_Index_ParseCtx_Inc(ctx, F4_Index_TokenSkipFlag_SkipWhitespace);
          break;
        }
        else if(token->kind == TokenBaseKind_ScopeClose ||
                token->sub_kind == TokenZigKind_ParenCl)
        {
          goto end;
        }
        F4_Index_ParseCtx_Inc(ctx, F4_Index_TokenSkipFlag_SkipWhitespace);
      }
    }
    else if(F4_Index_RequireTokenKind(ctx, TokenBaseKind_Comment, &name, F4_Index_TokenSkipFlag_SkipWhitespace))
    {
      F4_Index_ParseComment(ctx, name);
    }
    
    else
    {
      break;
    }
  }
  
  end:;
  F4_Index_PopParent(ctx, old_active_parent);
}

internal void
F4_Zig_ParseDeclSet_Braces(F4_Index_ParseCtx *ctx, F4_Index_Note *parent)
{
  if(F4_Index_RequireToken(ctx, S8Lit("{"), F4_Index_TokenSkipFlag_SkipWhitespace))
  {
    F4_Zig_ParseDeclSet(ctx, parent);
    F4_Index_RequireToken(ctx, S8Lit("}"), F4_Index_TokenSkipFlag_SkipWhitespace);
  }
}

internal void
F4_Zig_ParseDeclSet_Parens(F4_Index_ParseCtx *ctx, F4_Index_Note *parent)
{
  if(F4_Index_RequireToken(ctx, S8Lit("("), F4_Index_TokenSkipFlag_SkipWhitespace))
  {
    F4_Zig_ParseDeclSet(ctx, parent);
    F4_Index_RequireToken(ctx, S8Lit(")"), F4_Index_TokenSkipFlag_SkipWhitespace);
  }
}

internal void
F4_Zig_ParseEnumBody(F4_Index_ParseCtx *ctx)
{
  if(F4_Index_RequireToken(ctx, S8Lit("{"), F4_Index_TokenSkipFlag_SkipWhitespace))
  {
    for(;!ctx->done;)
    {
      Token *name = 0;
      if (F4_Index_RequireTokenKind(ctx, TokenBaseKind_Identifier, &name,  F4_Index_TokenSkipFlag_SkipWhitespace))
      {
        F4_Index_MakeNote(ctx, Ii64(name), F4_Index_NoteKind_Constant, 0);
        
        for(;!ctx->done;)
        {
          Token *token = token_it_read(&ctx->it);
          if(token->sub_kind == TokenZigKind_Comma)
          {
            F4_Index_ParseCtx_Inc(ctx, F4_Index_TokenSkipFlag_SkipWhitespace);
            break;
          }
          else if(token->kind == TokenBaseKind_ScopeClose ||
                  token->sub_kind == TokenZigKind_ParenCl)
          {
            goto end;
          }
          F4_Index_ParseCtx_Inc(ctx, F4_Index_TokenSkipFlag_SkipWhitespace);
        }
      }
      else if(F4_Index_RequireTokenKind(ctx, TokenBaseKind_Comment, &name, F4_Index_TokenSkipFlag_SkipWhitespace))
      {
        F4_Index_ParseComment(ctx, name);
      }
      
      else
      {
        break;
      }
    }
    end:
    F4_Index_RequireToken(ctx, S8Lit("}"), F4_Index_TokenSkipFlag_SkipWhitespace);
  }
}


internal F4_LANGUAGE_INDEXFILE(F4_Zig_IndexFile)
{
  int scope_nest = 0;
  
  for(;!ctx->done;)
  {
    Token *name = 0;
    F4_Index_TokenSkipFlags flags = F4_Index_TokenSkipFlag_SkipWhitespace;
    
    // NOTE(fakhri): Handle nests.
    {
      Token *token = token_it_read(&ctx->it);
      if(token)
      {
        if(token->kind == TokenBaseKind_ScopeOpen)
        {
          scope_nest += 1;
        }
        else if(token->kind == TokenBaseKind_ScopeClose)
        {
          scope_nest -= 1;
        }
        if(scope_nest < 0)
        {
          scope_nest = 0;
        }
      }
    }
    
    if(F4_Index_RequireTokenKind(ctx, TokenBaseKind_Identifier, &name, flags))
    {
      Token *id_name = name;
      if(F4_Index_RequireToken(ctx, S8Lit("="), flags))
      {
        for (;!ctx->done;)
        {
          if(F4_Index_RequireTokenKind(ctx, TokenBaseKind_Keyword, &name, flags))
          {
            if (name->sub_kind == TokenZigKind_packed || 
                name->sub_kind == TokenZigKind_extern)
            {
              continue;
            }
            if (name->sub_kind == TokenZigKind_struct || 
                name->sub_kind == TokenZigKind_opaque)
            {
              // NOTE(fakhri): struct or opaque definition
              F4_Index_Note *parent = F4_Index_MakeNote(ctx, Ii64(id_name), F4_Index_NoteKind_Type, F4_Index_NoteFlag_ProductType);
              F4_Odin_SkipToOpenBraces(ctx);
              F4_Zig_ParseDeclSet_Braces(ctx, parent);
            }
            else if (name->sub_kind == TokenZigKind_union)
            {
              // NOTE(fakhri): union definition
              F4_Index_Note *parent = F4_Index_MakeNote(ctx, Ii64(id_name), F4_Index_NoteKind_Type, F4_Index_NoteFlag_SumType);
              F4_Odin_SkipToOpenBraces(ctx);
              F4_Zig_ParseDeclSet_Braces(ctx, parent);
            }
            else if (name->sub_kind == TokenZigKind_enum ||
                     name->sub_kind == TokenZigKind_error)
            {
              // NOTE(fakhri): enum or error definition
              F4_Index_MakeNote(ctx, Ii64(id_name), F4_Index_NoteKind_Type, 0);
              F4_Odin_SkipToOpenBraces(ctx);
              F4_Zig_ParseEnumBody(ctx);
            }
            else break;
          }
          else
          {
            break;
          }
        }
      }
    }
    
    if(F4_Index_RequireTokenKind(ctx, TokenBaseKind_Keyword, &name, flags))
    {
      if (name->sub_kind == TokenZigKind_fn)
      {
        // NOTE(fakhri): procedure definition
        if(F4_Index_RequireTokenKind(ctx, TokenBaseKind_Identifier, &name, flags))
        {
          if(F4_Index_PeekToken(ctx, S8Lit("(")))
          {
            F4_Index_Note *parent = F4_Index_MakeNote(ctx, Ii64(name), F4_Index_NoteKind_Function, 0);
            F4_Zig_ParseDeclSet_Parens(ctx, parent);
          }
        }
      }
    }
    
    //~ NOTE(fakhri): Comment Tags
    else if(F4_Index_RequireTokenKind(ctx, TokenBaseKind_Comment, &name, F4_Index_TokenSkipFlag_SkipWhitespace))
    {
      F4_Index_ParseComment(ctx, name);
    }
    
    else
    {
      F4_Index_ParseCtx_Inc(ctx, flags);
    }
  }
}


internal Token *
_F4_Zig_FindDecl(Application_Links *app, Buffer_ID buffer, i64 pos, Token *decl_name)
{
  Token *result = 0;
  Scratch_Block scratch(app);
  
  int scope_nest = 0;
  String_Const_u8 decl_name_str = push_buffer_range(app, scratch, buffer, Ii64(decl_name));
  Token_Array tokens = get_token_array_from_buffer(app, buffer);
  Token_Iterator_Array it = token_iterator_pos(0, &tokens, pos);
  for(;;)
  {
    Token *token = token_it_read(&it);
    if(token)
    {
      if(scope_nest == 0 &&
         token->sub_kind == TokenZigKind_Colon &&
         token_it_dec_non_whitespace(&it))
      {
        Token *name_candidate = token_it_read(&it);
        if(name_candidate && name_candidate->kind == TokenBaseKind_Identifier)
        {
          String_Const_u8 name_candidate_string = push_buffer_range(app, scratch, buffer, Ii64(name_candidate));
          if(string_match(name_candidate_string, decl_name_str))
          {
            result = name_candidate;
            break;
          }
        }
      }
      else if(token->sub_kind == TokenZigKind_BraceCl)
      {
        scope_nest += 1;
      }
      else if(token->sub_kind == TokenZigKind_BraceOp)
      {
        scope_nest -= 1;
      }
    }
    else { break; }
    if(!token_it_dec_non_whitespace(&it))
    {
      break;
    }
  }
  return result;
}


internal F4_LANGUAGE_POSCONTEXT(F4_Zig_PosContext)
{
  int count = 0;
  F4_Language_PosContextData *first = 0;
  F4_Language_PosContextData *last = 0;
  
  Token_Array tokens = get_token_array_from_buffer(app, buffer);
  
  // NOTE(rjf): Search for left parentheses (function call or macro invocation).
  {
    Token_Iterator_Array it = token_iterator_pos(0, &tokens, pos);
    
    int paren_nest = 0;
    int arg_idx = 0;
    for(int i = 0; count < 4; i += 1)
    {
      Token *token = token_it_read(&it);
      if(token)
      {
        if(paren_nest == 0 &&
           token->sub_kind == TokenZigKind_ParenOp &&
           token_it_dec_non_whitespace(&it))
        {
          Token *name = token_it_read(&it);
          if(name && name->kind == TokenBaseKind_Identifier)
          {
            F4_Language_PosContext_PushData_Call(arena, &first, &last, push_buffer_range(app, arena, buffer, Ii64(name)), arg_idx);
						count += 1;
            arg_idx = 0;
          }
        }
        else if(token->sub_kind == TokenZigKind_ParenOp)
        {
          paren_nest -= 1;
        }
        else if(token->sub_kind == TokenZigKind_ParenCl && i > 0)
        {
          paren_nest += 1;
        }
        else if(token->sub_kind == TokenZigKind_Comma && i > 0 && paren_nest == 0)
        {
          arg_idx += 1;
        }
      }
      else { break; }
      if(!token_it_dec_non_whitespace(&it))
      {
        break;
      }
    }
  }
  return first;
}


internal F4_LANGUAGE_HIGHLIGHT(F4_Zig_Highlight)
{
}