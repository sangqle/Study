/*// priority queue.
#include<iostream>
using namespace std;
#define Max 15
typedef int ElementType;
typedef struct PriorityQueue{
	ElementType data[Max];
    int Last;	
};
// initialize priority rows.
void MakeNull(PriorityQueue &q)
{
	q.Last = 0;
}
//function return priority.
int Priority(ElementType x) // đơn giản độ ưu tiên là x. còn nâng cao hơn có thể có hàm khác
{
	return x;
}
// function inserst a element in priority queue.
void Inserst(ElementType x, PriorityQueue &q)
{
	if(q.Last>Max)
	{
		cout<<"priority is full";
		return;
	}
	else // dãy thu?t này cung tuong d?i hay. ch?p nh?p du?c
	{
		q.data[++q.Last] = x; // ban d?u th?ng 1 dã có nên while ? du?i ch? ch?y d?n 2
		int i = q.Last; // b?t d?u t? v? trí hiên t?i duy?t d? d?0t nso dúng v? trí
        while(i>1 && Priority(q.data[i])<Priority(q.data[i/2])) // Thứ tự ưu tiên của thằng Con nhỏ hơn thứ tự ưu tiên của Cha nó.
        {
        	// điều kiện của vòng while i/2 vì dù con trái con phải tìm cha đều là i/2 như nhau.
            ElementType Temp = q.data[i]; // tiến hành đổi chổ bình thường.
            q.data[i] = q.data[i/2];
            q.data[i/2] = Temp;
            i=i/2;
        }
	}
}
// function deletemin
int Deletemin(PriorityQueue &q)
{
	int mindata; // giá trị để return ra của hàm
	int j; // biến để thay thế đổi chổ.
		if(q.Last==0){
			cout<<"queue empty";
		}
		else
		{
			mindata = q.data[1]; // hàng ưu tiên theo cách cài đặt này thì thằng nhỏ nhất bao giờ cung là X[1];
			q.data[1] = q.data[q.Last--]; // gán thằng đầu tiên là thằng cuối xong giảm Last xuống.
			int i = 1;
			while(i<=q.Last/2) // theo lý thuyết chỉ cần chạy phân nữa cây thôi, theo ý tưởng.
			{
				// tìm nút bé nhất của hai con để thay thế.
				if((q.data[2*i]<q.data[2*i+1])||(2*i==q.Last)) j=2*i; // chổ này chưa hiểu lắm.
				    	else j=2*i+1;
				if (Priority(q.data[i])>Priority(q.data[j])) // đổi chổ để đưa thằng lớn xuống dưới.
				{
     			        int temp=q.data[i];
     			        q.data[i]=q.data[j];
     			        q.data[j]=temp; 	
     			        i=j; // bắt đầu lại tại mức mới lại tiếp tục xet
    		    }
    		    else break; // đến vị trí không đổi được nữa.
		    }
		}
		return mindata;
}
void Input(PriorityQueue &q)
{
	MakeNull(q);
	int n; // so luong phan tu
	cin>>n;
	int x;
	for(int i = 0; i < n; i++)
	{
         cin>>x;
         Inserst(x, q);
	}
}
void Output(PriorityQueue q)
{
	for(int i = 1; i <= 11; i++)
	{
		cout<<i<<" :"<<q.data[i]<<endl;
	}
}
int main()	
{
freopen("in3.txt", "r", stdin);
freopen("out3.txt", "w", stdout);
PriorityQueue q;
Input(q);
Output(q);
cout<<"\nDatamin: "<<Deletemin(q);
cout<<endl;
Output(q);
cout<<"\nDatamin: "<<Deletemin(q);
cout<<endl;
Output(q);
cout<<"\nDatamin: "<<Deletemin(q);
cout<<endl;
Output(q);
// xóa tất cả phần tử
cout<<"Xoa tung phan tu;"<<endl;
while(q.Last>0)
     cout<<Deletemin(q)<<endl;

	system("pause");
	return 0;
}

// le quang sang
*/


