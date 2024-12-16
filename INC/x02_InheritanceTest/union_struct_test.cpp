#include "union_struct_test.h"
#ifdef INC_UNION_STRUCT_TEST_H

void PrintTestUnion(struct test_t* pTest)
{
    printf("-- B0= %x | B1= %x | B2= %x | B3= %x | \n", 
    pTest->test_un.type1_t.B0, pTest->test_un.type1_t.B1, pTest->test_un.type1_t.B2, pTest->test_un.type1_t.B3);

    printf("-- W0= %x | W1= %x | \n", 
    pTest->test_un.type2_t.W0, pTest->test_un.type2_t.W1);

    printf("-- DW0= %x \n", pTest->test_un.type3_t.DW0);
}

void CALL_TestUnionStruct1(void)
{
    struct test_t test;
    test.test_un.type1_t.B0 = 0x00;
    test.test_un.type1_t.B1 = 0x11;
    test.test_un.type1_t.B2 = 0x22;
    test.test_un.type1_t.B3 = 0x33;
    PrintTestUnion((struct test_t*)&test);

    test.test_un.dword = (uint32_t)(-1);
    PrintTestUnion((struct test_t*)&test);

    test.test_un.dword = (uint32_t)(0);
    PrintTestUnion((struct test_t*)&test);
}

#endif // INC_UNION_STRUCT_TEST_H