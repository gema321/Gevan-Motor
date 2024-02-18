typedef struct {
	int IDKaryawan;
	char KodeKaryawan[50];
	char NamaKaryawan[50];
	char NomorTelepon[20];
	char Alamat[15];
	char Uname[100], Pass[100];
}DataKyw;

DataKyw karyawan;
FILE *DataKaryawan, *Temp;

void InputDataKyw();
void ViewDataKyw();
void UpdateDataKyw();
void DeleteDataKyw();


Karyawan(){
	
	int menu;
	menu!=5; 
	int kolom = 0, baris = 0;
    
	while(menu != 5){
		
		system("cls");
		TampilanIsi();
	
		gotoxy(kolom+0,baris+12);	printf("\tMENU MENGELOLA KASIR");
    	gotoxy(kolom+5,baris+16);	printf("[1] Input Data Kasir");
    	gotoxy(kolom+5,baris+18);	printf("[2] View Data Kasir");
    	gotoxy(kolom+5,baris+20);	printf("[3] Update Data Kasir");
    	gotoxy(kolom+5,baris+22);	printf("[4] Delete Data Kasir");
		gotoxy(kolom+5,baris+24);	printf("[5] Exit");	
		gotoxy(kolom+5,baris+26);	printf("Pilih Menu :[ ]");  
		gotoxy(kolom+18,baris+26);	scanf("%d", &menu);
	
	
	switch(menu){
		
    	case 1 :
    		InputDataKyw(); 
			break;
        case 2 :
        	ViewDataKyw();
			gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
			getch(); 
			break;
		case 3 :
			UpdateDataKyw(); 
			gotoxy(5,31);printf("Tekan apapun untuk lanjut!");	
			getch();
			break;
		case 4 :	
			DeleteDataKyw(); 
			gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
			getch();			
			break;
    	}
	}
}


void InputDataKyw(){
	
	int lastid=0; //untuk auto increment id
	char Kode[5],code[25];
	char isilagi='y';
	int kolom = 36, baris = 4;
		
	while(isilagi=='y'){
		
		TampilanIsi();
		
		DataKaryawan = fopen("DataKasir.dat", "ab+");
		
		while(fread(&karyawan,sizeof(karyawan),1,DataKaryawan)){
			lastid=karyawan.IDKaryawan;
		}

		lastid=lastid+1;
		sprintf(Kode,"%i",lastid);
		strcpy(code,"KAR");
		strcpy(Kode,strcat(code,Kode));
		
		underline(kolom+20, 12,"INPUT DATA KASIR");
		gotoxy(kolom+13,baris+12); printf("ID Kasir \t: "); 		printf("%s",Kode); karyawan.IDKaryawan=lastid;strcpy(karyawan.KodeKaryawan,Kode);fflush(stdin);
		gotoxy(kolom+13,baris+14); printf("Nama Kasir \t: ");  		gets(karyawan.NamaKaryawan);
        gotoxy(kolom+13,baris+16); printf("Nomor Telepon \t: ");  	gets(karyawan.NomorTelepon);     
        gotoxy(kolom+13,baris+18); printf("Alamat \t: "); 			gets(karyawan.Alamat);
        gotoxy(kolom+13,baris+20); printf("Username \t: "); 		gets(karyawan.Uname);
        gotoxy(kolom+13,baris+22); printf("Password \t: "); 		gets(karyawan.Pass);
		
		fwrite(&karyawan, sizeof(karyawan), 1 , DataKaryawan);
		
		gotoxy(kolom+13,baris+25); printf("Tambah Lagi ? (y/n) : "); 
		scanf("%c", &isilagi);
	
		system("cls");	
		fclose(DataKaryawan);
	}
}


void ViewDataKyw(){
	
	int kolom = 0, baris = 1;
	
	TampilanIsi();
    
	DataKaryawan = fopen("DataKasir.dat", "r");
    
	Vline(13, 45, 42, 179);
	Vline(13, 45, 55, 179);
	Vline(13, 45, 85, 179);
	Vline(13, 45, 110, 179);
	Vline(13, 45, 126, 179);
	Vline(13, 45, 143, 179);
	Vline(13, 45, 159, 179);
	Hline(42, 159, 13, 196);
	Hline(42, 159, 15, 196);
    
	gotoxy(kolom+44,baris+13); printf("ID Kasir\t\t Nama Kasir\t\tNomor Telepon \t\t   Alamat\t  Username\t  Password");
	
    while(fread(&karyawan, sizeof(karyawan), 1, DataKaryawan)){
		gotoxy(kolom+44,baris+15);		printf("%s", karyawan.KodeKaryawan);
		gotoxy(kolom+59,baris+15);		printf("%s", karyawan.NamaKaryawan);
		gotoxy(kolom+87,baris+15);		printf("%s", karyawan.NomorTelepon);
		gotoxy(kolom+115,baris+15);		printf("%s", karyawan.Alamat);
		gotoxy(kolom+131,baris+15);		printf("%s", karyawan.Uname);
		gotoxy(kolom+147,baris+15);		printf("%s", karyawan.Pass);
		baris++;
	}
	fclose(DataKaryawan);
}


