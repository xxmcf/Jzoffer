/*
 * @brief   从尾到头打印链表
 * @author  xxmcf
 * @version 1.0
 * @date    2020/03/08
 *
 */

#include "pub.h"
#include "linklist.h"
#include <iostream>

static void test(char* testName, LinkList& lst, const char* expected)
{
    if (testName != nullptr && testName[0] != '\0')
        std::cout << testName << " : ";
    string s = lst.printReverseList();
    if (s != expected)
        std::cout << "FAILED";
    else
        std::cout << "PASSED";
    std::cout << std::endl;
}

//空链表
static void Test1()
{
    LinkList lst;
    test((char*)__FUNCTION__, lst, "");
}

//只有一个结点的链表
static void Test2()
{
    LinkList lst;
    lst.addNode(1);
    test((char*)__FUNCTION__, lst, "1");
}

//2-3-4-5-6-10
static void Test3()
{
    LinkList lst;
    lst.addNode(2);
    lst.addNode(3);
    lst.addNode(4);
    lst.addNode(5);
    lst.addNode(6);
    lst.addNode(10);
    test((char*)__FUNCTION__, lst, "10,6,5,4,3,2");
}

void jz_mst_06_printlistreverse()
{
    log("\n<<<<<<<<<<<<<<<< 从尾到头打印链表 >>>>>>>>>>>>>>>>>\n");
    Test1();
    Test2();
    Test3();
}
