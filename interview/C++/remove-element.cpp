#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    int n = nums.size();
    for (auto i = nums.begin(); i != nums.end(); ++i)
    {
        if (*i == val)
        {
            nums.erase(i);
            i--;
        }
    }
    return nums.size();
}
int main()
{
    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int len = removeElement(nums, 2);
    for (int i = 0; i < len; i++)
    {
        cout << nums.at(i) << endl;
    }
}