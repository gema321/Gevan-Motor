#include "MasterKasir.h"
#include "MasterServis.h"
#include "MasterBarang.h"
#include "MasterAdmin.h"
#include "Transaksi.h"
#include "Laporan.h"


Admin(){

	int menu;
	int kolom = 0, baris = 2;
	
	system("cls");
	TampilanIsi();

	gotoxy(kolom+8,baris+10);printf("SELAMAT DATANG ADMIN");
	gotoxy(kolom+5,baris+14);printf("Menu Master :");
	gotoxy(kolom+5,baris+16);printf("[1] Master Servis"); 
	gotoxy(kolom+5,baris+18);printf("[2] Master Barang"); 
	gotoxy(kolom+5,baris+20);printf("[3] Log Out");
	gotoxy(kolom+5,baris+22);printf("Pilih Menu :[ ]");  
	gotoxy(kolom+18,baris+22);scanf("%d", &menu);
	system("cls");
	
	switch(menu){
		
		case 1 :
			Service(); 
			system("cls");
			Admin();
		
		case 2 : 
			Barang(); 
			system("cls");
			Admin();
		
		case 3 : 
			fflush(stdin); //buffer enter karena sebelumnya input int di variabel (menu)
			Login();
		   
	}while(menu!=3);
}


Kasir(){

	int menu;
	int kolom = 0, baris = 0;

	system("cls");
	TampilanIsi();
	
	gotoxy(kolom+8,baris+12);	printf("SELAMAT DATANG KASIR");
	gotoxy(kolom+5,baris+16);	printf("Menu Master :");
	gotoxy(kolom+5,baris+18);	printf("[1] Buat Transaksi"); 
	gotoxy(kolom+5,baris+20);	printf("[2] Lihat Transaksi");
	gotoxy(kolom+5,baris+22);	printf("[3] Keluar"); 
	gotoxy(kolom+5,baris+24);	printf("Pilih Nomor :[ ]"); 
	gotoxy(kolom+19,kolom+24);	scanf("%d", &menu); 
	
	switch(menu){
		
		case 1 : BuatTransaksi(); 	
		Kasir();
		
		case 2 : LihatTransaksi(); 
		Kasir();
		
		case 3 :
		fflush(stdin);		
		Login();
			    
	}
}


Pemilik(){
	
	int menu;
	int kolom = 0, baris = 2;
	
	system("cls");
	TampilanIsi();

	gotoxy(kolom+8,baris+10);	printf("SELAMAT DATANG PEMILIK");
	gotoxy(kolom+5,baris+14);	printf("MENU MASTER");
	gotoxy(kolom+5,baris+16);	printf("[1] Laporan Transaksi"); 
	gotoxy(kolom+5,baris+18);	printf("[2] Data Admin");
	gotoxy(kolom+5,baris+20);	printf("[3] Data Kasir");
	gotoxy(kolom+5,baris+22);	printf("[4] Keluar"); 
	gotoxy(kolom+5,baris+24);	printf("Pilih Nomor :[ ]");
	gotoxy(kolom+19,baris+24); 	scanf("%d", &menu); 
	system("cls");
	
	switch(menu){
		
		case 1 : 
			Laporan(); 		
			Pemilik();	
			
		case 2 : 
			AkunAdmin();
			Pemilik();
		
		case 3 : 
			Karyawan();
			Pemilik();
		
		case 4 : 
			fflush(stdin);
			Login();
	
	}while(menu!=4);	
	
}
