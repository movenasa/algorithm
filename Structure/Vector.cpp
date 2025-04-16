// vector 的自己实现与 调用（动态数组）

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;

// 自己实现Vector
class MyList
{
    private:
        int *arr ;
        int capacity = 10; // 目前容量
        int arrSize = 0; // 目前数组长度
        int extentRatio = 2; // 每次扩充的倍数
    public:
        // 构造方法
        MyList()
        {
            arr = new int[capacity];
        }
        // 析构方法
        ~MyList() // 自动释放
        {
            delete [] arr;
        }
        // 下面的都是一些常用方法
        int capacitys()
        {
            return capacity;
        }
        // 返回长度
        int size()
        {
            return arrSize;
        }
        int getNumber(int index)
        {
            if(index < 0 || index >= size()) throw out_of_range("索引越界");
            return arr[index];
        }
        void set(int index, int num)
        {
            if(index < 0 || index >= size()) throw out_of_range("索引越界");
            arr[index] = num;
        }
        void extendCapacity()
        {
            int Capacity = capacity * extentRatio;
            int *tmp = arr;
            arr  = new int[Capacity];
            for(int i = 0; i < size(); i ++)
                arr[i] = tmp[i];
            delete[] tmp;
            capacity = Capacity;
        }
        // 在末尾添加一个元素
        void add(int number)
        {
            if(size() == capacity) extendCapacity();
            arr[size()] = number;
            arrSize ++;
        }
        // 在任何位置插入一个元素
        void insert(int index, int number)
        {
            if(index < 0 || index >=size()) throw out_of_range("索引越界");
            else
            {
                if(size() + 1 == capacity) extendCapacity();
                for(int i = size() - 1; i >= index; i --)
                    arr[i + 1] = arr[i];
                    arr[index] = number;
                    arrSize ++;
            }
        }
        void remove(int index)
        {
            if(index < 0) throw out_of_range("索引越界");
            for(int i = index; i < size(); i ++)
                arr[i] = arr[i + 1];
                arrSize --;
        }
        vector<int> setVector()
        {
            // vector<int> arrs;
            vector<int> arrs(size());
            for(int i = 0 ; i < size() ; i++)
                arrs[i] = arr[i];
            return arrs;
        }
};


int main()
{
    // version 1. 调用实现

    // 创建
    vector<int> num;
    vector<int> nums = {1,2,5,4};
    int size = 10;
    
    // 插入元素 本质上也是按照序号后面填入进去
    for(int i = 0; i < size; i ++) num.push_back(i);


    // 遍历 两种方式
    for(int i = 0; i < num.size(); i ++) cout << num[i] << ' ';
    printf("\n");
    for(int nu : num) cout << nu << ' ';
    printf("\n");
    // 排序
    // 补充知识 使用 *iterator 可以获取迭代器指向的值 ; &(*iterator) 可以获取迭代器指向元素的地址
    sort(nums.begin(), nums.end());
    printf("%p", &(*num.begin()));
    cout << endl;
    // 插入元素
    num.insert(num.begin() + 3, 6);
    for(int nu : num) cout << nu << ' ';
    cout << endl;
    // 删除元素
    num.erase(num.begin() + 3);
    for(int nu : num) cout << nu << ' ';
    cout << endl;
    // 拼接列表
    num.insert(num.end(), nums.begin(), nums.end());
    for(int nu : num) cout << nu << ' ';
    cout << endl; 

    // 自己实现的vector
    MyList myself = MyList();
    myself.add(1);
    myself.add(2);
    myself.insert(1, 4);
    for(int i = 0; i < 10; i ++) myself.add(i);
    myself.remove(0);
    vector<int> see = myself.setVector();
    for(int i = 0; i < myself.size(); i++)
        cout << myself.getNumber(i) << ' ';
    return 0;
}