#include <unistd.h>
#include "Logger.h"


int main(int argc, char **argv)
{
    int a = 10;

    DEBUG("Karthikeyan");
    INFO("Karthikeyan");
    WARN("Karthikeyan");
    ERROR("Karthikeyan");

    MSG("Testing(%d) 1 2 3", a);
    MSG("Testing(%d) 1 2 3", a);

    ASSERT_MSG(a == 10, "Custom message: x is equal to 10");
    //ASSERT(0);
    ASSERT_MSG(a > 10, "Custom message: x must be greater than 10");
    return 0;
}