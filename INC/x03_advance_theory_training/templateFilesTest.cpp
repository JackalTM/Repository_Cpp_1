#include "templateFilesTest.h"
#ifdef CMP_TEMPLATE_FILES_TEST_H

/*********************************************
 * @brief   Why template functions  
 * 
 *          To avieve universal code regardeess of data type put inside
 * 
 *          Before every method template<typename T, int N> need to be used
 */

template<typename T, int N>
void TemplateClassTest<T, N>::setValue(T inValue, T inIndex)
{
    _arr[inIndex] = inValue;
}

template<typename T, int N>
T TemplateClassTest<T, N>::getValue(T inIndex)
{
    return _arr[inIndex];
}

void CallTemplateTest(void)
{
    int i;
    TemplateClassTest<TEMPLATE_VARIABLE_TYPE, TEMPLATE_ARR_SIZE> myTemplateClassTest;

    for(i=0; i<TEMPLATE_ARR_SIZE; i++)
    {
        myTemplateClassTest.setValue(-(i), i);
    }

    for(i=0; i<TEMPLATE_ARR_SIZE; i++)
    {
        cout << "index:= " << i << " val:= 0x" << hex << myTemplateClassTest.getValue(i) << endl;
    }
}
//=================================================

#endif // _TEMPLATE_FILES_TEST_H
