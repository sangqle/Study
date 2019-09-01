#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long mang[7]; // mang nay de luu gia tri cua chuoi s cho de tinh.

int main()
{
	int dem = 0;
	string s;
	getline(cin, s);
	int tong = 0; // tong 3 so dau.
	int tong1 = 0; // tong 3 so cuoi.
	// gan gia tri cua chuoi s vo mang
	for(int i = 0; i < s.length();i++)
	{
		mang[i] = s[i]-'0';
	}
	// tinh tong 3 so dau va 3 so cuoi.
	for(int i = 0; i < s.length(); i++)
	{
		if(i<3) tong+=(s[i]-'0');
		else tong1+=(s[i]-'0');
	}
	if(tong == tong1) // truogn hop da bang nhau
	{
		cout<<0;
		return 0;
	}
	// neu tong dau nho hon tong cuoi cho 3 vong for chay 3 so dau.
	if(tong<tong1)
	{
		//sap xep 3 so dau lai de chay ra duoc so lan thay so it nhat.
		sort(mang, mang+3); // sap xep lai 3 so dau.
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j <= 9; j++)
			{
			   mang[i] = j;
			   if(mang[0]+mang[1]+mang[2]==mang[3]+mang[4]+mang[5])
			    {
			    	cout<<dem+1;
			    	return 0;
				}
			}
			dem++;
		}
	}
	else
	{
		sort(mang+3, mang+s.length()); // sap xep lai 3 so cuoi.
		for(int i = 3; i < s.length(); i++)
		{
			for(int j = 0; j <= 9; j++)
			{
			   mang[i] = j;
			   if(mang[0]+mang[1]+mang[2]==mang[3]+mang[4]+mang[5])
			    {
			    	cout<<dem+1;
			    	return 0;
				}
			   
			}
			dem++;
		}
    }
//	system("pause");
	return 0;
}
