#include <stdio.h>
typedef int typeKey;
typedef float otherKey;
typedef struct
{
	typeKey key;
	otherKey other;
} record;

void Swap(record &x, record &y)
{
	record temp = x;
	x = y;
	y = temp;
}
void insert_Sort(record a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i;
		while (j > 0 && a[j].key < a[j - 1].key)
		{

			Swap(a[j], a[j - 1]);
			j--;
		}
	}
}
int main()
{
	FILE *f = fopen("dayso.inp", "r");
	int n;
	record a[100];
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &a[i].key);
	}
	insert_Sort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", a[i].key);
	}
	return 0;
}
