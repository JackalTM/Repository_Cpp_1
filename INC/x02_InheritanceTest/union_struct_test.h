//#define INC_UNION_STRUCT_TEST_H
#ifdef INC_UNION_STRUCT_TEST_H

#include <stdint.h>
#include <iostream>
#include <string>
#include <cstring>

/*
struct in_addr
#define s_addr				      S_un.S_addr
#define s_host				      S_un.S_un_b.s_b2
#define s_net				      S_un.S_un_b.s_b1
#define s_imp				      S_un.S_un_w.s_w2
#define s_impno 			      S_un.S_un_b.s_b4
#define s_lh				      S_un.S_un_b.s_b3
{ 
  union
  { 
    struct { u_char s_b1,s_b2,s_b3,s_b4; }S_un_b;
    struct { u_short s_w1,s_w2; }S_un_w;
    u_long S_addr;
  }S_un;
};
*/
struct test_t
{
    union
    {
        struct{uint8_t B0, B1, B2, B3; }type1_t;
        struct{uint16_t W0, W1; }type2_t;
        struct{uint32_t DW0; }type3_t;
        uint32_t dword;
    }test_un;
};
void PrintTestUnion(struct test_t* pTest);
void CALL_TestUnionStruct1(void);

#endif // INC_UNION_STRUCT_TEST_H