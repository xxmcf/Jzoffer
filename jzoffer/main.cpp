#include <QCoreApplication>

#include "pub.h"

void main_test()
{
    jz_2_2_1_00_sizeof_test();
    jz_2_2_1_01_mysring_test();
    jz_2_2_2_00_singleton();
    jz_2_3_1_01_duplicatearray();
    jz_2_3_2_01_replacespace();
    jz_mst_06_printlistreverse();
    link_list_test();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    main_test();
    getchar();

    return a.exec();
}
