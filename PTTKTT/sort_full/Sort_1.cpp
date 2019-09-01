
#include <stdio.h>
typedef int keytype;
typedef float typeOther;
typedef struct
{
	keytype key;
	typeOther otherkey;
}record;
void Swap(record &x, record &y)
{
	record tem = x;
	x = y;
	y = tem;
}
void selectionSort(record a[], int n)
{
	for(int i = 0; i < n -1; i++)
	{
		keytype min = a[i].key;
		int idMin = i;
		for(int j = i+1; j < n; j++)
		{
			if(min > a[j].key)
			{
				min = a[j].key;
				idMin = j;
			}

		}
		Swap(a[i], a[idMin]);
	}
}
int main()
{
	FILE *f = fopen("dayso.inp", "r");
	int n;
	record a[100];
	fscanf(f, "%d", &n);
	for(int i = 0; i < n ; i++)
	{	
	  fscanf(f, "%d", &a[i].key);
	}
	selectionSort(a, n);
	for(int i = 0; i < n; i++)
	{
		printf("%d\n", a[i].key);
	}
	return 0;
}
