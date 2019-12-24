#include <stdio.h>

typedef int keytype;
typedef float orthertype;
typedef struct
{
	keytype key;
	orthertype ortherfield;
} recordtype;

void swap(recordtype &x, recordtype &y)
{
	recordtype temp;
	temp = x;
	x = y;
	y = temp;
}

int findpivot(recordtype a[], int i, int j)
{
	keytype firstkey;
	int k = i + 1;		 // bat dau chay tu phan tu thu i + 1;
	firstkey = a[i].key; // i la first key
	while ((k <= j) && a[k].key == firstkey)
		k++;
	if (k > j)
		return -1;
	if (a[k].key > firstkey)
		return k;
	return i;
}

int partition(recordtype a[], int i, int j, keytype pivot)
{
	int L, R;
	L = i;
	R = j;
	while (L <= R)
	{
		while (a[L].key < pivot)
			L++;
		while (a[R].key >= pivot)
			R--;
		if (L < R)
			swap(a[L], a[R]);
	}
	return L;
}

void quicksort(recordtype a[], int i, int j)
{
	keytype pivot;
	int pivotindex, k;
	pivotindex = findpivot(a, i, j);
	if (pivotindex != -1)
	{
		pivot = a[pivotindex].key;
		k = partition(a, i, j, pivot);
		quicksort(a, i, k - 1);
		quicksort(a, k, j);
	}
}

int main()
{
	recordtype a[100];
	int i, n;
	FILE *f = fopen("dayso.inp", "r");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(f, "%d", &a[i]);
	}
	quicksort(a, 0, n - 1);
	for (i = 0; i < n; i++)
	{
		printf("<%d", a[i]);
	}
}
