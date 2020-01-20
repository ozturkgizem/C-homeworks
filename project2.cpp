#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma pack(1)

struct tarih{
	int gun;
	int ay;
	int yil;
};

struct ogrenci{
	int numara;
	char ad[25];
	char soyad[25];
	struct tarih dogTarihi;
	float matNotu;
	float fenNotu;
	float turNotu;
};

void ogrEkle(FILE *fp){
	    struct ogrenci ogrenci;
	    printf("-OGRENCI KAYDI-\n");
		printf("Ogrencinin numarasi: ");
	    scanf("%d",&ogrenci.numara);
    	printf("Ogrencinin adi: ");
    	scanf("%s",ogrenci.ad);
    	printf("Ogrencinin soyadi: ");
    	scanf("%s",ogrenci.soyad);
    	printf("Ogrencinin dogum tarihi(dd/mm/yy): ");
	    scanf("%d %d %d",&ogrenci.dogTarihi.gun,&ogrenci.dogTarihi.ay,&ogrenci.dogTarihi.yil);
	    printf("Matematik notu: ");
	    scanf("%d",&ogrenci.matNotu);
	    printf("Fen notu: ");
	    scanf("%d",&ogrenci.fenNotu);
	    printf("Turkce notu: ");
	    scanf("%d",&ogrenci.turNotu);
	    fseek(fp,0,SEEK_SET);
	    fwrite(&ogrenci,sizeof(ogrenci),1,fp);
	    printf("Kayit tamamlandi.\n");
}

void ogrSil(FILE *fp){
	struct ogrenci ogrenci;
	int no;
	printf("-OGRENCI SILME-\n");
	printf("Ogrencinin numarasi: ");
    scanf("%d",&no);
    int k;
    fseek(fp,0,SEEK_SET);
    k=ftell(fp)/sizeof(struct ogrenci);
	
	int i;
	for(i=0;i<k;i++){
	    fseek(fp,i,SEEK_CUR);
	    fread(&no,sizeof(no),1,fp);
		if(no==ogrenci.numara)
		{
			fseek(fp,i+1,SEEK_CUR);
		    struct ogrenci geciciOgrenci;
		    fread(&geciciOgrenci,sizeof(geciciOgrenci),1,fp);
            fseek(fp,i,SEEK_CUR);
    		fwrite(&geciciOgrenci,sizeof(geciciOgrenci),1,fp);  
		}	
	}
	
	if(k==ftell(fp)-sizeof(ogrenci)){
		printf("ogrenci silindi.");
	}
}

void ogrGuncelle(FILE *fp){
	struct ogrenci ogrenci;
	int no;
	printf("-OGRENCI GUNCELLEME-\n");
	printf("Ogrencinin numarasi: ");
    scanf("%d",&no);
    int k;
    k=ftell(fp);
	
	int i;
	for(i=0;i<k;i++){
	    fseek(fp,i,SEEK_CUR);
	    fread(&no,sizeof(no),1,fp);
		if(no==ogrenci.numara)
		{
			fseek(fp,i,SEEK_CUR);
    	    printf("-OGRENCI KAYDI\n-");
    		printf("Ogrencinin numarasi: ");
    	    scanf("%d",&ogrenci.numara);
        	printf("Ogrencinin adi: ");
        	scanf("%s",ogrenci.ad);
        	printf("Ogrencinin soyadi: ");
        	scanf("%s",ogrenci.soyad);
        	printf("Ogrencinin dogum tarihi(dd/mm/yy): ");
    	    scanf("%d %d %d",&ogrenci.dogTarihi.gun,&ogrenci.dogTarihi.ay,&ogrenci.dogTarihi.yil);
    	    printf("Matematik notu: ");
    	    scanf("%d",&ogrenci.matNotu);
    	    printf("Fen notu: ");
    	    scanf("%d",&ogrenci.fenNotu);
    	    printf("Turkce notu: ");
    	    scanf("%d",&ogrenci.turNotu);
    	    fseek(fp,0,SEEK_SET);
    	    fwrite(&ogrenci,sizeof(ogrenci),1,fp); 
    	    printf("ogrenci guncellendi.");
		}	
	}		
}

