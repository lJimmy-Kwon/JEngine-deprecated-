QT += testlib gui opengl

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += PROFILEING_ON


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DebugTools/Profiling/profiler.cpp \
    Rendering/renderer.cpp \
    Timing/Clock.cpp \
    engine.cpp \
    input/input.cpp

HEADERS += \
    DebugTools/Profiling/profile.h \
    DebugTools/Profiling/profiler.h \
    Misc/typeDefs.h \
    Rendering/Geometry.h \
    Rendering/Renderable.h \
    Rendering/renderer.h \
    Timing/Clock.h \
    input/input.h \
    math/Common.h \
    math/Matrix2D.h \
    math/Matrix2D.inl \
    math/Matrix3D.h \
    math/Matrix3D.inl \
    math/Vector2D.h \
    math/Vector2D.inl \
    engine.h \
    math/Vector3D.h \
    math/Vector3D.inl

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
