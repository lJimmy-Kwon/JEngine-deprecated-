#ifndef CLOCK_H
#define CLOCK_H
#include <QElapsedTimer>

namespace Timing{

    class Clock{
    public:

        bool initialize();
        bool shutdown();
        void start();
        void stop();
        void lap();
        float lastlapTime() const;

    private:
        QElapsedTimer timer;
        qint64 timeLastFrame;
        qint64 deltaLastFrame;
    };

}


#endif // CLOCK_H
