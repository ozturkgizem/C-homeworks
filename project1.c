#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define N 10
#define M 50000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char karakter;
	int secenek,tercih;
		   
			
	printf("************<<<<<<MENU>>>>>>************\n");
	printf("\n");
	printf("A.Siralama algoritmasi seciniz.\nB.Tum siralama algoritmalarini karsilastiriniz.\n");
    scanf("%c",&karakter);

	if(karakter=='A'|| karakter=='a')
	{
    	printf("1.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Shell sort\n");
    	scanf("%d",&secenek);
    	printf("Siralama sekli\n1-Kucukten buyuge\n2-Buyukten Kucuge\n");
    	scanf("%d",&tercih);
    	
		//RANDOM SAYI URETME(1-100)
		//srand(time(0)) islevini kullanmamin nedini atanan çekirdek degerin
		//her seferinde farkli olmasi ve atanan random sayilarin 
		//her seferinde farkli deger atanmasidir.
	   int i,rastgele;
	   int a[10];
	   srand(time(NULL));
	   for(i=0;i<10;i++)
	   {
	   	rastgele=(rand()%100 +1);
	   	a[i]=rastgele;
	   }
	   for(i=0;i<10;i++)
	   {
	   	printf("%d\t",a[i]);
	   }
	   printf("\n");
	   ///////////////////////////////
    	
        if(secenek==1)
        {
            //Bubble sort(kabarcik siralama)
            
            //kucukten buyuge
            if(tercih==1)
            {
            int i,k,temp;
            for(i=0;i<10;i++)
            	for(k=0;k<9;k++)
            	
            		if(a[k]>a[k+1])
            		{
            			temp=a[k];
            			a[k]=a[k+1];
            			a[k+1]=temp;
					}
				
				for(i=0;i<10;i++)
				printf("%d\t",a[i]);
			
            }
           //buyukten kucuge
		    if(tercih==2)
	        {
            int i,k,temp;
            for(i=0;i<10;i++)
            	for(k=0;k<9;k++)
            	
            		if(a[k]<a[k+1])
            		{
            			temp=a[k];
            			a[k]=a[k+1];
            			a[k+1]=temp;
					}
				
				for(k=0;k<10;k++)
				printf("%d\t",a[k]);            
            
		    
	        }
	    }
		
		if(secenek==2)
		{
			//Selection sort(secme siralamasi)
			
			//kucukten buyuge
			if(tercih==1)
			{
			int i,j,k,enk,temp;
			for(i=0;i<10;i++)
			{
				enk=i;
				for(j=i;j<10;j++)
				{
					if(a[j]<a[enk])
					enk=j;
				}
				   
		         	temp=a[i];
		        	a[i]=a[enk];
			        a[enk]=temp;	
			}
			for(k=0;k<10;k++)
			printf("%d\t",a[k]);
			
		   
	    	}
			
			//buyukten kucuge
			if(tercih==2)
		{
			int i,j,k,enb,temp;
			for(i=0;i<10;i++)
			{
				enb=i;
				for(j=i;j<10;j++)
				{
					if(a[j]>a[enb])
					enb=j;
				}
			        temp=a[i];
			        a[i]=a[enb];
			        a[enb]=temp;				
            }
			for(k=0;k<10;k++)
			printf("%d\t",a[k]);
		    
    	}
        }
		
		if(secenek==3)
		{
			//Insertion sort
			
			//kucukten buyuge
			if(tercih==1)
		{
			
			int i,k,indis;
			for(i=1;i<10;i++)
			{
				indis=a[i];
				for(k=i;k>0 && a[k-1]>indis;k--)
				{
					a[k]=a[k-1];
				}
				a[k]=indis;
			}
			for(i=0;i<10;i++)
			printf("%d\t",a[i]);
    	}
			//buyukten kucuge
			if(tercih==2)
		{
			
			int i,k,indis;
			for(i=1;i<10;i++)
			{
				indis=a[i];
				for(k=i;k>0 && a[k-1]<indis;k--)
				{
					a[k]=a[k-1];
				}
				a[k]=indis;
			}
			for(i=0;i<10;i++)
			printf("%d\t",a[i]);			
		}
	}
		if(secenek==4)
		{
			//Shell sort
			
			//kucukten buyuge
			if(tercih==1)
			{
	            int temp,i,j,aralik;
                for(aralik=N/2; aralik>0; aralik/=2)
                {
                    for (i=aralik; i<N; i+=1)
                    {
                        temp = a[i];
                        for (j=i; j>=aralik ; j-=aralik)
                        {
                            if(temp <a[j-aralik]){
                            	a[j]=a[j-aralik];
							}
							else 
							{
								break;
							}
                        }
                    a[j]=temp;
                    }
                }
                for(i=0;i<N;i++)
                printf("%d\t",a[i]);
			}
		
			//buyukten kucuge
			if(tercih==2)
			{
	            int temp,i,j,aralik;
                for(aralik=N/2; aralik>0; aralik/=2)
                {
                    for (i=aralik; i<N; i+=1)
                    {
                        temp = a[i];
                        for (j=i; j>=aralik ; j-=aralik)
                        {
                            if(temp >a[j-aralik]){
                            	a[j]=a[j-aralik];
							}
							else 
							{
								break;
							}
                        }
                    a[j]=temp;
                    }
                }
                for(i=0;i<N;i++)
                printf("%d\t",a[i]);
			}
		}			
	}

			
	//B SECENEGI SECILDIYSE;
	
	if(karakter=='B'|| karakter=='b')
	{
		//random sayi uretme
	    int i,a[50000],rastgele2;
	    srand(time(NULL));
	    for(i=0;i<50000;i++)
        {	
		    rastgele2=(1+rand()%200000);
            a[i]=rastgele2;
            
		}
    	printf("50000 sayi atandi.\n");
    	
		//sure yazdirma
        time_t start,end;
    	
		time(&start);
		//Bubble sort
            int k,temp;
            for(i=0;i<50000;i++)
            {
            	for(k=0;k<49999;k++)
            	{
            		if(a[k]>a[k+1])
            		{
            			temp=a[k];
            			a[k]=a[k+1];
            			a[k+1]=temp;
					}
				}
			}
    	time(&end);
    	printf("Bubble sort %f saniyede hesaplandi.\n",difftime (end,start));
    	
    	time(&start);
		//Selection sort
			int j,enk;
			for(i=0;i<50000;i++)
			{
				enk=i;
				for(j=i;j<50000;j++)
				{
					if(a[j]<a[enk])
					enk=j;
				}
			temp=a[i];
			a[i]=a[enk];
			a[enk]=temp;	
	    	}
		time(&end);
		printf("Selection sort %f saniyede hesaplandi.\n",difftime(end,start));
			
		//Insertion sort(araya sokma)
		time(&start);
			for(i=0;i<50000;i++)
			{
				temp=a[i];
				for(k=i;k>0 && a[k-1]>temp;k--)
				{
					a[k]=a[k-1];
				}
				a[k]=temp;
			}
	    time(&end);
	    printf("Insertion sort %f saniyede hesaplandi.\n",difftime(end,start));
	    
	    //Shell sort(kabuk siralama)
	    time(&start);
	    int aralik;
        for(aralik=M/2; aralik>0; aralik/=2)
                for(aralik=N/2; aralik>0; aralik/=2)
                {
                    for (i=aralik; i<N; i+=1)
                    {
                        temp = a[i];
                        for (j=i; j>=aralik ; j-=aralik)
                        {
                            if(temp <a[j-aralik]){
                            	a[j]=a[j-aralik];
							}
							else 
							{
								break;
							}
                        }
                    a[j]=temp;
                    }
                }
		    time(&end);
	        printf("Shell sort %f saniyede hesaplandi.\n",difftime(end,start));		    	
	
	}	
	return 0;
}
