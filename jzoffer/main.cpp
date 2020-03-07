#include <QCoreApplication>

#include "pub.h"

void main_test()
{
    jz_2_2_1_00_sizeof_test();
    jz_2_2_1_01_mysring_test();
    jz_2_2_2_00_singleton();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    main_test();
    getchar();

    return a.exec();
}