void UpdateDataKyw(){
	
	int cari;
	int pilih;
	int kolom = 0, baris = 0;
	int found=0;
	
	system("cls");
	TampilanIsi();
	ViewDataKyw();
	
	DataKaryawan 	= fopen ("DataKasir.dat","r+");
	Temp			= fopen ("TampungKar.dat", "a+");
	
	gotoxy(kolom+10,baris+12);	printf("MENU UPDATE DATA");
	gotoxy(kolom+5,baris+16);	printf("PILIH ID KARYAWAN : KAR"); scanf("%d", &cari);
    
    system("cls");
    TampilanIsi();
    
    gotoxy(11,12); printf("ID KASIR : KAR%d", cari);
    
	while(fread(&karyawan, sizeof(karyawan), 1, DataKaryawan)){
    	if(karyawan.IDKaryawan == cari){
    		found=found+1;
    		gotoxy(kolom+5,baris+18);printf("DATA YANG INGIN DIUBAH : ");
    		gotoxy(kolom+5,baris+20);printf("[1] Nama Kasir");
    		gotoxy(kolom+5,baris+22);printf("[2] Nomer Telepon");
    		gotoxy(kolom+5,baris+24);printf("[3] Alamat");
    		gotoxy(kolom+5,baris+26);printf("[4] Username");
    		gotoxy(kolom+5,baris+28);printf("[5] Password");
    		gotoxy(kolom+5,baris+30);printf("[6] Semuanya");
			gotoxy(kolom+5,baris+32);printf("Pilih Nomor :[ ]"); 
			gotoxy(kolom+19,baris+32);scanf("%d", &pilih);
    		fflush(stdin);
    		
    		if(pilih==1){
    			gotoxy(kolom+43,baris+20); printf("Nama Kasir Baru \t: "); scanf("%[^\n]s", &karyawan.NamaKaryawan);
    			MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else if (pilih==2){
				gotoxy(kolom+43,baris+20); printf("Nomer Telepon \t: "); scanf("%[^\n]s", &karyawan.NomorTelepon);
				MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else if (pilih==3){
				gotoxy(kolom+43,baris+20); printf("Alamat 	\t: "); scanf("%[^\n]s", &karyawan.Alamat);
		    	MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		   	}else if (pilih==4){
				gotoxy(kolom+43,baris+20); printf("Username 	\t: ");  scanf("%[^\n]s", &karyawan.Uname);
		   	MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		   	}else if (pilih==5){
				gotoxy(kolom+43,baris+20); printf("Password	\t: "); scanf("%[^\n]s", &karyawan.Pass);
				MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else if (pilih == 6){
		    	gotoxy(kolom+43,baris+20); printf("Nama Baru \t\t: "); 	 scanf("%[^\n]s", &karyawan.NamaKaryawan);	fflush(stdin);
				gotoxy(kolom+43,baris+22); printf("Nomer Telepon \t: "); scanf("%[^\n]s", &karyawan.NomorTelepon);	fflush(stdin);
		    	gotoxy(kolom+43,baris+24); printf("Alamat\t\t: ");       scanf("%[^\n]s", &karyawan.Alamat);	fflush(stdin);
		    	gotoxy(kolom+43,baris+26); printf("Username\t\t: ");   	 scanf("%[^\n]s", &karyawan.Uname);	fflush(stdin);
		    	gotoxy(kolom+43,baris+28); printf("Password\t\t: ");   	 scanf("%[^\n]s", &karyawan.Pass);	fflush(stdin);
				MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else{
				MessageBox(NULL, "Nomor Tidak Valid!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
			}	
        }fwrite(&karyawan, sizeof(karyawan), 1 , Temp);
    }
    
    if(found<1){
    	MessageBox(NULL, "Data Tidak Ditemukan!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
	}
        
    fclose(DataKaryawan);
    fclose(Temp);
        
	remove("DataKasir.dat");
    rename("TampungKar.dat", "DataKasir.dat");  
 
    system("cls");
    ViewDataKyw();
}

void DeleteDataKyw(){

	int cari;
	int kolom = 0, baris = 0 ;
	int found=0;
	
	TampilanIsi();
	ViewDataKyw();
	
	DataKaryawan 	= fopen("DataKasir.dat", "r+");
	Temp			= fopen("TampungKar.dat", "a+");

	gotoxy(kolom+5,baris+28);	printf("ID YANG AKAN DIHAPUS : KAR"); scanf("%d", &cari);
    
	while(fread(&karyawan, sizeof(karyawan), 1, DataKaryawan)){
		if(karyawan.IDKaryawan == cari){
			MessageBox(NULL, "Data Telah Dihapus!","Data Dihapus",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			found=found+1;
		}else if(karyawan.IDKaryawan != cari){
			fwrite(&karyawan, sizeof(karyawan), 1, Temp);
		}
	}
	
	if(found<1){
    	MessageBox(NULL, "Data Tidak Ditemukan!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
	}
			
	fclose(DataKaryawan);
	fclose(Temp);
	
	remove("DataKasir.dat");
    rename("TampungKar.dat", "DataKasir.dat");
	
	system("cls");
    ViewDataKyw();
}
