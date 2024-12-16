#include "advancePart1.h"
#ifdef CMP_ADVANCE_PART_1_H

/**************************************************************************************
 * @brief   Test of a friendship in C++ 
 * @note    Friend function can access private data
 * @return
*/
BaseClassFriend::BaseClassFriend(unsigned int x, unsigned int y): x(x), y(y)
{;}

BaseClassFriend::~BaseClassFriend()
{;}

void FriendFunction(BaseClassFriend& RefBase, unsigned int x)
{
    std::cout << RefBase.x << std::endl;
    RefBase.x = x;
    std::cout << RefBase.x << std::endl;
}

void CallFriendFunction(void)
{
    BaseClassFriend Base(0xFF, 0xEE); 
    FriendFunction(Base, 0xAA);
}
//=====================================================================================

/**************************************************************************************
 * @brief   Test of auto keyword
 * @note    
 * @return
*/
void AutoKeyword(void)
{
    auto X = 0xFF;
    auto y = 2.718;
    auto z = BaseClassFriend(0xFF, 0xEE);

    //std::cout << typeid(x).name() << std::endl;
}
//=====================================================================================

/**************************************************************************************
 * @brief   Code bloat is the production of code that is percieved as unnecessary long, 
 *          slow or otherwise wastefullof recources
*/
static void StrConcat(char* pDEST, char* pSRC, int* pStrHead)
{
    char head,i, tChar;
    head = *pStrHead;
    for(i=0; i<0x8; i++)
    {
        tChar = pSRC[i];
        pDEST[head + i] = tChar;
        if(tChar == 0)  break;
    }
    *pStrHead = head + i;
}
void CodeBloatExample(void)
{
    //char str1[] = {"Some text"};
    //std::cout << str1 << std::endl;

    char pWWW[] = {"www."};
    char pGoogle[] = {"google."};
    char pCom[] = {"com"};
    char parray[0x20]; 
    int strHead = 0;
    StrConcat(parray, pWWW,     &strHead);  //std::cout << "Head:= " << strHead << std::endl;
    StrConcat(parray, pGoogle,  &strHead);  //std::cout << "Head:= " << strHead << std::endl;
    StrConcat(parray, pCom,     &strHead);  //std::cout << "Head:= " << strHead << std::endl;

    std::cout << parray << std::endl;
}
//=====================================================================================

/**************************************************************************************
 * @brief   Inline function test
 *          IT is just information for compiler to copy and paste this function into main
*/
inline void InineTest::print(void)
{
    std::cout << "Value of " << _x << std::endl; 
    std::cout << "Value of " << _x << std::endl;
}
void CallInlineTest(void)
{
    InineTest testInline;
    testInline.print();
}
//=====================================================================================

/**************************************************************************************
 * @brief   Constant cast in C++
 *          The expresion of const_cast<t>(v) can be used to change const or volatile 
 *          qualifiers of pointers or reference
 *          Where T must to be a pointer
 *          Constant variable is a variable inside ROM memory
 * 
 *          Volatille is using as info to compiler to not optimalize some variable
*/
void CallConstantCast(void)
{
    const int  i = 0x10;
    const int* pInt1 = &i;
    int* pInt2 = const_cast<int*>(pInt1);
    *pInt2 = 0xFF; // Invalid and unefined behaviour

    std::cout << "Value of i = " << std::hex << i << std::endl; 
    std::cout << "Value of *pInt2 = "<< std::hex << *pInt2 << std::endl;

    int j = 0x20;
    const int* pInt11 = &j;
    int* pInt22 = const_cast<int*>(pInt11);
    *pInt22 = 0xFF; //Valid code

    std::cout << "Value of j = "<< std::hex << j << std::endl; 
    std::cout << "Value of *pInt222 = "<< std::hex << *pInt22 << std::endl;
}
//=====================================================================================

/**************************************************************************************
 * @brief   What is one of the use of decltype in C++
 *          It checks the type of expresion
*/
template <typename T_1, typename T_2>
auto add(T_1 a, T_2 b)->decltype(a + b)
{   return a + b;}

