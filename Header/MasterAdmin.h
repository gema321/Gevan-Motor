typedef struct {
	int IDAdmin;
	char KodeAdmin[50];
	char NamaAdmin[50];
	char NomorTelepon[20];
	char Alamat[15];
	char Uname[100], Pass[100];
}DataAdm;

DataAdm admin;
FILE *DataAdmin, *Temp;

void InputAdmin();
void ViewAdmin();
void UpdateAdmin();
void DeleteAdmin();


AkunAdmin(){
	
	int menu;
	menu!=5;
	int kolom = 0, baris = 0;
    
	while(menu != 5){
		
		system("cls"); 
		TampilanIsi();
		
		gotoxy(kolom+0,baris+12);	printf("\tMENU MENGELOLA ADMIN");
		gotoxy(kolom+5,baris+16);	printf("[1] Input Data Admin");
		gotoxy(kolom+5,baris+18);	printf("[2] View Data Admin");
		gotoxy(kolom+5,baris+20);	printf("[3] Update Data Admin");
		gotoxy(kolom+5,baris+22);	printf("[4] Delete Data Admin");
		gotoxy(kolom+5,baris+24);	printf("[5] Exit");
		gotoxy(kolom+5,baris+26);	printf("Pilih Menu :[ ]");
		gotoxy(kolom+18,baris+26);	scanf("%d", &menu);
	

	switch(menu){
		
    	case 1 :
    		InputAdmin(); 
			break;
        case 2 :
        	ViewAdmin();  
			gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
			getch();
			break;
		case 3 :
			UpdateAdmin(); 
        	gotoxy(5,31);printf("Tekan apapun untuk lanjut!");	
			getch();
			break;
		case 4 :
			DeleteAdmin(); 
			gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
			getch();
			break;
		}
	}
}


void InputAdmin(){
	
	int lastid=0; //untuk auto increment id
	char Kode[5],code[25];
	char isilagi='y';
	int kolom = 36, baris = 4;

	while(isilagi=='y'){
		
		TampilanIsi(); //untuk nampilin background
		
		DataAdmin = fopen("DataAdmin.dat", "ab+");
		
		while(fread(&admin,sizeof(admin),1,DataAdmin)){
			lastid=admin.IDAdmin;
		}
		
		lastid=lastid+1;
		sprintf(Kode,"%i",lastid);
		strcpy(code,"ADM");
		strcpy(Kode,strcat(code,Kode));
		
		underline(kolom+20, 12,"INPUT DATA ADMIN");
		gotoxy(kolom+13,baris+12);printf("ID Admin \t: "); 		printf("%s",Kode); admin.IDAdmin=lastid;strcpy(admin.KodeAdmin,Kode);fflush(stdin);
		gotoxy(kolom+13,baris+14);printf("Nama Admin \t: ");  	gets(admin.NamaAdmin);
        gotoxy(kolom+13,baris+16);printf("Nomor Telepon \t: "); gets(admin.NomorTelepon);     
        gotoxy(kolom+13,baris+18);printf("Alamat \t: "); 		gets(admin.Alamat);
        gotoxy(kolom+13,baris+20);printf("Username \t: "); 		gets(admin.Uname);
        gotoxy(kolom+13,baris+22);printf("Password \t: "); 		gets(admin.Pass);
		
		fwrite(&admin, sizeof(admin), 1 , DataAdmin);

		gotoxy(kolom+13,baris+25); printf("Tambah Lagi ? (y/n) : "); 
		scanf("%c", &isilagi);
		
		system("cls");
		fclose(DataAdmin);
	}
}


void ViewAdmin(){
	
	int kolom = 0, baris = 1;
	
	TampilanIsi();
	
    DataAdmin = fopen("DataAdmin.dat", "r");
    
	Vline(13, 45, 42, 179);	
	Vline(13, 45, 55, 179);
	Vline(13, 45, 85, 179);
	Vline(13, 45, 110, 179);
	Vline(13, 45, 126, 179);
	Vline(13, 45, 143, 179);
	Vline(13, 45, 159, 179);
	Hline(42, 159, 13, 196);
	Hline(42, 159, 15, 196);
	
	gotoxy(kolom+44,baris+13); printf("ID admin\t\t Nama Admin\t\tNomor Telepon \t\t   Alamat\t  Username\t  Password");
	
    while(fread(&admin, sizeof(admin), 1, DataAdmin)){
		gotoxy(kolom+44,baris+15);		printf("%s", admin.KodeAdmin);
		gotoxy(kolom+59,baris+15);		printf("%s", admin.NamaAdmin);
		gotoxy(kolom+87,baris+15);		printf("%s", admin.NomorTelepon);
		gotoxy(kolom+115,baris+15);		printf("%s", admin.Alamat);
		gotoxy(kolom+131,baris+15);		printf("%s", admin.Uname);
		gotoxy(kolom+147,baris+15);		printf("%s", admin.Pass);
		baris++;
	}
	fclose(DataAdmin);
}


