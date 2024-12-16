#include "_x03_include.h"
#ifdef CMP_TEMPLATE_FILES_TEST_H

#include <iostream>
#include <stdio.h>
#include <stdint.h>
using namespace std;

#ifndef templateFilesTest_h
#define templateFilesTest_h

/*********************************************
 * @brief   Why template functions  
 * 
 *          To avieve universal code regardeess of data type put inside
 * 
 *          Before every method template<typename T, int N> need to be used
 */
#define TEMPLATE_ARR_SIZE 0x08
#define TEMPLATE_VARIABLE_TYPE uint32_t

template<typename T, int N>
class TemplateClassTest
{
    T _arr[N];

public:
    void setValue(T inValue, T inIndex);

    T getValue(T inIndex);
};

void CallTemplateTest(void);

//=============================================

#endif // templateFilesTest_h

#endif // _TEMPLATE_FILES_TEST_H