//BAITAP10------------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include<math.h>
using namespace std;
#define Max 15
int Bienthaydoi = 0;
typedef struct Diem
{
	int x;
	int y;
};
typedef Diem ElementType; // định nghĩa kiểu dữ liệu là kiểu điểm
typedef struct PriorityQueue{
	ElementType data[Max];
    int Last; // chỉ số.	
};
float Priority(Diem d) // đồng thời hàm trả về độ ưu tiên.
{
	return sqrt(pow(d.x,2)+pow(d.y,2));
}
void MakeNull(PriorityQueue &q)
{
	q.Last = 0;
}
// function inserst a element in priority queue.
void Inserst(ElementType x, PriorityQueue &q)
{
	if(q.Last>Max)
	{
		cout<<"priority is full";
		return;
	}
	else // dãy thu?t này cung tuong d?i hay. ch?p nh?p du?c
	{
		q.data[++q.Last] = x; // ban d?u th?ng 1 dã có nên while ? du?i ch? ch?y d?n 2
		int i = q.Last; // b?t d?u t? v? trí hiên t?i duy?t d? d?0t nso dúng v? trí
        while(i>1 && Priority(q.data[i])<Priority(q.data[i/2])) // Thứ tự ưu tiên của thằng Con nhỏ hơn thứ tự ưu tiên của Cha nó.
        {
        	// điều kiện của vòng while i/2 vì dù con trái con phải tìm cha đều là i/2 như nhau.
            ElementType Temp = q.data[i]; // tiến hành đổi chổ bình thường.
            q.data[i] = q.data[i/2];
            q.data[i/2] = Temp;
            i=i/2;
        }
	}
}
// function deletemin
ElementType Deletemin(PriorityQueue &q)
{
	ElementType mindata; // giá trị để return ra của hàm
	int j; // biến để thay thế đổi chổ.
		if(q.Last==0){
			cout<<"queue empty";
		}
		else
		{
			mindata = q.data[1]; // hàng ưu tiên theo cách cài đặt này thì thằng nhỏ nhất bao giờ cung là X[1];
			q.data[1] = q.data[q.Last--]; // gán thằng đầu tiên là thằng cuối xong giảm Last xuống.
			int i = 1;
			while(i<=q.Last/2) // theo lý thuyết chỉ cần chạy phân nữa cây thôi, theo ý tưởng.
			{
				// tìm nút bé nhất của hai con để thay thế.
				if((Priority(q.data[2*i])<Priority(q.data[2*i+1]))||(2*i==q.Last)) j=2*i; // chổ này chưa hiểu lắm.
				    	else j=2*i+1;
				if (Priority(q.data[i])>Priority(q.data[j])) // đổi chổ để đưa thằng lớn xuống dưới.
				{
     			        ElementType temp=q.data[i];
     			        q.data[i]=q.data[j];
     			        q.data[j]=temp; 	
     			        i=j; // bắt đầu lại tại mức mới lại tiếp tục xet
    		    }
    		    else break; // đến vị trí không đổi được nữa.
		    }
		}
		return mindata;
}
Diem NhapDiem(Diem d)
{
	int x, y;
	cin>>x>>y;
	d.x = x;
	d.y = y;
	return d;
}
void XuatDiem(Diem d)
{
	cout<<"("<<d.x<<","<<d.y<<")"<<endl;
}
void Input(PriorityQueue &q)
{
	MakeNull(q);
	int n; // so luong phan tu
	cin>>n;
	Bienthaydoi = n;
	ElementType x;
	for(int i = 0; i < n; i++)
	{
		 Diem d;
         Inserst(NhapDiem(d), q);
	}
}
void Output(PriorityQueue q)
{
	for(int i = 1; i <= Bienthaydoi; i++)
	{
		XuatDiem(q.data[i]);
	}
}
int main()
{
freopen("in4.txt", "r", stdin);
freopen("out4.txt", "w", stdout);
	PriorityQueue q;
	Input(q);
	Output(q);
	cout<<"deliemin tung phan tu::"<<endl;
	while(q.Last>0)
		XuatDiem(Deletemin(q));
	return 0;
}
