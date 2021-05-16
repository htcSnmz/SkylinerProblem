#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int bitis_noktasi_bul(int **dizi, int boyut);
int baslangic_noktasi_bul(int **dizi,int boyut);
int yukseklik_bul(int **dizi,int boyut);

int m = 10, diziboyut = 0, n, i, j;

int main()
{
	int **elemanlar = (int**)malloc(m*sizeof(int*)), cevre, toplam_yukseklik = 0;
	for (n = 0 ; n < m ; n++)
	{
		elemanlar[n] = (int*)malloc(3*sizeof(int));
	}
	printf("Genislik,Yukseklik ve Yerdeki Pozisyonu girin: (Cikmak icin genisligi -1 girin)\n");
	for ( i = 0 ; i < m ; i++)
	{
		scanf("%d", &elemanlar[i][0]);
		if (elemanlar[i][0] == -1)
		{
			break;
		}
		diziboyut++;
		scanf("%d%d", &elemanlar[i][1], &elemanlar[i][2]);
		if (i == (m - 2))
		{
			m = 2 * m;
			int **yedek = elemanlar;
			yedek = (int**)realloc(elemanlar,m);
			if (yedek == NULL) 
			{
				printf("Yer ayrilamadi");
			}
			else
			{
				elemanlar = yedek;
				for (n = n ; n < m ; n++)
			{
				elemanlar[n] = (int*)malloc(3*sizeof(int));
			}
			}
			
		}
	}
	cevre = (bitis_noktasi_bul(elemanlar,diziboyut) - baslangic_noktasi_bul(elemanlar,diziboyut));
	cevre += yukseklik_bul(elemanlar,diziboyut);
	printf("Girilen binalarin toplam cevresi = %d",cevre);
	for(i = 0; i < diziboyut; i++)
	{
		free(elemanlar[i]);
	}
	free(elemanlar);
	return 0;
}

int bitis_noktasi_bul(int **dizi, int boyut)
{
	int bitis_noktasi = dizi[0][0] + dizi[0][2];
	for (i=1 ; i<boyut ; i++)
	{
		if (bitis_noktasi < dizi[i][0] + dizi[i][2])
		{
			bitis_noktasi = dizi[i][0] + dizi[i][2];
		}
	}
	return bitis_noktasi;
}

int baslangic_noktasi_bul(int **dizi,int boyut)
{
	int baslangic_noktasi = dizi[0][2];
	for (i = 1; i < boyut; i++)
	{
		if (dizi[i][2] < baslangic_noktasi)
		{
			baslangic_noktasi = dizi[i][2];
		}
	}
	return baslangic_noktasi;
}
int yukseklik_bul(int **dizi,int boyut)
{
	int k = bitis_noktasi_bul(dizi,boyut) , toplam_yukseklik = 0;
	int yukseklik[k+2];
	yukseklik[k+1] = 0;
	for (i=0 ; i<=k ; i++)
	{
		yukseklik[i] = 0;
		for ( j=0; j<boyut; j++)
		{
			if (dizi[j][2] <= i && i < dizi[j][2] + dizi[j][0])
			{
				if (dizi[j][1] > yukseklik[i])
				{
					yukseklik[i] = dizi[j][1];
				}
			}
		}
	}
	for(i=0 ; i<=k ; i++)
	{
		toplam_yukseklik += fabs(yukseklik[i] - yukseklik[i+1]);
	}
	return toplam_yukseklik;
}
