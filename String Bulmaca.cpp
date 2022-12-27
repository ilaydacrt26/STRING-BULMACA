#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
main(){
	
	int n;
	
	srand(time(NULL));
	
	char dizi[4][10]={"SOFTWARE","COMPILER","FLUTTER","REACT"};
	
	do
	{
		printf("N degerini giriniz: ");
		scanf("%d",&n);
	}while(n<=8);
	
	char matris[n][n];
	
	int secim=0;
	
	printf("\n");
	
	printf("Klasik yerlestirme icin 1 numarayi seciniz..\n");
	printf("Capraz yerlestirme icin 2 numarayi seciniz..\n\n");
	
	while(secim!=1 && secim!=2)
	{
		printf("Yerlestirme isleminizi seciniz(1 ya da 2): ");
		scanf("%d",&secim);
	}
	
	int random1[4],random2[4];
	
	int a=0,b=0;
	
	int sayac=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			matris[i][j]='0';
		}
	}
	
	do
	{
		random1[0]=1+rand()%4;
		random1[1]=1+rand()%4;
		random1[2]=1+rand()%4;
		random1[3]=1+rand()%4;
	}while(random1[0]==random1[1] || random1[0]==random1[2] || random1[0]==random1[3] || random1[1]==random1[2] || random1[1]==random1[3] || random1[2]==random1[3]);
	
	do
	{
		random2[0]=1+rand()%4;
		random2[1]=1+rand()%4;
		random2[2]=1+rand()%4;
		random2[3]=1+rand()%4;
	}while(random2[0]==random2[1] || random2[0]==random2[2] || random2[0]==random2[3] || random2[1]==random2[2] || random2[1]==random2[3] || random2[2]==random2[3]);
	
	int uzunluk[4];
	
	//y�n[1]=sag	y�n[2]=sol	y�n[3]=asagi	y�n[4]=yukari
	//y�n[1]=�apraz sa� yukar�	 y�n[2]=�apraz sol yukar�	y�n[3]=�apraz sa� a�a�� y�n[4]=�apraz sol a�a��
	
	for(int i=0;i<4;i++)
	{
		uzunluk[i]=strlen(dizi[i]);
	}
	
	if(secim==1)
	{
		while(sayac<4)
		{
			if(random1[sayac]==1)
			{
				devam:
				//sa� i�in 
				
				a=rand()%n;
				b=rand()%(n-uzunluk[sayac]+1);	
				
				for(int j=0;j<uzunluk[sayac];j++)
				{
					if(matris[a][b+j]!=dizi[sayac][j] && matris[a][b+j]!='0')
					{
						goto devam;
					}
				}
				
				for(int j=0;j<uzunluk[sayac];j++)
				{
					matris[a][b+j]=dizi[sayac][j];
				}
			}
			
			else if(random1[sayac]==2)
			{
				devamet: 
				//sol i�in
				
				a=rand()%n;
				b=rand()%(n-uzunluk[sayac]+1)+uzunluk[sayac]-1;
				
				for(int i=0;i<uzunluk[sayac];i++)
				{
					if(matris[a][b-i]!=dizi[sayac][i] && matris[a][b-i]!='0')
					{
						goto devamet;
					}
				}
				
				for(int i=0;i<uzunluk[sayac];i++)
				{
					matris[a][b-i]=dizi[sayac][i];
				}
				
			}
			
			else if(random1[sayac]==3)
			{
				ilerle:
				//yukar� i�in
				
				a=rand()%(n-uzunluk[sayac]+1)+uzunluk[sayac]-1;
				b=rand()%n;
				
				for(int k=0;k<uzunluk[sayac];k++)
				{
					if(matris[a-k][b]!=dizi[sayac][k] && matris[a-k][b]!='0')
					{
						goto ilerle;	
					}	
				}
				
				for(int k=0;k<uzunluk[sayac];k++)
				{
					matris[a-k][b]=dizi[sayac][k];	
				}	
			}
			
			else if(random1[sayac]==4)
			{
				ileri:
				//a�a�� i�in
				
				a=rand()%(n-uzunluk[sayac]+1);
				b=rand()%n;
				
				for(int l=0;l<uzunluk[sayac];l++)
				{
					if(matris[a+l][b]!=dizi[sayac][l] && matris[a+l][b]!='0')
					{
						goto ileri;		
					}	
				}
				
				for(int l=0;l<uzunluk[sayac];l++)
				{
					matris[a+l][b]=dizi[sayac][l];	
				}	
			}
			sayac++;
		}
	}
	
	else if(secim==2)
	{
		while(sayac<4)
		{
			if(random2[sayac]==1)
			{
				devamm: 
				//�apraz sa� yukar� i�in
				
				a=rand()%(n-uzunluk[sayac]+1)+uzunluk[sayac]-1;
				b=rand()%(n-uzunluk[sayac]+1);
				
				for(int i=0;i<uzunluk[sayac];i++)
				{
					if(matris[a-i][b+i]!=dizi[sayac][i] && matris[a-i][b+i]!='0')
					{
						goto devamm;
					}
				}
				
				for(int i=0;i<uzunluk[sayac];i++)
				{
					matris[a-i][b+i]=dizi[sayac][i];
				}
			}
			
			else if(random2[sayac]==2)
			{
				devamett:
				//�apraz sol yukar�
				
				a=rand()%(n-uzunluk[sayac]+1)+uzunluk[sayac]-1;
				b=rand()%(n-uzunluk[sayac]+1)+uzunluk[sayac]-1;
				
				for(int j=0;j<uzunluk[sayac];j++)
				{
					if(matris[a-j][b-j]!=dizi[sayac][j] && matris[a-j][b-j]!='0')
					{
						goto devamett;
					}
				}
				
				for(int j=0;j<uzunluk[sayac];j++)
				{
					matris[a-j][b-j]=dizi[sayac][j];
				}
			}
			
			else if(random2[sayac]==3)
			{
				burasi:
				//�apraz sa� a�a��
				
				a=rand()%(n-uzunluk[sayac]+1);
				b=rand()%(n-uzunluk[sayac]+1);
				
				for(int k=0;k<uzunluk[sayac];k++)
				{
					if(matris[a+k][b+k]!=dizi[sayac][k] && matris[a+k][b+k]!='0')
					{
						goto burasi;
					}
				}
				
				for(int k=0;k<uzunluk[sayac];k++)
				{
					matris[a+k][b+k]=dizi[sayac][k];
				}
			}
			
			else if(random2[sayac]==4)
			{
				burayagel: 
				//�apraz sol a�a��
				
				a=rand()%(n-uzunluk[sayac]+1);
				b=rand()%(n-uzunluk[sayac]+1)+uzunluk[sayac]-1;
				
				for(int l=0;l<uzunluk[sayac];l++)
				{
					if(matris[a+l][b-l]!=dizi[sayac][l] && matris[a+l][b-l]!='0')
					{
						goto burayagel;		
					}		
				}
				
				for(int l=0;l<uzunluk[sayac];l++)
				{
					matris[a+l][b-l]=dizi[sayac][l];	
				}	
			}
			sayac++;
		}
	}
	
	int sayi; 
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matris[i][j]=='0')
			{
				sayi=1+rand()%3;
				if(sayi==1)
				{
					matris[i][j]='1';	
				}
				else if(sayi==2)
				{
					matris[i][j]='2';	
				}
				else if(sayi==3)
				{
					matris[i][j]='3';	
				}	
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<n;j++)
		{
			if(matris[i][j]==0){
			matris[i][j]=1+rand()%3;
			}
			printf("\t%c",matris[i][j]);
		}
		printf("\n\n");
	}
	return 0;
}
