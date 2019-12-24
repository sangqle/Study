#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define Max 100
typedef struct{
	char tenDv[20];
	float TL, GT;
	int SL;
	int PA;
}DoVat;
DoVat *dsdv;
int n; // so luong do vat
int x[Max]; // luu phuong an tot nhat tam thoi
float w; // trong luong cai ba lo
float CT; // luu tru can tren
float TGT; // tong gia tri cat vat lua chon tai mot nut
float GiaLNTT; // lu gia lon nhat tam thoi
float TLConLai; // luu trong luong con lai cua cai ba lo
// ??c danh sách ?? v?t t? file
DoVat* ReadFile(float *w, int* n)
{
	FILE *f = fopen("CaiBalo3.inp", "r");
	fscanf(f,"%f", w);
	DoVat* dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f))
	{
		fscanf(f,"%f%f", &dsdv[i].TL, &dsdv[i].GT);
		fgets(dsdv[i].tenDv, 20, f);
		dsdv[i].tenDv[strlen(dsdv[i].tenDv)-1] = '\0';
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
	}
	*n= i;
	fclose(f);
	return dsdv;
}

// Sap xep danh sach do vat theo don gia giam dan
void swap(DoVat &x1, DoVat &x2)
{
	DoVat temp = x1;
	x1 = x2;
	x2 = temp;
}
void BubbleSort(DoVat *dsdv, int n)
{
	for(int i = 0; i < n; i++) // s? b??c th?c hi?n
	{
		for(int j = n-2; j >= i+1; j--) // ch?y tu cuoi len neu gia lon hon thi cho no noi len tren
		{
			float DGJ = dsdv[j].GT/dsdv[j].TL;
			float DGJ_1 = dsdv[j-1].GT/dsdv[j-1	].TL;
			if(DGJ > DGJ_1)
			{
				swap(dsdv[j], dsdv[j-1]);
			}
		}
	}
}
// in ra mang hinh danh sach do vat
void InDSDV(DoVat *dsdv ,int n, float W){
	int i;
	float TongTL = 0.0, TongGT = 0.0;
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	printf("|%-3s|%-20s|%-9s|%-9s|%-9s|%-9s|\n", "STT", " Ten Do Vat","T.Luong", "Gia Tri", "Don Gia", "P. An");
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	for(i=0;i<n;i++){
		printf("|%-3d",i+1); // Sô th? t? các ?? v?t
		printf("|%-20s",dsdv[i].tenDv);
		printf("|%-9.1f",dsdv[i].TL);
		printf("|%-9.1f",dsdv[i].GT);
		printf("|%-9.1f",dsdv[i].GT/dsdv[i].TL);
		printf("|%-9d|\n",dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	printf("Trong luong cua ba lo= %9.1f\n",w);
	printf("Tong trong luong= %9.1f, Tong gia tri= %9.1f\n", TongTL,
	TongGT);
}
// Tinh Dai cac dai luong o nut goc
void init()
{
	TLConLai = w;
	TGT = 0.0;
	CT = TLConLai*dsdv[0].GT/dsdv[0].TL;
	GiaLNTT = 0.0;
}
// ghi nhận phương án tốt nhất tạm thời
void ghiKyLuc()
{
	if(TGT > GiaLNTT)
	{
		GiaLNTT = TGT;
		for(int i = 0; i < n; i++)
		{
			dsdv[i].PA = x[i];
		}
	}
	
}

void Try(int i)
{
   int j = TLConLai/dsdv[i].TL;
   if(j > 1)
   {
   	j = 1;
   }
   for(j ; j >= 0; j--)
   {
   	TGT = TGT + j*dsdv[i].GT;
   	TLConLai = TLConLai - j*dsdv[i].TL;
   	CT = TGT + TLConLai*(dsdv[i+1].GT/dsdv[i+1].TL);
   	if(CT > GiaLNTT)
   	{
   		//Ghi nhan ket qua tam thoi
   		x[i] = j;
   		if(i==n-1 || TLConLai == 0)
   		{
   			ghiKyLuc();
   		}
   		else Try(i+1) ; // xet con cua no;
   	}
	   // Quan lui de xet con lai khoi phuc lai cai gi tru thi cong tro lai vo
	   // cai gi cong thi tru nguo lai
	  x[i] = 0;
	  TGT = TGT - j*dsdv[i].GT;
	  TLConLai = TLConLai + j*dsdv[i].TL;
   }
}
int main()
{
	dsdv = ReadFile(&w, &n);
	BubbleSort(dsdv, n);
	init();
	Try(0);
	InDSDV(dsdv, n, w);
	printf("le quang sang");
	free(dsdv);
	return 0;
}
