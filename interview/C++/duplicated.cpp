#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fast_duplicateds(int arr[], int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    int count = 0;
    for (auto i : map)
    {
        if (i.second > n / 2)
        {
            count = 1;
            return i.first;
        }
    }
    if (count == 0)
        return -1;
}
int duplicateds(int *a, int n)
{

    // sort array with nlogn
    sort(a, a + n);
    int max = 0;
    int count = 1;
    int maxValue = a[0];

    int last = a[0];
    if (n == 1)
        return a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] == last)
        {
            count++;
        }
        else
        {
            count = 1;
            last = a[i];
        }
        if (count > max)
        {
            max = count;
            maxValue = a[i];
            if (max > (n / 2))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int a[] = {1, 1, 2, 3, 4, 3, 3, 3, 3, 2, 3};
    // int hash[] = {0, 3, 2, 0, 0, 0, 0, 4, 2, 0};
    // [1, 1, 1, 2, 2, 8, 9, 9, 9]
    int n = sizeof(a) / sizeof(a[0]);
    // int isMajority = duplicateds(a, n);
    int isMajority = fast_duplicateds(a, n);
    cout << isMajority;
}