#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    // int *p = (int *)malloc(sizeof(int));
    // *p = 10;
    // printf("%p %p %d\n", p, &p, *p);
    // p = (int *)malloc(sizeof(int));
    // *p = 15;
    // printf("%p %p %d\n", p, &p, *p);
    int *arr;
    // arr = (int *)malloc(4 * sizeof(int));
    arr = (int *)malloc(10 * sizeof(int));
    arr[0] = 10;
    arr[4] = 20;
    // *arr = 100;
    int *a = (int *)malloc(sizeof(int));
    int b = 10;
    a = &b;
    cout << a;

    // cout << arr[0];

    return 0;
}