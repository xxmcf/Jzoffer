/*
 * @brief      sizeof���ʵ����ϰ
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
 * �����
û���κα����ͷ��������ʵ����С:1
ֻ���캯���������������ʵ����С��1
�����ʵ����С��4
*/
void jz_2_2_1_00_sizeof_test()
{
    log("\n<<<<<<<<<<<<<<<< sizeof����ϰ >>>>>>>>>>>>>>>>>\n\n");
    SizeofEmptyTest emptyClass;
    SizeofMethodTest methodClass;
    SizeofVirtalMethodTest virtalClass;
    int size = sizeof(emptyClass);
    log("û���κα����ͷ��������ʵ����С:%d\n", size);
    size = sizeof(methodClass);
    log("ֻ���캯���������������ʵ����С��%d\n", size);
    size = sizeof(virtalClass);
    log("���麯����ʵ����С��%d\n", size);
}
