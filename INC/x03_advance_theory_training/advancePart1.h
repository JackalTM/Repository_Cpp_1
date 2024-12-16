#include "_x03_include.h"
#ifdef CMP_ADVANCE_PART_1_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdint.h>
#include <typeinfo>
#include <type_traits>
#include <vector>
#include <algorithm>

/**************************************************************************************
 * @brief   Test of a friendship in C++ 
 * @note    Friend function can access private data
 * @return
*/
class BaseClassFriend
{
private:
    unsigned int x;
    unsigned int y;

public:
    BaseClassFriend(unsigned int x, unsigned int y);
    ~BaseClassFriend();

    friend void FriendFunction(BaseClassFriend& RefBase, unsigned int x);
};
void FriendFunction(BaseClassFriend& RefBase, unsigned int x);

void CallFriendFunction(void);
//=====================================================================================

/**************************************************************************************
 * @brief   Test of auto keyword
 * @note    
 * @return
*/
void AutoKeyword(void);
//=====================================================================================

/**************************************************************************************
 * @brief   Code bloat is the production of code that is percieved as unnecessary long, 
 *          slow or otherwise wastefullof recources
*/
void CodeBloatExample(void);
//=====================================================================================

/**************************************************************************************
 * @brief   Inline function test
 *          IT is just information for compiler to copy and paste this function into main
*/
class InineTest
{
private:
    int _x;
public:
    inline void print(void);
};
void CallInlineTest(void);

/**************************************************************************************
 * @brief   Constant cast in C++
 *          The expresion of const_cast<t>(v) can be used to change const or volatile 
 *          qualifiers of pointers or reference
 *          Where T must to be a pointer
 *          Constant variable is a variable inside ROM memory
 * 
 *          Volatille is using as info to compiler to not optimalize some variable
*/
void CallConstantCast(void);
//=====================================================================================

/**************************************************************************************
 * @brief   What is one of the use of decltype in C++
 *          It checks the type of expresion
*/
void CallDecltype(void);
//=====================================================================================

/**************************************************************************************
 * @brief   pointers and references
 *          Pointer is a memory adres of a variable
 *          Reference is a anaother alias for this variable and have to be asigned diring creation
*/
void CallTestPointersAndRef(void);
//=====================================================================================

/**************************************************************************************
 * @brief   Differences b/w ranges based for loop and for_each in C++
 *          Some of the diff are shown below
*/
void Print(int values);
void CallVecorRanges(void);
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
class BaseClass
{
public:
    void A_print(void)          { std::cout << "BaseClass!    void A_print" << std::endl;}
    virtual void B_print(void)  { std::cout << "BaseClass!    virtual void B_print" << std::endl;}
    virtual void C_print(void)  { std::cout << "BaseClass!    virtual void C_print" << std::endl;}
    //virtual void PurecVirtual(void) = 0x00;
};
class NextClass : public BaseClass
{
public:
    void A_print(void)          { std::cout << "NextClass!    void A_print" << std::endl;}
    void B_print(void)          { std::cout << "NextClass!    void B_print" << std::endl;}
    virtual void C_print(void)  { std::cout << "NextClass!    virtual void C_print" << std::endl;}
};

class Weapon
{// Base class with pure virtual function wich is only stencil for implementation
public:
    virtual void Usage(int n) = 0;// Pure virtual
};
//======================================================
class Sword : public Weapon
{
public:
    void Usage(int n)   { std::cout << "Sword swing " << n << " times" << std::endl;}
};
//---------------------------------
class Rifle: public Weapon
{
public:
    void Usage(int n)   { std::cout << "Rifle shoot " << n << " times" << std::endl;}
};
//======================================================
void CallVirtualFunctionsTest1(void);
void CallVirtualFunctionsTest2(void);
void CallPureVirtualFunctions(void);
//=====================================================================================

#endif // CMP_ADVANCE_PART_1_H