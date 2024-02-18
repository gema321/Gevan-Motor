typedef struct {
	int ID;
	char KodeBarang[50];
	char NamaBarang[50];
	int stok;
	int harga;
	int terjual;
}RincianBarang;

RincianBarang produk;
FILE *DataBarang, *Temp;

void InputBarang();
void ViewBarang();
void UpdateBarang();
void DeleteBarang();


Barang(){
	int menu;
	menu!=5; 
	int kolom = 0, baris = 0;

	while(menu != 5){
		
		system("cls");
		TampilanIsi();
		
		gotoxy(kolom+0,baris+12);	printf("\tMENU MENGELOLA DATA");
    	gotoxy(kolom+5,baris+16); 	printf("[1] Input Data Barang");
    	gotoxy(kolom+5,baris+18); 	printf("[2] View Data Barang");
    	gotoxy(kolom+5,baris+20); 	printf("[3] Update Data Barang");
    	gotoxy(kolom+5,baris+22); 	printf("[4] Delete Data Barang");
		gotoxy(kolom+5,baris+24); 	printf("[5] Exit");
		gotoxy(5,26);	printf("Pilih Menu :[ ]");  
		gotoxy(18,26);	scanf("%d", &menu);


	switch(menu)
   		{
    	case 1 :
    		InputBarang(); break;
        case 2 :
       		ViewBarang(); 
			gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
			getch();	   
	  		break;
			  	
		case 3 : 
			UpdateBarang(); 
			gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
			getch();
			break;
		case 4 :
   	    	DeleteBarang();
			gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
			getch();
			break;
    	}
	}
}


void InputBarang(){
	
	int lastid=0; //untuk auto increment id
	char Kode[5],code[25];
	char isilagi='y';
	int kolom = 36, baris = 4;
		
	while(isilagi=='y'){
		
		TampilanIsi();
		
		DataBarang = fopen("DataBarang.dat", "ab+");
		
		while(fread(&produk,sizeof(produk),1,DataBarang)){
			lastid=produk.ID;
		}

		lastid=lastid+1;
		sprintf(Kode,"%i",lastid);
		strcpy(code,"BAR");
		strcpy(Kode,strcat(code,Kode));

		underline(kolom+20, 12,"INPUT DATA BARANG");
		gotoxy(kolom+13,baris+12);	printf("Kode Barang \t: "); 	printf("%s",Kode); produk.ID=lastid;strcpy(produk.KodeBarang,Kode);fflush(stdin);
		gotoxy(kolom+13,baris+14);	printf("Nama Barang \t: ");  	gets(produk.NamaBarang);
		gotoxy(kolom+13,baris+16);	printf("Stok Barang \t: ");  	scanf("%d", &produk.stok);
        gotoxy(kolom+13,baris+18);	printf("Harga Barang \t: ");  	scanf("%d", &produk.harga);     
		
		fwrite(&produk, sizeof(produk), 1 , DataBarang);
		
		fflush(stdin);
		gotoxy(kolom+13,baris+25);	printf("Tambah Lagi ? (y/n) : "); 
		scanf("%c", &isilagi);	
		
		system("cls");
		fclose(DataBarang);
	}
}


void ViewBarang(){
	
	int kolom=0, baris=1;
		
	TampilanIsi();
	
    DataBarang = fopen("DataBarang.dat", "r");
    
    Vline(13, 45, 42, 179);
	Vline(13, 45, 55, 179);
	Vline(13, 45, 85, 179);
	Vline(13, 45, 110, 179);
	Vline(13, 45, 126, 179);
	Hline(42, 126, 13, 196);
	Hline(42, 126, 15, 196);
    
    gotoxy(kolom+44, baris+13);		printf("Kode Barang\t\tNama Barang\t\t\tStok\t\t   Harga");

    while(fread(&produk, sizeof(produk), 1, DataBarang)){
		gotoxy(kolom+46,baris+15);		printf("%s", produk.KodeBarang);
		gotoxy(kolom+59,baris+15);		printf("%s", produk.NamaBarang);
		gotoxy(kolom+93,baris+15);		printf("%d", produk.stok);
		gotoxy(kolom+115,baris+15);		printf("%d", produk.harga);
		baris++;
	}
	fclose(DataBarang);
}


