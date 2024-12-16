#include "advancePart3.h"
#ifdef CMP_ADVANCE_PART_3_H

/***********************************************************************************************************
 * @brief   Static variables in classes 
 *          
 */
void CallStaticVariablesInclasses(void)
{
    PrintClass<uint8_t> myPrintClassB1;
    PrintClass<uint8_t> myPrintClassB2;
    myPrintClassB1.PrintVal();
    myPrintClassB2.PrintVal();

    PrintClass<int> myPrintClassI1;
    PrintClass<int> myPrintClassI2;
    myPrintClassI1.PrintVal();
    myPrintClassI2.PrintVal();

    PrintClass<float> myPrintClassF1;
    PrintClass<float> myPrintClassF2;
    myPrintClassF1.PrintVal();
    myPrintClassF2.PrintVal();
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is this pointer in C++
 *          1. Passed as hidden argument to non static memeber function
 *          2. It a const pointer whitch holds the addr of current object [type*const this]
 *          3. If memeber function is cosnt then, this pointers type becomes [const type * const this]
 */
void SetValue(BaseClass01* pthis, int x)
{   
    pthis->SetValue(x);
    std::cout << "-- void SetValue(BaseClass01* pthis, int x)" << x << std::endl; 
    std::cout << "-- x = " << pthis->GetValue() << std::endl;  
    std::cout << "------------------------------------------" << std::endl;
}
void SetValue(BaseClass01& refthis, int x)
{
    refthis.SetValue(x);
    std::cout << "-- void SetValue(BaseClass01& refthis, int x)" << std::endl; 
    std::cout << "-- x = " << refthis.GetValue() << std::endl;  
    std::cout << "------------------------------------------" << std::endl;  
}

int GetValue(BaseClass01* pthis)
{   
    std::cout << "-- int GetValue(BaseClass01* pthis)" << std::endl;
    std::cout << "-- return = " << pthis->GetValue() << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    return pthis->GetValue() ;  
}
int GetValue(BaseClass01& refthis)
{
    std::cout << "-- int GetValue(BaseClass01& refthis)" << std::endl;
    std::cout << "-- return = " << refthis.GetValue() << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    return refthis.GetValue();  
}
void CallClassThisPointer_x01(void)
{
    BaseClass01 myBaseClass01;
    //myBaseClass01.SetValue(11);  
    //myBaseClass01.GetValue();
    std::cout << "------------------------------------------" << std::endl;

    //SetValue(myBaseClass01.GetThis(), 22); 
    //GetValue(myBaseClass01.GetThis());

    SetValue(myBaseClass01.GetThisRef(), 33);
    GetValue(myBaseClass01.GetThisRef());
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How to assign any object to premitive data types (uint8_t ... int64_t, float etc)
 *          Then operator uint64_t(...) need to be used and allow conversion
 */

void CallBaseTypeChange(void)
{
    BaseTypeChange myBaseTypeChange(-1);

    uint64_t temp1  = myBaseTypeChange; // operator int64_t() const    { return _value; }
    int64_t  temp2  = myBaseTypeChange; // operator int64_t() const    { return _value; }

    uint32_t temp3 = myBaseTypeChange;
    int32_t  temp4 = myBaseTypeChange;

    uint16_t temp5 = myBaseTypeChange;
    int16_t  temp6 = myBaseTypeChange;

    std::cout << "temp1 = " << temp1 << std::endl;
    std::cout << "sizeof(Temp1) = " << sizeof(temp1) << std::endl;

    std::cout << "temp2 = " << temp2 << std::endl;
    std::cout << "sizeof(temp2) = " << sizeof(temp2) << std::endl;

    std::cout << "temp3 = " << temp3 << std::endl;
    std::cout << "sizeof(temp3) = " << sizeof(temp3) << std::endl;

    std::cout << "temp4 = " << temp4 << std::endl;
    std::cout << "sizeof(temp4) = " << sizeof(temp4) << std::endl;

    std::cout << "temp5 = " << temp5 << std::endl;
    std::cout << "sizeof(temp5) = " << sizeof(temp5) << std::endl;

    std::cout << "temp6 = " << temp6 << std::endl;
    std::cout << "sizeof(temp6) = " << sizeof(temp6) << std::endl;
}

/***********************************************************************************************************
 * @brief   How to call some function before main()
 * 
 *          With use of global variable or static data memeber of class
 */
// int FunBeforeMain(void)    
// {   std::cout << "FunBeforeMain()" <<  std::endl; 
//     return 0;   }

// class BaseBeforeMain
// {
// public:
//     static int sVaribale;

//     BaseBeforeMain(void)    {FunBeforeMain();}
// };

// BaseBeforeMain  myBaseBeforeMain();
// int BaseBeforeMain::sVaribale = FunBeforeMain();

// int main()
// {
//     std::cout << "main()" <<  std::endl; 
//     return 0;
// }
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How to check two diffrent object belong to the same class
 * 
 *          By using typeid from #include <typeinfo> nd pointer addr
 */
void CallClassTypeChack(void)
{
    ClassType_AA myClassType_AA11;
    ClassType_AA myClassType_AA22;

    ClassType_BB myClassType_BB11;
    ClassType_BB myClassType_BB22;
/* 
    if(typeid(myClassType_AA11) == typeid(myClassType_AA22))
    {
        std::cout << "typeid() the same " <<  std::endl;
    }
    else
    {
        std::cout << "typeid() diffrent " <<  std::endl;
    }

    if(typeid(myClassType_AA11) == typeid(myClassType_BB11))
    {// Check what class it belong to
        std::cout << "typeid() the same " <<  std::endl;
    }
    else
    {
        std::cout << "typeid() diffrent " <<  std::endl;
    }  */

    if(&myClassType_AA11 == &myClassType_AA22)
    {// Check the memory addr of a instance
        std::cout << "typeid() the same " <<  std::endl;
    }
    else
    {
        std::cout << "typeid() diffrent " <<  std::endl;
    }
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How to overload pre and post operator in C++
 * 
 *          (myClassOverloadElement++).Print() - Data is updated after this line
 * 
 *          (++myClassOverloadElement).Print() - data is updated before this line
 */

void CallOverloadElement(void)
{
    ClassOverloadElement myClassOverloadElement(0x00);

    std::cout << "value after init " <<  std::endl;
    myClassOverloadElement.Print();

    std::cout << "=================================" <<  std::endl;

    std::cout << "value after (myClassOverloadElement++).Print();" <<  std::endl;
    (myClassOverloadElement++).Print();
    std::cout << " next print " <<  std::endl;
    myClassOverloadElement.Print();

    std::cout << "=================================" <<  std::endl;

    std::cout << "value after (++myClassOverloadElement).Print();" <<  std::endl;
    (++myClassOverloadElement).Print();
    std::cout << " next print " <<  std::endl;
    myClassOverloadElement.Print();

    return;
}
void CallOverloadElement2(void)
{
    ClassOverloadElement tObj1;
    ClassOverloadElement tObj2;

    std::cout << "Post incrementation" <<  std::endl;
    for(int i=0; i<8; i++)
    {
        tObj1.PrintThis();
        (tObj1++).Print();
        tObj1.PrintThis();
        std::cout << "--------" <<  std::endl;
    }
    std::cout << "=================================" <<  std::endl;

    std::cout << "Pre incrementation" <<  std::endl;
    for(int i=0; i<8; i++)
    {
        tObj2.PrintThis();
        (++tObj2).Print();
        tObj2.PrintThis();
        std::cout << "--------" <<  std::endl;
    }
}
void CallTestPostAndPreUpdatedValue(void)
{
    uint16_t i,j, k;
    j = 0; k = 0;
    std::cout << "Post and pre increment test" <<  std::endl;
    for (i = 0; i < 0x07; i++)
    {
        putchar('j'); putchar(' '); putchar(j++ + 0x30); putchar(' ');
        putchar('k'); putchar(' '); putchar(++k + 0x30); putchar(' ');
        putchar('\n');
    }putchar('\n');

    std::cout << "while ((j++) < 0x7)" <<  std::endl;
    j = 0x00; k = 0x00;

    while ((j++) < 0x7)
    {
        putchar(j + 0x30);
        putchar(' ');
    }putchar('\n');

    std::cout << "while ((++k) < 0x7)" <<  std::endl;
    while ((++k) < 0x7)
    {
        putchar(k + 0x30);
        putchar(' ');
    }putchar('\n');
}
//==========================================================================================================


/***********************************************************************************************************
 * @brief   How to print smething N times without using loop or recursion in C++
 * 
 *          Constructor will be called PRINT_N_TIMES times because class is constructed
 */

void CallBasePrintNtimes(void)
{
    BasePrintNtimes myBasePrintNtimes[PRINT_N_TIMES];
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Stop from assign and copy object:
 * 
 *          1. Keep copy constructor and assigment operator as privatein clas
 *          2. Inherit dummy class with private copy constructor and assigment operator
 *          3. Delete copy constructor and assigment operator from class
 */
void CallBaseStopCopy(void)
{
    BaseStopCopy myBaseStopCopy11(11);
    BaseStopCopy myBaseStopCopy22(22);

    BaseCopy myBasePrintNtimes11(11);
    BaseCopy myBasePrintNtimes22();

    BaseStopCopyDeleteConstr myBaseStopCopyDeleteConstr11(11);
    BaseStopCopyDeleteConstr myBaseStopCopyDeleteConstr22(22);

    // 1.
    //myBaseStopCopy11.Print();
    //myBaseStopCopy11 = myBaseStopCopy22;
    //myBaseStopCopy11.Print();

    // 2.
    //myBasePrintNtimes11 = myBasePrintNtimes22;

    // 3.
    //myBaseStopCopyDeleteConstr11 = myBaseStopCopyDeleteConstr22;

    std::cout << "Stop copy test" <<  std::endl;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Stop from from takig addr of my object
 * 
 *          1. overload & operator and keep it private
 *          2. Delete  * operator from class
 */
void CallBaseStopFromADDRMth1(void)
{
    BaseStopFromADDRMth1  myBaseStopFromADDRMth1(11);
    BaseStopFromADDRMth1* pBaseStopFromADDRMth1;

    // With private we have error
    //pBaseStopFromADDRMth1 = &myBaseStopFromADDRMth1;

    //std::cout << "ADDR:= " << std::hex << &myBaseStopFromADDR << std::endl;
    //std::cout << "ADDR:= " << std::hex << pBaseStopFromADDR << std::endl;
}

void CallBaseStopFromADDRMth2(void)
{
    BaseStopFromADDRMth2 myBaseStopFromADDRMth2(22);
    BaseStopFromADDRMth2* pBaseStopFromADDRMth2;

    //pBaseStopFromADDRMth2 = &myBaseStopFromADDRMth2;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Stop from from inheritance from my class
 * 
 *          1. Use final keyword, dont use any other tweak to achieve that
 *          2. Just use final keyword
 */
void CallStopFromInheritance(void)
{
    DerivedFromBaseInheritance myDerivedFromBaseInheritance(11, 22);

    std::cout << "Stop inheritance test" <<  std::endl;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How to write own atoi function
 * 
 *          Convert string to integer
 */
uint16_t MyAtoi(const char* str, uint8_t maxControl)
{
    uint16_t value, sign;
    uint8_t i;


    if(str[0] == '-')
    {   sign = 0xFFFF;
        i = 1;}
    else
    {   sign = 0x0001;
        i = 0;}

    value = 0;
    while ((i < maxControl) && (str[i] != '\0'))
    {
        value = value*10 + (str[i] - 0x30);
        i++;
    }

    if(i == maxControl) return 0xFFFF; // Error
    
    return value * sign;
}

uint16_t ClasicAtoi(const char* str)
{
    uint16_t value, factor;
    uint8_t i = 0;

    value = 0;
    i = 0;

    for(; str[i] != '\0'; ++i)
    {
        value = value*10 + str[i] - '0';
    }
    
    return value;
}
void CallAtoi(void)
{
    const char pStr[] = {"1024"};

    uint16_t temp = MyAtoi(pStr, 6);

    std::cout << "String converted to integer method1: " << temp <<  std::endl;

    temp = ClasicAtoi(pStr);
    std::cout << "String converted to integer method2: " << temp <<  std::endl;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How vector work internaly
 */
void CallWorkingOfVestors(void)
{
    std::vector<uint64_t> myVector;

    std::cout << "myVector.size() " << myVector.size() <<  std::endl;
    std::cout << "myVector.capacity() " << myVector.capacity() <<  std::endl;

    myVector.push_back(0x11);
    std::cout << "myVector.size() " << myVector.size() <<  std::endl;
    std::cout << "myVector.capacity() " << myVector.capacity() <<  std::endl;
}// 3,14
//==========================================================================================================

#endif // _ADVANCE_PART_3_H