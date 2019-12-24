#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct{
	char tenDoVat[20];
	int TL, GT, PA;
}DoVat;

DoVat* ReadFile(int *w, int *n)
{
	FILE *f = fopen("CaiBalo1.inp", "r");
	fscanf(f, "%d", w); // doc trong luong ba lo
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f))
	{
		fscanf(f, "%d%d", &dsdv[i].TL, &dsdv[i].GT);
		fgets(dsdv[i].tenDoVat, 20, f);
		dsdv[i].tenDoVat[strlen(dsdv[i].tenDoVat)-1] = '\0';
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i + 1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void Swap(DoVat &x, DoVat &y)
{
	DoVat temp = x;
	x = y;
	y = temp;
}

void Sort(DoVat *dsdv, int n)
{
	for(int i = 0;i < n; i++)
	{
		for(int j = n-1; j > i; j--)
		{
			float DGJ = (float)dsdv[j].GT / dsdv[j].TL;
			float DGJ_1 = (float)dsdv[j -1].GT / dsdv[j - 1].TL;
			if(DGJ > DGJ_1)
			{
				Swap(dsdv[j], dsdv[j - 1]);
			}
		}
	}
}

void InDs(DoVat* dsdv, int n, int w)
{
	printf("%d\n", w);
	int TongTL = 0;
	int TongGT = 0;
	for(int i = 0;i < n; i++)
	{
		printf("%d-----%d-----%s: PA: %d\n", dsdv[i].TL, dsdv[i].GT, dsdv[i].tenDoVat, dsdv[i].PA);
		TongTL += dsdv[i].PA*dsdv[i].TL;
		TongGT += dsdv[i].PA*dsdv[i].GT;
	}
	printf("TongTL = %d, TongGT = %d", TongTL, TongGT);
}

void Greed(DoVat* dsdv, int n, int w)
{
	for(int i = 0; i < n; i++)
	{
		dsdv[i].PA = w/dsdv[i].TL;
		w = w - dsdv[i].PA*dsdv[i].TL;
		
	}
}
int main()
{
	int w;
	int n;
	DoVat *dsdv = ReadFile(&w, &n);
	Sort(dsdv, n);
	Greed(dsdv, n, w);
	InDs(dsdv, n, w);
	return 0;
}