static void _PrintAdd(int a, int b)
{
    std::cout << "T_1 add(T_1, T_2) " << add(a, b) << std::endl; 
    std::cout << "T_2 add(T_1, T_2) " << add(a, b) << std::endl;
}
static void _PrintAdd(double a, double b)
{
    std::cout << "T_1 add(T_1, T_2) " << add(a, b) << std::endl; 
    std::cout << "T_2 add(T_1, T_2) " << add(a, b) << std::endl;
}
static void _PrintAdd(int a, double b)
{
    std::cout << "T_1 add(T_1, T_2) " << add(a, b) << std::endl; 
    std::cout << "T_2 add(T_1, T_2) " << add(a, b) << std::endl;
}
static void _PrintAdd(double a, int b)
{
    std::cout << "T_1 add(T_1, T_2) " << add(a, b) << std::endl; 
    std::cout << "T_2 add(T_1, T_2) " << add(a, b) << std::endl;
}

void CallDecltype(void)
{
    _PrintAdd(1, 5);
    _PrintAdd(1.0, 5.0);
    _PrintAdd(1, 5.0);
    _PrintAdd(1.0, 5);
}
//=====================================================================================

/**************************************************************************************
 * @brief   pointers and references
 *          Pointer is a memory adres of a variable
 *          Reference is a anaother alias for this variable and have to be asigned diring creation
*/
void CallTestPointersAndRef(void)
{
    uint32_t data;

    uint32_t* pData;
    uint32_t& refData = data;

    pData = &data;
}
//=====================================================================================

/**************************************************************************************
 * @brief   Differences b/w ranges based for loop and for_each in C++
 *          Some of the diff are shown below
*/
void Print(int values)  { std::cout << "for_each with print: " << values << std::endl; }
void CallVecorRanges(void)
{
    std::vector<uint8_t> vect;
    uint8_t i;

    for(i=0; i<8; i++)
    {   vect.push_back(i);}

    for(uint8_t j: vect)
    {   std::cout << "j: vect: " << j << std::endl;}

    std::for_each(vect.begin(), vect.end(), [](uint8_t k)
    {   std::cout << "for_each: " << k << std::endl;    });

    std::for_each(vect.begin(), vect.end(), Print);
}
//=====================================================================================

/**************************************************************************************
 * @brief   Virtual methods in class
 *  1.      Why use virtual function:
 *  1.      To achieve dynamic polimirphizm. Which is the ability to call derived calass function using Base class pointer or reference.
 * 
 *  2.      How to use virtual functions:
 *  2.      By declaring function as virtual in Base class and overriding that function in derived class.
 *  2.      (Function signature should be same in Base and Derived class)         
*/
void CallVirtualFunctionsTest1(void)
{
    std::cout << "=======================================================" << std::endl;

    BaseClass* pBaseClass1 = new BaseClass();
    pBaseClass1->A_print(); pBaseClass1->B_print(); pBaseClass1->C_print();

    std::cout << "==========" << std::endl;

    NextClass* pNextClass1 = new NextClass();
    pNextClass1->A_print(); pNextClass1->B_print(); pNextClass1->C_print();

    std::cout << "=======================================================" << std::endl;

    BaseClass* pBaseClass2 = new BaseClass();
    pBaseClass2->A_print(); pBaseClass2->B_print(); pBaseClass2->C_print();

    std::cout << "==========" << std::endl;
    
    BaseClass* pNextClass2 = new NextClass();
    pNextClass2->A_print(); pNextClass2->B_print(); pNextClass2->C_print();

    std::cout << "=======================================================" << std::endl;

    BaseClass b; 
    NextClass n;
    BaseClass& refBaseClass3 = b;
    //refBaseClass3.A_print(); refBaseClass3.B_print(); refBaseClass3.C_print();
    //std::cout << "==========" << std::endl;
    BaseClass& refNextClass3 = n;
    //refNextClass3.A_print(); refNextClass3.B_print(); refNextClass3.C_print();

    //std::cout << "=======================================================" << std::endl;
}

void CallVirtualFunctionsTest2(void)
{
    BaseClass* pBaseClass; 
    NextClass* pNextClass; 
    
    pNextClass = new NextClass();
    pNextClass->A_print();
    pNextClass->B_print();
    pNextClass->C_print();

    std::cout << "=======================================================" << std::endl;

    pBaseClass = (BaseClass*)pNextClass;
    pBaseClass->A_print();
    pBaseClass->B_print();
    pBaseClass->C_print();
}

void CallPureVirtualFunctions(void)
{
    Sword* pSword = new Sword();
    Rifle* pRifle = new Rifle();

    Sword* pSword1;
    Rifle* pRifle1;

    pSword->Usage(7);
    pRifle->Usage(9);

    pRifle1 = (Rifle*)pSword;
    pSword1 = (Sword*)pRifle;

    pSword1->Usage(7);
    pRifle1->Usage(9);
}

#endif // CMP_ADVANCE_PART_1_H