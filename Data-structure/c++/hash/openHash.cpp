#include <iostream>
using namespace std;
#define B 10
struct Node
{
	int data;
	Node *next;
};

typedef Node *Position;
typedef Position Dictionary[B];

int h(int x)
{
	return x % 11;
}
void make_null_set(Dictionary &D)
{
	for (int i = 0; i < B; i++)
		D[i] = NULL;
}

int member(int x, Dictionary D)
{
	Position p = D[h(x)];
	while (p->next != NULL)
	{
		if (p->data == x)
			return 1;
		else
			p = p->next;
	}
	return 0;
}

void insert_set(int x, Dictionary &D)
{
	int bucket;
	Position p;
	if (!member(x, D))
	{
		bucket = h(x);
		D[bucket] = (Node *)malloc(sizeof(Node));
		p = D[bucket];
		D[bucket]->data = x;
		D[bucket]->next = p;
	}
}

void init_set(int arr[], int len, Dictionary &D)
{
	printf("%ld", sizeof(arr));
	for (int i = 0; i < len; i++)
	{
		// printf("1 ");
		printf("%d\n", arr[i]);
	}
	// insert_set(*(arr + i), D);
}
int main()
{
	Dictionary D;
	int a[] = {1, 2, 3, 3, 10, 11, 9, 8, 7, 20};
	int len = sizeof(a) / sizeof(int);
	make_null_set(D);
	init_set(a, len, D);
	// for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	// {
	// 	printf("%d", a[i]);
	// }
	// 	printf("d: %d\n", D[i]->data);
	// printf("end");
	return 0;
}
