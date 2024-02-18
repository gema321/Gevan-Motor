typedef struct{
	int ID;
	char kode[50];
	char nama[50];
	char motor[50];
	char plat[50];
	char Telepon[50];
	char alamat[50];
	
	char Servis[50];
	char Barang[50];
	int total;
	int bayar;
	int kembali;
	int JumlahSer;
	int JumlahBar;
	
	int hari,bulan,tahun;
}RincianTransaksi;

RincianTransaksi Transaksi;
FILE *DataTransaksi;


typedef struct{
	char kodetrss[50];
	char nama[50];
	char kodeser[50];
	char namaser[50];
	int hargaser;
	int hari, bulan, tahun;
}DetailServis;

DetailServis details;
FILE *DataDetailServis;


typedef struct{
	char kodetrsb[50];
	char nama[50];
	char kodebar[50];
	char namabar[50];
	int hargabar;
	int hari, bulan, tahun;
}DetailBarang;

DetailBarang detailb;
FILE *DataDetailBarang;


FILE *TempBarang;

void KurangStok(){
	
	DataBarang = fopen("DataBarang.dat", "r");
	TempBarang = fopen("TempBarang.dat", "w"); 
	
	fread(&produk, sizeof(produk), 1, DataBarang);
	while (!feof(DataBarang))
	{
	fwrite(&produk, sizeof(produk), 1 , TempBarang);
	fread(&produk, sizeof(produk), 1, DataBarang);
	}
	fclose(DataBarang);
	fclose(TempBarang);


	DataBarang = fopen("DataBarang.dat", "w");
	TempBarang = fopen("TempBarang.dat", "r");

	fread(&produk, sizeof(produk), 1 , TempBarang);
	while(!feof(TempBarang))
	{
		if((strcmp(Transaksi.Barang, produk.KodeBarang)==0))
		{
		produk.stok = produk.stok - 1;
		produk.terjual = produk.terjual + 1;
		}
		fwrite(&produk, sizeof(produk), 1 , DataBarang);
		fread(&produk, sizeof(produk), 1 , TempBarang);
	}
	fclose(DataBarang);
	fclose(TempBarang);
}


void SimpanDetailServis(){
	
	DataDetailServis = fopen("DataDetailServis.dat", "ab+");

	strcpy(details.kodetrss, Transaksi.kode);
	strcpy(details.nama, Transaksi.nama);
	strcpy(details.kodeser, servis.KodeServis);
	strcpy(details.namaser, servis.NamaServis);
	details.hargaser = servis.harga;
	fwrite(&details, sizeof(details), 1 , DataDetailServis);

	fclose(DataDetailServis);
}

void SimpanDetailBarang(){
	
	DataDetailBarang = fopen("DataDetailBarang.dat", "ab+");

	strcpy(detailb.kodetrsb, Transaksi.kode);
	strcpy(detailb.nama, Transaksi.nama);
	strcpy(detailb.kodebar, produk.KodeBarang);
	strcpy(detailb.namabar, produk.NamaBarang);
	detailb.hargabar = produk.harga;
	fwrite(&detailb, sizeof(detailb), 1 , DataDetailBarang);

	fclose(DataDetailBarang);
}



void LihatBarang();
void LihatServis();

