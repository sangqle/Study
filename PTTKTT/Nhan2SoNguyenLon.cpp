#include<iostream>
#include<string>
using namespace std;

string Mult(string x, string y)
{
	
	int ngang = x.length()+y.length();
	int doc = x.length()+y.length();
	int array[ngang][doc]; // khai bao bang chua kq tinh
	for(int i = 0; i < ngang; i++)
	{
		for(int j = 0; j < doc; j++)
		{
			array[i][j] = 0;
		}
		cout<<endl;
	}
	for(int i = y.length()-1; i >= 0; i--)
	{
		for(int j = x.length()-1; j >= 0; j--)
		{
			array[y.length()-1-i][i+j+1] = (x[j]-'0')*(y[i]-'0');
		}
	}
	
	// tinh tong theo tung cot

	
	for(int i = ngang; i >=0; i--)
	{
		int tong = 0;
	    for(int j = 0; j < y.length(); j++)
	    {
	    	tong+=array[j][i];
		}
		array[y.length()][i] = tong;
	}
	
	for(int i = ngang; i>=0; i--)
	{
		int du = array[y.length()][i]%10; // ra duoc phan du khi chia cho 10
		array[y.length()+1][i] = du;
		array[y.length()+1][i-1] = (array[y.length()][i]+array[y.length()][i+1])%10;
		
	}
	
	for(int i = 0; i < ngang; i++)
	{
		for(int j = 0; j < doc; j++)
		{
			cout<<array[i][j] <<"   ";
		}
		cout<<endl;
 }
	return "sang";
}
int main()
{

	Mult("123","123");
	//string str = "123";
	//cout<<str.length();
	return 0;
}
