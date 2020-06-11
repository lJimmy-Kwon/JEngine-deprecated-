#include "clock_test.h"
#include "vector2d_test.h"
#include "vector3d_test.h"
#include "matrix2d_test.h"
#include "matrix3d_test.h"
#include "common_test.h"

int main(int argc, char** argv ){


    int status = 0;
    {
//        Clock_test ct;
//        status |= QTest::qExec(&ct, argc, argv );
    }
    {
//        vector2D_test vt;
//        status |= QTest::qExec(&vt, argc, argv );
    }
    {
//        common_test cot;
//        status |= QTest::qExec(&cot, argc, argv );
    }
    {
//        matrix2D_test mt;
//        status |= QTest::qExec(&mt, argc, argv );
    }
    {
//        vector3d_test v3t;
//        status |= QTest::qExec(&v3t, argc, argv );
    }
    {
         matrix3D_test m3t;
         status |= QTest::qExec(&m3t, argc, argv );
    }

    return status;
}
