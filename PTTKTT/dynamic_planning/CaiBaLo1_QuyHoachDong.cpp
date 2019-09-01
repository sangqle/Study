#include<stdio.h>
#include<malloc.h>
#include<string.h>
// typedef struct
typedef struct
{
	char tenDv[20];
	int TL, GT;
	int PA;
}DoVat;

typedef int bang[50][100]; // 50 do vat va 100 trong luong

// reader file
DoVat *ReadFile(int *n, int *w)
{
	FILE *f = fopen("CaiBalo1.inp", "r");
	fscanf(f, "%d", w);
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f))
	{
		fscanf(f, "%d%d", &dsdv[i].TL, &dsdv[i].GT);
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
		printf("%d----%d----%d----%s\n", dsdv[i].TL, dsdv[i].GT, dsdv[i].PA, dsdv[i].tenDv);
		TongTL += dsdv[i].PA*dsdv[i].TL;
		TongGT += dsdv[i].PA*dsdv[i].GT;
	}
	printf("TongTL: %d, TongGT: %d", TongTL, TongGT);

}
// create table
void createTable(DoVat *dsdv, int n, int w, bang x, bang f)
{
	int xMax;
	for(int v = 0; v <= w; v++)
	{
		x[0][v] = v/dsdv[0].TL;
		f[0][v] = x[0][v] * dsdv[0].GT; 
		//printf("///%d///",x[0][v] );
	}
	
	for(int k = 1; k < n; k++) // điền tất cả đồ vật còn lai
	{
		
		for(int v = 0; v <= w; v++)
		{
			
			//int fMax = f[k-1][v] ;
			int fMax = 0;
			for(int xk = 0; xk <= v/dsdv[k].TL; xk++)
			{
				if(f[k-1][v - xk*dsdv[k].TL] + xk*dsdv[k].GT > fMax)
				{
					fMax = f[k-1][v - xk*dsdv[k].TL] + xk*dsdv[k].GT;
					xMax = xk;
				}

			}
			x[k][v]  = xMax;
			f[k][v]  = fMax;
		}
	}
}
void findTable(DoVat *dsdv, int n, int w, bang x)
{
	int v = w;
	for(int i = n -1 ; i >= 0; i--)
	{
		dsdv[i].PA = x[i][v];
		printf(".....%d ", dsdv[i].PA);
		v -=dsdv[i].PA*dsdv[i].TL;
	}
}
void TraBang(DoVat *dsdv, int n, int W, bang X) {
   int k, V;
   V = W;
   for(k= n-1; k>=0; k--) {
      dsdv[k].PA = X[k][V];
      V = V - X[k][V] * dsdv[k].TL;
   }
}
int main()
{
	bang x, f;
	int w;
	int n;
	DoVat *dsdv = ReadFile(&n, &w);
	createTable(dsdv, n, w, x, f);
	findTable(dsdv, n, w, x);
	Inds(dsdv, n, w);
}
