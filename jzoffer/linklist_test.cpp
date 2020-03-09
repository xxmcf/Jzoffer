/*
 * @brief   链表测试
 * @author  xxmcf
 * @version 1.0
 * @date    2020/03/08
 */
#include "pub.h"
#include "linklist.h"
#include <iostream>

static void test(char* testName, LinkList& lst, const char* expected)
{
    if (nullptr != testName && testName[0]!= '\0')
        std::cout << testName << " : ";
    string s = lst.printList();
    if (s==expected)
        std::cout << "PASSED";
    else
        std::cout << "FAILED";
    std::cout << std::endl;
}

//空链表
static void Test1()
{
    LinkList lst;
    test((char*)__FUNCTION__, lst, "");
}

//链表添加结点
static void Test2()
{
    LinkList lst;
    lst.addNode(1);
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(2);
    test((char*)__FUNCTION__, lst, "1,2,3,4,2");
}

//链表删除中间结点
static void Test3()
{
    LinkList lst;
    lst.addNode(1);
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(2);
    lst.removeNode(2); //删除第2个元素
    test((char*)__FUNCTION__, lst, "1,2,4,2");
}

//链表删除最后一个结点
static void Test4()
{
    LinkList lst;
    lst.addNode(1);
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(2);
    lst.removeNode(4); //删除第4个元素
    test((char*)__FUNCTION__, lst, "1,2,3,4");
}

//链表删除第一个结点
static void Test5()
{
    LinkList lst;
    lst.addNode(1);
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(2);
    lst.removeNode(0); //删除第4个元素
    test((char*)__FUNCTION__, lst, "2,3,4,2");
}

//链表删除所有结点
static void Test6()
{
    LinkList lst;
    lst.addNode(1);
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(2);
    int len = lst.length();
    for (int i=0; i<len; i++)
    {
        lst.removeNode(0);
    }
    test((char*)__FUNCTION__, lst, "");
}

//链表按值删除
static void Test7()
{
    LinkList lst;
    lst.addNode(1);
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(2);
    lst.removeValue(2);
    test((char*)__FUNCTION__, lst, "1,3,4");
}

//在中间插入结点
static void Test8()
{
    LinkList lst;
    lst.addNode(1);
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(2);
    lst.insertNode(2, 10);
    test((char*)__FUNCTION__, lst, "1,2,10,3,4,2");
}

//在结尾插入结点
static void Test9()
{
    LinkList lst;
    lst.addNode(1);
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(2);
    lst.insertNode(5, 10);
    test((char*)__FUNCTION__, lst, "1,2,3,4,2,10");
}

//清空链表
static void Test10()
{
    LinkList lst;
    lst.addNode(1);
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(2);
    lst.clear();
    test((char*)__FUNCTION__, lst, "");
}

//在开头插入结点
static void Test11()
{
    LinkList lst;
    lst.addNode(1);
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(2);
    lst.insertNode(0, 10);
    test((char*)__FUNCTION__, lst, "10,1,2,3,4,2");
}

//从头开始插入结点
static void Test12()
{
    LinkList lst;
    lst.insertNode(0, 1);
    lst.insertNode(1, 2);
    lst.insertNode(2, 3);
    lst.insertNode(3, 4);
    lst.insertNode(4, 2);
    test((char*)__FUNCTION__, lst, "1,2,3,4,2");
}

//按值删除多个结点
static void Test13()
{
    LinkList lst;
    lst.insertNode(0, 1);
    lst.insertNode(1, 2);
    lst.insertNode(2, 3);
    lst.insertNode(3, 4);
    lst.insertNode(4, 2);
    lst.removeValue(2);
    test((char*)__FUNCTION__, lst, "1,3,4");
}

void link_list_test()
{
    log("\n<<<<<<<<<<<<<<<< 链表测试用例 >>>>>>>>>>>>>>>>>\n");
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
    Test12();
    Test13();
}
