#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x == 0)
        return true;
    vector<int> arr;
    while (x != 0)
    {
        arr.push_back(x % 10);
        x = x / 10;
    }
    int n = arr.size();
    for (int i = 0; i <= n / 2; i++)
    {
        if (arr.at(i) != arr.at(n - i - 1))
            return false;
    }
    return true;
}

// 1 2 1 3 2
// 121%10 = 12
// pos = 1

int main()
{
    bool rs = isPalindrome(0);
    cout << rs;
}