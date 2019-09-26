#include<iostream>
using namespace std;
#define B 9 // hàm băm có 9 butket.
/*typedef string ElementType;*/
typedef int ElementType;
typedef struct Node{
    ElementType data;
    Node* pNext; // con trỏ phần tử của danh sách của mỗi butket.
};
typedef Node* Positon; // có định nghĩa hay không cũng không quan trọng
typedef Positon Dictionary[B]; // khai báo mảng con trỏ chứa mảng băm.
// function makenull
void MakeNull(Dictionary &D)
{
	for(int i =0; i < B; i++) // vòng lặp chạy tất cả butket cho con trỏ chỉ mục trỏ NULL
	  D[i] = NULL;
}
// function Hash
/*int Hash(ElementType X)
{
	int sum = 0;
	for(int i = 0; i < X.length(); i++) // sum string
		sum+=X[i];
	return sum%B; // hàm băm tuyến tính bình thường
}*/
int Hash(ElementType X)
{
	return X%B;
}
// function check Member.
int Member(ElementType X, Dictionary D)
{
    int bucket = Hash(X); // xác định butket sau đó kiểm tra list đó đến cuối list
   for(Node* k = D[bucket]; k!=NULL; k=k->pNext) // element in list.
    	{
    		if(k->data==X) return 1;
    	}
    return 0; // does not exist.
}
void Inserst(ElementType X, Dictionary &D)
{
	int bucket = Hash(X);
	if(!Member(X,D))
	{

            Node*p = new Node; // tạo con trỏ p để giữ địa chỉ của đầu danh sách lại sau đó ta cập nhât lại thằng D[butket];
            p = D[bucket];
            D[bucket] = new Node; // allocates new memory
            D[bucket]->data = X;
            D[bucket]->pNext = p; // link with pointer at bouning
     }
}
void Input(Dictionary &D)
{
     MakeNull(D);
     int n;
     cin>>n;
     ElementType X;
     for(int i = 0; i < n;i++)
     {
         cin>>X;
         Inserst(X, D);
     }
}
void Output(Dictionary D)
{
	for(int i = 0; i < B; i++)
	{
		if(D[i]!=NULL)
		{
			for(Node* k = D[i]; k!=NULL; k=k->pNext)
			{
				cout<<k->data<<" ";
			}
		}
		cout<<endl;
	}
}
void Delete(ElementType X, Dictionary &D)
{
	int bucket = Hash(X);
	if(!Member(X,D)) // Does not exist.
	{
		cout<<"Does not exist!!!\n";
		return;
	}
	else
	{
		if(D[bucket]->data==X) // first element.
		{
			D[bucket]=D[bucket]->pNext; // chổ này không cần hủy ô nhớ vì khi trỏ nơi khác vùng nhớ tự động hủy.
		}
		else // in list
		{
            for(Node* k = D[bucket]; k!=NULL; k=k->pNext) // chạy trong danh sách/.
            {
            	if(k->pNext->data==X) // ta cho nó trỏ đi trước một con trỏ để thuận tiện cho việc xóa node sau này.
            	{
            		Node* p = new Node;
            		p=k->pNext;
            		k->pNext = p->pNext;
            		delete(p);
            		return;
            	}
            }
		}
	}
}

int main()
{
	// đây ta cho đọc file luôn cho nó nhanh khỏi mất thời gian test. chỉ cần test thôi không cần nhập
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	Dictionary D;
	Input(D);
	cout<<endl;
	Output(D);
	//cout<<"after delet:\n";
	//Delete("o", D);
	//cout<<endl;\
	//Output(D);
	system("pause");
	return 0;
}

//---------------------------------------------------------------------
