/*
 * @brief   单链表，支持添加、删除、清空节点
 * @author  xxmcf
 * @version 1.0
 * @date    2020/03/09
 *
 *
 */
#include "linklist.h"
#include <iostream>
#include <stack>
#include <sstream>

LinkList::LinkList()
{
    head_ = nullptr;
}

LinkList::~LinkList()
{
    clear();
}

ListNode* LinkList::createNode(int value)
{
    ListNode* node = new ListNode;
    node->key = value;
    node->next = nullptr;
    return node;
}

void LinkList::destroyNode(ListNode *node)
{
    if(node != nullptr)
    {
        node->next = nullptr;
        delete node;
    }
}

void LinkList::addNode(int value)
{
    ListNode* node = createNode(value);
    addNode(node);
}

void LinkList::addNode(ListNode* node)
{
    if (nullptr == node || node->next != nullptr)
        return;

    if (head_==nullptr || head_ == node)
    {
        head_ = node;
    }
    else
    {
        ListNode* p = head_;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        p->next = node;
    }

}

void LinkList::insertNode(int pos, int value)
{
    if (pos<0)
        return;
    int len = this->length();
    if (pos>len)
        return;
    ListNode* node = createNode(value);

    int i = 0;
    ListNode* p = head_;
    ListNode* pre = p;
    while(p != nullptr)
    {
        if (i==pos)
        {
            break;
        }
        else
        {
            pre = p;
            p = p->next;
        }
        i++;
    }

    if (0==len)
    {
        head_ = node;
    }
    else if (i==0)
    {
        node->next = p;
        head_ = node;
    }
    else if (i==len)
    {
        pre->next = node;
    }
    else
    {
        pre->next = node;
        node->next = p;
    }
}

void LinkList::removeNode(int pos)
{
    if (pos<0)
        return;
    int len = this->length();
    if (pos>=len)
        return;

    int i = 0;
    ListNode* p = head_;
    ListNode* pre = p;
    while(p != nullptr)
    {
        if (i==pos)
        {
            if (0==i)
            {
                head_ = p->next;
            }
            else
            {
                pre->next = p->next;

            }
            destroyNode(p);
            break;
        }
        else
        {
            pre = p;
            p = p->next;
        }
        i++;
    }
}

void LinkList::removeValue(int value)
{
    ListNode* p = head_;
    ListNode* pre = p;

    while(nullptr != p)
    {
        if (p->key == value)
        {
            if (p == head_)
            {
                pre = head_ = p->next;
                destroyNode(p);
                p = head_->next;
            }
            else
            {
                pre->next = p->next;
                destroyNode(p);
                p = pre->next;
            }
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

void LinkList::removeNode(ListNode* node)
{
    if (nullptr==node)
        return;
    ListNode* p = head_;
    ListNode* pre = p;
    while(p!=nullptr)
    {
        if (p==node)
        {
            if (p == head_)
            {
                pre = head_ = p->next;
                destroyNode(p);
            }
            else
            {
                pre = p->next;
                destroyNode(p);
                p = pre;
            }
            break;
        }
        else
        {
            p = p->next;
            pre = p;
        }
    }
}

void LinkList::clear()
{
    ListNode* p = head_;
    ListNode* temp = p;
    while(p!=nullptr)
    {
        temp = p->next;
        destroyNode(p);
        p = temp;
    }

    head_ = nullptr;
}

int LinkList::length()
{
    int count = 0;
    ListNode* p = head_;

    while(p!=nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
}

string LinkList::printList()
{
    if (nullptr==head_)
    {
        return "";
    }
    std::stringstream sstr;
    ListNode* p = head_;
    while(p!=nullptr && p->next!=nullptr)
    {
        sstr << p->key << ",";
        p = p->next;
    }
    if (p!=nullptr)
    {
        sstr << p->key;
    }
    //std::cout << sstr.str() << std::endl;

    return sstr.str();
}

string LinkList::printReverseList()
{
    if (nullptr==head_)
    {
        return "";
    }
    ListNode* p = head_;
    std::stringstream sstr;
    std::stack<int> stack;
    while(p!=nullptr)
    {
        stack.push(p->key);
        p = p->next;
    }

    while(stack.size() > 1)
    {
        int v = stack.top();
        sstr << v << ",";
        stack.pop();
    }

    int v = stack.top();
    sstr << v;
    stack.pop();
    //std::cout << sstr.str() << std::endl;
    return sstr.str();
}
