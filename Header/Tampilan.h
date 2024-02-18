void TampilanAwal(){
	int i, j;
	system("color B0");
			
		for(i=0; i<=167; i++)	//Horizontal Atas
	    {
	        gotoxy(i,0);printf("%c", 219);
		}
		
		for(i=0; i<=167; i++)	//Horizontal Tengah
	    {
	        gotoxy(i,10);printf("%c", 219);
		}
	
		for(i=0; i<=167; i++)	//Horizontal Bawah
	    {
	        gotoxy(i,47);printf("%c", 219);
		}
		
		for(j=1; j<=46; j++)	//Vertikal Kanan-Kiri
	    {
	    	gotoxy(0,j);printf("%c", 219);
	    	gotoxy(1,j);printf("%c", 219);
	        gotoxy(166,j);printf("%c", 219);
			gotoxy(167,j);printf("%c", 219);
		}	
		
		for(i=1; i<=10; i++)	//Tampilan tutup judul samping
		{
		  gotoxy(49,i); printf("%c", 219);
		  gotoxy(50,i); printf("%c", 219);
		  gotoxy(117,i); printf("%c", 219);
		  gotoxy(118,i); printf("%c", 219);
		}
	
	gotoxy(21,4);	printf("APLIKASI");	
	gotoxy(19,6);	printf("BENGKEL MOTOR");		
	
	DrawFile(52, 2, "Text\\Judul.txt");	
	DrawFile(17, 17, "Text\\Motor.txt");
	
	DateTime dateNow;
	DateTimeNow(&dateNow);
	gotoxy(130,4); printf("Tanggal : %02d - %02d - %04d", dateNow.tgl, dateNow.bulan, dateNow.tahun);
	gotoxy(133,6); printf("Pukul : %02d : %02d WIB", dateNow.hour, dateNow.min);	
	

	KotakNama(98, 20, 51, 8);
	underline(118, 21,"KELOMPOK 11");
	gotoxy(101, 25); printf("Dito Modovan Junian");
	gotoxy(136, 25); printf("0320210019");
	gotoxy(101, 27); printf("Muhammad Gema Rhomadhon"); 
	gotoxy(136, 27); printf("0320210041");
	
	loading(69, 36);
	
	gotoxy(72, 40);printf("Tekan apapun untuk mulai!");	
	getch();
	
}


void TampilanLogin(){
		
	
		int i, j;
		system("color B0");
		
		for(i=0; i<=167; i++)	//Horizontal Atas
	    {
	        gotoxy(i,0);printf("%c", 219);
		}
		
		for(i=0; i<=167; i++)	//Horizontal Tengah
	    {
	        gotoxy(i,10);printf("%c", 219);
		}
	
//			for(i=1; i<=38; i++) //Horizontal Tengah bawah 
//		{
//			gotoxy(i,14);printf("%c", 219);
//		}
	
		for(i=0; i<=167; i++)	//Horizontal Bawah
	    {
	        gotoxy(i,47);printf("%c", 219);
		}
		
		for(j=1; j<=46; j++)	//Vertikal Kanan-Kiri
	    {
	    	gotoxy(0,j);printf("%c", 219);
	    	gotoxy(1,j);printf("%c", 219);
	        gotoxy(166,j);printf("%c", 219);
			gotoxy(167,j);printf("%c", 219);
		}	
		
		for(i=1; i<=10; i++)	//Tampilan tutup judul samping
		{
		  gotoxy(49,i); printf("%c", 219);
		  gotoxy(50,i); printf("%c", 219);
		  gotoxy(117,i); printf("%c", 219);
		  gotoxy(118,i); printf("%c", 219);
		}
	
	gotoxy(21,4);	printf("APLIKASI");	
	gotoxy(19,6);	printf("BENGKEL MOTOR");

	DrawFile(52, 2, "Text\\Judul.txt");
		
	DateTime dateNow;
	DateTimeNow(&dateNow);
	gotoxy(130,4); printf("Tanggal : %02d - %02d - %04d", dateNow.tgl, dateNow.bulan, dateNow.tahun);
	gotoxy(133,6); printf("Pukul : %02d : %02d WIB", dateNow.hour, dateNow.min);		
		
	textBox1(51, 20, 64, 20);
	textBox1(56, 27, 54, 2);
	textBox1(56, 33, 54, 2);	
	
	gotoxy(57,38);
	printf("[0] Kembali");
}

void TampilanIsi(){
		
	
		int i, j;
		system("color B0");
		
		for(i=0; i<=167; i++)	//Horizontal Atas
	    {
	        gotoxy(i,0);printf("%c", 219);
		}
		
		for(i=0; i<=167; i++)	//Horizontal Tengah
	    {
	        gotoxy(i,10);printf("%c", 219);
		}
	
			for(i=1; i<=38; i++) //Horizontal Tengah bawah 
		{
			gotoxy(i,14);printf("%c", 219);
		}
	
		for(i=0; i<=167; i++)	//Horizontal Bawah
	    {
	        gotoxy(i,47);printf("%c", 219);
		}
		
		for(j=1; j<=46; j++)	//Vertikal Kanan-Kiri
	    {
	    	gotoxy(0,j);printf("%c", 219);
	    	gotoxy(1,j);printf("%c", 219);
	        gotoxy(166,j);printf("%c", 219);
			gotoxy(167,j);printf("%c", 219);
		}	
		
		for(i=1; i<=10; i++)	//Tampilan tutup judul samping
		{
		  gotoxy(49,i); printf("%c", 219);
		  gotoxy(50,i); printf("%c", 219);
		  gotoxy(117,i); printf("%c", 219);
		  gotoxy(118,i); printf("%c", 219);
		}
		
		for(j=10; j<=46; j++)	//Vertikal Kanan-Kiri
	    {
	    	gotoxy(37,j);printf("%c", 219);
	    	gotoxy(38,j);printf("%c", 219);
		}		

	gotoxy(21,4);	printf("APLIKASI");	
	gotoxy(19,6);	printf("BENGKEL MOTOR");
		
	DrawFile(52, 2, "Text\\Judul.txt");	
	
	DateTime dateNow;
	DateTimeNow(&dateNow);
	gotoxy(130,4); printf("Tanggal : %02d - %02d - %04d", dateNow.tgl, dateNow.bulan, dateNow.tahun);
	gotoxy(133,6); printf("Pukul : %02d : %02d WIB", dateNow.hour, dateNow.min);		
	

}
