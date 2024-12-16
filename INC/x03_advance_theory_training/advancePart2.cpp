#include "advancePart2.h"
#ifdef CMP_ADVANCE_PART_2_H

/**************************************************************************************
 * @brief   Dynamic cast
 * @note    1. Work only on polimorfic base class (at least one virtual function)
 *             IT uses this information to decide about wrong down cast
 *          2. It is used for up-cast (D->B) and down-cast(b->D), but it is mainly used for correct downcast.
 *          3. Uaing this cast has run time overhead coz it checks object types at runtime using RTTi 
 *          4. If we are sure that we will never cast to wrong object than we should always avoid this cast and sue static_cast
 *          5. dynamic_cast is used only at run time to find out correct down cast
 *          6. If cast fail then return NULL pointer of that type.
 *          7. If cast fail for reference then throw an exception that matches a handler of type std::bad_cast
 *          8. Virtual keywork makes it polimorfic
*/
void BaseClass::Print(void) {std::cout << "BASE CLASS!! void" << std::endl;}
void BaseClass::Print(uint8_t value) {std::cout << "BASE CLASS!! uint8_t" << value << std::endl;}

void Derived11::Print(void) {std::cout << "Derived11 CLASS!! void" << std::endl;}
void Derived22::Print(void) {std::cout << "Derived22 CLASS!! void" << std::endl;}

