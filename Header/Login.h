Login(){
	
typedef struct {
	int IDKaryawan;
	char KodeKaryawan[50];
	char NamaKaryawan[50];
	char NomorTelepon[20];
	char Alamat[15];
	char Uname[100];
	char Pass[100];
}DataKyw;

DataKyw karyawan;
FILE *DataKaryawan;


typedef struct {
	int IDAdmin;
	char KodeAdmin[50];
	char NamaAdmin[50];
	char NomorTelepon[20];
	char Alamat[15];
	char Uname[100], Pass[100];
}DataAdm;

DataAdm admin;
FILE *DataAdmin;


	system("cls");	
	TampilanLogin();
	

	underline(79,22, "MENU LOGIN");
	
	char username[100];
	char password[100];
	
	gotoxy(57,26);	printf("Username");
	gotoxy(57,32);	printf("Password");
	gotoxy(57,28);	gets(username);
	gotoxy(57,34);
	
	
	if(strcmp("0", username) == 0){
    	gotoxy(10, 45); 
		exit(0);
		
	}else if(strcmp("0", username) != 0){
		
		char ch;	//deklarasi input karakter satu2
		int i = 0;	//deklar i buat looping 
	
		while((ch = getch()) != '\r'){	//getch dimasukin ke ch selama getch nya bukan enter
			if (ch != '\b'){ //Kalo dia bukan backspace dan 0 maka input dan tampil bintang
				password[i] = ch;
				printf("*");
				i++;
		
			}else if(ch == '\b' && i != 0){  //Kalo dia backspace maka hapus bintang
				printf("\b \b"); //untuk menghapus *
				i--;
				password[i]='\0'; // untuk menghapus isi array di password
			}		
		}
	}
	system("cls");
	
	DataKaryawan = fopen("DataKasir.dat", "r");
		
	while (fread(&karyawan,sizeof(karyawan),1,DataKaryawan)){	
		if(strcmp(username, karyawan.Uname)==0 && strcmp(password, karyawan.Pass)==0){
			MessageBox(NULL, "Selamat Datang Kasir!","Selamat Datang",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			fclose(DataKaryawan);
			Kasir();
			break;
		}
	}
	fclose(DataKaryawan);
	
	
	DataAdmin = fopen("DataAdmin.dat", "r");
		
	while (fread(&admin,sizeof(admin),1,DataAdmin)){	
		if(strcmp(username, admin.Uname)==0 && strcmp(password, admin.Pass)==0){
			MessageBox(NULL, "Selamat Datang Admin!","Selamat Datang",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			fclose(DataAdmin);
			Admin();
			break;
		}
	}
	fclose(DataAdmin);

		
	if(strcmp(username,"pemilik")==0 && strcmp (password,"pemilik")== 0){
		MessageBox(0, "Selamat Datang Pemilik", "Selamat Datang", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);	
		fflush(stdin);
		Pemilik();
					
	}else{
		MessageBox(0, "Data yang anda input salah", "Maaf", MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
    	fflush(stdin);
		Login();
	}
}