void UpdateAdmin(){
	
	int cari;
	int pilih;
	int kolom = -6, baris = 1;
	int found=0;

	system("cls");
	TampilanIsi();
	ViewAdmin();
	
	DataAdmin 	= fopen ("DataAdmin.dat","r+");
	Temp		= fopen ("TampungAdm.dat", "a+");
	
	gotoxy(kolom+16,baris+11);	printf("MENU UPDATE DATA");
	gotoxy(kolom+11,baris+15);	printf("PILIH ID ADMIN : ADM");scanf("%d", &cari);

    system("cls");
    TampilanIsi();
    
    gotoxy(11,12); printf("ID ADMIN : ADM%d", cari);

    
	while(fread(&admin, sizeof(admin), 1, DataAdmin)){
    	if(admin.IDAdmin == cari){
    		found=found+1;
    		gotoxy(kolom+11,baris+17);printf("DATA YANG INGIN DIUBAH ");
    		gotoxy(kolom+11,baris+19);printf("[1] Nama Admin");
    		gotoxy(kolom+11,baris+21);printf("[2] Nomer Telepon");
    		gotoxy(kolom+11,baris+23);printf("[3] Alamat");
    		gotoxy(kolom+11,baris+25);printf("[4] Username");
    		gotoxy(kolom+11,baris+27);printf("[5] Password");
    		gotoxy(kolom+11,baris+29);printf("[6] Semuanya");
			gotoxy(kolom+11,baris+31);printf("Pilih Nomor :[ ]"); 
			gotoxy(kolom+25,baris+31);scanf("%d", &pilih);
    		fflush(stdin);
    		
    		if(pilih==1){
    			gotoxy(kolom+49,baris+19); printf("Nama Admin Baru \t: "); scanf("%[^\n]s", &admin.NamaAdmin);
    			MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else if (pilih==2){
				gotoxy(kolom+49,baris+19); printf("Nomer Telepon \t: "); scanf("%[^\n]s", &admin.NomorTelepon);
				MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else if (pilih==3){
				gotoxy(kolom+49,baris+19); printf("Alamat 	\t: "); scanf("%[^\n]s", &admin.Alamat);
		    	MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		   	}else if (pilih==4){
				gotoxy(kolom+49,baris+19); printf("Username 	\t: ");  scanf("%[^\n]s", &admin.Uname);
				MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		   	}else if (pilih==5){
				gotoxy(kolom+49,baris+19); printf("Password	\t: "); scanf("%[^\n]s", &admin.Pass);
				MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else if (pilih == 6){
		    	gotoxy(kolom+49,baris+19); printf("Nama Baru \t\t: "); 	 scanf("%[^\n]s", &admin.NamaAdmin);	fflush(stdin);
				gotoxy(kolom+49,baris+21); printf("Nomer Telepon \t: "); scanf("%[^\n]s", &admin.NomorTelepon);	fflush(stdin);
		    	gotoxy(kolom+49,baris+23); printf("Alamat\t\t: ");       scanf("%[^\n]s", &admin.Alamat);	fflush(stdin);
		    	gotoxy(kolom+49,baris+25); printf("Username\t\t: ");   	 scanf("%[^\n]s", &admin.Uname);	fflush(stdin);
		    	gotoxy(kolom+49,baris+27); printf("Password\t\t: ");   	 scanf("%[^\n]s", &admin.Pass);		fflush(stdin);
				MessageBox(NULL, "Data Telah Di Update!","Data Di Update",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			}else{
				MessageBox(NULL, "Nomor Tidak Valid!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
			}
        }fwrite(&admin, sizeof(admin), 1 , Temp);
    }
    
    if(found<1){
    	MessageBox(NULL, "Data Tidak Ditemukan!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
	}
        
    fclose(DataAdmin);
    fclose(Temp);
        
	remove("DataAdmin.dat");
    rename("TampungAdm.dat", "DataAdmin.dat");  
 
    system("cls"); 
    ViewAdmin();
}


void DeleteAdmin(){

	int cari;
	int kolom = 0, baris = 0 ;
	int found=0;
	
	TampilanIsi();
	ViewAdmin();
	
	DataAdmin 		= fopen("DataAdmin.dat", "r+");
	Temp			= fopen("TampungAdm.dat", "a+");

	gotoxy(kolom+5,baris+28);	printf("ID YANG AKAN DIHAPUS : ADM"); scanf("%d", &cari); 
    
	while(fread(&admin, sizeof(admin), 1, DataAdmin)){
		if(admin.IDAdmin == cari){
			MessageBox(NULL, "Data Telah Dihapus!","Data Dihapus",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			found=found+1;
		}else if(admin.IDAdmin != cari){
			fwrite(&admin, sizeof(admin), 1, Temp);
		}
	}
	
	if(found<1){
    	MessageBox(NULL, "Data Tidak Ditemukan!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
	}
			
	fclose(DataAdmin);
	fclose(Temp);
	
	remove("DataAdmin.dat");
    rename("TampungAdm.dat", "DataAdmin.dat");  
    
	system("cls");	
    ViewAdmin();
}
