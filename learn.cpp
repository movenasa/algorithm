#include<iostream>
#include<random>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

void insert(ListNode *p, ListNode *ins)
{
    ins->next = p->next;
    p->next = ins;
}
// 删除n0 后面的一个列表元素
void deletes(ListNode *p)
{
    if(p->next == nullptr)
        return;
    ListNode *t = p->next;
    ListNode *P = t->next;
    p->next = P;
}

int find(ListNode *P, int target)
{
    // 遍历整个链表
    int cnt = 0;
    for(ListNode *p = P; p != nullptr; p = p->next, cnt++)
    {
        if(p->val == target)
            return cnt;
    }
    return -1;
}

int main()
{
    // int *p = new int[5]; // 初始化在堆上
    // printf("%d\n", p[0]); // 0
    // rand();
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);


    node1.next = &node2;
    node2.next = &node3;
    // 堆上分配一个新内存
    ListNode *p = new ListNode(4);
    // 栈上分配内存
    ListNode node4(5);
    insert(&node1, p);
    insert(&node1, &node4);
    deletes(&node1);
    int target = find(&node1, 2);
    printf("%d\n", target);
    for(ListNode *p = &node1; p!= nullptr; p = p->next)
    {
        cout << p->val ;
    }


    return 0;
}