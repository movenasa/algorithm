#include <queue>
#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Queue{
    private:
        ListNode *front, *rear;
        int Size;

    public:
        Queue()
        {
            rear = nullptr;
            front = nullptr;
            Size = 0;
        }
        int size()
        {
            return Size;
        }
        bool isEmpty()
        {
            return size() == 0;
        }
        void push(int x)
        {
            // 往尾部插入一个元素,如果为空
            ListNode *ins = new ListNode(x);
            if(isEmpty())
            {
                front = ins;
                rear = ins;
            }
            else
            {
                rear->next = ins;
                rear = ins;
            }
            Size++;
        }
        int peek()
        {
            if(isEmpty()) throw out_of_range("队列为空");
            return front->val;
        }
        void pop()
        {
            if(isEmpty()) throw out_of_range("队列为空");
            int num = front->val;
            ListNode *p = front;
            front = front->next;
            delete p;
            printf("弹出元素为 %d", num);
            Size--;
        }
};

const int N = 100010;
class ArQueue{
    private:
        int arr[N];
        int Size;
        int st;
        int ed;
    
    public :
        ArQueue()
        {
            st = 0;
            ed = -1;
            Size = 0;
        }
        int size()
        {
            return Size;
            // if(st > ed) 为空 cout << (st <= ed ? "NO" : "Yes")
        }
        bool isempty()
        {
            return Size == 0;
        }
        void push(int x)
        {
            arr[++ed] = x;
            Size++;
        }
        int peek()
        {
            return arr[st];
        }
        void pop()
        {
            st++;
            Size--;
        }
};


int main()
{
    // stl 的单向队列实现
    queue<int> que;
    // 队列的插入 记住满足先入先出
    for(int i = 0; i < 10; i ++) que.push(i);
    cout << que.back(); // 尾部元素
    que.pop(); // 只是弹出队头元素，没有任何输出
    cout << que.front() << endl;;
    int size = que.size();
    bool jud = que.empty();
    cout << size << ' ' << jud << endl;

    // 使用链表实现一个队列，链表的头部模拟队列弹出，列表的尾部模拟队列元素插入
    Queue ques = Queue();
    for(int i = 0; i < 10 ; i ++) ques.push(i);
    cout << ques.peek() << endl;
    ques.pop();
    cout << ques.size() << ques.isEmpty() << endl;
    return 0;

    // 使用数组实现一个队列



}