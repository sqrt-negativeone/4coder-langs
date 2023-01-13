#if !defined(FCODER_LEX_GEN_HAND_WRITTEN)
#define FCODER_LEX_GEN_HAND_WRITTEN

internal u64
lexeme_hash(u64 seed, u8 *ptr, u64 size){
    u64 result = 0;
    for (u64 i = 0; i < size; i += 1, ptr += 1){
        result ^= ((*ptr) ^ result*59) + seed;
    }
    return(result);
}

internal Lexeme_Table_Lookup
lexeme_table_lookup(u64 *hash_array, String_Const_u8 *key_array, 
                    Lexeme_Table_Value *value_array, i32 slot_count, u64 seed,
                    u8 *ptr, u64 size){
    Lexeme_Table_Lookup result = {};
    u64 hash = lexeme_hash(seed, ptr, size);
    u64 comparison_hash = hash | 1;
    i32 first_index = (hash % slot_count);
    i32 index = first_index;
    for (;;){
        if (hash_array[index] == comparison_hash){
            if (string_match(SCu8(ptr, size), key_array[index])){
                result.found_match = true;
                result.base_kind = value_array[index].base_kind;
                result.sub_kind = value_array[index].sub_kind;
                break;
            }
        }
        else if (hash_array[index] == 0){
            break;
        }
        index += 1;
        if (index == slot_count){
            index = 0;
        }
        if (index == first_index){
            break;
        }
    }
    return(result);
}

