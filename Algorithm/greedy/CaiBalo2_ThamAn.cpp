#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct{
	char tenDv[20];
	float TL, GT;
	int SL;
	int PA;
}DoVat;

DoVat *ReadFile(float *w, int * n)
{
	FILE *f = fopen("CaiBalo2.inp", "r");
	fscanf(f, "%f", w);
	int i = 0;
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	while(!feof(f))
	{
		fscanf(f,"%f%f%d", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL);
		fgets(dsdv[i].tenDv, 20, f);
		dsdv[i].tenDv[strlen(dsdv[i].tenDv) -1 ] = '\0';
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i + 1));
	}
	*n  = i; // câp nhat so luong cho n
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
	for(int i = 0; i < n; i ++)
	{
		for(int j = n -1; j > i; j--)
		{
			float DGJ = dsdv[j].GT/dsdv[j].TL;
			float DGJ_1 = dsdv[j -1].GT/dsdv[j -1].TL;
			if(DGJ > DGJ_1)
			{
				Swap(dsdv[j], dsdv[j -1]);
			}
		}
	}
}

void InDs(DoVat *dsdv, int n, float w)
{
	float TongTL = 0.0;
	float TongGT = 0.0;
	printf("%.1f\n", w);
	for(int i = 0; i < n; i++)
	{
		printf("%.1f----%.1f----%d----%s, PA: %d\n", dsdv[i].TL, dsdv[i].GT, dsdv[i].SL, dsdv[i].tenDv, dsdv[i].PA);
		TongTL+= dsdv[i].PA*dsdv[i].TL;
		TongGT+= dsdv[i].PA*dsdv[i].GT;
	}
	printf("TongTL = %.2f, TongGT = %.2f", TongTL, TongGT);
	
}
int Min(int a, int b)
{
	return (a < b ? a : b);
}
void Greed(DoVat *dsdv, int n , float w)
{
	for(int i = 0; i < n; i++)
	{
		dsdv[i].PA = Min(w/dsdv[i].TL, dsdv[i].SL);
		w -= dsdv[i].PA*dsdv[i].TL;
	}
}
int main()
{
	int n;
	float w;
	DoVat* dsdv = ReadFile(&w, &n);
	Sort(dsdv, n);
	Greed(dsdv, n, w);
	InDs(dsdv, n, w);

	return 0;
}
