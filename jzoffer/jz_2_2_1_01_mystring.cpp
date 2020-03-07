/*
 * @brief      赋值运算符练习
 * @author     xxmcf
 * @version    1.0
 * @date       2020/03/05
*/

#include "pub.h"
#include <string>

class MyString
{
public:
    MyString(const char* s)
    {
        if (nullptr == s)
        {
            data = new char[1];
            data[0] = '\0';
        }
        else
        {
            data = new char[strlen(s)+1];
            strcpy(data, s);
        }
    }

    MyString(const MyString& s)
    {
        this->data = new char[strlen(s.data)+1];
        strcpy(this->data, s.data);
    }

    MyString& operator=(const MyString& s)
    {
        if (this == &s)
        {
            return *this;
        }
        if (this->data != nullptr)
        {
            delete this->data;
        }
        this->data = new char[strlen(s.data)+1];
        strcpy(this->data, s.data);
    }

protected:
    char* data;
};



void jz_2_2_1_01_mysring_test()
{
    log("\n<<<<<<<<<<<<<<<< 字符串赋值运算符、复制构造函数练习 >>>>>>>>>>>>>>>>>\n\n");
}