#endif
u64 zig_main_keys_hash_array[153] = {
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x38febeb80c94bb91,
0x0000000000000000,0xdd3f1bff994cdd3d,0x0000000000000000,0x71627daded4e44ed,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xb31b128fde9ac391,0x38febeb80c94bb01,0x39fbb86d467adddf,0xb31b1243c0916269,
0x0000000000000000,0x0000000000000000,0x38febeb80c94b50d,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xba11f7b7645f1f85,0x0000000000000000,
0xba11f7b45c5f76d3,0xba11f7b77cd5e8c9,0x62f733ab55ad52f1,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x71627daded483ae1,0x71627daded4896ed,
0x0000000000000000,0xba11f7b45f92ccb7,0xba11f7b45f5f60bd,0x0000000000000000,
0x71627daded4f90bd,0x0000000000000000,0x0000000000000000,0x39fbb86d41abb58f,
0xb31b12898b898a85,0x0000000000000000,0x0000000000000000,0xb31b128eb791d03b,
0x71627daded4e52d1,0xdd3f06ef426e4aeb,0x0000000000000000,0xb31b128fdee0fc9b,
0x39fbb86d41ede657,0x71627daded4817b1,0x0000000000000000,0x0000000000000000,
0xf95250291ee9f8a1,0x0000000000000000,0x71627daded48171d,0x0000000000000000,
0xba11f7b46cd895e5,0xf9524813389d8e61,0x63fcb2fc5561e527,0x001f5d422b3704e1,
0x71627daded4880eb,0x0000000000000000,0xf94d596cafa4e8c1,0x39fbb86d4672cb5f,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xba11f7b459393cfd,0xf94d596ca68640fd,0x0000000000000000,
0xba11f7b45c4e88cf,0xb31b12371a5e7741,0x39fbb86d4191ca85,0x0000000000000000,
0x0000000000000000,0xf95286e84123c8fd,0x39fbb86d41ec7a7d,0x1ead2f9f2145eff7,
0xba11f7b7591855a7,0x0000000000000000,0xb31b128fb1f912f1,0x0000000000000000,
0x0000000000000000,0x71627daded48381b,0x39fbb86d41ec20df,0x0000000000000000,
0x0000000000000000,0x39fbb86d41ecfba1,0x0000000000000000,0x0000000000000000,
0x0ab3e9eab7bdc925,0x71627daded4e539b,0x5403df9fad5ec41d,0x0000000000000000,
0xdd3f1b5b7ce0544f,0x71627daded48335f,0x0000000000000000,0x71627daded483a8d,
0x0000000000000000,0xfd870fccb83fe527,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xb31b1288d12f2b07,0xb31b12898b237cd3,0x0000000000000000,
0x0000000000000000,0x38febeb80c94bbfb,0x0000000000000000,0x62f7ccf383535a57,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xba11f7b7584ffc21,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd0e9f026fb4dbb3b,0xf945222d19717be5,0x38febeb80c94b443,0x0000000000000000,
0xdd3f0701fd5e3b27,0x0000000000000000,0xb31b12371a607411,0x71627daded4e53bd,
0xb31b1289846025d7,0x71627daded4e53bd,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xba11f7b46759e401,0x0000000000000000,0x71627daded48c7bd,
0x0000000000000000,0x0000000000000000,0x312026ad5190011d,0x39fbb86d41ea66cf,
0x39fbb86d41912969,0x0000000000000000,0xba11f7b46766b2c9,0xba11f7b4564506db,
0x0000000000000000,0x62ea68254e8b8aeb,0xb31b128e8bd53427,0xba11f7b7652698f3,
0xf94d0717a58fb411,0x71627daded48121b,0x0000000000000000,0xdd3f07003228179b,
0xf9526b219d63bc9b,
};
u8 zig_main_keys_key_array_3[] = {0x69,0x66,};
u8 zig_main_keys_key_array_5[] = {0x61,0x6e,0x79,0x74,0x79,0x70,0x65,};
u8 zig_main_keys_key_array_7[] = {0x76,0x61,0x72,};
u8 zig_main_keys_key_array_12[] = {0x65,0x78,0x74,0x65,0x72,0x6e,};
u8 zig_main_keys_key_array_13[] = {0x66,0x6e,};
u8 zig_main_keys_key_array_14[] = {0x69,0x31,0x32,0x38,};
u8 zig_main_keys_key_array_15[] = {0x69,0x6e,0x6c,0x69,0x6e,0x65,};
u8 zig_main_keys_key_array_18[] = {0x6f,0x72,};
u8 zig_main_keys_key_array_22[] = {0x66,0x61,0x6c,0x73,0x65,};
u8 zig_main_keys_key_array_24[] = {0x63,0x61,0x74,0x63,0x68,};
u8 zig_main_keys_key_array_25[] = {0x69,0x73,0x69,0x7a,0x65,};
u8 zig_main_keys_key_array_26[] = {0x61,0x6e,0x79,0x6f,0x70,0x61,0x71,0x75,0x65,};
u8 zig_main_keys_key_array_30[] = {0x66,0x31,0x36,};
u8 zig_main_keys_key_array_31[] = {0x61,0x73,0x6d,};
u8 zig_main_keys_key_array_33[] = {0x62,0x72,0x65,0x61,0x6b,};
u8 zig_main_keys_key_array_34[] = {0x64,0x65,0x66,0x65,0x72,};
u8 zig_main_keys_key_array_36[] = {0x70,0x75,0x62,};
u8 zig_main_keys_key_array_39[] = {0x62,0x6f,0x6f,0x6c,};
u8 zig_main_keys_key_array_40[] = {0x6f,0x72,0x65,0x6c,0x73,0x65,};
u8 zig_main_keys_key_array_43[] = {0x63,0x5f,0x75,0x69,0x6e,0x74,};
u8 zig_main_keys_key_array_44[] = {0x75,0x31,0x36,};
u8 zig_main_keys_key_array_45[] = {0x73,0x75,0x73,0x70,0x65,0x6e,0x64,};
u8 zig_main_keys_key_array_47[] = {0x65,0x78,0x70,0x6f,0x72,0x74,};
u8 zig_main_keys_key_array_48[] = {0x74,0x65,0x73,0x74,};
u8 zig_main_keys_key_array_49[] = {0x69,0x31,0x36,};
u8 zig_main_keys_key_array_52[] = {0x63,0x6f,0x6d,0x70,0x74,0x69,0x6d,0x65,};
u8 zig_main_keys_key_array_54[] = {0x69,0x33,0x32,};
u8 zig_main_keys_key_array_56[] = {0x77,0x68,0x69,0x6c,0x65,};
u8 zig_main_keys_key_array_57[] = {0x63,0x6f,0x6e,0x74,0x69,0x6e,0x75,0x65,};
u8 zig_main_keys_key_array_58[] = {0x63,0x5f,0x75,0x6c,0x6f,0x6e,0x67,0x6c,0x6f,0x6e,0x67,};
u8 zig_main_keys_key_array_59[] = {0x6c,0x69,0x6e,0x6b,0x73,0x65,0x63,0x74,0x69,0x6f,0x6e,};
u8 zig_main_keys_key_array_60[] = {0x61,0x6e,0x64,};
u8 zig_main_keys_key_array_62[] = {0x61,0x6e,0x79,0x66,0x72,0x61,0x6d,0x65,};
u8 zig_main_keys_key_array_63[] = {0x66,0x31,0x32,0x38,};
u8 zig_main_keys_key_array_69[] = {0x65,0x72,0x72,0x6f,0x72,};
u8 zig_main_keys_key_array_70[] = {0x61,0x6e,0x79,0x65,0x72,0x72,0x6f,0x72,};
u8 zig_main_keys_key_array_72[] = {0x63,0x6f,0x6e,0x73,0x74,};
u8 zig_main_keys_key_array_73[] = {0x72,0x65,0x73,0x75,0x6d,0x65,};
u8 zig_main_keys_key_array_74[] = {0x65,0x6c,0x73,0x65,};
u8 zig_main_keys_key_array_77[] = {0x65,0x72,0x72,0x64,0x65,0x66,0x65,0x72,};
u8 zig_main_keys_key_array_78[] = {0x74,0x79,0x70,0x65,};
u8 zig_main_keys_key_array_79[] = {0x74,0x68,0x72,0x65,0x61,0x64,0x6c,0x6f,0x63,0x61,0x6c,};
u8 zig_main_keys_key_array_80[] = {0x61,0x77,0x61,0x69,0x74,};
u8 zig_main_keys_key_array_82[] = {0x6f,0x70,0x61,0x71,0x75,0x65,};
u8 zig_main_keys_key_array_85[] = {0x66,0x36,0x34,};
u8 zig_main_keys_key_array_86[] = {0x75,0x31,0x32,0x38,};
u8 zig_main_keys_key_array_89[] = {0x74,0x72,0x75,0x65,};
u8 zig_main_keys_key_array_92[] = {0x75,0x73,0x69,0x6e,0x67,0x6e,0x61,0x6d,0x65,0x73,0x70,0x61,0x63,0x65,};
u8 zig_main_keys_key_array_93[] = {0x75,0x36,0x34,};
u8 zig_main_keys_key_array_94[] = {0x63,0x5f,0x6c,0x6f,0x6e,0x67,0x64,0x6f,0x75,0x62,0x6c,0x65,};
u8 zig_main_keys_key_array_96[] = {0x6e,0x6f,0x61,0x6c,0x69,0x61,0x73,};
u8 zig_main_keys_key_array_97[] = {0x66,0x38,0x30,};
u8 zig_main_keys_key_array_99[] = {0x66,0x33,0x32,};
u8 zig_main_keys_key_array_101[] = {0x63,0x5f,0x6c,0x6f,0x6e,0x67,0x6c,0x6f,0x6e,0x67,};
u8 zig_main_keys_key_array_105[] = {0x70,0x61,0x63,0x6b,0x65,0x64,};
u8 zig_main_keys_key_array_106[] = {0x73,0x77,0x69,0x74,0x63,0x68,};
u8 zig_main_keys_key_array_109[] = {0x69,0x38,};
u8 zig_main_keys_key_array_111[] = {0x61,0x6c,0x6c,0x6f,0x77,0x7a,0x65,0x72,0x6f,};
u8 zig_main_keys_key_array_116[] = {0x61,0x6c,0x69,0x67,0x6e,};
u8 zig_main_keys_key_array_120[] = {0x63,0x6f,0x6d,0x70,0x74,0x69,0x6d,0x65,0x5f,0x69,0x6e,0x74,};
u8 zig_main_keys_key_array_121[] = {0x76,0x6f,0x6c,0x61,0x74,0x69,0x6c,0x65,};
u8 zig_main_keys_key_array_122[] = {0x75,0x38,};
u8 zig_main_keys_key_array_124[] = {0x63,0x5f,0x75,0x6c,0x6f,0x6e,0x67,};
u8 zig_main_keys_key_array_126[] = {0x72,0x65,0x74,0x75,0x72,0x6e,};
u8 zig_main_keys_key_array_127[] = {0x74,0x72,0x79,};
u8 zig_main_keys_key_array_128[] = {0x73,0x74,0x72,0x75,0x63,0x74,};
u8 zig_main_keys_key_array_129[] = {0x75,0x33,0x32,};
u8 zig_main_keys_key_array_133[] = {0x75,0x6e,0x69,0x6f,0x6e,};
u8 zig_main_keys_key_array_135[] = {0x66,0x6f,0x72,};
u8 zig_main_keys_key_array_138[] = {0x75,0x6e,0x72,0x65,0x61,0x63,0x68,0x61,0x62,0x6c,0x65,};
u8 zig_main_keys_key_array_139[] = {0x76,0x6f,0x69,0x64,};
u8 zig_main_keys_key_array_140[] = {0x65,0x6e,0x75,0x6d,};
u8 zig_main_keys_key_array_142[] = {0x75,0x73,0x69,0x7a,0x65,};
u8 zig_main_keys_key_array_143[] = {0x63,0x5f,0x69,0x6e,0x74,};
u8 zig_main_keys_key_array_145[] = {0x6e,0x6f,0x73,0x75,0x73,0x70,0x65,0x6e,0x64,};
u8 zig_main_keys_key_array_146[] = {0x63,0x5f,0x6c,0x6f,0x6e,0x67,};
u8 zig_main_keys_key_array_147[] = {0x61,0x73,0x79,0x6e,0x63,};
u8 zig_main_keys_key_array_148[] = {0x6e,0x6f,0x72,0x65,0x74,0x75,0x72,0x6e,};
u8 zig_main_keys_key_array_149[] = {0x69,0x36,0x34,};
u8 zig_main_keys_key_array_151[] = {0x63,0x5f,0x73,0x68,0x6f,0x72,0x74,};
u8 zig_main_keys_key_array_152[] = {0x63,0x5f,0x75,0x73,0x68,0x6f,0x72,0x74,};
String_Const_u8 zig_main_keys_key_array[153] = {
{0, 0},
{0, 0},
{0, 0},
{zig_main_keys_key_array_3, 2},
{0, 0},
{zig_main_keys_key_array_5, 7},
{0, 0},
{zig_main_keys_key_array_7, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{zig_main_keys_key_array_12, 6},
{zig_main_keys_key_array_13, 2},
{zig_main_keys_key_array_14, 4},
{zig_main_keys_key_array_15, 6},
{0, 0},
{0, 0},
{zig_main_keys_key_array_18, 2},
{0, 0},
{0, 0},
{0, 0},
{zig_main_keys_key_array_22, 5},
{0, 0},
{zig_main_keys_key_array_24, 5},
{zig_main_keys_key_array_25, 5},
{zig_main_keys_key_array_26, 9},
{0, 0},
{0, 0},
{0, 0},
{zig_main_keys_key_array_30, 3},
{zig_main_keys_key_array_31, 3},
{0, 0},
{zig_main_keys_key_array_33, 5},
{zig_main_keys_key_array_34, 5},
{0, 0},
{zig_main_keys_key_array_36, 3},
{0, 0},
{0, 0},
{zig_main_keys_key_array_39, 4},
{zig_main_keys_key_array_40, 6},
{0, 0},
{0, 0},
{zig_main_keys_key_array_43, 6},
{zig_main_keys_key_array_44, 3},
{zig_main_keys_key_array_45, 7},
{0, 0},
{zig_main_keys_key_array_47, 6},
{zig_main_keys_key_array_48, 4},
{zig_main_keys_key_array_49, 3},
{0, 0},
{0, 0},
{zig_main_keys_key_array_52, 8},
{0, 0},
{zig_main_keys_key_array_54, 3},
{0, 0},
{zig_main_keys_key_array_56, 5},
{zig_main_keys_key_array_57, 8},
{zig_main_keys_key_array_58, 11},
{zig_main_keys_key_array_59, 11},
{zig_main_keys_key_array_60, 3},
{0, 0},
{zig_main_keys_key_array_62, 8},
{zig_main_keys_key_array_63, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{zig_main_keys_key_array_69, 5},
{zig_main_keys_key_array_70, 8},
{0, 0},
{zig_main_keys_key_array_72, 5},
{zig_main_keys_key_array_73, 6},
{zig_main_keys_key_array_74, 4},
{0, 0},
{0, 0},
{zig_main_keys_key_array_77, 8},
{zig_main_keys_key_array_78, 4},
{zig_main_keys_key_array_79, 11},
{zig_main_keys_key_array_80, 5},
{0, 0},
{zig_main_keys_key_array_82, 6},
{0, 0},
{0, 0},
{zig_main_keys_key_array_85, 3},
{zig_main_keys_key_array_86, 4},
{0, 0},
{0, 0},
{zig_main_keys_key_array_89, 4},
{0, 0},
{0, 0},
{zig_main_keys_key_array_92, 14},
{zig_main_keys_key_array_93, 3},
{zig_main_keys_key_array_94, 12},
{0, 0},
{zig_main_keys_key_array_96, 7},
{zig_main_keys_key_array_97, 3},
{0, 0},
{zig_main_keys_key_array_99, 3},
{0, 0},
{zig_main_keys_key_array_101, 10},
{0, 0},
{0, 0},
{0, 0},
{zig_main_keys_key_array_105, 6},
{zig_main_keys_key_array_106, 6},
{0, 0},
{0, 0},
{zig_main_keys_key_array_109, 2},
{0, 0},
{zig_main_keys_key_array_111, 9},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{zig_main_keys_key_array_116, 5},
{0, 0},
{0, 0},
{0, 0},
{zig_main_keys_key_array_120, 12},
{zig_main_keys_key_array_121, 8},
{zig_main_keys_key_array_122, 2},
{0, 0},
{zig_main_keys_key_array_124, 7},
{0, 0},
{zig_main_keys_key_array_126, 6},
{zig_main_keys_key_array_127, 3},
{zig_main_keys_key_array_128, 6},
{zig_main_keys_key_array_129, 3},
{0, 0},
{0, 0},
{0, 0},
{zig_main_keys_key_array_133, 5},
{0, 0},
{zig_main_keys_key_array_135, 3},
{0, 0},
{0, 0},
{zig_main_keys_key_array_138, 11},
{zig_main_keys_key_array_139, 4},
{zig_main_keys_key_array_140, 4},
{0, 0},
{zig_main_keys_key_array_142, 5},
{zig_main_keys_key_array_143, 5},
{0, 0},
{zig_main_keys_key_array_145, 9},
{zig_main_keys_key_array_146, 6},
{zig_main_keys_key_array_147, 5},
{zig_main_keys_key_array_148, 8},
{zig_main_keys_key_array_149, 3},
{0, 0},
{zig_main_keys_key_array_151, 7},
{zig_main_keys_key_array_152, 8},
};
Lexeme_Table_Value zig_main_keys_value_array[153] = {
{0, 0},
{0, 0},
{0, 0},
{4, TokenZigKind_if},
{0, 0},
{4, TokenZigKind_anytype},
{0, 0},
{4, TokenZigKind_var},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenZigKind_extern},
{4, TokenZigKind_fn},
{4, TokenZigKind_i128},
{4, TokenZigKind_inline},
{0, 0},
{0, 0},
{4, TokenZigKind_or},
{0, 0},
{0, 0},
{0, 0},
{8, TokenZigKind_LiteralFalse},
{0, 0},
{4, TokenZigKind_catch},
{4, TokenZigKind_isize},
{4, TokenZigKind_anyopaque},
{0, 0},
{0, 0},
{0, 0},
{4, TokenZigKind_f16},
{4, TokenZigKind_asm},
{0, 0},
{4, TokenZigKind_break},
{4, TokenZigKind_defer},
{0, 0},
{4, TokenZigKind_pub},
{0, 0},
{0, 0},
{4, TokenZigKind_bool},
{4, TokenZigKind_orelse},
{0, 0},
{0, 0},
{4, TokenZigKind_c_uint},
{4, TokenZigKind_u16},
{4, TokenZigKind_suspend},
{0, 0},
{4, TokenZigKind_export},
{4, TokenZigKind_test},
{4, TokenZigKind_i16},
{0, 0},
{0, 0},
{4, TokenZigKind_comptime},
{0, 0},
{4, TokenZigKind_i32},
{0, 0},
{4, TokenZigKind_while},
{4, TokenZigKind_continue},
{4, TokenZigKind_c_ulonglong},
{4, TokenZigKind_linksection},
{4, TokenZigKind_and},
{0, 0},
{4, TokenZigKind_anyframe},
{4, TokenZigKind_f128},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenZigKind_error},
{4, TokenZigKind_anyerror},
{0, 0},
{4, TokenZigKind_const},
{4, TokenZigKind_resume},
{4, TokenZigKind_else},
{0, 0},
{0, 0},
{4, TokenZigKind_errdefer},
{4, TokenZigKind_type},
{4, TokenZigKind_threadlocal},
{4, TokenZigKind_await},
{0, 0},
{4, TokenZigKind_opaque},
{0, 0},
{0, 0},
{4, TokenZigKind_f64},
{4, TokenZigKind_u128},
{0, 0},
{0, 0},
{8, TokenZigKind_LiteralTrue},
{0, 0},
{0, 0},
{4, TokenZigKind_usingnamespace},
{4, TokenZigKind_u64},
{4, TokenZigKind_c_longdouble},
{0, 0},
{4, TokenZigKind_noalias},
{4, TokenZigKind_f80},
{0, 0},
{4, TokenZigKind_f32},
{0, 0},
{4, TokenZigKind_c_longlong},
{0, 0},
{0, 0},
{0, 0},
{4, TokenZigKind_packed},
{4, TokenZigKind_switch},
{0, 0},
{0, 0},
{4, TokenZigKind_i8},
{0, 0},
{4, TokenZigKind_allowzero},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenZigKind_align},
{0, 0},
{0, 0},
{0, 0},
{4, TokenZigKind_comptime_int},
{4, TokenZigKind_volatile},
{4, TokenZigKind_u8},
{0, 0},
{4, TokenZigKind_c_ulong},
{0, 0},
{4, TokenZigKind_return},
{4, TokenZigKind_try},
{4, TokenZigKind_struct},
{4, TokenZigKind_u32},
{0, 0},
{0, 0},
{0, 0},
{4, TokenZigKind_union},
{0, 0},
{4, TokenZigKind_for},
{0, 0},
{0, 0},
{4, TokenZigKind_unreachable},
{4, TokenZigKind_void},
{4, TokenZigKind_enum},
{0, 0},
{4, TokenZigKind_usize},
{4, TokenZigKind_c_int},
{0, 0},
{4, TokenZigKind_nosuspend},
{4, TokenZigKind_c_long},
{4, TokenZigKind_async},
{4, TokenZigKind_noreturn},
{4, TokenZigKind_i64},
{0, 0},
{4, TokenZigKind_c_short},
{4, TokenZigKind_c_ushort},
};
i32 zig_main_keys_slot_count = 153;
u64 zig_main_keys_seed = 0x26e6ceaafb955d0b;
struct Lex_State_Zig{
u32 flags_ZF0;
u8 *base;
u8 *delim_first;
u8 *delim_one_past_last;
u8 *emit_ptr;
u8 *ptr;
u8 *opl_ptr;
};
internal void
lex_full_input_zig_init(Lex_State_Zig *state_ptr, String_Const_u8 input){
state_ptr->flags_ZF0 = 0;
state_ptr->base = input.str;
state_ptr->delim_first = input.str;
state_ptr->delim_one_past_last = input.str;
state_ptr->emit_ptr = input.str;
state_ptr->ptr = input.str;
state_ptr->opl_ptr = input.str + input.size;
}
internal b32
lex_full_input_zig_breaks(Arena *arena, Token_List *list, Lex_State_Zig *state_ptr, u64 max){
b32 result = false;
u64 emit_counter = 0;
Lex_State_Zig state;
block_copy_struct(&state, state_ptr);
{
state_label_1: // root
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
case 0x00:case 0x01:case 0x02:case 0x03:case 0x04:case 0x05:case 0x06:
case 0x07:case 0x08:case 0x0e:case 0x0f:case 0x10:case 0x11:case 0x12:
case 0x13:case 0x14:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:
case 0x1a:case 0x1b:case 0x1c:case 0x1d:case 0x1e:case 0x1f:case 0x23:
case 0x60:case 0x7f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x09:case 0x0a:case 0x0b:case 0x0c:case 0x0d:case 0x20:
{
state.ptr += 1;
goto state_label_3; // whitespace
}break;
case 0x21:
{
state.ptr += 1;
goto state_label_56; // op stage
}break;
case 0x22:
{
state.ptr += 1;
goto state_label_20; // string
}break;
default:
{
state.ptr += 1;
goto state_label_2; // identifier
}break;
case 0x25:
{
state.ptr += 1;
goto state_label_46; // op stage
}break;
case 0x26:
{
state.ptr += 1;
goto state_label_52; // op stage
}break;
case 0x27:
{
state.ptr += 1;
state.flags_ZF0 |= 0x100;
goto state_label_20; // string
}break;
case 0x28:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_ParenOp;
token.kind = 13;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x29:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_ParenCl;
token.kind = 14;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_43; // op stage
}break;
case 0x2b:
{
state.ptr += 1;
goto state_label_37; // op stage
}break;
case 0x2c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Comma;
token.kind = 15;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2d:
{
state.ptr += 1;
goto state_label_40; // op stage
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_5; // operator_or_fnumber_dot
}break;
case 0x2f:
{
state.ptr += 1;
goto state_label_6; // operator_or_comment_slash
}break;
case 0x30:
{
state.ptr += 1;
goto state_label_8; // znumber
}break;
case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:case 0x37:
case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_7; // number
}break;
case 0x3a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Colon;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Semicolon;
token.kind = 15;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3c:
{
state.ptr += 1;
goto state_label_47; // op stage
}break;
case 0x3d:
{
state.ptr += 1;
goto state_label_55; // op stage
}break;
case 0x3e:
{
state.ptr += 1;
goto state_label_50; // op stage
}break;
case 0x3f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Question;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x40:
{
state.ptr += 1;
goto state_label_33; // builtin_function
}break;
case 0x5b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_BrackOp;
token.kind = 13;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x5c:
{
state.ptr += 1;
goto state_label_4; // backslash
}break;
case 0x5d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_BrackCl;
token.kind = 14;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x5e:
{
state.ptr += 1;
goto state_label_54; // op stage
}break;
case 0x7b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_BraceOp;
token.kind = 11;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x7c:
{
state.ptr += 1;
goto state_label_53; // op stage
}break;
case 0x7d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_BraceCl;
token.kind = 12;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x7e:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Tilde;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_2: // identifier
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(zig_main_keys_hash_array, zig_main_keys_key_array, zig_main_keys_value_array, zig_main_keys_slot_count, zig_main_keys_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenZigKind_Identifier;
token.kind = 6;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
case 0x00:case 0x01:case 0x02:case 0x03:case 0x04:case 0x05:case 0x06:
case 0x07:case 0x08:case 0x09:case 0x0a:case 0x0b:case 0x0c:case 0x0d:
case 0x0e:case 0x0f:case 0x10:case 0x11:case 0x12:case 0x13:case 0x14:
case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1a:case 0x1b:
case 0x1c:case 0x1d:case 0x1e:case 0x1f:case 0x20:case 0x21:case 0x22:
case 0x23:case 0x25:case 0x26:case 0x27:case 0x28:case 0x29:case 0x2a:
case 0x2b:case 0x2c:case 0x2d:case 0x2e:case 0x2f:case 0x3a:case 0x3b:
case 0x3c:case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x5b:case 0x5c:
case 0x5d:case 0x5e:case 0x60:case 0x7b:case 0x7c:case 0x7d:case 0x7e:
case 0x7f:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(zig_main_keys_hash_array, zig_main_keys_key_array, zig_main_keys_value_array, zig_main_keys_slot_count, zig_main_keys_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenZigKind_Identifier;
token.kind = 6;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
default:
{
state.ptr += 1;
goto state_label_2; // identifier
}break;
}
}
{
state_label_3: // whitespace
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Whitespace;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Whitespace;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x09:case 0x0a:case 0x0b:case 0x0c:case 0x0d:case 0x20:
{
state.ptr += 1;
goto state_label_3; // whitespace
}break;
}
}
{
state_label_4: // backslash
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Backslash;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Backslash;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x0a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Backslash;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x0d:
{
state.ptr += 1;
goto state_label_4; // backslash
}break;
}
}
{
state_label_5: // operator_or_fnumber_dot
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Dot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Dot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_DotStar;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_9; // fnumber_decimal
}break;
case 0x3f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_DotQuestion;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_6: // operator_or_comment_slash
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Div;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Div;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_34; // comment_block
}break;
case 0x2f:
{
state.ptr += 1;
goto state_label_36; // comment_line
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_DivEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_7: // number
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_9; // fnumber_decimal
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x5f:
{
state.ptr += 1;
goto state_label_7; // number
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_10; // fnumber_exponent
}break;
}
}
{
state_label_8: // znumber
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_9; // fnumber_decimal
}break;
case 0x42:case 0x62:
{
state.ptr += 1;
state.flags_ZF0 |= 0x80;
goto state_label_15; // number_bin_first
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_10; // fnumber_exponent
}break;
case 0x4f:case 0x6f:
{
state.ptr += 1;
state.flags_ZF0 |= 0x2;
goto state_label_17; // number_oct
}break;
case 0x58:case 0x78:
{
state.ptr += 1;
state.flags_ZF0 |= 0x1;
goto state_label_13; // number_hex_first
}break;
case 0x5a:case 0x7a:
{
state.ptr += 1;
state.flags_ZF0 |= 0x4;
goto state_label_14; // number_doz_first
}break;
}
}
{
state_label_9: // fnumber_decimal
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x5f:
{
state.ptr += 1;
goto state_label_9; // fnumber_decimal
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_10; // fnumber_exponent
}break;
}
}
{
state_label_10: // fnumber_exponent
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2b:case 0x2d:
{
state.ptr += 1;
goto state_label_11; // fnumber_exponent_sign
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_12; // fnumber_exponent_digits
}break;
}
}
{
state_label_11: // fnumber_exponent_sign
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_12; // fnumber_exponent_digits
}break;
}
}
{
state_label_12: // fnumber_exponent_digits
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x5f:
{
state.ptr += 1;
goto state_label_12; // fnumber_exponent_digits
}break;
}
}
{
state_label_13: // number_hex_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_16; // number_hex
}break;
}
}
{
state_label_14: // number_doz_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x61:case 0x62:
{
state.ptr += 1;
goto state_label_18; // number_doz
}break;
}
}
{
state_label_15: // number_bin_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:
{
state.ptr += 1;
goto state_label_19; // number_bin
}break;
case 0x5f:
{
state.ptr += 1;
state.flags_ZF0 |= 0x80;
goto state_label_15; // number_bin_first
}break;
}
}
{
state_label_16: // number_hex
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralIntegerHex;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralIntegerHex;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x5f:case 0x61:case 0x62:case 0x63:case 0x64:
case 0x65:case 0x66:
{
state.ptr += 1;
goto state_label_16; // number_hex
}break;
}
}
{
state_label_17: // number_oct
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralIntegerOct;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralIntegerOct;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x5f:
{
state.ptr += 1;
state.flags_ZF0 |= 0x2;
goto state_label_17; // number_oct
}break;
}
}
{
state_label_18: // number_doz
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralIntegerDoz;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralIntegerDoz;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x5f:case 0x61:case 0x62:case 0x63:case 0x64:
case 0x65:case 0x66:
{
state.ptr += 1;
goto state_label_18; // number_doz
}break;
}
}
{
state_label_19: // number_bin
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralIntegerBin;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LiteralIntegerBin;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x5f:
{
state.ptr += 1;
goto state_label_19; // number_bin
}break;
}
}
{
state_label_20: // string
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_20; // string
}break;
case 0x0a:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x22:
{
if ((!HasFlag(state.flags_ZF0, 0x100))){
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
if (HasFlag(state.flags_ZF0, 0x8)){
token.sub_kind = TokenZigKind_LiteralStringWide;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x10)){
token.sub_kind = TokenZigKind_LiteralStringUTF8;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x20)){
token.sub_kind = TokenZigKind_LiteralStringUTF16;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x40)){
token.sub_kind = TokenZigKind_LiteralStringUTF32;
token.kind = 10;
break;
}
token.sub_kind = TokenZigKind_LiteralString;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
state.ptr += 1;
goto state_label_20; // string
}break;
case 0x27:
{
if ((HasFlag(state.flags_ZF0, 0x100))){
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
if (HasFlag(state.flags_ZF0, 0x8)){
token.sub_kind = TokenZigKind_LiteralCharacterWide;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x10)){
token.sub_kind = TokenZigKind_LiteralCharacterUTF8;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x20)){
token.sub_kind = TokenZigKind_LiteralCharacterUTF16;
token.kind = 10;
break;
}
if (HasFlag(state.flags_ZF0, 0x40)){
token.sub_kind = TokenZigKind_LiteralCharacterUTF32;
token.kind = 10;
break;
}
token.sub_kind = TokenZigKind_LiteralCharacter;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
state.ptr += 1;
goto state_label_20; // string
}break;
case 0x5c:
{
state.ptr += 1;
goto state_label_21; // string_esc
}break;
}
}
{
state_label_21: // string_esc
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:
{
state.ptr += 1;
goto state_label_22; // string_esc_oct2
}break;
case 0x55:
{
state.ptr += 1;
goto state_label_25; // string_esc_universal_8
}break;
case 0x75:
{
state.ptr += 1;
goto state_label_29; // string_esc_universal_4
}break;
case 0x78:
{
state.ptr += 1;
goto state_label_24; // string_esc_hex
}break;
}
}
{
state_label_22: // string_esc_oct2
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:
{
state.ptr += 1;
goto state_label_23; // string_esc_oct1
}break;
}
}
{
state_label_23: // string_esc_oct1
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:
{
state.ptr += 1;
goto state_label_20; // string
}break;
}
}
{
state_label_24: // string_esc_hex
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_24; // string_esc_hex
}break;
}
}
{
state_label_25: // string_esc_universal_8
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_26; // string_esc_universal_7
}break;
}
}
{
state_label_26: // string_esc_universal_7
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_27; // string_esc_universal_6
}break;
}
}
{
state_label_27: // string_esc_universal_6
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_28; // string_esc_universal_5
}break;
}
}
{
state_label_28: // string_esc_universal_5
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_29; // string_esc_universal_4
}break;
}
}
{
state_label_29: // string_esc_universal_4
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_30; // string_esc_universal_3
}break;
}
}
{
state_label_30: // string_esc_universal_3
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_31; // string_esc_universal_2
}break;
}
}
{
state_label_31: // string_esc_universal_2
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_32; // string_esc_universal_1
}break;
}
}
{
state_label_32: // string_esc_universal_1
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_20; // string
}
}
switch (*state.ptr){
default:
{
goto state_label_20; // string
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_20; // string
}break;
}
}
{
state_label_33: // builtin_function
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_BuiltinFunctions;
token.kind = 18;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_BuiltinFunctions;
token.kind = 18;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x24:case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:
case 0x36:case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:
case 0x44:case 0x45:case 0x46:case 0x47:case 0x48:case 0x49:case 0x4a:
case 0x4b:case 0x4c:case 0x4d:case 0x4e:case 0x4f:case 0x50:case 0x51:
case 0x52:case 0x53:case 0x54:case 0x55:case 0x56:case 0x57:case 0x58:
case 0x59:case 0x5a:case 0x5f:case 0x61:case 0x62:case 0x63:case 0x64:
case 0x65:case 0x66:case 0x67:case 0x68:case 0x69:case 0x6a:case 0x6b:
case 0x6c:case 0x6d:case 0x6e:case 0x6f:case 0x70:case 0x71:case 0x72:
case 0x73:case 0x74:case 0x75:case 0x76:case 0x77:case 0x78:case 0x79:
case 0x7a:
{
state.ptr += 1;
goto state_label_33; // builtin_function
}break;
}
}
{
state_label_34: // comment_block
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_BlockComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_34; // comment_block
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_35; // comment_block_try_close
}break;
}
}
{
state_label_35: // comment_block_try_close
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_BlockComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_34; // comment_block
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_35; // comment_block_try_close
}break;
case 0x2f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_BlockComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_36: // comment_line
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LineComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_36; // comment_line
}break;
case 0x0a:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LineComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_37: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Plus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Plus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x25:
{
state.ptr += 1;
goto state_label_38; // op stage
}break;
case 0x2b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_PlusPlus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_PlusEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x7c:
{
state.ptr += 1;
goto state_label_39; // op stage
}break;
}
}
{
state_label_38: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_PlusMod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_PlusMod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_PlusModEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_39: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_PlusOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_PlusOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_PlusOrEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_40: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Minus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Minus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x25:
{
state.ptr += 1;
goto state_label_41; // op stage
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_MinusEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x7c:
{
state.ptr += 1;
goto state_label_42; // op stage
}break;
}
}
{
state_label_41: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_MinusMod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_MinusMod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_MinusModEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_42: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_MinusOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_MinusOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_MinusOrEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_43: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Star;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Star;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x25:
{
state.ptr += 1;
goto state_label_44; // op stage
}break;
case 0x2a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_StarStar;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_StarEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x7c:
{
state.ptr += 1;
goto state_label_45; // op stage
}break;
}
}
{
state_label_44: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_StarMod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_StarMod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_StarModEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_45: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_StarOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_StarOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_StarOrEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_46: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Mod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Mod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_ModEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_47: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Less;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Less;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3c:
{
state.ptr += 1;
goto state_label_48; // op stage
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LessEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_48: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LessLess;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LessLess;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LessLessEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x7c:
{
state.ptr += 1;
goto state_label_49; // op stage
}break;
}
}
{
state_label_49: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LessLessOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LessLessOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_LessLessOrEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_50: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Grtr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Grtr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_GrtrEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3e:
{
state.ptr += 1;
goto state_label_51; // op stage
}break;
}
}
{
state_label_51: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_GrtrGrtr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_GrtrGrtr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_GrtrGrtrEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_52: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_And;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_And;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_AndEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_53: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Or;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Or;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_OrEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x7c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_OrOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_54: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Carrot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Carrot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_CarrotEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_55: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Eq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Eq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_EqEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_56: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Not;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_Not;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenZigKind_NotEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
end:;
block_copy_struct(state_ptr, &state);
return(result);
}
internal Token_List
lex_full_input_zig(Arena *arena, String_Const_u8 input){
Lex_State_Zig state = {};
lex_full_input_zig_init(&state, input);
Token_List list = {};
lex_full_input_zig_breaks(arena, &list, &state, max_u64);
return(list);
}