void ogrYazdir(FILE *fp){
	struct ogrenci ogrenci;
	printf("-OGRENCI LISTESI YAZDIRMA-\n");
    int k;
    fseek(fp,0,SEEK_SET);
    k=ftell(fp)/sizeof(struct ogrenci);
	int i;
	for(i=0;i<k;i++){
	    fseek(fp,i,SEEK_CUR);
    	fread(&ogrenci,sizeof(ogrenci),1,fp);
    	printf("  AD      SOYAD      D.TARIHI          Mnot    Fnot    Tnot");
    	printf("%d",i);
    	printf("%1s",ogrenci.ad);
    	printf("%6s",ogrenci.soyad);
    	printf("%6d/%d/%d",ogrenci.dogTarihi.gun,ogrenci.dogTarihi.ay,ogrenci.dogTarihi.yil);
    	printf("%10d",ogrenci.fenNotu);
    	printf("%4d",ogrenci.matNotu);
    	printf("%4d",ogrenci.turNotu);
	}	
}

void numaraSirala(FILE *fp){
    struct ogrenci ogrencim;
    int k,i,j;
    printf("-NUMARAYA GORE KAYIT SIRALAMA-");
	k=ftell(fp);

	for(i=0;i<k;i++){
        for(j=0;j<k;j++) {
       	struct ogrenci dizi1,dizi2;
       	fseek(fp,j,SEEK_CUR);
       	fread(&dizi1,sizeof(dizi1),1,fp);
       	fseek(fp,j+1,SEEK_CUR);
       	fread(&dizi2,sizeof(dizi2),1,fp);
            if(dizi1.numara>dizi2.numara){
            	fseek(fp,j,SEEK_CUR);
                fwrite(&dizi2,sizeof(dizi2),1,fp);
                fseek(fp,j+1,SEEK_CUR);
                fwrite(&dizi1,sizeof(dizi1),1,fp);
            }                                         
        }
    }
    ogrYazdir(fp);
    struct ogrenci *ogr1[k];
    ogr1[k]=(struct ogrenci*)malloc(sizeof(struct ogrenci));
    
    for(i=0;i<k;i++){
    	fseek(fp,i,SEEK_CUR);
    	fread(&ogrencim,sizeof(ogrencim),1,fp);
    	ogr1[i]=&ogrencim;
	}
}

void isimSirala(FILE *fp){
    struct ogrenci ogrencim;
    int k,i,j;
    printf("-ISME GORE KAYIT SIRALAMA-");
	fseek(fp,0,SEEK_SET);
    k=ftell(fp)/sizeof(struct ogrenci);
	
	for(i=0;i<k;i++){
        for(j=0;j<k;j++) {
        	struct ogrenci dizi1,dizi2;
        	fseek(fp,j,SEEK_CUR);
    	    fread(&dizi1,sizeof(dizi1),1,fp);
        	fseek(fp,j+1,SEEK_CUR);
            fread(&dizi2,sizeof(dizi2),1,fp);
            if(strcmp(dizi1.ad,dizi2.ad)>0){
        	    fseek(fp,j,SEEK_CUR);
                fwrite(&dizi2,sizeof(dizi2),1,fp);
                fseek(fp,j+1,SEEK_CUR);
                fwrite(&dizi1,sizeof(dizi1),1,fp);
            }                                         
        }
    }
    ogrYazdir(fp);
    struct ogrenci *ogr2[k];
    ogr2[k]=(struct ogrenci*)malloc(sizeof(struct ogrenci));
    
    for(i=0;i<k;i++){
    	fseek(fp,i,SEEK_CUR);
    	fread(&ogrencim,sizeof(ogrencim),1,fp);
    	ogr2[i]=&ogrencim;
	}
}

