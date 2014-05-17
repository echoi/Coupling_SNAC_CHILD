#include "TestWrapper.h"
#include "Test.hh"

extern "C" {

CTest * test_new(int i) {
       Test *t = new Test(i);

       return (CTest *)t;
}

void test_testfunc(const CTest *test) {
        Test *t = (Test *)test;
        t->testfunc();
}

void test_delete(CTest *test) {
        Test *t = (Test *)test;

        delete t;
}
}
