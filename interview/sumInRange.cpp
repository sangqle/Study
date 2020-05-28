#include <iostream>
#include <vector>
#include <map>
using namespace std;
int checkInRange(int pos, std::vector<std::vector<int>> queries)
{
    int count = 0;
    for (vector<int> x : queries)
    {
        if (x.at(0) <= pos && pos <= x.at(1))
            count++;
    }
    return count;
}
int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries)
{
    int N = 1000000007;
    int prefixSum[nums.size() + 1] = {}; // initialize prefix array with zero numbers.
    int sum = 0;
    for (int i = 1; i < nums.size() + 1; i++)
    {
        sum += nums.at(i - 1);
        prefixSum[i] = sum;
    }
    sum = 0;
    for (vector<int> x : queries)
    {
        sum += prefixSum[x.at(1) + 1] - prefixSum[x.at(0)];
    }

    if (sum < 0)
        sum = (sum % N + N) % N;
    else
        sum = sum % N;
    return sum;
}

int main()
{
    vector<int> nums{3, 0, -2, 6, -3, 2};
    vector<vector<int>> queries{
        {0, 2},
        {2, 5},
        {0, 5}};
    int sum = sumInRange(nums, queries);
    cout << sum;
}