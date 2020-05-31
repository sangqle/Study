#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map[nums.at(i)])
        {
            return nums.at(i);
        }
        else
            map[nums.at(i)]++;
    }
}

int main()
{
    vector<int> nums{1, 3, 4, 2, 2};
    int rs = findDuplicate(nums);
    cout << rs;
}