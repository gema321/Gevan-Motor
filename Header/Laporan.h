void LaporanTransaksi();
void LaporanUrutNama();
void LaporanTransaksiHari();
void LaporanTransaksiBulan();
void LaporanTransaksiTahun();
void LaporanTerlaris();

Laporan(){
	int menu;
	menu !=7;
	int kolom = 5;
	
	while (menu != 7){
		system("cls");
		TampilanIsi();
		gotoxy(kolom+8,12);	printf("MENU LAPORAN");
    	gotoxy(kolom,16);	printf("[1] Riwayat Transaksi");
    	gotoxy(kolom,18);	printf("[2] 3 Barang Terlaris");
		gotoxy(kolom,20);	printf("[3] Bedasarkan Nama");
		gotoxy(kolom,22);	printf("[4] Bedasarkan Hari");
		gotoxy(kolom,24);	printf("[5] Bedasarkan Bulan");
		gotoxy(kolom,26);	printf("[6] Bedasarkan Tahun");
		gotoxy(kolom,28);	printf("[7] Keluar");
		gotoxy(kolom,30);	printf("Pilih Menu :[ ]");
		gotoxy(kolom+13,30);	scanf("%d", &menu);	
	
	
	switch(menu){
		case 1 :
			LaporanTransaksi();
			gotoxy(5, 32);printf("Tekan apapun untuk lanjut!");	
			getch();			
		break;
		
		case 2 :
			LaporanTerlaris();
			gotoxy(5, 32);printf("Tekan apapun untuk lanjut!");	
			getch();			
		break;
		
		case 3 :
			LaporanUrutNama();
			gotoxy(5, 32);printf("Tekan apapun untuk lanjut!");	
			getch();
		break;
		
		case 4 :
			LaporanTransaksiHari();
			gotoxy(5, 32);printf("Tekan apapun untuk lanjut!");	
			getch();
		break;
		
		case 5 :
			LaporanTransaksiBulan();
			gotoxy(5, 32);printf("Tekan apapun untuk lanjut!");	
			getch();
		break;	
		
		case 6 :
			LaporanTransaksiTahun();
			gotoxy(5, 32);printf("Tekan apapun untuk lanjut!");	
			getch();			
		}
	}
	
}



void LaporanTransaksi(){
	
	LihatTransaksi();

}

RincianTransaksi Transaksi;
typedef RincianTransaksi Simpan[500];


void Save(Simpan A, int *n){
	int i;
	i=0;
	*n = 0;
	DataTransaksi = fopen("DataTransaksi.dat", "r+");
	
	while(fread(&Transaksi, sizeof(Transaksi), 1, DataTransaksi)){
	A[i] = Transaksi;
	i++;
	*n = *n+1;
	}
	fclose(DataTransaksi);
}


void Urut(Simpan A,int n){
	int i;
	int pass;
	int k;
	RincianTransaksi temp;
	int kolom = 46, baris = 15;

	Save(A,&n);	
	for(pass = 0; pass <= n-2; pass++){
		for(k = n-1; k>= pass+1; k--){
			if(strcmp(A[k].nama , A[k-1].nama)<0){
				temp = A[k];
				A[k] = A[k-1];
				A[k-1] = temp;
			}
		}
	}
	Hline(44, 157, 13, 196);
	Hline(44, 157, 15, 196);
	
	gotoxy(kolom,baris-1);		printf("Kode"); 
	gotoxy(kolom+10,baris-1);	printf("Nama");
	gotoxy(kolom+32,baris-1);	printf("Nama Motor");
	gotoxy(kolom+46,baris-1);	printf("No Plat");
	gotoxy(kolom+58,baris-1);	printf("No Handphone");
	gotoxy(kolom+74,baris-1);	printf("Alamat");
	gotoxy(kolom+86,baris-1);	printf("Tanggal");
	gotoxy(kolom+100,baris-1);	printf("Total Harga");

	for(i=0; i<n; i++){
		
	gotoxy(kolom,baris+1);			printf("%s", A[i].kode);
	gotoxy(kolom+10,baris+1);		printf("%s", A[i].nama);
	gotoxy(kolom+32,baris+1);		printf("%s", A[i].motor);
	gotoxy(kolom+46,baris+1);		printf("%s", A[i].plat);
	gotoxy(kolom+58,baris+1);		printf("%s", A[i].Telepon);
	gotoxy(kolom+74,baris+1);		printf("%s", A[i].alamat);
	gotoxy(kolom+86,baris+1);		printf("%d/%d/%d",A[i].hari, A[i].bulan, A[i].tahun);	
	gotoxy(kolom+100,baris+1);		printf("%d", A[i].total);
	
		baris++;
	}		
}


