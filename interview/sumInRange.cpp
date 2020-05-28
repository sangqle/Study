#include <iostream>
#include <vector>
#include <map>
using namespace std;
int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries)
{
    int N = 1000000007;
    int sum = 0;
    map<int, int> map;
    for (vector<int> x : queries)
    {
        for (int i = x.at(0); i <= x.at(1); i++)
        {
            map[i]++;
        }
    }
    for (auto x : map)
    {
        sum += (nums.at(x.first) * x.second);
        // cout << x.first << " " << x.second << endl;
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