#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int length = nums.size();
    int max = nums.at(0);
    int sum = nums.at(0);
    for (int i = 1; i < nums.size(); i++)
    {
        sum = std::max(nums.at(i), nums.at(i) + sum);
        if (sum > max)
        {
            max = sum;
        }
    }
    return max;
}

int main()
{
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int rs = maxSubArray(arr);
    cout << rs;
}