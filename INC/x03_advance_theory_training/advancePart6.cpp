#include "advancePart6.h"
#ifdef CMP_ADVANCE_PART_6_H

/***********************************************************************************************************
 * @brief       Why using namespace is bad to use
 * 
 *              This can cause multiple definitions of the same function if other lib is using also similat functionalities
 */

//==========================================================================================================

/***********************************************************************************************************
 * @brief       Why Vestors was introduced in C++
 * 
 *              It gives advantages of using array and linked list
 * 
 *              If capacity of vector exted then it create another instance and coppy all values
 */

void CallUsageOfVectors(void)
{
    uint16_t i;
    std::vector<uint16_t> myVector;

    for(i=0; i<8; i++)
    {
        myVector.push_back(i);
    }

    std::cout << "myVector.size()     := " << myVector.size() << std::endl;
    std::cout << "myVector.capacity() := " << myVector.capacity() << std::endl;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief       Why return reference from copy assigment operator in cpp
 *              
 *              To support chaining assigment. But there is a point:
 *              
 */

//==========================================================================================================

#endif // _ADVANCE_PART_6_H