void matNotuSirala(FILE *fp){
    struct ogrenci ogrencim;
    int k,i,j;
    printf("-MATEMATIK NOTUNA GORE KAYIT SIRALAMA-");
	k=ftell(fp);

	for(i=0;i<k;i++){
        for(j=0;j<k;j++) {
       	struct ogrenci dizi1,dizi2;
       	fseek(fp,j,SEEK_CUR);
       	fread(&dizi1,sizeof(dizi1),1,fp);
       	fseek(fp,j+1,SEEK_CUR);
       	fread(&dizi2,sizeof(dizi2),1,fp);
            if(dizi1.matNotu>dizi2.matNotu){
            	fseek(fp,j,SEEK_CUR);
                fwrite(&dizi2,sizeof(dizi2),1,fp);
                fseek(fp,j+1,SEEK_CUR);
                fwrite(&dizi1,sizeof(dizi1),1,fp);
            }                                         
        }
    }
    ogrYazdir(fp);
    struct ogrenci *ogr3[k];
    ogr3[k]=(struct ogrenci*)malloc(sizeof(struct ogrenci));
    
    for(i=0;i<k;i++){
    	fseek(fp,i,SEEK_CUR);
    	fread(&ogrencim,sizeof(ogrencim),1,fp);
    	ogr3[i]=&ogrencim;
	}
}

void fenNotuSirala(FILE *fp){
    struct ogrenci ogrencim;
    int k,i,j;
    printf("-FEN NOTUNA GORE KAYIT SIRALAMA-");
	fseek(fp,0,SEEK_SET);
    k=ftell(fp)/sizeof(struct ogrenci);

	for(i=0;i<k;i++){
        for(j=0;j<k;j++) {
       	struct ogrenci dizi1,dizi2;
       	fseek(fp,j,SEEK_CUR);
       	fread(&dizi1,sizeof(dizi1),1,fp);
       	fseek(fp,j+1,SEEK_CUR);
       	fread(&dizi2,sizeof(dizi2),1,fp);
            if(dizi1.fenNotu>dizi2.fenNotu){
            	fseek(fp,j,SEEK_CUR);
                fwrite(&dizi2,sizeof(dizi2),1,fp);
                fseek(fp,j+1,SEEK_CUR);
                fwrite(&dizi1,sizeof(dizi1),1,fp);
            }                                         
        }
    }
    ogrYazdir(fp);
    
    struct ogrenci *ogr4[k];
    ogr4[k]=(struct ogrenci*)malloc(sizeof(struct ogrenci));
    
    for(i=0;i<k;i++){
    	fseek(fp,i,SEEK_CUR);
    	fread(&ogrencim,sizeof(ogrencim),1,fp);
    	ogr4[i]=&ogrencim;
	}
}

void turNotuSirala(FILE *fp){
    struct ogrenci ogrencim;
    int k,i,j;
    printf("-TURKCE NOTUNA GORE KAYIT SIRALAMA-");
	fseek(fp,0,SEEK_SET);
    k=ftell(fp)/sizeof(struct ogrenci);

	for(i=0;i<k;i++){
        for(j=0;j<k;j++) {
       	struct ogrenci dizi1,dizi2;
       	fseek(fp,j,SEEK_CUR);
       	fread(&dizi1,sizeof(dizi1),1,fp);
       	fseek(fp,j+1,SEEK_CUR);
       	fread(&dizi2,sizeof(dizi2),1,fp);
            if(dizi1.turNotu>dizi2.turNotu){
            	fseek(fp,j,SEEK_CUR);
                fwrite(&dizi2,sizeof(dizi2),1,fp);
                fseek(fp,j+1,SEEK_CUR);
                fwrite(&dizi1,sizeof(dizi1),1,fp);
            }                                         
        }
    }
    ogrYazdir(fp);
    
    struct ogrenci *ogr5[k];
    ogr5[k]=(struct ogrenci*)malloc(sizeof(struct ogrenci));
    
    for(i=0;i<k;i++){
    	fseek(fp,i,SEEK_CUR);
    	fread(&ogrencim,sizeof(ogrencim),1,fp);
    	ogr5[i]=&ogrencim;
	}
}

