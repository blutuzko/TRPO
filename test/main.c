#define CTEST_MAIN
#define CTEST_SEGFAULT
#define CTEST_COLOR_OK

#include "../thirdparty/ctest.h"

int main(int argc, char *argv[])
{
    int result = ctest_main(argc, (const char **)argv);
    
    return result;
}
