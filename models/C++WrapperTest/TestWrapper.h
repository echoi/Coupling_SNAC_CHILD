typedef void CTest;

#ifdef __cplusplus
extern "C" {
#endif
CTest * test_new(int i);
void test_testfunc(const CTest *t);
void test_delete(CTest *t);
#ifdef __cplusplus
}
#endif
