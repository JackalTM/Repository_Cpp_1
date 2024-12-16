#include "xTest.h"
#ifdef CPM_XTEST_H

void CALL_Test1(void)
{
    Children_class myChildren(8,8);

    myChildren.PrintAll(0xF0, 0x0F);

    myChildren.PrintLastOperations1();
    myChildren.PrintLastOperations2();
}

#endif // CPM_XTEST_H