#include "_x03_include.h"
#ifdef CMP_ADVANCE_PART_2_H

#include <stdio.h>
#include <iostream>

/*
extern "C"{
#include "cfileTest.h"
}
*/

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
class BaseClass
{
public:
    virtual void Print(void);
    virtual void Print(uint8_t value);
};

class Derived11: public BaseClass 
{
public:
    void Print(void);
};

class Derived22: public BaseClass 
{
public:
    void Print(void);
};
void CallDynamicCast(void);
//=====================================================================================

/**************************************************************************************
 * @brief   Explicit cast in c++
 * @note    
 * @return
*/
//void CallDynamicCast(void);
//=====================================================================================

/**************************************************************************************
 * @brief   Explicit cast in C++
 * @note    Prevent call the object in some strange way.
*/
#define EXPLICIT_CAST
class BaseImplicit
{
    int _var;
public:
#ifdef EXPLICIT_CAST
    explicit BaseImplicit(void);
    explicit BaseImplicit(int invar);
#else
    BaseImplicit(void);
    BaseImplicit(int invar);
#endif

    void Print(void);
};
void CallExplicitcast(void);
void CallExplicitcast(void);
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
inline void CallExternCinCpp(void);
//=====================================================================================

/**************************************************************************************
 * @brief   What is function chaining in C++?
 * 
 *          It gives proper code analisis power
 *          Method return pointer to itself class.
 * 
 */
class FunctionChainingClass
{// this is a pointer to class itself
    unsigned int _valueA, _valueB, _valueC;
    unsigned int _valueX, _valueY, _valueZ;
public:
// Returning class itself by refeerence
    FunctionChainingClass&  SetParameterA(unsigned int inA)
    {   _valueA = inA;
        return *this;   }// return reference

    FunctionChainingClass&  SetParameterB(unsigned int inB)
    {   _valueB = inB;
        return *this;   }// return reference

    FunctionChainingClass&  SetParameterC(unsigned int inC)
    {   _valueC = inC;
        return *this;   }// return reference
//==========================================================
// Returning class itself by pointer
    FunctionChainingClass*  SetParameterX(unsigned int inX)
    {   _valueX = inX;
        return this;    }// return pointer

    FunctionChainingClass*  SetParameterY(unsigned int inY)
    {   _valueY = inY;
        return this;    }// return pointer

    FunctionChainingClass*  SetParameterZ(unsigned int inZ)
    {   _valueZ = inZ;
        return this;    }// return pointer
//==========================================================
    void Print(void)
    {   std::cout << "Parameters value: " << std::endl;
        std::cout << " A= " << std::hex << _valueA << ", B= " << std::hex << _valueB << ", C= " << std::hex << _valueC << std::endl;
        std::cout << " X= " << std::hex << _valueX << ", Y= " << std::hex << _valueY << ", Z= " << std::hex << _valueZ << std::endl;}
};

void CallFunctionChaining(void);
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
class FunHiddingBase
{
private:
    /* data */
public:
    void Funct(void) 
    { std::cout << "Base class void" << std::endl; }

    unsigned int Funct(unsigned int i, unsigned int j)
    {   std::cout << "Base class i, j" << std::endl;
        return 0;   }
};

class FunHiddingDerived11: public FunHiddingBase
{
private:
    /* data */
public:
// Now not scope resolution is needed to acces Funct from base class
    using FunHiddingBase::Funct;

    unsigned int Funct(char c)
    {   std::cout << "Derived class char" << std::endl;
        return 0;   }
};

void CallFunHidding(void);
//=====================================================================================

/**************************************************************************************
 * @brief   What is a function pointer?
 * 
 *          Addres in memory where function start
 *          
 */

typedef uint8_t (*pFunType)(uint8_t, uint8_t);

pFunType RetFunPtr(pFunType FunPtr);
pFunType RetFunPtrFromList(pFunType FunPtr[], uint8_t n);
uint8_t (*pFun44(uint8_t, uint8_t));

void CallFunctionPointers(void);
//=====================================================================================

/**************************************************************************************
 * @brief   What is Functor is C++
 *          IT work as function and achievied by overloadind "operator()" in some class
 * 
 *          Class object the work as function with initialized object to certain value
 */
class  FunctorBaseMull
{
    uint8_t _value;
public:
    //FunctorBaseMull(void);
    FunctorBaseMull(uint8_t val):  _value{val} {;}

    uint8_t operator()(uint8_t val)    
    {   return (val * _value); }   

};
void CallFunctorBase(void);
//=====================================================================================

/**************************************************************************************
 * @brief   What is GDB and how to use to debug code 
 *          
 */
void CallDebugTest(void);
//=====================================================================================

/**************************************************************************************
 * @brief   How delete[] know how many object delete
 *          
 */
int const n = 0xA;
class DeteteClassTest
{
private:
    /* data */
public:
    int _val;
};
void CallDeleteTest1(void);
void CallDeleteTest2(void);
//=====================================================================================

#endif // CMP_ADVANCE_PART_2_H