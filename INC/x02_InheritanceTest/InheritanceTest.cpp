#include "InheritanceTest.h"
#ifdef CMP_X02_INHERITANCE_TEST_H

/************************************************************************************
 * @name    Parrent_class
 * @brief   Class Contruktor
 * @param   initVal Initial value for private data
*/
Parrent_class::Parrent_class(uint32_t initVal)
{
    lastAdd = initVal;
    lastSubb = initVal - 1;
    lastMull = initVal - 2;
    lastDiv = initVal - 3;
}
//===================================================================================

/************************************************************************************
 * @name    Parrent_class
 * @brief   Class deconstruktor
*/
Parrent_class::~Parrent_class()
{
    ;
}
//===================================================================================

/************************************************************************************
 * @name    Add
 * @brief   Return summ from two varibles
 * @param   inA argument A
 * @param   inB argument B
 * @return  Summ of two arguments
*/
uint32_t Parrent_class::Add(uint32_t inA, uint32_t inB)
{
    lastAdd = inA + inB;
    return lastAdd;
}
//===================================================================================

/************************************************************************************
 * @name    Subb
 * @brief   Return subtraction from two varibles
 * @param   inA argument A
 * @param   inB argument B
 * @return  Subtraction of two arguments
*/
uint32_t Parrent_class::Subb(uint32_t inA, uint32_t inB)
{
    lastSubb = inA - inB;
    return lastSubb;
}
//===================================================================================

/************************************************************************************
 * @name    Mull
 * @brief   Return multiplication of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  Multiplication of two arguments
*/
uint32_t Parrent_class::Mull(uint32_t inA, uint32_t inB)
{
    lastMull = inA * inB;
    return lastMull;
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Return division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  Division of two arguments
*/
uint32_t Parrent_class::Dive(uint32_t inA, uint32_t inB)
{
    lastDiv = inA / inB;
    return lastDiv;
}
//===================================================================================

/************************************************************************************
 * @name    BoolAND
 * @brief   Logical and between arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  Resoult of logical and.
*/
uint32_t Parrent_class::BoolAND(uint32_t inA, uint32_t inB)
{
    lastAND = inA & inB;
    return lastAND;
}
//===================================================================================

/************************************************************************************
 * @name    BoolOR
 * @brief   Logical or between arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  Resoult of logical or.
*/
uint32_t Parrent_class::BoolOR(uint32_t inA, uint32_t inB)
{
    lastOR = inA | inB;
    return lastOR;
}
//===================================================================================

/************************************************************************************
 * @name    GetLastVals
 * @brief   Set values by pointer
 * @param   pAdd Pointer to last summ variable
 * @param   pSubb Pointer to last sub variable
 * @param   pMull Pointer to last mull variable
 * @param   pDiv Pointer to last Div variable
 * @return  void
*/
void Parrent_class::GetLastVals(uint32_t* pAdd, uint32_t* pSubb, 
    uint32_t* pMull, uint32_t* pDiv, 
    uint32_t* pAnd, uint32_t* pOr)
{
    *pAdd = lastAdd;
    *pSubb = lastSubb;
    *pMull = lastMull;
    *pDiv = lastDiv;
    *pAnd = lastAND;
    *pOr = lastOR;
}
//===================================================================================

/************************************************************************************
 * @name    GetLastVals
 * @brief   Return values by structure
 * @return  Structure of type struct values_t
*/
struct values_t Parrent_class::GetLastVals(void)
{
    struct values_t rvals;
    rvals.vadd = lastAdd;
    rvals.vsubb = lastSubb;
    rvals.vmull = lastMull;
    rvals.vdiv = lastDiv;
    rvals.vand = lastAND;
    rvals.vor = lastOR;

    return rvals;
}
//===================================================================================

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/************************************************************************************
 * @name    Children_class
 * @brief   Class Contruktor
 * @param   initValtoPrint Initial value for private data
 * @param   initvalForLast Initial value for last data 
*/
Children_class::Children_class(uint32_t initValtoPrint, uint32_t initvalForLast):
    Parrent_class(initvalForLast)
{
    valueToPrint = initValtoPrint;   
}
//===================================================================================

/************************************************************************************
 * @name    Children_class
 * @brief   Class Deconstrutor
*/
Children_class::~Children_class()
{;}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintAdd(uint32_t inA, uint32_t inB)
{
    retVals[0] = Parrent_class::Add(inA, inB);
    printf("RES: 0x%x + 0x%x = 0x%x \n", inA, inB, retVals[0]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintSubb(uint32_t inA, uint32_t inB)
{
    retVals[1] = Subb(inA, inB);
    printf("RES: 0x%x - 0x%x = 0x%x \n", inA, inB, retVals[1]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintMull(uint32_t inA, uint32_t inB)
{
    retVals[2] = Parrent_class::Mull(inA, inB);
    printf("RES: 0x%x * 0x%x = 0x%x \n", inA, inB, retVals[2]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintDive(uint32_t inA, uint32_t inB)
{
    retVals[3] = Dive(inA, inB);
    printf("RES: 0x%x / 0x%x = 0x%x \n", inA, inB, retVals[3]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintAND(uint32_t inA, uint32_t inB)
{
    retVals[4] = Parrent_class::BoolAND(inA, inB);
    printf("RES: 0x%x & 0x%x = 0x%x \n", inA, inB, retVals[4]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintOR(uint32_t inA, uint32_t inB)
{
    retVals[5] = BoolOR(inA, inB);
    printf("RES: 0x%x | 0x%x = 0x%x \n", inA, inB, retVals[5]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintAll(uint32_t inA, uint32_t inB)
{
    PrintAdd(inA, inB);
    PrintSubb(inA, inB);
    PrintMull(inA, inB);
    PrintDive(inA, inB);
    PrintAND(inA, inB);
    PrintOR(inA, inB);
}
//===================================================================================


/************************************************************************************
 * @name    PrintLastOperations 
 * @brief   Print last operations from parent class
 * @param   void
 * @return  void
*/
void Children_class::PrintLastOperations1(void)
{
    uint32_t retvals[8];
    GetLastVals((uint32_t*)&retvals[0], (uint32_t*)&retvals[1], (uint32_t*)&retvals[2], (uint32_t*)&retvals[3], (uint32_t*)&retvals[4], (uint32_t*)&retvals[5]);
    
    printf("\nCurrent last operation retvals: \n");
    printf(" last '+' %x \n", retvals[0]);
    printf(" last '-' %x \n", retvals[1]);
    printf(" last '*' %x \n", retvals[2]);
    printf(" last '/' %x \n", retvals[3]);
    printf(" last '&' %x \n", retvals[4]);
    printf(" last '|' %x \n", retvals[5]);
}

/************************************************************************************
 * @name    PrintLastOperations 
 * @brief   Print last operations from parent class
 * @param   void
 * @return  void
*/
void Children_class::PrintLastOperations2(void)
{
    struct values_t retvals = GetLastVals();

    printf("\nCurrent last operation values: \n");
    printf(" last '+' %x \n", retvals.vadd);
    printf(" last '-' %x \n", retvals.vsubb);
    printf(" last '*' %x \n", retvals.vmull);
    printf(" last '/' %x \n", retvals.vdiv);
    printf(" last '&' %x \n", retvals.vand);
    printf(" last '|' %x \n", retvals.vor);
}

#endif // CMP_X02_INHERITANCE_TEST_H