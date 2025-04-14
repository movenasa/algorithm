#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e6;
int arr[N], n;

// 核心操作： 每次操作之后，当前第i个位置的元素是最小的
// 例如： i = 0， 外层循环走完一遍之后，arr[0]是最小的
// 例如： i = 1， 外层循环走完一遍之后，arr[1]是第二小的
void select_sort(int *arr, int n)
{
    for(int i = 0; i < n ; i ++)
        for(int j = i + 1; j < n ; j++)
        {
            if(arr[j] < arr[i])
            {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
}

// 核心操作， 从最底部开始，逐次向上比较
// 每次完事之后，浮上来的元素是最小的
void bubble_sort(int *arr, int n)
{
    for(int i = 0; i < n ; i ++) // 从标号0开始，需要交换的次数，逐次递减的
        for(int j = n - 1; j > i; j --)
            {
                if(arr[j] < arr[j - 1])
                {
                    swap(arr[j], arr[j - 1]);
                }
            }
}

// test case
// 5
// 3 1 2 4 5
// void quicksort(int *arr, int l, int r)
// {
//     if(l >= r) return ;
//     int p = l, q = r; // 0 , 4
//     int mid = (l + r) >> 1; // 2
//     while(p < mid || q > mid)
//     {
//         while(arr[p] < arr[mid]) p++;
//         while(arr[q] > arr[mid]) q--;
//         if(p <= mid && q >= mid) swap(arr[p], arr[q]);
//     }
//     for(int i = 0 ; i < n; i ++)
//     {
//         printf("%d ", arr[i]);
//     }
//     // printf("%d", p);
//     return;
//     // printf("\n");

//     // 2 1 3 4 5
//     quicksort(arr, l, p);
//     quicksort(arr, p + 1, r);
    
    
// }

void quicksort(int *arr, int l, int r)
{
    if(l >= r) return ;
    int p = l - 1, q = r + 1;
    int povit = arr[(l + r) >> 1];
    while(p < q)
    {
        do p++; while(arr[p] < povit);
        do q--; while(arr[q] > povit);
        if(p < q)
        {
            swap(arr[p], arr[q]);
        }
    }
    quicksort(arr, l, q);
    quicksort(arr, q + 1, r);
    
}




int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n ; i++) scanf("%d", &arr[i]);
    // select_sort(arr, n);
    quicksort(arr, 0, n - 1);
    for(int i = 0; i < n ; i++) printf("%d ", arr[i]);
        
    return 0;
}