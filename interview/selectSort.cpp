#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    // int temp = a;
    // a = b;
    // b = temp;
    a = a + b;
    b = a - b;
    a = a - b;
}
void selectSort(int a[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        // cout << "min: " << minIndex << endl;
        if (i != minIndex)
            swap(a[i], a[minIndex]);
    }
}
int main()
{
    int a[] = {5, 6, 2, 2, 3, 10, 12, 9, 9, 3};
    int n = sizeof(a) / sizeof(a[0]);
    selectSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}