void BuatTransaksi(){
	
	int pilih, lastid=0;
	char Kode[5],code[25];
	int HargaServis=0;
	int HargaBarang=0;
	int found=0;
	int i;
	
	int baris = 15, kolom = 49;
	
	DataTransaksi = fopen("DataTransaksi.dat", "ab+");
	
	while(fread(&Transaksi,sizeof(Transaksi),1,DataTransaksi)==1)
	{
		lastid=Transaksi.ID;
	}
	
	lastid=lastid+1;
	sprintf(Kode,"%i",lastid);
	strcpy(code,"TRS");
	strcpy(Kode,strcat(code,Kode));
	
	gotoxy(kolom,baris);	printf("Kode Transaksi\t: "); 	printf("%s",Kode); Transaksi.ID=lastid;strcpy(Transaksi.kode,Kode);	
	gotoxy(kolom,baris+2);	printf("Nama Pelanggan\t: "); 
	gotoxy(kolom,baris+4);	printf("Nama Motor\t: ");
	gotoxy(kolom,baris+6);	printf("Plat Nomor\t: ");
	gotoxy(kolom,baris+8);	printf("No Handphone\t: "); 
	gotoxy(kolom,baris+10);	printf("Alamat\t\t: "); 

	fflush(stdin); 
	gotoxy(kolom+17,baris+2);	gets(Transaksi.nama);
	gotoxy(kolom+17,baris+4);	gets(Transaksi.motor);
	gotoxy(kolom+17,baris+6);	gets(Transaksi.plat);
	gotoxy(kolom+17,baris+8);	gets(Transaksi.Telepon);
	gotoxy(kolom+17,baris+10);	gets(Transaksi.alamat);	


 //---------------------------------------Tanggalan Start-----------------------------------------
	/* Declaration */
		
	struct 
	{
	       int tahun;
	       int bulan;
	       int hari;
	}waktu;
	
	
	time_t t1 = time(0);
	struct tm * now = localtime(&t1);
	
	waktu.tahun=now->tm_year+1900;
	waktu.bulan=now->tm_mon+1;
	waktu.hari=now->tm_mday;

	gotoxy(kolom,baris+12);	printf("Tanggal\t: %i - %i - %i",waktu.hari,waktu.bulan,waktu.tahun); // tanggal hari ini
	Transaksi.hari=waktu.hari;
	Transaksi.bulan=waktu.bulan;
	Transaksi.tahun=waktu.tahun;
	
	details.hari=waktu.hari;
	details.bulan=waktu.bulan;
	details.tahun=waktu.tahun;
	
	detailb.hari=waktu.hari;
	detailb.bulan=waktu.bulan;
	detailb.tahun=waktu.tahun;
	
	
//------------------------------------------Tanggalan end-----------------------------------------------

	gotoxy(kolom+17,baris+26); printf("Tekan apapun untuk lanjut");
	getch();
	
	

	while(pilih != 3){
		baris = 7;
		kolom= 49;
	
		system ("cls");
		TampilanIsi();
	
		gotoxy(0,12);	printf("\tMENU TRANSAKSI");
		gotoxy(5,16);	printf("[1] Servis");
		gotoxy(5,18);	printf("[2] Ganti Barang");
		gotoxy(5,20);	printf("[3] Selesai");	
		gotoxy(5,22);   printf("Pilih Transaksi :[ ]");	
 		gotoxy(23,22);  scanf("%d", &pilih);
	
		switch(pilih){
	
		case 1 :
			
			underline(50, 12,"TRANSAKSI SERVIS");
			LihatServis();
			
			baris = 3;
			kolom= 45;		
			gotoxy(kolom,baris+12);	printf("Jumlah Servis : ");	scanf("%d", &Transaksi.JumlahSer);
			fflush(stdin);

		for(i=1; i<=Transaksi.JumlahSer; i++){
		
			found = 0;
			strcpy(code,"SER");
			
			gotoxy(kolom,baris+15);	printf("Kode Service ke-%d \t: SER",i); 	scanf("%s", &Kode);
			strcpy(Transaksi.Servis,strcat(code,Kode));
	
			if((DataServis = fopen("DataServis.dat", "r"))==NULL){
				MessageBox(NULL, "Data masih kosong","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				Kasir();
			}
		
			while((!feof(DataServis) && found == 0)){
			
				fread(&servis, sizeof(servis), 1, DataServis);
	
				if (strcmp(Transaksi.Servis, servis.KodeServis) == 0){
					SimpanDetailServis();
					gotoxy(kolom,baris+16);	printf("Nama Service\t: %s", servis.NamaServis);
					gotoxy(kolom,baris+17); printf("Harga Service\t: %d", servis.harga);
					HargaServis = HargaServis + servis.harga;
					found=1;
				}
			}
			
			if (found == 0){
				gotoxy(kolom,baris+16);	printf("Servis Tersebut Tidak Tersedia");
			}
			
			baris = baris + 4;
		
			if(baris >= 25){
				baris = 3;
				kolom = 96;		
			}
		}
		
		gotoxy(77, 44); printf("Tekan apapun untuk lanjut");
		getch();
		break;

		baris=7;
		
		case 2 :
			underline(50, 12,"TRANSAKSI GANTI BARANG");
			LihatBarang();
			baris = 3;
			kolom= 45;		
					
			gotoxy(kolom,baris+12);	printf("Jumlah Ganti Barang : ");	scanf("%d", &Transaksi.JumlahBar);
			fflush(stdin);
	
		for(i=1; i<=Transaksi.JumlahBar; i++){
			found = 0;
			strcpy(code,"BAR");
			gotoxy(kolom,baris+15);	printf("Kode Barang ke-%d \t: BAR",i); 	scanf("%s", &Kode);
			strcpy(Transaksi.Barang,strcat(code,Kode));
	
			if((DataBarang = fopen("DataBarang.dat", "r+"))==NULL){
				MessageBox(NULL, "Data masih kosong","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				Kasir();
			}
		
			while(fread(&produk, sizeof(produk), 1, DataBarang) && found == 0){
				if (strcmp(Transaksi.Barang, produk.KodeBarang)==0){
					if (produk.stok == 0){
						MessageBox(0, "Barang Sedang Tidak Tersedia", "Produk Habis", MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
					}else if (produk.stok > 0){
						SimpanDetailBarang();
						gotoxy(kolom,baris+16);  printf("Nama Barang\t: %s", produk.NamaBarang);
						gotoxy(kolom,baris+17);  printf("Harga Barang\t: %d", produk.harga);
						HargaBarang = HargaBarang + produk.harga;
						KurangStok();
						found=1;
					}
				}
			}	
					
			if (found == 0){
				gotoxy(kolom,baris+16);	printf("Barang Tersebut Tidak Tersedia"); 
			}
			
			baris = baris + 4;
		
			if(baris >= 25){	//agar gesser kekanan 
				baris = 3;
				kolom = 96;
				}
			}
			
		gotoxy(77, 44); printf("Tekan apapun untuk lanjut");
		getch();
		break;
		
		}
		
	Transaksi.total = HargaServis + HargaBarang ;
	}
	int pembayaran = 0;
	int kembali;
	
	
//	gotoxy(kolom+10,baris+10); printf("Harga Servis \t: Rp. %d", HargaServis);
//	gotoxy(kolom+10,baris+12); printf("Harga Barang \t: Rp. %d", HargaBarang);
//	gotoxy(kolom+10, baris+14);	printf("Total Harga \t: Rp. %d", Transaksi.total);
//	gotoxy(kolom+15, baris+18); printf("Bayar \t: Rp. "); scanf("%d", &pembayaran);
	
	
	while(pembayaran < Transaksi.total){
		TampilanIsi();
		
		gotoxy(kolom+10,baris+10); printf("Harga Servis \t: Rp. %d", HargaServis);
		gotoxy(kolom+10,baris+12); printf("Harga Barang \t: Rp. %d", HargaBarang);
		gotoxy(kolom+10, baris+14);	printf("Total Harga \t\t: Rp. %d", Transaksi.total);
		
		gotoxy(kolom+10, baris+16); printf("Bayar \t\t: Rp. "); scanf("%d", &pembayaran);
		
		if(pembayaran < Transaksi.total){
			MessageBox(0, "Pembayaran Kurang", "Maaf", MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
			system("cls");
		}
	}
	kembali = pembayaran - Transaksi.total;
	gotoxy(kolom+10, baris+19); printf("Kembalian \t\t: Rp. %d", kembali); 
		
	gotoxy(72, 37); printf("Tekan apapun untuk mulai!");			
	getch();	
	fwrite(&Transaksi, sizeof(Transaksi), 1 , DataTransaksi);
	fclose(DataTransaksi);
	
	fclose(DataBarang);
    fclose(Temp);
 
    system("cls");

}


void LihatDetailTransaksi(){
	
	int pil;
	pil!=3;
		
	
	
	while(pil!=3){
		
	int kolom = 49, baris = 7;
	
	system("cls");
	TampilanIsi();
	
	gotoxy(0,12);	printf("\tMENU DETAIL TRANSAKSI");
	gotoxy(5,16);	printf("[1] Detail Servis");	
	gotoxy(5,18);	printf("[2] Detail Ganti Barang");
	gotoxy(5,20);	printf("[3] Keluar");
	gotoxy(5,22); 	printf("Pilih :[ ]");	
	gotoxy(13,22);  scanf("%d", &pil);
	
		if(pil==1){
			
			DataDetailServis = fopen("DataDetailServis.dat", "r");
			
			Hline(47, 127, 13, 196);
			Hline(47, 127, 15, 196);
			gotoxy(kolom,baris+7);		printf("Kode Transaksi");
			gotoxy(kolom+20,baris+7);	printf("Kode Servis");
			gotoxy(kolom+40,baris+7);	printf("Nama Servis");
			gotoxy(kolom+65,baris+7);	printf("Harga Servis");

			while(fread(&details, sizeof(details), 1, DataDetailServis)){		
				gotoxy(kolom,baris+9);		printf("%s", details.kodetrss);
				gotoxy(kolom+20,baris+9);	printf("%s", details.kodeser);
				gotoxy(kolom+40,baris+9);	printf("%s", details.namaser);
				gotoxy(kolom+65,baris+9);	printf("%d", details.hargaser);
				baris++;
			}
			fclose(DataDetailServis);
		gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
		getch();
		
		}else if(pil == 2){
			
			DataDetailBarang = fopen("DataDetailBarang.dat", "r");
	
			Hline(47, 127, 13, 196);
			Hline(47, 127, 15, 196);
			gotoxy(kolom,baris+7);		printf("Kode Transaksi");
			gotoxy(kolom+20,baris+7);	printf("Kode Barang");
			gotoxy(kolom+40,baris+7);	printf("Nama Barang");
			gotoxy(kolom+65,baris+7);	printf("Harga Barang");
		
			while(fread(&detailb, sizeof(detailb), 1, DataDetailBarang)){
				gotoxy(kolom,baris+9);		printf("%s", detailb.kodetrsb);
				gotoxy(kolom+20,baris+9);	printf("%s", detailb.kodebar);
				gotoxy(kolom+40,baris+9);	printf("%s", detailb.namabar);
				gotoxy(kolom+65,baris+9);	printf("%d", detailb.hargabar);
				baris++;
			}
			fclose(DataDetailBarang);
		gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
		getch();
		}
	}
}


void LihatTransaksi(){
	int kolom = 42, baris = 15;
	int i;

	TampilanIsi();
	DataTransaksi = fopen("DataTransaksi.dat", "r");
	
	Hline(40, 161, 13, 196);
	Hline(40, 161, 15, 196);
	gotoxy(kolom,baris-1);		printf("Kode"); 
	gotoxy(kolom+10,baris-1);	printf("Nama");
	gotoxy(kolom+32,baris-1);	printf("Nama Motor");
	gotoxy(kolom+48,baris-1);	printf("No Plat");
	gotoxy(kolom+62,baris-1);	printf("No Handphone");
	gotoxy(kolom+80,baris-1);	printf("Alamat");
	gotoxy(kolom+92,baris-1);	printf("Tanggal");
	gotoxy(kolom+107,baris-1);	printf("Total Harga");
	
	while(fread(&Transaksi, sizeof(Transaksi), 1, DataTransaksi)){
		gotoxy(kolom,baris+1);			printf("%s", Transaksi.kode);
		gotoxy(kolom+10,baris+1);		printf("%s", Transaksi.nama);
		gotoxy(kolom+32,baris+1);		printf("%s", Transaksi.motor);
		gotoxy(kolom+48,baris+1);		printf("%s", Transaksi.plat);
		gotoxy(kolom+62,baris+1);		printf("%s", Transaksi.Telepon);
		gotoxy(kolom+80,baris+1);		printf("%s", Transaksi.alamat);
		gotoxy(kolom+92,baris+1);		printf("%i/%i/%i",Transaksi.hari, Transaksi.bulan, Transaksi.tahun);
		gotoxy(kolom+107,baris+1);		printf("%d", Transaksi.total); 
		baris++;
	}
	fclose(DataTransaksi);
		
	char Lihat[50];
	fflush(stdin);
	gotoxy(kolom,baris+3);		printf("Apakah Ingin Melihat Detail Transaksi (y/n): "); gets(Lihat);
	
	if(strcmp(Lihat, "y")==0){
		LihatDetailTransaksi();
	}
	
}


void LihatBarang(){
	
	int kolom=90, baris=1;
		
	TampilanIsi();
	
    DataBarang = fopen("DataBarang.dat", "r");
    
    Vline(13, 45, kolom+43, 179);
	Vline(13, 45, kolom+55, 179);
	Vline(13, 45, kolom+73, 179);
	Hline(kolom+43, kolom+73, 13, 196);
	Hline(kolom+43, kolom+73, 15, 196);
    
    gotoxy(kolom+44, baris+13);		printf("Kode Barang");
	gotoxy(kolom+57, baris+13);		printf("Nama Barang");

    while(fread(&produk, sizeof(produk), 1, DataBarang)){
		gotoxy(kolom+46,baris+15);		printf("%s", produk.KodeBarang);
		gotoxy(kolom+57,baris+15);		printf("%s", produk.NamaBarang);
		baris++;
	}
	fclose(DataBarang);
}


void LihatServis(){
	
	int kolom=90, baris=1;
		
	TampilanIsi();
	
    DataServis = fopen("DataServis.dat", "r");
    
    Vline(13, 45, kolom+43, 179);
	Vline(13, 45, kolom+55, 179);
	Vline(13, 45, kolom+73, 179);
	Hline(kolom+43, kolom+73, 13, 196);
	Hline(kolom+43, kolom+73, 15, 196);
    
    gotoxy(kolom+44, baris+13);		printf("Kode Sevis");
	gotoxy(kolom+57, baris+13);		printf("Nama Servis");

    while(fread(&servis, sizeof(servis), 1, DataServis)){
		gotoxy(kolom+46,baris+15);		printf("%s", servis.KodeServis);
		gotoxy(kolom+57,baris+15);		printf("%s", servis.NamaServis);
		baris++;
	}
	fclose(DataServis);
}
