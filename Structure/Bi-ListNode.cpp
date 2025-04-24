// 双链表相关操作
#include<iostream>
#include<cstdio>

using namespace std;

// 双向链表
struct BListNode{
    int val;
    BListNode *next;
    BListNode *prev;
    BListNode(int x): val(x), next(nullptr), prev(nullptr) {}
};

// 双向链表插入元素
void insert(BListNode *p, int x)
{
    BListNode *ins = new BListNode(x);
    ins->next = p->next;
    p->next = ins;
    ins->prev = p;
    BListNode *ne = p->next;
    ne->prev = ins;
    // (p->next->prev) = ins; 两种方式都可以
}

// 双向链表删除元素
void deletes(BListNode *p) // 删除p 后面的元素
{
    BListNode *ne = p->next;
    BListNode *nes = ne->next;
    p->next = ne->next;
    ne->next = nullptr;
    nes->prev = p;
    ne->prev = nullptr;
    delete ne;
}

// 双向链表查找操作
int find(BListNode *p1, int target)
{
    int cnt = 0;
    if(p1 == nullptr) return 0;
    for(BListNode *p = p1; p != nullptr; p = p->next, cnt++)
    {
        if(p->val == target) return cnt;
    }
    return -1;
}


int main()
{
    BListNode node1 = BListNode(3);
    BListNode node2 = BListNode(5);
    node1.next = &node2;
    node2.prev = &node1;
    insert(&node1, 4);
    // cout << &node1 <<' '  << node2.prev << ' ';
    printf("%d", find(&node1, 4));
    deletes(&node1);
    printf("%d", find(&node1, 4));
    // 遍历双向链表
    for(BListNode *p = &node1; p != nullptr; p = p->next)
        cout << p->val << ' ';
    return 0;
}
