#include "advancePart4.h"
#ifdef CMP_ADVANCE_PART_4_H

/***********************************************************************************************************
 * @brief   Is it posible to call constructor and deconstructor by your self?
 * 
 *          Dstructor sould not be called explictly. It is dengerous code
 *          If constructor is called widhout variable asign thn destructor is called in the same time   
 */
void CallBaseConstructorAndDeconstructor(void)
{
    // This work like that 
    BaseConstructorAndDeconstructor().~BaseConstructorAndDeconstructor();
}

//==========================================================================================================

/***********************************************************************************************************
 * @brief   TO check optimazation code https://godbolt.org/
 */

//==========================================================================================================

/***********************************************************************************************************
 * @brief   How Cpp achieve function overloading
 *          Name mangling - changng name of functions and classes
 * 
 *          If function has namy forms for diffrnet king of input parameters.\
 *          Compiler create more function with diffrent name depend on parameter
 * 
 *          Function in class is just another function with name combination.
 */
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is object slicing in C++
 * 
 *          When assiging only BaseObjSlice data will be copied to BaseObjSlice instance
 */
void CallObjcectSlice(void)
{
    DerivedObjSlice myDerivedObjSlice;
    myDerivedObjSlice.dataD = 1;
    myDerivedObjSlice.dataB = 2;
    std::cout << "myDerivedObjSlice.dataB = " << myDerivedObjSlice.dataB << std::endl;
    std::cout << "myDerivedObjSlice.dataD = " << myDerivedObjSlice.dataD << std::endl;

    BaseObjSlice myBaseObjSlice = myDerivedObjSlice;
    std::cout << "myBaseObjSlice.dataB = " << myBaseObjSlice.dataB << std::endl;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is good way to count number of set bit using C++
 * 
 */
void CallCountNumberInCpp(void)
{
    int number, counter, i, tSize;

    tSize = sizeof(int) * 8;
    number = 0x7F;
    counter = 0x00;
    for(i=0; i<tSize; i++)
    {
        if((number & 0x01) == 0x01) counter++;

        number = (number >> 1);
    }
    std::cout << "Method1 Amount of set bits:= " << counter << std::endl;

    number = 0x7F;
    counter = 0x00;
    while(number)
    {
        counter = counter + (number & 0x01);
        number >>= 1;
    }
    std::cout << "Metho2 Amount of set bits:= " << counter << std::endl;

    number = 0x7F;
    counter = 0x00;
    unsigned int a,b;
    for(counter=0; number; ++counter)
    {// Britan Kernightan way
        a = number - 1;
        b = number & a;
        number = number & (number - 1);
        printf("-- %x & %x = %x \n", b,a,number);
    }
    std::cout << std::endl << "Metho3 Amount of set bits:= " << counter << std::endl;
}// 3,32
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is override keyowrd in C++
 * 
 *          Testing beomes more easy with iths
 *          Compile time check can be performed. Future error can be reduced
 * 
 *          void Function(void) override { std::cout << "Derived Class function " << std::endl; } points to
 *          virtual void Function(void) { std::cout << "Base Class function " << std::endl; } and override tells explicid 
 *          that this method need to be overrided
 */
void CallOverrideKey(void)
{
    BaseOverrideKey* pBaseOverrideKey = new DerivedOverrideKey();

    pBaseOverrideKey->Function();
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is placement new in C++
 * 
 *          In case when more object need to be alocated dynamic it is better to upront alocated moemory
 *          For Kernel its is 
 */
void CallPlacementNew(void)
{
    // Normal case:
    std::cout << "Normal case:" << std::endl;
    BasePlecementNew* pBasePlecementNew = new BasePlecementNew(0x00);
    delete pBasePlecementNew;

    // Placement new case
    std::cout << "Placement new case:" << std::endl;

    uint8_t memSize = sizeof(BasePlecementNew);
    uint8_t* pBase = new uint8_t[10 * memSize]; // Memory pool
    std::cout << ">> Memory pool= " << 10*memSize << std::endl;

    BasePlecementNew* pBasePlecementNew1 = new (pBase + (0 * memSize)) BasePlecementNew(0x00);
    BasePlecementNew* pBasePlecementNew2 = new (pBase + (1 * memSize)) BasePlecementNew(0x04);
    BasePlecementNew* pBasePlecementNew3 = new (pBase + (2 * memSize)) BasePlecementNew(0x08);

    // Only reason to explicid call destructor in placement new
    pBasePlecementNew1->~BasePlecementNew();
    pBasePlecementNew2->~BasePlecementNew();
    pBasePlecementNew3->~BasePlecementNew();

    delete[] pBase;

    // Drestruction neef to be done bacwards
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Reinterpreted cast
 *          
 *          It can perform dangerous conversation beacuse it can typecast ant pointer to ant other pointer
 */
void CallReinterpretedCast1(void)
{
    Golock* pGolock = new Golock();
    Paranga* pParanga = new Paranga();

    Golock* newGolock = reinterpret_cast<Golock*>(pParanga);

    newGolock->Swing(9);

    pGolock->Swing(2);
    pParanga->Swing(1);
}
void CallReinterpretedCast2(void)
{//#pragma pack(0) // Enable padding then empty spaces are placed
    someTool_t tTool;

    tTool.x = 0x1100;
    tTool.y = 0x3322;
    tTool.z = 0x5544;
    tTool.volume = 0x99887766;

    uint8_t* pTool = reinterpret_cast<uint8_t*>(&tTool);

    std::cout << "tTool.x = " << std::hex << *(reinterpret_cast<uint16_t*>(pTool + 0)) <<   std::endl;
    std::cout << "tTool.y = " << std::hex << *(reinterpret_cast<uint16_t*>(pTool + 2)) <<   std::endl;
    std::cout << "tTool.z = " << std::hex << *(reinterpret_cast<uint16_t*>(pTool + 4)) <<   std::endl;
    std::cout << "tTool.volume = " << std::hex << *(reinterpret_cast<uint32_t*>(pTool + 8)) <<   std::endl;

    std::cout << "tTool.x = " << std::hex << tTool.x <<   std::endl;
    std::cout << "tTool.y = " << std::hex << tTool.y <<   std::endl;
    std::cout << "tTool.z = " << std::hex << tTool.z <<   std::endl;
    std::cout << "tTool.volume = " << std::hex << tTool.volume <<   std::endl;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Static cast in C++
 * 
 *          It performs implicit conversion between types 
 *          This will check in compile time;
 * 
 *          If constructor has one parameter then asigning one parameter to class object cause to call donctructor
 * 
 *          Use for all upcast but never use for confuzed  down cast
 * 
 *          For compabitility type conversion 
 *          For conversion operators and conversion constructors
 *          To avoid unrelated pointer conversion
 *          Used for uppcast but never for don cast
 *          Intenstion are more clear on C++
 *          Erros found in compile time
 */
void CallStaticCast1(void)
{
    uint64_t quadripleWord;
    uint32_t doubleWord;

    quadripleWord = -1;
    doubleWord = static_cast<uint32_t>(quadripleWord);

    std::cout << "uint64_t quadripleWord = " << std::hex << quadripleWord <<   std::endl;
    std::cout << "uint32_t doubleWord    = " << std::hex << doubleWord <<   std::endl;
}
void CallStaticCast2(void)
{
    Convert myConvert(7);
    uint8_t temp1 = myConvert;
    std::string myStr1 = myConvert;
    std::cout << "---------------------------------" << std::endl; 

    myConvert = 20;
    uint8_t temp = static_cast<uint8_t>(myConvert);
    std::string myStr2 = static_cast<std::string>(myConvert);
    std::cout << "---------------------------------" << std::endl; 

    myConvert = static_cast<int>(30);

    std::cout << "std::string myStr1 = myConvert " << myStr1 <<   std::endl;
    std::cout << "std::string myStr2 = static_cast<std::string>(myConvert) " << myStr1 << std::endl;

    std::cout << "myConvert = static_cast<int>(30) " << std::string(myConvert) <<   std::endl;

    std::cout << "---------------------------------" << std::endl;
    int temp3 = +myConvert;
}
void CallStaticCast3(void)
{
    uint8_t byte;
    uint32_t dWord;

    uint8_t* pByte;
    uint32_t* pDWord;

    pByte = (uint8_t*)(&dWord); // C style casting

    // Dangerous cast!!!
    pDWord = (uint32_t*)(&byte); // Pass by compile time but fail at run time


    pByte = static_cast<uint8_t*>((uint8_t*)(&dWord)); //C++ style casting
    //pDWord = static_cast<uint32_t*>(&byte); // Fail in compile time then is safe
}
void CallStaticCast4(void)
{

}
void CallStaticCast5(void)
{
    DerivedCastTest11 myDerivedCastTest11;
    DerivedCastTest22 myDerivedCastTest22;

    BaseCastTest* pBaseCastTest11 = static_cast<BaseCastTest*>(&myDerivedCastTest11);
    BaseCastTest* pBaseCastTest22 = static_cast<BaseCastTest*>(&myDerivedCastTest22);

    // This is confuzing
    DerivedCastTest11* pDerivedCastTest11 = static_cast<DerivedCastTest11*>(pBaseCastTest11);
    DerivedCastTest22* pDerivedCastTest22 = static_cast<DerivedCastTest22*>(pBaseCastTest22);
}
void CallStaticCast6(void)
{
    uint8_t byte;
    void* pVoid;
    uint8_t* pByte;

    pVoid = static_cast<void*>(&byte);
    pByte = static_cast<uint8_t*>(pVoid);
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is structular padding and packing in C++
 *          This is way to speed up the cpu
 * 
 *          In this case with   #pragma pack(1) sizeof(someStruct_t) = less
 *          With case of        #pragma pack(0) sizeof(someStruct_t) = more
 * 
 *          uint8_t  can be stored at multiple of 1 Byte
 *          uint16_t can be stored at multiple of 2 Byte
 *          uint32_t can be stored at multiple of 4 Byte
 *          uint64_t can be stored at multiple of 8 Byte
 * 
 *          1 WORD is 4 Byte in 32 bit procesor
 *          1 WORD is 8 Byte in 64 bit procesor
 */
void CallStructularPadding1(void)
{
    uint16_t lenght;
    lenght = sizeof(someStruct11_t);

    std::cout << "sizeof(someStruct_t) = " << lenght <<   std::endl;
}
void CallStructularPadding2(void)
{
    uint16_t lenght;
    lenght = sizeof(someStruct44_t);

    std::cout << "sizeof(someStruct_t) = " << lenght <<   std::endl;
}
//==========================================================================================================

#endif // _ADVANCE_PART_4_H