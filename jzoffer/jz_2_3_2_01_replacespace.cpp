/*
 * @breif   面试题5：替换空格
            题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
            则输出“We%20are%20happy.”。
 * @author  xxmcf
 * @version 1.0
 * @date    2020/03/08
 */

#include "pub.h"
#include <iostream>

void replace_space(char s[], int length)
{
    if (nullptr == s || !s[0] || 0==length)
        return;

    int n = 1, m = 3, count = 0;
    int len = strlen(s);


    for (int i=0; i<length; i++)
    {
        if (s[i] == ' ')
            ++count;
    }

    if (0==count)
        return;

    int dst_len = len+(m-n) * count;

    if (length < dst_len+1)
        return;

    char* p1 = s+dst_len;
    char* p2 = s+len;

    for (int i = len; i>=0; i--)
    {
        if (' ' != *p2)
        {
            *(p1--) = *p2;
        }
        else
        {
            *(p1-2) = '%';
            *(p1-1) = '2';
            *(p1) = '0';
            p1 -= 3;
        }
        p2--;
    }
}

static void test(char* testName, char s[], int length, char expected[])
{
    if (nullptr != testName && 0!=testName[0])
        std::cout << testName << " : ";

    replace_space(s, length);

    if (nullptr==s && nullptr==expected)
        std::cout << "Passed\n";
    else if (nullptr==s && nullptr!=expected)
        std::cout << "FAILED\n";
    else if (0<=length&& 0==strcmp(s, expected))
        std::cout << "Passed\n";
    else if (0==strcmp(s, expected))
        std::cout << "Passed\n";
    else
        std::cout << "FAILED\n";
}


//空指针
static void Test1()
{
    char* s = nullptr;
    test((char*)__FUNCTION__, s, 0, nullptr);
}


//长度为0
static void Test2()
{
    char* s = nullptr;
    test((char*)__FUNCTION__, s, 0, nullptr);
}

//数组长度不够
static void Test3()
{
    char s[12] = {"hello world"};
    char expected[] = "hello world";
    test((char*)__FUNCTION__, s, 12, expected);
}

//空格在中间
static void Test4()
{
    char s[30] = {"hello world"};
    char expected[] = "hello%20world";
    test((char*)__FUNCTION__, s, 30, expected);
}

//空格在结尾
static void Test5()
{
    char s[30] = {"helloworld "};
    char expected[] = "helloworld%20";
    test((char*)__FUNCTION__, s, 30, expected);
}

//空格在开头
static void Test6()
{
    char s[30] = {" helloworld"};
    char expected[] = "%20helloworld";
    test((char*)__FUNCTION__, s, 30, expected);
}

//有两个连续空格
static void Test7()
{
    char s[30] = {"hello  world"};
    char expected[] = "hello%20%20world";
    test((char*)__FUNCTION__, s, 30, expected);
}

//只有一个空格
static void Test8()
{
    char s[30] = {" "};
    char expected[] = "%20";
    test((char*)__FUNCTION__, s, 30, expected);
}

//只有空格，多个
static void Test9()
{
    char s[30] = {"  "};
    char expected[] = "%20%20";
    test((char*)__FUNCTION__, s, 30, expected);
}

//没有空格
static void Test10()
{
    char s[30] = {"helloworld"};
    char expected[] = "helloworld";
    test((char*)__FUNCTION__, s, 30, expected);
}

//空字符串
static void Test11()
{
    char s[30] = {""};
    char expected[] = "";
    test((char*)__FUNCTION__, s, 30, expected);
}


void jz_2_3_2_01_replacespace()
{
    log("\n<<<<<<<<<<<<<<<< 替换字符串练习 >>>>>>>>>>>>>>>>>\n");
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
}
