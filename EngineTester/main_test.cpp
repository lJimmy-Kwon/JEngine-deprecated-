#include "clock_test.h"
#include "vector2d_test.h"

int main(int argc, char** argv ){

    int status = 0;
    {
        Clock_test ct;
        status |= QTest::qExec(&ct, argc, argv );
    }
    {
        vector2D_test vt;
        status |= QTest::qExec(&vt, argc, argv );
    }

    return status;
}
