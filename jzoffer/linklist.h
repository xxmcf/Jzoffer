#ifndef LINKLIST_H
#define LINKLIST_H

#include <string>

using std::string;

struct ListNode
{
    int key;
    ListNode* next;
};


class LinkList
{
public:
    LinkList();
    ~LinkList();

    void addNode(int value);
    void insertNode(int pos, int value);
    void removeValue(int value);
    void removeNode(int pos);
    void clear();
    int length();
    string printList();
    string printReverseList();

protected:
    ListNode* createNode(int value);
    void destroyNode(ListNode* node);
    void addNode(ListNode* node);
    void removeNode(ListNode*);


protected:
    ListNode* head_;
};

#endif // LINKLIST_H
