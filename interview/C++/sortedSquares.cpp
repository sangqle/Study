#include <iostream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &A)
{
    vector<int> squares;
    auto left = A.begin();
    auto right = --A.end();

    while (left <= right)
    {
        if (abs(*left) > abs(*right))
        {
            squares.insert(squares.begin(), (int)pow(*left, 2));
            ++left;
        }
        else
        {
            squares.insert(squares.begin(), (int)pow(*right, 2));
            --right;
        }
    }
    // cout << *right << endl;
    return squares;
}

int main()
{
    vector<int> A{-4, -1, 0, 3, 10};
    vector<int> output = sortedSquares(A);
    for (int x : output)
    {
        cout << x << endl;
    }
}