#if !defined(FCODER_LEX_GEN_HAND_WRITTEN_TYPES)
#define FCODER_LEX_GEN_HAND_WRITTEN_TYPES

struct Lexeme_Table_Value{
    Token_Base_Kind base_kind;
    u16 sub_kind;
};

struct Lexeme_Table_Lookup{
    b32 found_match;
    Token_Base_Kind base_kind;
    u16 sub_kind;
};

#endif
typedef u16 Token_Zig_Kind;
enum{
TokenZigKind_EOF = 0,
TokenZigKind_Whitespace = 1,
TokenZigKind_LexError = 2,
TokenZigKind_BlockComment = 3,
TokenZigKind_LineComment = 4,
TokenZigKind_Backslash = 5,
TokenZigKind_LiteralInteger = 6,
TokenZigKind_LiteralIntegerHex = 7,
TokenZigKind_LiteralIntegerOct = 8,
TokenZigKind_LiteralIntegerDoz = 9,
TokenZigKind_LiteralIntegerBin = 10,
TokenZigKind_LiteralFloat = 11,
TokenZigKind_LiteralString = 12,
TokenZigKind_LiteralStringWide = 13,
TokenZigKind_LiteralStringUTF8 = 14,
TokenZigKind_LiteralStringUTF16 = 15,
TokenZigKind_LiteralStringUTF32 = 16,
TokenZigKind_LiteralStringRaw = 17,
TokenZigKind_LiteralStringWideRaw = 18,
TokenZigKind_LiteralStringUTF8Raw = 19,
TokenZigKind_LiteralStringUTF16Raw = 20,
TokenZigKind_LiteralStringUTF32Raw = 21,
TokenZigKind_LiteralCharacter = 22,
TokenZigKind_LiteralCharacterWide = 23,
TokenZigKind_LiteralCharacterUTF8 = 24,
TokenZigKind_LiteralCharacterUTF16 = 25,
TokenZigKind_LiteralCharacterUTF32 = 26,
TokenZigKind_KeywordGeneric = 27,
TokenZigKind_BuiltinFunctions = 28,
TokenZigKind_IdentifierMacro = 29,
TokenZigKind_BraceOp = 30,
TokenZigKind_BraceCl = 31,
TokenZigKind_ParenOp = 32,
TokenZigKind_BrackOp = 33,
TokenZigKind_ParenCl = 34,
TokenZigKind_BrackCl = 35,
TokenZigKind_Semicolon = 36,
TokenZigKind_Dot = 37,
TokenZigKind_Colon = 38,
TokenZigKind_Eq = 39,
TokenZigKind_Question = 40,
TokenZigKind_Plus = 41,
TokenZigKind_PlusEq = 42,
TokenZigKind_PlusMod = 43,
TokenZigKind_PlusModEq = 44,
TokenZigKind_PlusOr = 45,
TokenZigKind_PlusOrEq = 46,
TokenZigKind_Minus = 47,
TokenZigKind_MinusEq = 48,
TokenZigKind_MinusMod = 49,
TokenZigKind_MinusModEq = 50,
TokenZigKind_MinusOr = 51,
TokenZigKind_MinusOrEq = 52,
TokenZigKind_Star = 53,
TokenZigKind_StarEq = 54,
TokenZigKind_StarMod = 55,
TokenZigKind_StarModEq = 56,
TokenZigKind_StarOr = 57,
TokenZigKind_StarOrEq = 58,
TokenZigKind_Div = 59,
TokenZigKind_DivEq = 60,
TokenZigKind_Mod = 61,
TokenZigKind_ModEq = 62,
TokenZigKind_LessLess = 63,
TokenZigKind_LessLessEq = 64,
TokenZigKind_LessLessOr = 65,
TokenZigKind_LessLessOrEq = 66,
TokenZigKind_GrtrGrtr = 67,
TokenZigKind_GrtrGrtrEq = 68,
TokenZigKind_And = 69,
TokenZigKind_AndEq = 70,
TokenZigKind_Or = 71,
TokenZigKind_OrEq = 72,
TokenZigKind_Carrot = 73,
TokenZigKind_CarrotEq = 74,
TokenZigKind_Tilde = 75,
TokenZigKind_DotQuestion = 76,
TokenZigKind_Not = 77,
TokenZigKind_EqEq = 78,
TokenZigKind_NotEq = 79,
TokenZigKind_Less = 80,
TokenZigKind_Grtr = 81,
TokenZigKind_LessEq = 82,
TokenZigKind_GrtrEq = 83,
TokenZigKind_PlusPlus = 84,
TokenZigKind_StarStar = 85,
TokenZigKind_DotStar = 86,
TokenZigKind_OrOr = 87,
TokenZigKind_Comma = 88,
TokenZigKind_align = 89,
TokenZigKind_allowzero = 90,
TokenZigKind_and = 91,
TokenZigKind_anyframe = 92,
TokenZigKind_anytype = 93,
TokenZigKind_asm = 94,
TokenZigKind_async = 95,
TokenZigKind_await = 96,
TokenZigKind_break = 97,
TokenZigKind_catch = 98,
TokenZigKind_comptime = 99,
TokenZigKind_const = 100,
TokenZigKind_continue = 101,
TokenZigKind_defer = 102,
TokenZigKind_else = 103,
TokenZigKind_enum = 104,
TokenZigKind_errdefer = 105,
TokenZigKind_error = 106,
TokenZigKind_export = 107,
TokenZigKind_extern = 108,
TokenZigKind_fn = 109,
TokenZigKind_for = 110,
TokenZigKind_if = 111,
TokenZigKind_inline = 112,
TokenZigKind_noalias = 113,
TokenZigKind_nosuspend = 114,
TokenZigKind_or = 115,
TokenZigKind_orelse = 116,
TokenZigKind_opaque = 117,
TokenZigKind_packed = 118,
TokenZigKind_pub = 119,
TokenZigKind_resume = 120,
TokenZigKind_return = 121,
TokenZigKind_linksection = 122,
TokenZigKind_struct = 123,
TokenZigKind_suspend = 124,
TokenZigKind_switch = 125,
TokenZigKind_test = 126,
TokenZigKind_threadlocal = 127,
TokenZigKind_try = 128,
TokenZigKind_union = 129,
TokenZigKind_unreachable = 130,
TokenZigKind_usingnamespace = 131,
TokenZigKind_var = 132,
TokenZigKind_volatile = 133,
TokenZigKind_while = 134,
TokenZigKind_LiteralTrue = 135,
TokenZigKind_LiteralFalse = 136,
TokenZigKind_i8 = 137,
TokenZigKind_u8 = 138,
TokenZigKind_i16 = 139,
TokenZigKind_u16 = 140,
TokenZigKind_i32 = 141,
TokenZigKind_u32 = 142,
TokenZigKind_i64 = 143,
TokenZigKind_u64 = 144,
TokenZigKind_i128 = 145,
TokenZigKind_u128 = 146,
TokenZigKind_isize = 147,
TokenZigKind_usize = 148,
TokenZigKind_c_short = 149,
TokenZigKind_c_ushort = 150,
TokenZigKind_c_int = 151,
TokenZigKind_c_uint = 152,
TokenZigKind_c_long = 153,
TokenZigKind_c_ulong = 154,
TokenZigKind_c_longlong = 155,
TokenZigKind_c_ulonglong = 156,
TokenZigKind_c_longdouble = 157,
TokenZigKind_f16 = 158,
TokenZigKind_f32 = 159,
TokenZigKind_f64 = 160,
TokenZigKind_f80 = 161,
TokenZigKind_f128 = 162,
TokenZigKind_bool = 163,
TokenZigKind_anyopaque = 164,
TokenZigKind_void = 165,
TokenZigKind_noreturn = 166,
TokenZigKind_type = 167,
TokenZigKind_anyerror = 168,
TokenZigKind_comptime_int = 169,
TokenZigKind_Identifier = 170,
TokenZigKind_COUNT = 171,
};
char *token_zig_kind_names[] = {
"EOF",
"Whitespace",
"LexError",
"BlockComment",
"LineComment",
"Backslash",
"LiteralInteger",
"LiteralIntegerHex",
"LiteralIntegerOct",
"LiteralIntegerDoz",
"LiteralIntegerBin",
"LiteralFloat",
"LiteralString",
"LiteralStringWide",
"LiteralStringUTF8",
"LiteralStringUTF16",
"LiteralStringUTF32",
"LiteralStringRaw",
"LiteralStringWideRaw",
"LiteralStringUTF8Raw",
"LiteralStringUTF16Raw",
"LiteralStringUTF32Raw",
"LiteralCharacter",
"LiteralCharacterWide",
"LiteralCharacterUTF8",
"LiteralCharacterUTF16",
"LiteralCharacterUTF32",
"KeywordGeneric",
"BuiltinFunctions",
"IdentifierMacro",
"BraceOp",
"BraceCl",
"ParenOp",
"BrackOp",
"ParenCl",
"BrackCl",
"Semicolon",
"Dot",
"Colon",
"Eq",
"Question",
"Plus",
"PlusEq",
"PlusMod",
"PlusModEq",
"PlusOr",
"PlusOrEq",
"Minus",
"MinusEq",
"MinusMod",
"MinusModEq",
"MinusOr",
"MinusOrEq",
"Star",
"StarEq",
"StarMod",
"StarModEq",
"StarOr",
"StarOrEq",
"Div",
"DivEq",
"Mod",
"ModEq",
"LessLess",
"LessLessEq",
"LessLessOr",
"LessLessOrEq",
"GrtrGrtr",
"GrtrGrtrEq",
"And",
"AndEq",
"Or",
"OrEq",
"Carrot",
"CarrotEq",
"Tilde",
"DotQuestion",
"Not",
"EqEq",
"NotEq",
"Less",
"Grtr",
"LessEq",
"GrtrEq",
"PlusPlus",
"StarStar",
"DotStar",
"OrOr",
"Comma",
"align",
"allowzero",
"and",
"anyframe",
"anytype",
"asm",
"async",
"await",
"break",
"catch",
"comptime",
"const",
"continue",
"defer",
"else",
"enum",
"errdefer",
"error",
"export",
"extern",
"fn",
"for",
"if",
"inline",
"noalias",
"nosuspend",
"or",
"orelse",
"opaque",
"packed",
"pub",
"resume",
"return",
"linksection",
"struct",
"suspend",
"switch",
"test",
"threadlocal",
"try",
"union",
"unreachable",
"usingnamespace",
"var",
"volatile",
"while",
"LiteralTrue",
"LiteralFalse",
"i8",
"u8",
"i16",
"u16",
"i32",
"u32",
"i64",
"u64",
"i128",
"u128",
"isize",
"usize",
"c_short",
"c_ushort",
"c_int",
"c_uint",
"c_long",
"c_ulong",
"c_longlong",
"c_ulonglong",
"c_longdouble",
"f16",
"f32",
"f64",
"f80",
"f128",
"bool",
"anyopaque",
"void",
"noreturn",
"type",
"anyerror",
"comptime_int",
"Identifier",
};