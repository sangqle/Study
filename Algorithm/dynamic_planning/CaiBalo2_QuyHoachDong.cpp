#include<stdio.h>
#include<malloc.h>
#include<string.h>
// typedef struct
typedef struct
{
	char tenDv[20];
	int TL, GT, SL;
	int PA;
}DoVat;

typedef int bang[50][100]; // 50 do vat va 100 trong luong

// reader file
DoVat *ReadFile(int *n, int *w)
{
	FILE *f = fopen("CaiBalo2.inp", "r");
	fscanf(f, "%d", w);
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f))
	{
		fscanf(f, "%d%d%d", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL);
		fgets(dsdv[i].tenDv, 20, f);
		dsdv[i].tenDv[strlen(dsdv[i].tenDv) - 1] = '\0';
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat) * (i + 1));
	}
	*n = i;
	fclose(f);
    return dsdv;
}
// print list
void Inds(DoVat *dsdv, int n, int w)
{
	printf("%d\n", w);
	int TongGT = 0;
	int TongTL = 0;
	for(int i = 0;i < n; i++)
	{
		printf("%d  %d  %d  %d Ten: %s\n", dsdv[i].TL, dsdv[i].GT, dsdv[i].SL, dsdv[i].PA, dsdv[i].tenDv);
		TongTL += dsdv[i].PA*dsdv[i].TL;
		TongGT += dsdv[i].PA*dsdv[i].GT;
	}
	printf("TongTL: %d, TongGT: %d", TongTL, TongGT);
}

int min(int a, int b)
{
	return (a<b) ? a : b;
}
void createTable(DoVat *dsdv, int w, int n, bang x, bang f)
{
	// dien du lieu cho dong dau tieng
	for(int v = 0; v <= w; v++)
	{
		x[0][v] = v/dsdv[0].TL;
		f[0][v] = x[0][v]*dsdv[0].GT;
	}
	for(int k = 1; k < n; k++)
	{
		for(int v = 0; v <= w; v++)
		{
			//int fmax = f[k-1][v] ;
			int fmax = 0;
			int xmax = 0;
			for(int xk = 0; xk <= min(dsdv[k].SL, v/dsdv[k].TL); xk++)
			{
				if(f[k-1][v - xk*dsdv[k].TL] + xk*dsdv[k].GT > fmax)
				{
					fmax = f[k-1][v - xk*dsdv[k].TL] + xk*dsdv[k].GT;
					xmax = xk;
				}
			}
			x[k][v] = xmax;
			f[k][v] = fmax;
		}
	}
	// dien du lieu cho dong thu 2
}
void findTable(DoVat *dsdv, int n, int w, bang x)
{
	for(int k = n -1; k >= 0; k--)
	{
		dsdv[k].PA = x[k][w];
		w -= dsdv[k].PA*dsdv[k].TL;
	}
}
int main()
{
	int w, n;
	bang x, f;
	DoVat *dsdv = ReadFile(&n, &w);
	createTable(dsdv, w, n, x, f);
	findTable(dsdv	, n, w, x);
	Inds(dsdv, n , w);
}
