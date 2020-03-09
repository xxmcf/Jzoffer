/*
 * @breif   ������5���滻�ո�
            ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
            �������We%20are%20happy.����
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


//��ָ��
static void Test1()
{
    char* s = nullptr;
    test((char*)__FUNCTION__, s, 0, nullptr);
}


//����Ϊ0
static void Test2()
{
    char* s = nullptr;
    test((char*)__FUNCTION__, s, 0, nullptr);
}

//���鳤�Ȳ���
static void Test3()
{
    char s[12] = {"hello world"};
    char expected[] = "hello world";
    test((char*)__FUNCTION__, s, 12, expected);
}

//�ո����м�
static void Test4()
{
    char s[30] = {"hello world"};
    char expected[] = "hello%20world";
    test((char*)__FUNCTION__, s, 30, expected);
}

//�ո��ڽ�β
static void Test5()
{
    char s[30] = {"helloworld "};
    char expected[] = "helloworld%20";
    test((char*)__FUNCTION__, s, 30, expected);
}

//�ո��ڿ�ͷ
static void Test6()
{
    char s[30] = {" helloworld"};
    char expected[] = "%20helloworld";
    test((char*)__FUNCTION__, s, 30, expected);
}

//�����������ո�
static void Test7()
{
    char s[30] = {"hello  world"};
    char expected[] = "hello%20%20world";
    test((char*)__FUNCTION__, s, 30, expected);
}

//ֻ��һ���ո�
static void Test8()
{
    char s[30] = {" "};
    char expected[] = "%20";
    test((char*)__FUNCTION__, s, 30, expected);
}

//ֻ�пո񣬶��
static void Test9()
{
    char s[30] = {"  "};
    char expected[] = "%20%20";
    test((char*)__FUNCTION__, s, 30, expected);
}

//û�пո�
static void Test10()
{
    char s[30] = {"helloworld"};
    char expected[] = "helloworld";
    test((char*)__FUNCTION__, s, 30, expected);
}

//���ַ���
static void Test11()
{
    char s[30] = {""};
    char expected[] = "";
    test((char*)__FUNCTION__, s, 30, expected);
}


void jz_2_3_2_01_replacespace()
{
    log("\n<<<<<<<<<<<<<<<< �滻�ַ�����ϰ >>>>>>>>>>>>>>>>>\n");
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
