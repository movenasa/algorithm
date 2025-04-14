#include<iostream>
#include<cstdio>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    // 构造方法
    ListNode(int x): val(x), next(nullptr) 
    {
        if(x < 0)
        {
            val = x * 2;
        }
    }
};

// 链表插入 在链表的节点p1 之后插入x
void insert(ListNode *p1, int x)
{
    ListNode *ins = new ListNode(x); // 一定要在堆上开辟一片空间，栈上是不可以的，会被系统销毁
    ins->next = p1->next;
    p1->next = ins;
}

// 链表删除 删除p1 后面的一个元素
void deletes(ListNode *p1)
{
    if(p1 == nullptr) return;
    ListNode *p = p1->next;
    p1->next = p->next;
    // delete p;
}

// 链表查找
int find(ListNode *p1, int target)
{
    int cnt = 0;
    if(p1 == nullptr) return -1;
    for(ListNode *p = p1; p!=nullptr; p=p->next, cnt++)
    {
        if(p->val == target) return cnt;
    }
    return 0;
}

int main()
{
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(3);
    ListNode node3 = ListNode(4);
    node1.next = &node2;
    node2.next = &node3;

    // 在这里进行插入操作
    insert(&node1, 2);
    ListNode *mark = node1.next;
    // deletes(mark);
    int index = find(&node1, 4);
    printf("%d\n", index);
    // // 遍历整个链表
    // ListNode *n0 = &node1;
    // while(n0!=nullptr)
    // {
    //     cout << n0->val << ' ';
    //     n0 = n0->next;
    // }
    for(ListNode *p = &node1; p != nullptr; p = p->next)
    cout << p->val << ' ';

    return 0;
}
