#include<iostream>
using namespace std;
#define B 9
typedef string ElementType;
/*typedef int ElementType;*/
#define Deleted "deleted" // the value was deleted.
#define Empty "Empty"
typedef ElementType Dictionary[B]; // khai báo mảng con trỏ chứa mảng băm.
// function makenull
void MakeNull(Dictionary &D)
{
	for(int i =0; i < B; i++)
		  D[i] = Empty;
}
// function Hash same hashTable	
int Hash(ElementType X)
{
	int sum = 0;
	for(int i = 0; i < X.length(); i++) // sum string
		sum+=X[i];
	return sum%B;
}
// function check Member.
int Locate(ElementType X, Dictionary D)
{
	int bucket = Hash(X);
	int i = 0;
	while((i<B) && (D[(i+bucket)%B]!=X) && (D[(i+bucket)%B]!=Empty)) // chiến lượt băm lại tuyến tính.
		i++;
	return (i+bucket)%B;
}
int Locate1(ElementType X, Dictionary D) // tìm vị trí thích @hợp để thêm một phần tử.
{
    int bucket = Hash(X);
    int i;
    for(i = 0; i<B && D[(i+bucket)%B]!=X && D[(i+bucket)%B]!=Empty && D[(i+bucket)%B]!=Deleted; i++); // ở đây nhớ đấu chẩm ;
    	return (bucket+i)%B;
}
/*int Locate(ElementType X, Dictionary D)
{
	int bucket = Hash(X);
	int i = 0;
	while((i<B) && (D[(i*i+bucket)%B]!=X) && (D[(i*i+bucket)%B]!=Empty)) // chiến lượt băm lại tuyến tính.
		i++;
	return (i*i+bucket)%B;
}
int Locate1(ElementType X, Dictionary D) // tìm vị trí thích @hợp để thêm một phần tử.
{
    int bucket = Hash(X);
    int i;
    for(i = 0; i<B && D[(i*i+bucket)%B]!=X && D[(i*i+bucket)%B]!=Empty && D[(i*i+bucket)%B]!=Deleted; i++); // ở đây nhớ đấu chẩm ;
    	return (bucket+i*i)%B;
}*/
int Menber(ElementType X, Dictionary D)
{
	return D[Locate(X,D)]==X;
}
void Inserst(ElementType X, Dictionary &D)
{
	int bucket;
	if(D[Locate(X,D)]!=X) // chưa có phần tử đó trong bảng băm.
	{
         bucket = Locate1(X, D); // tim bucket để đặt nó vô bảng băm.
         if(D[bucket]==Empty||D[bucket]==Deleted)
         {
         	D[bucket]=X;
         }
	}
	else cout<<"\nBang bam day\n";
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
        cout<<D[i]<<endl;
}
void Delete(ElementType X, Dictionary &D)
{
	int bucket = Locate(X,D);
	if(D[bucket]==X)
		D[bucket] = Deleted; // check deleted.
}
int main()
{
	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
	Dictionary D;
	Input(D);
	cout<<endl;
	Output(D);
	Delete("a", D);
	Delete("e", D);
	Delete("f", D);

	cout<<"\nafter delet:\n";
	Output(D);
	Inserst("x", D);
	//Inserst("y", D);
	cout<<"\nAfter insert\n";
	Output(D);
	
	system("pause");
	return 0;
}
