#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("a\n");
    getchar();

    return a.exec();
}
