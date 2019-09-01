#include<stdio.h>
#include<string.h>
#include<malloc.h>
//1 dinh nghi cau truc DoVat
#define Max 100
typedef struct{
	char tenDoVat[20];
	float TL, GT;
	int PA, SL;
}DoVat;
//2 Khai Bao Cac bien toan cuc
DoVat *dsdv;
int n;
int x[Max]; // danh sach phuong an tot nhat
float w, CT, TGT, GiaLNTT, TLConLai;
//3 Doc file
DoVat* ReadFile(float *w, int *n)
{
	FILE *f = fopen("CaiBalo2.inp", "r");
	fscanf(f, "%f", w); // doc trong luong ba lo
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f))
	{
		fscanf(f, "%f%f%d", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL);
		fgets(dsdv[i].tenDoVat, 20, f);
		dsdv[i].tenDoVat[strlen(dsdv[i].tenDoVat)-1] = '\0';
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i + 1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

int min(int a, int b){
	return (a<b)? a:b;
}
//4 Hoan Vi
void Swap(DoVat &x, DoVat &y)
{
	DoVat temp = x;
	x = y;
	y = temp;
}
//5 Sap xep theo don gia
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
//6 thiet lap cac thong so cho nut GOC
void Init()
{
	TLConLai = w;
	TGT = 0.0;
	CT = TLConLai*dsdv[0].GT/dsdv[0].TL;
	GiaLNTT = 0;
}

//7 Ghi nhan ky lua . thiet lap phuong an cho mang x[Max]
void GhiNhanPA()
{
	// ghi nhap gia lon nhat tam thoi va cap nhat phuong an
	if(TGT > GiaLNTT) // trong hop di den nut cuoi rois
	{
		GiaLNTT = TGT;
		for(int i = 0; i < n; i++)
			{
				dsdv[i].PA = x[i];
			}
	}
	
}
//8 Try thu cac truogn hop cua nhanh can
void Try(int i)
{
	for(int j = min(TLConLai/dsdv[i].TL, dsdv[i].SL); j >= 0; j--) // so do vat duoc chon
	{
		TGT = TGT + j*dsdv[i].GT;
		TLConLai -= j*dsdv[i].TL;
		CT = TGT + TLConLai*(dsdv[i+1].GT/dsdv[i+1].TL); // TKConLai*DG (vat ke tiep)
		if(CT > GiaLNTT)
		{
			x[i] = j;
			if(i==n-1 || TLConLai == 0)
			{
				GhiNhanPA();
			}
			else Try(i + 1);
			
		}
		
		// Quay lui xet cat truong hop con lai
		x[i] = 0; // tra lai 
		TGT -= j*dsdv[i].GT;
		TLConLai += j*dsdv[i].TL;
	}
}
//9 in danh do vat
void InDs(DoVat* dsdv, int n, int w)
{
	printf("%d\n", w);
	float TongTL = 0;
	float TongGT = 0;
	printf("%-5s | %-20s %-5s %-5s %-5s \n", "PA", "Ten", "TL", "GT", "SL");
	for(int i = 0;i < n; i++)
	{
		printf("%-5d | %-20s %-5.f %-5.f %-5d %-5.1f \n", dsdv[i].PA, dsdv[i].tenDoVat, dsdv[i].TL, dsdv[i].GT, dsdv[i].SL,dsdv[i].GT/ dsdv[i].TL );
		TongTL += dsdv[i].PA*dsdv[i].TL;
		TongGT += dsdv[i].PA*dsdv[i].GT;
	}
	printf("TongTL = %.1f, TongGT = %.1f", TongTL, TongGT);
}


int main()
{
	dsdv = ReadFile(&w, &n);
	Init();
	Sort(dsdv, n);
	Try(0);
	InDs(dsdv, n, w);
	return 0;
}