void UpdateBarang(){
	
	int cari;
	int pilih;
	int kolom = 0, baris = 0;
	int found=0;
	
	system("cls");			
	TampilanIsi();
	ViewBarang();
	
	DataBarang 	= fopen ("DataBarang.dat","r+");
	Temp		= fopen ("Barang.dat", "a+");
	

	gotoxy(kolom+10,baris+12);	printf("MENU UPDATE DATA");
	gotoxy(kolom+5,baris+16);	printf("PILIH KODE BARANG : BAR"); scanf("%d", &cari);
	
	system("cls");
    TampilanIsi();
    
    gotoxy(11,12); printf("KODE BARANG : BAR%d", cari);
    
	while(fread(&produk, sizeof(produk), 1, DataBarang)){
    	if(produk.ID==cari){
    		found=found+1;
    		gotoxy(kolom+5,baris+16);	printf("DATA YANG INGIN DIUBAH ");
    		gotoxy(kolom+5,baris+18);	printf("[1] Nama Barang");
    		gotoxy(kolom+5,baris+20);	printf("[2] Jumlah Stok");
    		gotoxy(kolom+5,baris+22);	printf("[3] Harga Barang");
    		gotoxy(kolom+5,baris+24);	printf("[4] Semuanya");
    		gotoxy(kolom+5,baris+26);	printf("Pilih Nomor :[ ]"); 
			gotoxy(kolom+19,baris+26);	scanf("%d", &pilih); 
			fflush(stdin);
	
    		if(pilih==1){
    			gotoxy(kolom+43,baris+20);	printf("Nama Barang Baru : "); scanf("%[^\n]s", &produk.NamaBarang);
    			MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else if (pilih==2){
				gotoxy(kolom+43,baris+20);	printf("Stok Baru : ");  scanf("%d", &produk.stok); 
				MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else if (pilih==3){
				gotoxy(kolom+43,baris+20);	printf("Harga Barang : ");	scanf("%d", &produk.harga); 
		   		MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		   	}else if (pilih == 4){
		    	gotoxy(kolom+43,baris+20);	printf("Nama Barang Baru \t: "); scanf("%[^\n]s", &produk.NamaBarang); fflush(stdin);
		    	gotoxy(kolom+43,baris+22);	printf("Jumlah Stok Baru  \t: "); scanf("%d", &produk.stok); fflush(stdin);
		    	gotoxy(kolom+43,baris+24);	printf("Harga Baru 	    \t: ");  scanf("%d", &produk.harga); fflush(stdin);
				MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else{
				MessageBox(NULL, "Nomor Tidak Valid!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
			}
        }fwrite(&produk, sizeof(produk), 1 , Temp);
    }
        
	if(found<1){
    	MessageBox(NULL, "Data Tidak Ditemukan!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
	}
	
    fclose(DataBarang);
    fclose(Temp);
        
	remove("DataBarang.dat");
    rename("Barang.dat", "DataBarang.dat");   
	
	system("cls");
    ViewBarang();
}


void DeleteBarang(){

	int cari;
	int kolom = 0, baris = 0;
	int found=0;
	
	TampilanIsi();
	ViewBarang();

	DataBarang 	= fopen("DataBarang.dat", "r+");
	Temp 		= fopen("Barang.dat", "a+");
    
	gotoxy(kolom+5,baris+28);	printf("KODE YANG AKAN DIHAPUS : BAR"); scanf("%d", &cari);
    
	while(fread(&produk, sizeof(produk), 1, DataBarang)){
		if(produk.ID==cari){
			MessageBox(NULL, "Data Telah Dihapus!","Data Dihapus",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			found=found+1;
		}else if(produk.ID!=cari){
			fwrite(&produk, sizeof(produk), 1, Temp);
		}
	}
	
	
	if(found<1){
    	MessageBox(NULL, "Data Tidak Ditemukan!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
	}
	
	fclose(DataBarang);
	fclose(Temp);
	
	remove("DataBarang.dat");
    rename("Barang.dat", "DataBarang.dat");
	
	system("cls");
    ViewBarang(); 
		
}