DetailServis details;
typedef DetailServis Simpans [500];


void Saves(Simpans S, int *ns){
	int i;
	i=0;
	*ns = 0;
	
	DataDetailServis = fopen("DataDetailServis.dat", "r+");
	
	while(fread(&details, sizeof(details), 1, DataDetailServis)){
		S[i] = details;
		i++;
		*ns = *ns+1;
	}
	fclose(DataDetailServis);
}


void Uruts(Simpans S, int ns){
	int i;
	int pass;
	int k;
	DetailServis temps;
	int kolom = 50, baris = 4;
	
	Saves(S,&ns);
	for(pass = 0; pass <= ns-2; pass++){
		for(k = ns-1; k>= pass+1; k--){
			if(strcmp(S[k].nama, S[k-1].nama)<0){
				temps = S[k];
				S[k] = S[k-1];
				S[k-1] = temps;
			}
		}
	}
		Hline(47, 127, 13, 196);
		Hline(47, 127, 15, 196);	
			gotoxy(kolom,baris+10);		printf("Kode Transaksi");
			gotoxy(kolom+20,baris+10);	printf("Kode Servis");
			gotoxy(kolom+40,baris+10);	printf("Nama Servis");
			gotoxy(kolom+65,baris+10);	printf("Harga Servis");	
	
			for(i=0; i<ns; i++){	
				gotoxy(kolom,baris+12);		printf("%s", S[i].kodetrss);
				gotoxy(kolom+20,baris+12);	printf("%s", S[i].kodeser);
				gotoxy(kolom+40,baris+12);	printf("%s", S[i].namaser);
				gotoxy(kolom+65,baris+12);	printf("%d", S[i].hargaser);
				baris++;
			}
}


DetailBarang detailb;
typedef DetailBarang Simpanb [500];

void Saveb(Simpanb B, int *nb){
	int i;
	i=0;
	*nb = 0;
	
	DataDetailBarang = fopen("DataDetailBarang.dat", "r+");
	
	while(fread(&detailb, sizeof(detailb), 1, DataDetailBarang)){
		B[i] = detailb;
		i++;
		*nb = *nb+1;
	}
	fclose(DataDetailBarang);
}


void Urutb(Simpanb B, int nb){
	int i;
	int pass;
	int k;
	DetailBarang tempb;
	int kolom = 50, baris = 7;
	
	Saveb(B,&nb);
	for(pass = 0; pass <= nb-2; pass++){
		for(k = nb-1; k>= pass+1; k--){
			if(strcmp(B[k].nama, B[k-1].nama)<0){
				tempb = B[k];
				B[k] = B[k-1];
				B[k-1] = tempb;
			}
		}
	}
	
			Hline(47, 127, 13, 196);
			Hline(47, 127, 15, 196);
			gotoxy(kolom,baris+7);		printf("Kode Transaksi");
			gotoxy(kolom+20,baris+7);	printf("Kode Barang");
			gotoxy(kolom+40,baris+7);	printf("Nama Barang");
			gotoxy(kolom+65,baris+7);	printf("Harga Barang");	
	
			for(i=0; i<nb; i++){	
				gotoxy(kolom,baris+9);		printf("%s", B[i].kodetrsb);
				gotoxy(kolom+20,baris+9);	printf("%s", B[i].kodebar);
				gotoxy(kolom+40,baris+9);	printf("%s", B[i].namabar);
				gotoxy(kolom+65,baris+9);	printf("%d", B[i].hargabar);
				baris++;
			}
}


