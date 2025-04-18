#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

struct BlistNode{
    int val;
    BlistNode *next;
    BlistNode(int x): val(x), next(nullptr) {}
};


class Stack{
    private:
        BlistNode *element;
        int Size;
        
    public:
        // 初始化方法
        Stack()
        {
            element = nullptr;
            Size = 0;
        }
        ~Stack()
        {
            // 遍历链表节点，释放所有元素
            for(BlistNode *p = element; p != nullptr; p = p->next)
                    delete [] p;
        }
        // push 元素入栈
        void push(int x)
        {
            // 保证顶部元素始终为element
            BlistNode *ins = new BlistNode(x);
            ins->next = element;
            element = ins;
            Size ++;
        }
        // 判断栈元素是否为空
        bool IsEmpty()
        {
            if(!Size) return true;
            return false;
        }
        // 返回栈的长度
        int StSize()
        {
            return Size;
        }
        // 访问栈顶元素
        int peek()
        {
            if(IsEmpty()) throw out_of_range("栈为空");
            return element->val;
        }
        // 弹出栈顶元素
        void top()
        {
            if(IsEmpty()) throw out_of_range("栈为空");
            printf("栈顶元素为 :%d ", element->val);
            BlistNode *ins = element->next;
            element = ins;
            Size--;
            printf("栈长度:%d\n", Size);
        }
            /* 将 List 转化为 Array 并返回 */
        vector<int> toVelctor() {
            BlistNode *node = element;
            vector<int> res(StSize());
            for (int i = res.size() - 1; i >= 0; i--) {
                res[i] = node->val;
                node = node->next;
            }
            return res;
        }
};

// 数组实现一个栈
const int N = 100010;
int cnt;
class ArrayStack{
    private :
        int St[N];
        int top;
    public :
        ArrayStack()
        {
            top = 0;
        }
        void push(int x)
        {
            St[++top] = x;
        }
        void pop()
        {
            int peek = St[top];
            top--;
            return;
        }
        int query()
        {
            return St[top];
        }
        bool isEmpty()
        {
            if(!top) return true;
            else return false;
        }
};

int main()
{
    // 使用 stl的 stack 库
    // 定义
    stack<int> st;
    // 插入元素
    for(int i = 0; i < 10; i ++) st.push(i);
    // 访问栈顶元素
    cout << st.top() << endl;
    // 弹出栈顶元素
    st.pop(); // 注意没有返回值
    cout << endl;
    // 判断栈是否为空
    bool empty = st.empty();
    cout << empty;

    // 使用链表去实现 stack 可以把链表头视为栈顶
    // 这样每次入栈就是往链表头插入一个元素，出栈就是访问链表头元素，并删除，栈判断是否为空可以通过栈的长度来定
    Stack sts = Stack();
    for(int i = 0; i < 10; i ++) sts.push(i);
    int x  = sts.peek();
    cout << x;
    for(int i = 0; i < 10; i ++) sts.top();

    // 利用链表去实现 stack
    ArrayStack t = ArrayStack();
    cin >> cnt;
    while(cnt--)
    {
        string op;
        int x;
        cin >> op;
        if(op == "push")
        {
            cin >> x;
            t.push(x);
        }
        else if (op == "pop")
        {
            t.pop();
        }
        else if(op == "query")
        {
            int ans = t.query();
            cout << ans << endl;
        }
        else if(op == "empty")
        {
            if(t.isEmpty())
            {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }


}

