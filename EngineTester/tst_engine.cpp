#include <QtTest>

// add necessary includes here

class Engine : public QObject
{
    Q_OBJECT

public:
    Engine();
    ~Engine();

private slots:
    void test_case1();

};

Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::test_case1()
{

}

QTEST_APPLESS_MAIN(Engine)

#include "tst_engine.moc"
