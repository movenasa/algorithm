// 双向队列
#include<cstdio>
#include<iostream>
#include<deque>

using namespace std;

int main()
{
    // 使用 stl 的双向队列
    deque<int> de;
    for(int i = 0; i < 5; i ++) de.push_back(i);
    for(int i = 0; i < 5; i ++) de.push_front(i);
    cout << de.size() << endl;
    cout << de.front() << endl;
    cout << de.back() << endl;
    cout << de.empty() << endl;
    de.pop_front(); // 弹出队首的元素
    de.pop_back(); // 弹出队尾的元素
    // 遍历
    for(auto it = de.begin(); it != de.end(); it ++)
        cout << *it << ' ';
        cout << endl;
    for(deque<int>::iterator it = de.begin(); it != de.end(); it ++)
        cout << *it << ' ';

    return 0;
}
