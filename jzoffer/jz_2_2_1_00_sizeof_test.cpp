/*
 * @brief      sizeof类的实例练习
 * @author     xxmcf
 * @version    1.0
 * @date       2020/03/05
*/

#include "pub.h"

class SizeofEmptyTest
{

};

class SizeofMethodTest
{
public:
    SizeofMethodTest() {};
    ~SizeofMethodTest() {};

};

class SizeofVirtalMethodTest
{
public:
    SizeofVirtalMethodTest(){};
    virtual ~SizeofVirtalMethodTest(){};
    virtual void methond1(){}

};


/*
 * 输出：
没有任何变量和方法的类的实例大小:1
只构造函数和析构函数类的实例大小：1
有虚的实例大小：4
*/
void jz_2_2_1_00_sizeof_test()
{
    log("\n<<<<<<<<<<<<<<<< sizeof类练习 >>>>>>>>>>>>>>>>>\n\n");
    SizeofEmptyTest emptyClass;
    SizeofMethodTest methodClass;
    SizeofVirtalMethodTest virtalClass;
    int size = sizeof(emptyClass);
    log("没有任何变量和方法的类的实例大小:%d\n", size);
    size = sizeof(methodClass);
    log("只构造函数和析构函数类的实例大小：%d\n", size);
    size = sizeof(virtalClass);
    log("有虚函数的实例大小：%d\n", size);
}