void LaporanUrutNama(){
	Simpan A;
	int n;
	
	
	Urut(A,n);

	char Lihat[50];
	fflush(stdin);
	gotoxy(5,31);		printf("Lihat Detail Transaksi?(y/n):"); gets(Lihat);
	
	if(strcmp(Lihat, "y")==0){
	
		int kolom = 38, baris = 8;
		int pil;
		pil !=3;
		while(pil !=3){
	system("cls");
	TampilanIsi();	
	gotoxy(0,12);	printf("\tMENU DETAIL TRANSAKSI");
	gotoxy(5,16);	printf("[1] Detail Servis");	
	gotoxy(5,18);	printf("[2] Detail Ganti Barang");
	gotoxy(5,20);	printf("[3] Keluar");
	gotoxy(5,22); 	printf("Pilih :[ ]");	
	gotoxy(13,22);  scanf("%d", &pil);
		
		if(pil==1){
			Simpans S;
			int ns;
			Uruts(S, ns);	
		gotoxy(5, 32);printf("Tekan apapun untuk lanjut!");
		getch();
		
		}else if(pil==2){
			Simpanb B;
			int nb;
			Urutb(B, nb);
		gotoxy(5, 32);printf("Tekan apapun untuk lanjut!");
		getch();
		}
		}
	}
}


void TampilDetails(){
	FILE *LaporanDetailServis;
		int kolom=48, baris=7;	
		Hline(47, 127, 13, 196);
		Hline(47, 127, 15, 196);
		TampilanIsi();
		gotoxy(kolom,baris+7);		printf("Kode Transaksi");
		gotoxy(kolom+20,baris+7);	printf("Kode Servis");
		gotoxy(kolom+40,baris+7);	printf("Nama Servis");
		gotoxy(kolom+65,baris+7);	printf("Harga Servis");

		
		LaporanDetailServis = fopen("LaporanDetailServis.dat", "r");
		while(fread(&details, sizeof(details), 1, LaporanDetailServis)){	
			gotoxy(kolom,baris+9);		printf("%s", details.kodetrss);
			gotoxy(kolom+20,baris+9);	printf("%s", details.kodeser);
			gotoxy(kolom+40,baris+9);	printf("%s", details.namaser);
			gotoxy(kolom+65,baris+9);	printf("%d", details.hargaser);
				baris++;
		}fclose(LaporanDetailServis);
		gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
		getch();
}


void TampilDetailb(){
	FILE *LaporanDetailBarang;
		int kolom=48, baris=7;	
		Hline(47, 127, 13, 196);
		Hline(47, 127, 15, 196);
		TampilanIsi();
		gotoxy(kolom,baris+7);		printf("Kode Transaksi");
		gotoxy(kolom+20,baris+7);	printf("Kode Barang");
		gotoxy(kolom+40,baris+7);	printf("Nama Barang");
		gotoxy(kolom+65,baris+7);	printf("Harga Barang");

		
		LaporanDetailBarang = fopen("LaporanDetailBarang.dat", "r");
		while(fread(&detailb, sizeof(detailb), 1, LaporanDetailBarang)){	
			gotoxy(kolom,baris+9);		printf("%s", detailb.kodetrsb);
			gotoxy(kolom+20,baris+9);	printf("%s", detailb.kodebar);
			gotoxy(kolom+40,baris+9);	printf("%s", detailb.namabar);
			gotoxy(kolom+65,baris+9);	printf("%d", detailb.hargabar);
				baris++;
		}fclose(LaporanDetailBarang);
		gotoxy(5, 31);printf("Tekan apapun untuk lanjut!");	
		getch();	
}


