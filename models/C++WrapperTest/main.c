#include <stdio.h>
#include "TestWrapper.h"

int main() {
        CTest *t = NULL;

        t = test_new(5);
        test_testfunc(t);
        test_delete(t);
        t = NULL;

        return 0;
}
