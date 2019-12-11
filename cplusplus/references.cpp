#include <iostream>
using namespace std;
int main()
{

    string food = "Pizza";
    int a = 1;
    float b = 2.0;
    bool c = true;

    cout << &food <<endl;
    cout << &b <<endl;
    cout << &c;
    return 0;
}