void CallDynamicCast(void)
{
    Derived11   myDerived11;
    Derived11*  pDerived11;
    BaseClass*  pBaseClass;

    pBaseClass = dynamic_cast<BaseClass*>(&myDerived11);
    if(pBaseClass == NULL)
        std::cout << "pBaseClass == NULL" << std::endl;
    else
    {
        std::cout << "======================" << std::endl;
        std::cout << "pBaseClass is valid" << std::endl;
        pBaseClass->Print();    // Derived11 CLASS!! void
        pBaseClass->Print(0x0F);// BASE CLASS!! uint8_t
        std::cout << "======================" << std::endl;
    }

    pDerived11 = dynamic_cast<Derived11*>(pBaseClass);
    if(pDerived11 == NULL)
        std::cout << "pDerived11 == NULL" << std::endl;
    else
    {
        std::cout << "======================" << std::endl;
        std::cout << "pDerived11 is valid" << std::endl;
        pDerived11->Print();    // Derived11 CLASS!! void
        //pDerived11->Print(0xFF); Not valid
        std::cout << "======================" << std::endl;
    }

    try
    {
        Derived11& refDerived11 = dynamic_cast<Derived11&>(myDerived11);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
//=====================================================================================

/**************************************************************************************
 * @brief   Explicit cast in C++
 * @note    Prevent call the object in some strange way.
*/
BaseImplicit::BaseImplicit(void)                    {;}
BaseImplicit::BaseImplicit(int invar): _var(invar)  {;}

void BaseImplicit::Print(void)  { std::cout << "Value of _var: 0x" << std::hex << _var << std::endl; }

static void _FunctPrint(BaseImplicit inClass)       { inClass.Print(); }

void CallExplicitcast(void)
{
    BaseImplicit myObj11(0x10); // Normal call to constructor
    _FunctPrint(myObj11);// Normal call to constructor

#ifndef EXPLICIT_CAST
    BaseImplicit myObj22 = 0x20;// Implicid call to constructor
    _FunctPrint(myObj22);// Normal call to constructor

    _FunctPrint(0x30);// Implicid call to constructor
    _FunctPrint(0x40);// Implicid call to constructor
#endif


    // To remove this option to happen its raquired to add keywork explicit before contructor in .h

    return;
}
//=====================================================================================

/**************************************************************************************
 * @brief   Usage of extern C in C++
 *          1. It it is compiles separatly its OK
 *          2. IF its compiles normal:  'undefined reference to `LogicAND(unsigned char, unsigned char)'
 *                                      'undefined reference to `LogicOR(unsigned char, unsigned char)'
 *          3. Cpp linker is changing name of functions to achieve function overloading and polimorfism
 *          4.To correctly include C file in Cpp build it need to be done like that:
                extern "C"
                {
                    #include "cfile.h"
                }
 * @return
*/
void CallExternCinCpp(void)
{
    uint8_t temp;
    temp = 0x00;
    //temp = FuncfileTestLogicAND(temp, 0xFF);
    //temp = FuncfileTestLogicOR(temp, 0xFF);

    std::cout << "Resoult of logic: 0x" << std::hex << temp << std::endl;
}
//=====================================================================================

/**************************************************************************************
 * @brief   What is function chaining in C++?
 * 
 *          It gives proper code analisis power
 * 
 */
void CallFunctionChaining(void)
{
    FunctionChainingClass myFunChain;

    myFunChain.SetParameterA(0x11).SetParameterB(0x22).SetParameterC(0x33);

    myFunChain.SetParameterX(0x44)->SetParameterY(0x55)->SetParameterZ(0x66)->Print();

    return;
}
//=====================================================================================

/**************************************************************************************
 * @brief   What is function hiding in C++?
 *          IF the same name wil be is derived class then these function will be hidden
 *          To unlock these function 
 * 
 *          Base class void
 *          Base class i, j
 *          Derived class char
 *          
 *          To inlock function hidding:
 *          using FunHiddingBase::Funct;
 */
void CallFunHidding(void)
{
    FunHiddingDerived11 Derived;

    Derived.Funct();
    Derived.Funct(99, 99);
    Derived.Funct('X');

    return;
}
//=====================================================================================

/**************************************************************************************
 * @brief   What is a function pointer?
 * 
 *          !! Copy code here !!
 * 
 */
static uint8_t _AddTwonumbers(uint8_t A, uint8_t B) { return A + B;}
static uint8_t _SubTwonumbers(uint8_t A, uint8_t B) { return A - B;}
static uint8_t _MulTwonumbers(uint8_t A, uint8_t B) { return A * B;}
static uint8_t _DivTwonumbers(uint8_t A, uint8_t B) { return A / B;}

pFunType RetFunPtr(pFunType FunPtr)
{
    return FunPtr;
}
pFunType RetFunPtrFromList(pFunType FunPtr[], uint8_t n)
{
    return FunPtr[n];
}

uint8_t (*pFun44(uint8_t, uint8_t))
{
    ;
}

void CallFunctionPointers(void)
{
    uint8_t (*pFunAdd11)(uint8_t, uint8_t); 
    pFunAdd11 = &_AddTwonumbers;

    pFunType pFun11 = &_AddTwonumbers;
    printf(" pFun11 resoult %d \n", (pFun11)(2, 2));

    pFunType pFun22 = RetFunPtr(pFun11);
    uint8_t temp = (*pFun22)(2, 2);
    printf(" pFun22 resoult %d \n", temp);

    pFunType pFunArr1[] = { &_AddTwonumbers, &_SubTwonumbers, &_MulTwonumbers, &_DivTwonumbers};
    pFunType pFun33 = RetFunPtrFromList(pFunArr1, 0);
    temp = (*pFun33)(2, 2);
    printf(" pFun33 resoult %d \n", temp);

    uint8_t (*pFunArr2[])(uint8_t, uint8_t) = { &_AddTwonumbers, &_SubTwonumbers, &_MulTwonumbers, &_DivTwonumbers};
    pFun33 = RetFunPtrFromList(pFunArr2, 0);
    temp = (*pFun33)(2, 2);
    printf(" pFun33 resoult %d \n", temp);
}
//=====================================================================================

/**************************************************************************************
 * @brief   What is Functor is C++
 *          IT work as function and achievied by overloadind "operator()" in some class
 * 
 *          Class object the work as function with initialized object to certain value
 */
//FunctorBaseMull::FunctorBaseMull(void):         _value{0x00}{;}
void CallFunctorBase(void)
{
    FunctorBaseMull myMull(0x02); // Asign initial value

    std::cout << "Value = " << std::hex << myMull(1) << std::endl; // Call and multiply by call value a it is a function
    std::cout << "Value = " << std::hex << myMull(2) << std::endl;
    std::cout << "Value = " << std::hex << myMull(3) << std::endl;
}
//=====================================================================================

/**************************************************************************************
 * @brief   What is GDB and how to use to debug code 
 *          
 */
static void _DebugFunction11(void)
{
    uint8_t temp = 0x11;
    std::cout << "_DebugFunction11 local temp = " << temp << std::endl;
}
static void _DebugFunction22(void)
{
    uint8_t temp = 0x22;
    std::cout << "_DebugFunction22 local temp = " << temp << std::endl;
}
static void _DebugFunction33(void)
{
    uint8_t temp = 0x33;
    std::cout << "_DebugFunction33 local temp = " << temp << std::endl;
}
void CallDebugTest(void)
{
    uint8_t temp = 0xFF;
    std::cout << "Variable in call temp = " << temp << std::endl;

    _DebugFunction11();
    _DebugFunction22();
    _DebugFunction33();
}
//=====================================================================================

/**************************************************************************************
 * @brief   How delete[] know how many object delete
 *          1 Over allocation 2 associate array
 */
#define WORDSIZE 8
void CallDeleteTest1(void)
{
    DeteteClassTest* pObject = new DeteteClassTest[n];
    // Expand to this :
    char* temp = (char*) operator new[] (WORDSIZE + n * sizeof(DeteteClassTest)); //similar to (char*)malloc(...)
    DeteteClassTest* ptr = (DeteteClassTest*) (temp  + WORDSIZE);
    *(size_t*)temp = n;
    for(int i=0; i<n; i++)  
        new(ptr + i) DeteteClassTest(); // placement new 2,10
    // New object is construct in there memory
    // ITs like preparing memory and then puting object over there
    // Overallocation is for know the memory amount

    delete[] pObject;
    // Expand to this :
    size_t n = *(size_t*) ((char*)ptr - WORDSIZE); 
    while(n-- !=0)
        (ptr + n) -> ~DeteteClassTest();
    operator delete[] ((char*)ptr - WORDSIZE);
    // Its calling decontructor in reverse order
    
}
void CallDeleteTest2(void)
{
    DeteteClassTest* pObject = new DeteteClassTest[n];
    // Expand to this :
    /*
    DeteteClassTest* pBase = (DeteteClassTest*) operator new[] (n * sizeof(DeteteClassTest)); //similar to (char*)malloc(...)
    size_t i;
    for(i=0; i<n; i++)  
        new(pBase + i) DeteteClassTest(); // placement new 2,10
    // associationArray.insert(pBase, n);
    // ITs like preparing memory and then puting object over there
    */

    delete[] pObject;
    // Expand to this :
    /*
    size_t n = associationArray.lookup(pBase) ;
    while(n-- !=0)
        (pBase + n) -> ~DeteteClassTest()
    operator delete[] (pBase);
    // Its calling decontructor in reverse order
    // On the end it delete associationArray with pointer addrs
    */
    
}// 2,16
//=====================================================================================

#endif // #ifdef CMP_ADVANCE_PART_2_H