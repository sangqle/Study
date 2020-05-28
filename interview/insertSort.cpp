#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
void insert_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}
int main()
{
    int a[] = {5, 6, 2, 2, 10, 12, 9, 10, 9, 3};
    int n = sizeof(a) / sizeof(a[0]);
    insert_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}