void TampilLaporan(){
	int TotalTransaksi;
	int TotalPendapatan;
	TotalTransaksi = 0;
	int j,i;
	FILE *DataLaporan,*LaporanDetailServis,*LaporanDetailBarang;
	int baris = 20, kolom=43;
	Hline(40, 161, 18, 196);
	Hline(40, 161, 20, 196);
	gotoxy(kolom,baris-1);		printf("Kode");
	gotoxy(kolom+7,baris-1);	printf("Nama");
	gotoxy(kolom+16,baris-1);	printf("Nama Motor");
	gotoxy(kolom+30,baris-1);	printf("No Plat");
	gotoxy(kolom+43,baris-1);	printf("No Handphone");
	gotoxy(kolom+64,baris-1);	printf("Alamat");
	gotoxy(kolom+75,baris-1);	printf("Tanggal");
	gotoxy(kolom+90,baris-1);	printf("Total Harga");
	
	
	DataLaporan = fopen("DataLaporan.dat", "rb");
	fread(&Transaksi, sizeof(Transaksi), 1, DataLaporan);
	while(!feof(DataLaporan))
	{
	TotalPendapatan = TotalPendapatan + Transaksi.total;
	gotoxy(kolom,baris+1);		printf("%s", Transaksi.kode);
	gotoxy(kolom+7,baris+1);		printf("%s", Transaksi.nama);
	gotoxy(kolom+16,baris+1);		printf("%s", Transaksi.motor);
	gotoxy(kolom+30,baris+1);		printf("%s", Transaksi.plat);
	gotoxy(kolom+43,baris+1);		printf("%s", Transaksi.Telepon);
	gotoxy(kolom+64,baris+1);		printf("%s", Transaksi.alamat);
	gotoxy(kolom+75,baris+1);		printf("%d/%d/%d", Transaksi.hari, Transaksi.bulan, Transaksi.tahun);
	gotoxy(kolom+90,baris+1);		printf("%d", Transaksi.total);		
		baris++;
	fread(&Transaksi, sizeof(Transaksi), 1, DataLaporan);	
	}
	
	gotoxy(kolom+80,baris+3); 	printf("Total Pendapatan : %d", TotalPendapatan);
	
	
	char Lihat[50];
	fflush(stdin);
	gotoxy(kolom,baris+3);		printf("Apakah Ingin Melihat Detail Transaksi (y/n): "); gets(Lihat);
	
	if(strcmp(Lihat, "y")==0){
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
			TampilDetails();
		}
		else if(pil==2){
			TampilDetailb();
		}
	}

	fclose(DataLaporan);	
	}
}




void LaporanTransaksiHari(){
	TampilanIsi();
	int CekHari;
	int CekBulan;
	int CekTahun;
	int baris = 16, kolom = 49;
	FILE *DataLaporan;
	FILE *DataTransaksi;
	FILE *DataDetailServis;
	FILE *LaporanDetailServis;
	FILE *LaporanDetailBarang;
	
	underline(kolom, baris-3, "LAPORAN TRANSAKSI HARIAN");	
	gotoxy(kolom, baris);printf("Masukkan Tanggal : "); scanf("%d", &CekHari);
	gotoxy(kolom+30, baris);printf("Masukkan Bulan : "); scanf("%d", &CekBulan);
	gotoxy(kolom+60, baris);printf("Masukkan Tahun : "); scanf("%d", &CekTahun);
	
	
	DataTransaksi = fopen("DataTransaksi.dat", "r");
	DataLaporan = fopen("DataLaporan.dat", "wb");
	
	fread(&Transaksi, sizeof(Transaksi), 1, DataTransaksi);
	while(!feof(DataTransaksi)){
	
		if((CekHari == Transaksi.hari) && (CekBulan == Transaksi.bulan) && (CekTahun == Transaksi.tahun)){
			fwrite(&Transaksi, sizeof(Transaksi), 1, DataLaporan);
		}
		fread(&Transaksi, sizeof(Transaksi), 1, DataTransaksi);
	}
	

	DataDetailServis 	= fopen("DataDetailServis.dat", "r");
	LaporanDetailServis = fopen("LaporanDetailServis.dat", "wb");		
	
	fread(&details, sizeof(details), 1, DataDetailServis);
	while(!feof(DataDetailServis)){		
	
			if(((CekHari == details.hari) && (CekBulan == details.bulan) && (CekTahun == details.tahun))){
			fwrite(&details, sizeof(details), 1, LaporanDetailServis);
			}
			fread(&details, sizeof(details), 1, DataDetailServis);
		}
		
		
	DataDetailBarang 	= fopen("DataDetailBarang.dat", "r");
	LaporanDetailBarang = fopen("LaporanDetailBarang.dat", "wb");
	
	fread(&detailb, sizeof(detailb), 1, DataDetailBarang);
	while(!feof(DataDetailBarang)){		
	
			if((CekHari == detailb.hari) && (CekBulan == detailb.bulan) && (CekTahun == detailb.tahun)){
			fwrite(&detailb, sizeof(detailb), 1, LaporanDetailBarang);
				}
			fread(&detailb, sizeof(detailb), 1, DataDetailBarang);
		}		
		
		

	fclose(DataDetailBarang);
	fclose(LaporanDetailBarang);
			
	fclose(DataDetailServis);
	fclose(LaporanDetailServis);
	
	fclose(DataTransaksi);
	fclose(DataLaporan);
	TampilLaporan();		
}


