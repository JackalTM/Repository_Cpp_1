#include "_x03_include.h"
#ifdef CMP_ADVANCE_PART_5_H

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <typeinfo>
#include <vector>
#include <string.h>
#include <tuple>

/***********************************************************************************************************
 * @brief       The differences betwen plain enum and enum class in C++
 * 
 */
enum normalEnum
{
    worngData = 0x11U,
    shortData = 0x22U,
    longData = 0x33U
};

enum errorType_t
{
    ERROR_WRONG_DATA = 0x11U,
    ERROR_SHORT_DATA = 0x22U,
    ERROR_LONG_DATA = 0x33U
};

enum class classEnum
{
    worngData = 0x11U,
    shortData = 0x22U,
    longData = 0x33U
};

void CallEnumTypes(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief  Returnng multiple values in C++ 
 *          Using tuplets from std
 */
struct engineparams_t{uint8_t oilP1, oilP2; uint16_t engRPM; uint32_t totMilage;};
std::tuple<uint8_t, uint8_t, uint16_t, uint32_t> GetParameters(struct engineparams_t inEngParam);
std::tuple<uint8_t, uint8_t, uint16_t, uint32_t> GetParameters(uint64_t inEngParam);

typedef std::tuple<uint32_t, uint32_t, uint64_t, std::string> dataFrameRow_t;
dataFrameRow_t RetTupleFunction(uint8_t inIndex);

void CallRetTupleFunction(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Why we need virtual destructor
 * 
 *          To call both dectructors from derived class and from base class.
 *          This can lead to memory leak
 */
class BaseVirtualDestructor
{
    uint8_t _num;

public:
    virtual void Print(void)                { std::cout << ">> Base class |  method - Print " << std::endl; }

    BaseVirtualDestructor(uint8_t inNum): _num(inNum)
    {   std::cout << "| " << _num << " Base class | constructor  "<< std::endl; }

    virtual ~BaseVirtualDestructor(void)    
    {   std::cout << "| " << _num << " Base class | destructor virtual  " << std::endl; }
};

class DerivedVirtualDestructor: public BaseVirtualDestructor
{
    uint8_t _num;

public:
    virtual void Print(void)                { std::cout << ">> Derived class | method - Print "  << std::endl; }

    DerivedVirtualDestructor(uint8_t inNum): BaseVirtualDestructor::BaseVirtualDestructor(inNum), _num(inNum)
    {   std::cout << "| " << _num << " Derived class | constructor" << std::endl; }

    ~DerivedVirtualDestructor(void)         
    {   std::cout << "| " << _num << " Derived class | destructor  "     << std::endl; }
};
void CallVirtualDestructor1(void);
void CallVirtualDestructor2(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What are the places where initializer list must be present
 * 
 *          When constatnt is initialized
 *          When reference is initialized
 *          When class is asigning inside class
 */
typedef std::tuple<int, int> bothVals_tuple;
class BaseListInitializer
{
    const int _X;
    int& refSomeInt;
public:
    BaseListInitializer(int& refSomeInt):           _X(0x00),   refSomeInt(refSomeInt)      { refSomeInt++;}
    BaseListInitializer(int x, int& refSomeInt):    _X(x),      refSomeInt(refSomeInt)      { refSomeInt++;}

    int GetValue(void)  { return _X; }
    void Print(void)    { std::cout << "_X = " << _X << std::endl; }
};

class DerivedListInitializer: public BaseListInitializer
{
    const int _Y;
public:
    DerivedListInitializer(int y, int x, int& refSomeInt):  BaseListInitializer(x, refSomeInt), _Y(y) 
    {   std::cout << "DerivedListInitializer and BaseListInitializer" << std::endl; }

    int GetValue(void)  { return _Y; }

    bothVals_tuple GetBothValues(void) 
    {   return std::make_tuple( _Y, BaseListInitializer::GetValue()); }

    void Print(void) 
    {   std::cout << "_Y = " << _Y << std::endl; }

    void PrintBoth(void)    
    {   Print(); 
        BaseListInitializer::Print(); }
};
void CallListInitializer(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What are the drawback of vectors in C++
 *          It overalocated memory which some times could be very bad in terms of performance
 *          When ever capacity of vecors it copy element from previous to new vector 
 */
void CallDrawbackOfVectors(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is Constructor Delegation in C++
 * 
 *          Constructior is delegated to bottom constructor
 *          If the constructor has heavy code inside to prevent code bloating constructor is delegated to main one
 */
class BaseConstrDelegation
{
    int _x, _y;
    int _xy;

public:
    // Both delegated constructors
    BaseConstrDelegation(void):             BaseConstrDelegation(0, 0) {;}
    BaseConstrDelegation(int x):            BaseConstrDelegation(x, 0) {;}
    // True constructor-
    BaseConstrDelegation(int x, int y):     _x(x), _y(y) 
    {//  Example of some inside calculation that are present.
        int temp = 1;
        temp = (x << 2) + temp;
        temp = (y << 2) + temp;
        _xy = temp;
    }

    void Print(void)    
    {   std::cout << " _x= " << _x << " | _y= " << _y << std::endl; 
        std::cout << " resould of _xy= "     << _xy << std::endl;  }
};
void CallDelegationCOnstruction(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What does the printf and scanf function returns?
 * 
 *          printf returns number of characters printed succesfuly 
 *          scanf returns the number of elements read successfully from console
 */
void CallTestPrintfScanf(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is RVO and NRVO in C++?
 * 
 *          It stands for return value optimazition and named return value optimazition
 */
class Base_RVO_NRVO
{
    int X;
public:
    Base_RVO_NRVO(void) 
    {   std::cout << "Constructor: Base_RVO_NRVO " << std::endl;    }

    Base_RVO_NRVO(const Base_RVO_NRVO &) // Call when copy
    {   std::cout << "Copy Constructor: Base_RVO_NRVO " << std::endl;    }
};
Base_RVO_NRVO FunctionOf_RVO_NRVO(void);

void Call_RVO_NRVO(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the best place to use enum in C++
 *          
 *          Enum is used in some limited sets of values
 *          Function can take one values from set like parameter input
 */
enum class MAIN_COLORS { RED = 0x11U, GRN = 0x22U, BLU = 0x33U };
void CallEnumTestFunc(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the diffrence between struct and class in C++
 *  
 *          Class memebers are private by dafault
 *          Struct memebers are public by default
 */
class classBaseType
{// Default it is private
    int x;
    int y;
    int z;
};

class classDrivedType: classBaseType
{// Default it is private
    int a;
    int b;
    int c;
};

struct structBaseType
{// Default it is public
    int x;
    int y;
    int z;
};
struct structDerivedType: structBaseType
{// Default it is public
    int a;
    int b;
    int c;
};

void Call_classTestType_structTestType(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the order of functionevaluation in C++
 */
bool FunParamOrder_build(void);
bool FunParamOrder_use(void);
void FunParamOrder_power2(unsigned int inA);
void FunParamOrder_mull(unsigned int inA, unsigned int inB);
void CallFunParamOrder(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the diferences in references and pointers in C++
 *          And when is best usage of both of them
 * 
 *          Reference: Used in function paremeter and return type
 *          1. Pass big object
 *          2. Avoid object slice
 *          3. Modify local variables of call function
 * 
 *          Pointers: Algoritms and data structures like list , tree graph
 *          1. On the end of node NULL pointer can be used
 *          2. Pointer can be changes to another pointer
 *          3. 
 */
class Weapon
{
int _mass;

public:
    virtual void PrintVV(void)
    {   std::cout << "virtual Weapon class: Base" << std::endl; }

    virtual void PrintVD(void)         
    {   std::cout << "virtual Weapon class: Base" << std::endl; }

    void PrintDV(void)         
    {   std::cout << "Weapon class: Base" << std::endl; }

    void Print(void)         
    {   std::cout << "Weapon class: Base" << std::endl; }
};

class Blade: public Weapon
{
int _lenght;

public:
    virtual void PrintVV(void)
    {   std::cout << "virtual Blade(Weapon) class: Deriv" << std::endl; }

    void PrintVD(void)
    {   std::cout << "Blade(Weapon) class: Deriv" << std::endl; }

    virtual void PrintDV(void)
    {   std::cout << "virtual Blade(Weapon) class: Deriv" << std::endl; }

    void Print(void)
    {   std::cout << "Blade(Weapon) class: Deriv" << std::endl; }
};

void SomeFun(Weapon& inClass);

class OpticREF
{
    static uint16_t sCalln;
    uint8_t _type;
    uint16_t _dim;

public:
    OpticREF(uint8_t inType, uint16_t inDim):  _type(inType), _dim(inDim) 
    {   ; }

    OpticREF(const OpticREF& refOptic): _type(refOptic._type + 1) 
    {   _dim = refOptic._dim + 1; }

virtual void Print(void)
    {   std::cout << "OpticREF | Optic class: " << _type << " | Optic dim: " << _dim << std::endl; }
};

class OpticPTR
{
    static uint16_t sCalln;
    uint8_t _type;
    uint16_t _dim;

public:
    OpticPTR(uint8_t inType, uint16_t inDim): _type(inType), _dim(inDim) 
    {   ; }

    OpticPTR(const OpticPTR* pOpticPTR): _type(pOpticPTR->_type + 1) 
    {   _dim = pOpticPTR->_dim + 1; }

virtual void Print(void)
    {   std::cout << "OpticPTR | Optic class: " << _type << " | Optic dim: " << _dim << std::endl; }
};

void CallPtrAndRefDifference1(void);
void CallPtrAndRefDifference2(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Why static define data memeber must to be defined in file.cpp and not in file.h
 * 
 *          If it is called in file.h then it is intialized multiple times.
 *          Compiler then will throw error multiple definitions
 */

typedef struct 
{
    uint8_t mass;
    uint8_t lenght;
    uint8_t type;
    uint8_t tickness;
}sword_t;

void Callstaticmemebers(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Why is better to pass by Reference or by Pointer then by value.
 * 
 *          
 */

void PrintVestorValues(std::vector<uint64_t> &refVector);

void CallRefAndPointerDeffrerence(void);

//==========================================================================================================

/***********************************************************************************************************
 * @brief   Why size of an empty class or structure is not zero in C++?
 * 
 *          Returning ref to local variable can be coz its can cause segmentacion error
 *          
 *          This is cause cpp cause to seperate each other.
 *          But when class or struct has some values inside then size would by of that size.
 */
class SomeTestEmptyClass    {};

class SomeTestClass
{
    uint16_t _value;
};

struct sometestEmptyStruct_t    {};

struct sometestStruct_t
{
    uint16_t _value;
};

void CallTestEmptyClassAndStruct(void);
//==========================================================================================================



#endif // _ADVANCE_PART_5_H