#include "_x03_include.h"
#ifdef CMP_ADVANCE_PART_4_H

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <typeinfo>
#include <vector>
#include <string.h>

/***********************************************************************************************************
 * @brief   Is it posible to call constructor and deconstructor by your self?
 * 
 *          Dstructor sould not be called explictly. It is dengerous code
 *          If constructor is called widhout variable asign thn destructor is called in the same time   
 */
class BaseConstructorAndDeconstructor
{
private:
    int _x;
public:
    BaseConstructorAndDeconstructor(void)   {std::cout << "Class Constructor" << std::endl;}

    ~BaseConstructorAndDeconstructor(void)  {std::cout << "Class Deconstructor" << std::endl;}
};

void CallBaseConstructorAndDeconstructor(void);
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
class BaseObjSlice
{
private:
    int _x;
public:
    int dataB;
    BaseObjSlice(void)  { std::cout << ">> Base Class constructor   " << std::endl; }
    ~BaseObjSlice(void) { std::cout << ">> Base Class deconstructor " << std::endl; }
};

class DerivedObjSlice: public BaseObjSlice
{
private:
    int _x;
public:
    int dataD;
    DerivedObjSlice(void)  { std::cout << ">> Derived Class constructor    " << std::endl; }
    ~DerivedObjSlice(void) { std::cout << ">> Derived Class deconstructor " << std::endl; }
};

void CallObjcectSlice(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is good way to count number of set bit using C++
 * 
 */
void CallCountNumberInCpp(void);
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
class BaseOverrideKey
{
    int _x;
public:
    virtual void Function(void) { std::cout << "Base Class function " << std::endl; }
};

class DerivedOverrideKey: public BaseOverrideKey
{
    int _y;
public:
    //void Function(void) { std::cout << "Derived Class function " << std::endl; }
    void Function(void) override { std::cout << "Derived Class function " << std::endl; }
    //void Function(int x) override { std::cout << "Derived Class function " << std::endl; }
};

void CallOverrideKey(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is placement new in C++
 * 
 *          In case when more object need to be alocated dynamic it is better to upront alocated moemory
 *          For Kernel its is 
 */
class BasePlecementNew
{
    int _offsetMem;
public:
    BasePlecementNew(int offsetMem)  
    {   std::cout << "Base Class Constructor    ADDR + 0x" << std::hex << offsetMem << std::endl; 
        _offsetMem = offsetMem;}

    ~BasePlecementNew(void) 
    {    std::cout << "Base Class Deconstructor  ADDR + 0x" << std::hex << _offsetMem << std::endl; }
};
void CallPlacementNew(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Reinterpreted cast
 *          
 *          It can perform dangerous conversation beacuse it can typecast ant pointer to ant other pointer
 */
class Golock
{
private:
    int _n;
public:
    void Swing(int n)   
    {   std::cout << "Golock swings " << n << " times" <<  std::endl; 
        _n = n; }
};

class Paranga
{
private:
    int _n;
public:
    void Swing(int n)   
    {   std::cout << "Paranga swings " << n << " times" <<  std::endl; 
        _n = n; }
};

typedef struct
{
    uint16_t x;
    uint16_t y;
    uint16_t z;
    uint32_t volume;
}someTool_t;

void CallReinterpretedCast1(void);
void CallReinterpretedCast2(void);
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
void CallStaticCast1(void);

class Convert
{
    int _x;
public:
    Convert(int x=0): _x{x} 
    {   std::cout << "---------------------------------" << std::endl;
        std::cout << "-- Convert constructor " << x <<   std::endl; 
        std::cout << "-- Current value _x= " << _x <<   std::endl;
        std::cout << "-- Current ADDR= " << std::hex << this << std::endl; 
        std::cout << "---------------------------------" << std::endl;}

    operator uint8_t (void)
    {   std::cout << ">> static_cast<uint8_t>" << std::endl; 
        return (uint8_t)_x; }

    operator std::string (void)  
    {   std::cout << ">> static_cast<std::string> " << _x << std::endl;    
        return "str"; }

    operator + (void)
    {   std::cout << ">> operator + " << _x << std::endl;    
        return _x; }

};
void CallStaticCast2(void);
void CallStaticCast3(void);
void CallStaticCast4(void);

class BaseCastTest  {;};
class DerivedCastTest11: public BaseCastTest  {;};
class DerivedCastTest22: public BaseCastTest  {;};
void CallStaticCast5(void);
void CallStaticCast6(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is structular padding and packing in C++
 *          This is way to 
 * speed up the cpu
 * 
 *          In this case with   #pragma pack(1) => sizeof(someStruct_t) = less
 *          With case of        #pragma pack(0) => sizeof(someStruct_t) = more
 * 
 *          uint8_t  can be stored at multiple of 1 Byte
 *          uint16_t can be stored at multiple of 2 Byte
 *          uint32_t can be stored at multiple of 4 Byte
 *          uint64_t can be stored at multiple of 8 Byte
 * 
 *          1 WORD is 4 Byte in 32 bit procesor
 *          1 WORD is 8 Byte in 64 bit procesor
 */
//#pragma pack(1) // Disable padding
typedef struct 
{// This will ocupied 16 Bytes
    uint8_t     B;
    uint64_t    QW;
}someStruct11_t;

typedef struct 
{// This will ocupied 16 Bytes also
    uint8_t     B[8];
    uint64_t    QW;
}someStruct22_t;

void CallStructularPadding1(void);

typedef struct 
{// sizeof(someStruct33_t) = 16
    uint32_t    DW;
    uint64_t    QW;
}someStruct33_t;

typedef struct 
{// sizeof(someStruct44_t) = 24
    uint32_t a;              // sizeof(uint32_t) = 4 + 4(paddint)
    someStruct33_t  somedat; // sizeof(someStruct33_t) = 16
}someStruct44_t;

void CallStructularPadding2(void);
//==========================================================================================================

#endif // CMP_ADVANCE_PART_4_H