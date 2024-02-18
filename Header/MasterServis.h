typedef struct {
	int ID;
	char KodeServis[50];
	char NamaServis[50];
	int harga;
}DataService;

DataService servis;
FILE *DataServis, *Temp;

void InputServis();
void ViewServis();
void UpdateServis();
void DeleteServis();


Service(){
	
	int kolom = 0, baris = 0;
	int menu;
	menu!=5; 
    
	while(menu != 5){
		
		system("cls"); 	
		TampilanIsi();
		
		gotoxy(kolom+0,baris+12);	printf("\tMENU MENGELOLA DATA");
		gotoxy(kolom+5,baris+16); 	printf("[1] Input Data servis");
		gotoxy(kolom+5,baris+18);	printf("[2] View Data servis");
		gotoxy(kolom+5,baris+20);	printf("[3] Update Data servis");
    	gotoxy(kolom+5,baris+22);	printf("[4] Delete Data servis");
		gotoxy(kolom+5,baris+24);	printf("[5] Exit");
		gotoxy(5,26);	printf("Pilih Menu :[ ]");  
		gotoxy(18,26);	scanf("%d", &menu);


	switch(menu){
		
    	case 1 :
    		InputServis();	
			break;
        case 2 :
        	ViewServis();
			gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
			getch();	
			break;
		case 3 :
			UpdateServis(); 
			gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
			getch();			
			break;
		case 4 :
   		 	DeleteServis(); 
			gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
			getch();				   
			break;
    	}
	}
}


void InputServis(){

	int lastid=0; //untuk auto increment id
	char Kode[5],code[25];
	char isilagi='y';
	int kolom = 36, baris = 4;

	while(isilagi=='y'){
		
		TampilanIsi();
		
		DataServis = fopen("DataServis.dat", "ab+");
	
		while(fread(&servis,sizeof(servis),1,DataServis)==1){
			lastid=servis.ID;
		}
		
		lastid=lastid+1;
		sprintf(Kode,"%i",lastid);
		strcpy(code,"SER");
		strcpy(Kode,strcat(code,Kode));
		
		underline(kolom+20, 12,"INPUT DATA SERVIS");
		gotoxy(kolom+13,baris+12);	printf("Kode servis \t: "); 	printf("%s",Kode); servis.ID=lastid;strcpy(servis.KodeServis,Kode);fflush(stdin);
		gotoxy(kolom+13,baris+14);	printf("Nama Servis \t: ");  	gets(servis.NamaServis); 
        gotoxy(kolom+13,baris+16);	printf("Harga Servis \t: ");  	scanf("%d", &servis.harga);     
		
		fwrite(&servis, sizeof(servis), 1 , DataServis);
		
		fflush(stdin);
		gotoxy(kolom+13,baris+25);	printf("Tambah Lagi ? (y/n) : "); 
		scanf("%c", &isilagi);
	
		system("cls");
		fclose(DataServis);
	}
}


void ViewServis(){
	
	int kolom=0, baris=1;
	
	TampilanIsi();
  
    DataServis = fopen("DataServis.dat", "r");
    
    Vline(13, 45, 42, 179);
	Vline(13, 45, 55, 179);
	Vline(13, 45, 85, 179);
	Vline(13, 45, 110, 179);
	Hline(42, 110, 13, 196);
	Hline(42, 110, 15, 196);
	
	gotoxy(kolom+44,baris+13);		printf("Kode Servis\t\t Nama Servis\t\t  Harga Servis");
	
    while(fread(&servis, sizeof(servis), 1, DataServis)){
		gotoxy(kolom+46,baris+15);		printf("%s", servis.KodeServis);
		gotoxy(kolom+59,baris+15);		printf("%s", servis.NamaServis);
		gotoxy(kolom+93,baris+15);		printf("%d", servis.harga);
		baris++;
	}
	fclose(DataServis);
}

void UpdateServis(){
	
	int cari;
	int pilih;
	int kolom = 0, baris = 0;
	int found=0;
	
	system("cls");
	TampilanIsi();
	ViewServis();
	
	DataServis 	= fopen ("DataServis.dat","r+");
	Temp		= fopen("Tampung.dat", "a+");
	

	gotoxy(kolom+10,baris+12);	printf("MENU UPDATE DATA");
	gotoxy(kolom+5,baris+16);	printf("PILIH KODE SERVIS : SER"); scanf("%d", &cari);
	
	system("cls");
    TampilanIsi();

    gotoxy(11,12); printf("KODE SERVIS : SER%d", cari);
	
	while(fread(&servis, sizeof(servis), 1, DataServis)){
    	if(servis.ID==cari){
    		found=found+1;
    		gotoxy(kolom+5,baris+18);printf("[1] Nama Servis");
    		gotoxy(kolom+5,baris+20);printf("[2] Harga Servis");
    		gotoxy(kolom+5,baris+22);printf("[3] Semuanya");
    		gotoxy(kolom+5,baris+24);printf("Pilih Nomor :[ ]");
    		gotoxy(kolom+19,baris+24);scanf("%d", &pilih);
    		fflush(stdin);
    		
    		if(pilih == 1){
    			gotoxy(kolom+43,baris+20);	printf("Nama Servis Baru : ");	scanf("%[^\n]s", &servis.NamaServis);
    			MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else if (pilih == 2){
				gotoxy(kolom+43,baris+20);	printf("Harga Barang 	: ");   scanf("%d", &servis.harga);
		   		MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		    }else if (pilih == 3){
		    	gotoxy(kolom+43,baris+20);	printf("Nama Servis Baru \t: "); scanf("%[^\n]s", &servis.NamaServis);	fflush(stdin);
		    	gotoxy(kolom+43,baris+22);	printf("Harga Barang \t: ");  scanf("%d", &servis.harga);	fflush(stdin);
				MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else{
				MessageBox(NULL, "Nomor Tidak Valid!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
			}	
		}fwrite(&servis, sizeof(servis), 1 , Temp);
    }
        
    if(found<1){
    	MessageBox(NULL, "Data Tidak Ditemukan!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
	}
	
    fclose(DataServis);
    fclose(Temp);
        
	remove("DataServis.dat");
    rename("Tampung.dat", "DataServis.dat");  
    
    system("cls");
    ViewServis();
}


void DeleteServis(){
	
	int cari;
	int kolom = 0, baris = 0 ;
    int found=0;
    
    TampilanIsi();
    ViewServis();
    
    DataServis 	= fopen("DataServis.dat", "r+");
	Temp 		= fopen("Tampung.dat", "a+");
    
	gotoxy(kolom+5,baris+28);	printf("KODE YANG AKAN DIHAPUS : SER"); scanf("%d", &cari);
    
	while(fread(&servis, sizeof(servis), 1, DataServis)){
		if(servis.ID==cari){
			MessageBox(NULL, "Data Telah Dihapus!","Data Dihapus",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			found=found+1;
		}else if(servis.ID!=cari){
			fwrite(&servis, sizeof(servis), 1, Temp);
		}
	}

	if(found<1){
    	MessageBox(NULL, "Data Tidak Ditemukan!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
	}
	
	fclose(DataServis);
	fclose(Temp);
	
	remove("DataServis.dat");
    rename("Tampung.dat", "DataServis.dat");  
	
	system("cls");
    ViewServis();
}
