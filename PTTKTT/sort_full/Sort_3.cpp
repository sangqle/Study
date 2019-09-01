#include<stdio.h>
typedef int typeKey;
typedef float otherKey;
typedef struct{
	typeKey key;
	otherKey other;
}record;

void Swap(record &x, record &y)
{
	record temp = x;
	x = y;
	y = temp;
}
void bubble_Sort(record a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = n -1; j > i; j--)
		{
			if(a[j].key < a[j -1].key)
			{
				Swap(a[i], a[j]);
			}
		}
	}
}
int main()
{
	FILE *f = fopen("dayso.inp", "r");
	int n;
	record a[100];
	fscanf(f, "%d", &n);
	for(int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &a[i].key);
	}
	bubble_Sort(a, n);
	for(int i = 0; i < n; i++)
	{
		printf("%d\n", a[i].key);
	}
	return 0;
}