void LaporanTransaksiBulan(){
	TampilanIsi();
	int CekBulan;
	int CekTahun;
	int baris = 15, kolom = 49;
	FILE *DataLaporan;
	FILE *DataTransaksi;
	FILE *LaporanDetailServis;
	FILE *LaporanDetailBarang;	

	underline(kolom, baris-3, "LAPORAN TRANSAKSI BULANAN");	
	gotoxy(kolom+30, baris);printf("Masukkan Bulan : "); scanf("%d", &CekBulan);
	gotoxy(kolom+60, baris);printf("Masukkan Tahun : "); scanf("%d", &CekTahun);
	
	DataTransaksi = fopen("DataTransaksi.dat", "r");
	DataLaporan = fopen("DataLaporan.dat", "wb");
	
	fread(&Transaksi, sizeof(Transaksi), 1, DataTransaksi);
	while(!feof(DataTransaksi))
	{
		if((CekBulan == Transaksi.bulan) && (CekTahun == Transaksi.tahun))
		{
			fwrite(&Transaksi, sizeof(Transaksi), 1, DataLaporan);
		}
		fread(&Transaksi, sizeof(Transaksi), 1, DataTransaksi);
	}
	
	DataDetailServis 	= fopen("DataDetailServis.dat", "r");
	LaporanDetailServis = fopen("LaporanDetailServis.dat", "wb");		
	
	fread(&details, sizeof(details), 1, DataDetailServis);
	while(!feof(DataDetailServis)){		
	
			if((CekBulan == details.bulan) && (CekTahun == details.tahun)){
			fwrite(&details, sizeof(details), 1, LaporanDetailServis);
				}
			fread(&details, sizeof(details), 1, DataDetailServis);
		}
		
		
	DataDetailBarang 	= fopen("DataDetailBarang.dat", "r");
	LaporanDetailBarang = fopen("LaporanDetailBarang.dat", "wb");		
	
	fread(&detailb, sizeof(detailb), 1, DataDetailBarang);
	while(!feof(DataDetailBarang)){		
	
			if((CekBulan == detailb.bulan) && (CekTahun == detailb.tahun)){
			fwrite(&detailb, sizeof(detailb), 1, LaporanDetailBarang);
				}
			fread(&detailb, sizeof(detailb), 1, DataDetailBarang);
		}		
		
		

	fclose(DataDetailBarang);
	fclose(LaporanDetailBarang);
			
	fclose(DataDetailServis);
	fclose(LaporanDetailServis);	
	
	
		
	fclose(DataTransaksi);
	fclose(DataLaporan);
	TampilLaporan();
}


