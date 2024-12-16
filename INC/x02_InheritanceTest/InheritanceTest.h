#include "_x02_inheritance_test.h"
#ifdef CMP_X02_INHERITANCE_TEST_H

#include <stdint.h>
#include <stdio.h>

#ifndef _INHERITANCE_TEST_H
#define _INHERITANCE_TEST_H

struct values_t
{
    uint32_t vadd;
    uint32_t vsubb;
    uint32_t vmull;
    uint32_t vdiv;
    uint32_t vand;
    uint32_t vor;
};

//===================================================================================
class Parrent_class
{
private:// Private data
    uint32_t lastAdd;
    uint32_t lastSubb;
    uint32_t lastMull;
    uint32_t lastDiv;
    uint32_t lastAND;
    uint32_t lastOR;

public:
    Parrent_class(uint32_t initVal);
    ~Parrent_class();

    uint32_t Add(uint32_t inA, uint32_t inB);
    uint32_t Subb(uint32_t inA, uint32_t inB);
    uint32_t Mull(uint32_t inA, uint32_t inB);
    uint32_t Dive(uint32_t inA, uint32_t inB);
    uint32_t BoolAND(uint32_t inA, uint32_t inB);
    uint32_t BoolOR(uint32_t inA, uint32_t inB);

    void GetLastVals(uint32_t* pAdd, uint32_t* pSubb, uint32_t* pMull, uint32_t* pDiv, uint32_t* pAnd, uint32_t* pOr);
    struct values_t GetLastVals(void);
};
//===================================================================================
class Children_class: private Parrent_class
{
private:
    uint32_t valueToPrint;
    uint32_t retVals[8];
    struct values_t _values;

public:
    Children_class(uint32_t initValtoPrint, uint32_t initvalForLast);
    ~Children_class();

    void PrintAdd(uint32_t inA, uint32_t inB);
    void PrintSubb(uint32_t inA, uint32_t inB);
    void PrintMull(uint32_t inA, uint32_t inB);
    void PrintDive(uint32_t inA, uint32_t inB);
    void PrintAND(uint32_t inA, uint32_t inB);
    void PrintOR(uint32_t inA, uint32_t inB);

    void PrintAll(uint32_t inA, uint32_t inB);
    void PrintLastOperations1(void);
    void PrintLastOperations2(void);
};
//===================================================================================
#endif // _INHERITANCE_TEST_H
#endif // CMP_X02_INHERITANCE_TEST_H