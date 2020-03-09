/*
 * @brief   ���޸������ҵ���һһ���ظ�������
 *          �����Сn+1,�����е����ַ�Χ��1-n
 * @author  xxmcf
 * @version 1.0
 * @date    2020/03/07
 */

#include "pub.h"
#include <iostream>

int countRange(int numbers[], int length, int start, int end)
{
    int count = 0;
    for (int i=0; i<length; i++)
    {
        if (numbers[i] >= start && numbers[i] <= end)
        {
            count++;
        }
    }
    return count;
}

int getDuplicate(int numbers[], int length)
{
    if (nullptr == numbers || length <=0)
        return -1;

    int start = 1;
    int end = length -1;
    while(start <= end)
    {
        int mid = (end - start) / 2 + start;
        int count = countRange(numbers, length, start, mid);
        if (end == start)
        {
            if (count > 1)
                return start;
            else
                break;
        }
        if (count > mid - start + 1)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
}

// ====================���Դ���====================
static void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
    int result = getDuplicate(numbers, length);
    for(int i = 0; i < dupLength; ++i)
    {
        if(result == duplications[i])
        {
            std::cout << testName << " passed." << std::endl;
            return;
        }
    }
    std::cout << testName << " FAILED." << std::endl;
}

// ����ظ�������
static void test1()
{
    int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
    int duplications[] = { 2, 3 };
    test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ���ظ�������
static void test2()
{
    int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
    int duplications[] = { 4 };
    test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������С������
static void test3()
{
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
    int duplications[] = { 1 };
    test("test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������������
static void test4()
{
    int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
    int duplications[] = { 8 };
    test("test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ������ֻ����������
static void test5()
{
    int numbers[] = { 1, 1 };
    int duplications[] = { 1 };
    test("test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�������λ�����鵱��
static void test6()
{
    int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
    int duplications[] = { 3 };
    test("test6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ����ظ�������
static void test7()
{
    int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
    int duplications[] = { 2, 6 };
    test("test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ�������ظ�����
static void test8()
{
    int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
    int duplications[] = { 2 };
    test("test8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// û���ظ�������
static void test9()
{
    int numbers[] = { 1, 2, 6, 4, 5, 3 };
    int duplications[] = { -1 };
    test("test9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ��Ч������
void test10()
{
    int* numbers = nullptr;
    int duplications[] = { -1 };
    test("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

void jz_2_3_1_01_duplicatearray()
{
    log("\n<<<<<<<<<<<<<<<< ���޸������ҵ���һһ���ظ������� >>>>>>>>>>>>>>>>>\n");
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
}
