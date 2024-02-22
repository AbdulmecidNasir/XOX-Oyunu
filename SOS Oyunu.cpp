/* SOS 101
oyununu 2 kisilik oynayacak sekilde C dilinde yaziniz
*/

#include <stdio.h>

void matrisGoster(char dizi[3][3])
{
	for(int satir = 0; satir < 3; satir++)
	{
		for(int sutun = 0; sutun < 3; sutun++)
		{
			if(dizi[satir][sutun] == ' ')
			{
				printf("\t-  ");
			}
			else
			{
				printf("\t%c  ",dizi[satir][sutun]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

int kazananKontrol(char dizi[3][3], char oyuncu)
{
	int kazandi = 0;
	//Yatay Kontrol
	for(int satir = 0; satir < 3; satir++)
	{
		if(dizi[satir][0] == oyuncu && dizi[satir][1] == oyuncu && dizi[satir][2] == oyuncu)
		{
			kazandi = 1;
			break;
		}
	}
	//Dikey Kontrol
	for(int sutun = 0; sutun < 3; sutun++)
	{
		if(dizi[sutun][0] == oyuncu && dizi[sutun][1] == oyuncu && dizi[sutun][2] == oyuncu)
		{
			kazandi = 1;
			break;
		}
	}
	//Capraz Kontrol
	if(dizi[0][0] == oyuncu && dizi[1][1] == oyuncu && dizi[2][2] == oyuncu)
	{
		kazandi = 1;
	}
	else if(dizi[0][2] == oyuncu && dizi[1][1] == oyuncu && dizi[2][2] == oyuncu)
	{
		kazandi = 1;
	}
	return kazandi;
}


int main(void)
{
	char dizi[3][3];
	char oyuncu,kazananoyuncu= ' ';
	int satir,sutun,oyuncusatir,oyuncusutun,oyunsonuc,sayi;
	for(satir=0;satir<3;satir++)
	{
		for(sutun=0;sutun<3;sutun++)
		{
			dizi[satir][sutun] = ' ';
		}
	}
		printf("\t--------Merhaba Bu XOX oyunu-------\n");
		printf("\n\tBu Oyunda 1. oyuncu \'x\' 2. oyuncu \'o\' dir\n");
	
	oyuncu= 'x';
	while(1)
	{
		matrisGoster(dizi);
		printf("\nNereye \'%c\' karakterini nereye koymak istiyorsunuz?\n", oyuncu);
		scanf("%d %d",&oyuncusatir,&oyuncusutun);
	
		if(dizi[oyuncusatir][oyuncusutun]== ' ')
		{
			dizi[oyuncusatir][oyuncusutun] = oyuncu;
			//oyun bitti mi kontrol
			if(kazananKontrol(dizi,oyuncu))
			{
				kazananoyuncu = oyuncu;
				break;
			}
		
			
			
			oyuncu = (oyuncu == 'x') ? 'o' : 'x';
			
		}
		
	}
	matrisGoster(dizi);
	
	if(kazananoyuncu!= ' ')
	{
		printf("\t\'%c\' Karakterli oyuncu oyunu kazandi, tebrikler, muhtesemsin :)",kazananoyuncu);
	}
	else
	{
		printf("Oyun bitti kimse kazanamadi.");
	}
	
	
	return 0;
}