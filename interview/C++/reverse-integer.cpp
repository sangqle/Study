#include <iostream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

int reverse(int x)
{
    vector<int> arr;
    while (abs(x) > 0)
    {
        int remain = x % 10;
        arr.push_back(remain);
        x = x / 10; // stop when x < 10
    }
    long output = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        output += arr.at(i) * pow(10, n - i - 1);
        if (output > INT_MAX)
            return 0;
    }
    return (int)output;
}
int reverse2(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int pos = x % 10;
        x = x / 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10) && pos > 7)
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pos < -8))
            return 0;
        rev = rev * 10 + pos;
    }
    return rev;
}

int main()
{
    int result = reverse2(153);
    cout << result;
}