void LaporanTransaksiTahun(){
	TampilanIsi();
	int CekTahun;
	int baris = 15, kolom = 49;
	FILE *DataLaporan;
	FILE *DataTransaksi;
	FILE *LaporanDetailServis;
	FILE *LaporanDetailBarang;	
	
	underline(kolom, baris-3, "LAPORAN TRANSAKSI BULANAN");	
	gotoxy(kolom+60, baris);printf("Masukkan Tahun : "); scanf("%d", &CekTahun);
	
	DataTransaksi = fopen("DataTransaksi.dat", "r");
	DataLaporan = fopen("DataLaporan.dat", "wb");
	
	fread(&Transaksi, sizeof(Transaksi), 1, DataTransaksi);
	while(!feof(DataTransaksi))
	{
		if(CekTahun == Transaksi.tahun)
		{
			fwrite(&Transaksi, sizeof(Transaksi), 1, DataLaporan);
		}
		fread(&Transaksi, sizeof(Transaksi), 1, DataTransaksi);
	}
	
	
	DataDetailServis 	= fopen("DataDetailServis.dat", "r");
	LaporanDetailServis = fopen("LaporanDetailServis.dat", "wb");		
	
	fread(&details, sizeof(details), 1, DataDetailServis);
	while(!feof(DataDetailServis)){		
	
			if(CekTahun == details.tahun){
			fwrite(&details, sizeof(details), 1, LaporanDetailServis);
				}
			fread(&details, sizeof(details), 1, DataDetailServis);
		}
		
		
	DataDetailBarang 	= fopen("DataDetailBarang.dat", "r");
	LaporanDetailBarang = fopen("LaporanDetailBarang.dat", "wb");		
	
	fread(&detailb, sizeof(detailb), 1, DataDetailBarang);
	while(!feof(DataDetailBarang)){		
	
			if(CekTahun == detailb.tahun){
			fwrite(&detailb, sizeof(detailb), 1, LaporanDetailBarang);
				}
			fread(&detailb, sizeof(detailb), 1, DataDetailBarang);
		}		
		
		

	fclose(DataDetailBarang);
	fclose(LaporanDetailBarang);
			
	fclose(DataDetailServis);
	fclose(LaporanDetailServis);		
	
		
	fclose(DataTransaksi);
	fclose(DataLaporan);
	TampilLaporan();
}


RincianBarang produk;
typedef RincianBarang SimpanT[500];


void SaveT(SimpanT T, int *nt){
	int i;
	i=0;
	*nt = 0;
	
	DataBarang = fopen("DataBarang.dat", "r+");
	
	while(fread(&produk, sizeof(produk), 1, DataBarang)){
		T[i] = produk;
		i++;
		*nt = *nt+1;
	}
	fclose(DataBarang);
}


void UrutT(SimpanT T, int nt){
	int i;
	int pass;
	int k;
	RincianBarang tempT;
	int kolom = 50, baris = 6;
	
	SaveT(T,&nt);
	for(pass = 0; pass <= nt-2; pass++){
		for(k = nt-1; k>= pass+1; k--){
			if(T[k].terjual > T[k-1].terjual){
				tempT = T[k];
				T[k] = T[k-1];
				T[k-1] = tempT;
			}
		}
	}
		Hline(47, 105, 15, 196);
		Hline(47, 105, 17, 196);	
			gotoxy(kolom,baris+10);		printf("Kode Barang");
			gotoxy(kolom+20,baris+10);	printf("Nama Barang");
			gotoxy(kolom+40,baris+10);	printf("Jumlah Terjual");
	
			for(i=0; i<3; i++){
				gotoxy(kolom,baris+12);		printf("%s", T[i].KodeBarang);
				gotoxy(kolom+20,baris+12);	printf("%s", T[i].NamaBarang);
				gotoxy(kolom+40,baris+12);	printf("%d", T[i].terjual);
				baris++;
			}
}

void LaporanTerlaris(){
	
		underline(50, 12,"LAPORAN 3 BARANG TERLARIS");
		SimpanT T;
		int nt;
		UrutT(T, nt);	
}
