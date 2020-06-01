#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int kthLargestElement(std::vector<int> v, int k)
{
    sort(v.begin(), v.end(), greater<int>());
    return v.at(k - 1);
}
int main()
{
    vector<int> nums{3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = kthLargestElement(nums, k);
    cout << result;
    return 0;
}