void dosyayaAt(FILE *fp){
	FILE *kp;
    kp=fopen("sorted.bin","rb+");
    if(kp==NULL)
    kp=fopen("sorted.bin","wb+");
    
    int i,k;
    fseek(fp,0,SEEK_SET);
    k=ftell(fp)/sizeof(struct ogrenci);
    struct ogrenci ogrencim;
    
    numaraSirala(fp);
    struct ogrenci *ogr1[k];
    ogr1[k]=(struct ogrenci*)malloc(sizeof(struct ogrenci));
    for(i=0;i<k;i++){
    	fseek(fp,i,SEEK_CUR);
    	fread(&ogrencim,sizeof(ogrencim),1,fp);
    	ogr1[i]=&ogrencim;
	}
	for(i=0;i<k;i++){
		fwrite(ogr1[i],sizeof(ogr1),1,kp);
	} 
	
	isimSirala(fp);
	struct ogrenci *ogr2[k];
    ogr2[k]=(struct ogrenci*)malloc(sizeof(struct ogrenci));
    for(i=0;i<k;i++){
    	fseek(fp,i,SEEK_CUR);
    	fread(&ogrencim,sizeof(ogrencim),1,fp);
    	ogr2[i]=&ogrencim;
	}
	for(i=0;i<k;i++){
		fwrite(ogr2[i],sizeof(ogr2),1,kp);
	} 
	
	matNotuSirala(fp);
	struct ogrenci *ogr3[k];
    ogr3[k]=(struct ogrenci*)malloc(sizeof(struct ogrenci));
    for(i=0;i<k;i++){
    	fseek(fp,i,SEEK_CUR);
    	fread(&ogrencim,sizeof(ogrencim),1,fp);
    	ogr3[i]=&ogrencim;
	}
    for(i=0;i<k;i++){
    	fwrite(ogr3[i],sizeof(ogr3),1,kp);
	} 
	
	fenNotuSirala(fp);
	struct ogrenci *ogr4[k];
    ogr4[k]=(struct ogrenci*)malloc(sizeof(struct ogrenci));
    for(i=0;i<k;i++){
    	fseek(fp,i,SEEK_CUR);
    	fread(&ogrencim,sizeof(ogrencim),1,fp);
    	ogr4[i]=&ogrencim;
	}
	for(i=0;i<k;i++){
		fwrite(ogr4[i],sizeof(ogr4),1,kp);
	} 
	turNotuSirala(fp);
	struct ogrenci *ogr5[k];
    ogr5[k]=(struct ogrenci*)malloc(sizeof(struct ogrenci));
    for(i=0;i<k;i++){
    	fseek(fp,i,SEEK_CUR);
    	fread(&ogrencim,sizeof(ogrencim),1,fp);
    	ogr5[i]=&ogrencim;
	}
	for(i=0;i<k;i++){
		fwrite(ogr5[i],sizeof(ogr5),1,kp);
    }   
}
	

int main(){
	FILE *fp;
	fp=fopen("person.bin","rb");
	if(fp==NULL)
	fp=fopen("person.bin","wb");
	
	FILE *kp;
    kp=fopen("sorted.bin","rb+");
    if(kp==NULL)
    kp=fopen("sorted.bin","wb+");
	
	while(1){
		printf("\n");
		printf("-----SECIM MENUSU-----\n");
		printf("1-Ogrenci kaydi ekle.\n");	
		printf("2-Ogrenci kaydi sil.\n");
		printf("3-Ogrenci kaydi güncelle.\n");
		printf("4-Tum ogrencileri ekranda listele.\n");
		printf("5-Ogrenci kayitlarini numaraya gore sirala.\n");
		printf("6-Ogrenci kayitlarini isme gore sirala.\n");
		printf("7-Ogrenci kayitlarini matematik notuna gore sirala\n");
		printf("8-Ogrenci kayitlarini fen notuna gore siralama.\n");
		printf("9-Ogrenci kayitlarini turkce notuna gore siralama.\n");
		printf("10-Ogrenci kayitlarini 'sorted.bin'e yerlestir.\n");
		printf("11-Cikis\n");
		int secim;
		scanf("%d",&secim);
		
		switch(secim){
			case 1:{
				ogrEkle(fp); 
				break;
			}
			
			case 2:{
				ogrSil(fp);
				break;
			}
			
			case 3:{
				ogrGuncelle(fp);
				break;
			}
			
			case 4:{
				ogrYazdir(fp);
				break;
			}
			
			case 5:{
				numaraSirala(fp);
				break;
			}
			
			case 6:{
				isimSirala(fp);
				break;
			}
			
			case 7:{
				matNotuSirala(fp); 
				break;
			}
			
			case 8:{
				fenNotuSirala(fp); 
				break;
			}
			
			case 9:{
				turNotuSirala(fp); 
				break;
			}
			
			case 10:{
				dosyayaAt(fp); 
				break;
			}
			
			case 11:{
				break;
				break;
			}
		}
	}
	fclose(fp);
	fclose(kp);
}
