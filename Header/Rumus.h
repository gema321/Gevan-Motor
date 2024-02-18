//prosedur dan Rumus Tampilan

void fullscreen() //otomatis layar penuh
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

//(min)mulai dari kor y ke berapa, (max)berhenti di kor y yg keberapa atau panjang garis, (x)naro garis di x mana/letak x, (179)ascii garis
void Vline( int min, int max,int x, int a) //garis keatas/kebawah
{
	int i;
	for(i=min;i<=max;i++)
	{
		gotoxy(x,i);printf("%c",a);
	}
}

//(min)mulai dari kor y ke berapa, (max)berhenti di kor y yg keberapa atau panjang garis, (x)naro garis di x mana/letak x, (179)ascii garis
void Hline( int min, int max,int y, int a) //garis kesamping
{
	int i;
	for(i=min;i<=max;i++)
	{
		gotoxy(i,y);printf("%c",a);
	}
}


	//Input Gambar txt
void DrawFile(int x, int y, char filename[255]) {
	FILE *fp;
    char str[MAXCHAR];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("File Tidak Di Temukan");
    }
    i = 0;
    while (fgets(str, MAXCHAR, fp) != NULL) {
    	gotoxy(x, y + i);
        printf("%s", str);
        i++;
	}
    fclose(fp);
}
	
	//Kotak
void textBox1(int x, int y, int width, int height) {
	int i, j;
	
	/* first Line */
	gotoxy(x, y);
	printf("%c", 218);
	for(i = 1; i <= width; i++) {
		printf("%c", 196);
	}
	printf("%c", 191);
	
	/* looping for height */
	for(i = 1; i <= height; i++) {
		gotoxy(x, y + i);
		printf("%c", 179);
		
		gotoxy(x + width + 1, y + i);
		printf("%c", 179);
	}
	
	/* last line */
	printf("\n");
	gotoxy(x, y + height);
	printf("%c", 192);
	for(i = 1; i <= width; i++) {
		printf("%c", 196);
	}
	printf("%c", 217);
}

void loading(int x, int y) { //loading di tampilan awal
	int i;
	
	gotoxy(x + 12, y-1);
	printf("LOADING");
	textBox1(x, y, 30, 2);
	for(i = 1; i <= 30; i++) {
		gotoxy(x + i, y + 1);
		printf("%c", 177);
		Sleep(50);
		if(i == 8 || i == 28) {
			Sleep(200);
		} else if(i == 20) {
			Sleep(400);
		}
		
	}
}
	//Garis bwah kata
void underline(int x, int y, char text[255]) {	//x,y gotoxy textnya buat kata yg ingin di cetak
	int i;
	
	gotoxy(x, y);
	printf("%s", text);
	for(i = 0; i < strlen(text); i++) {
		gotoxy(x+i, y+1);
		printf("%c", 196);
	}
}

void KotakNama(int x, int y, int width, int height) {
	int i, j;
	
	/* first Line */
	gotoxy(x, y);
	printf("%c", 218);
	for(i = 1; i <= width; i++) {
		printf("%c", 196);
	}
	printf("%c", 191);
	
	/* looping for height */
	for(i = 1; i <= height; i++) {
		gotoxy(x, y + i);
		printf("%c", 219);
		
		gotoxy(x + width + 1, y + i);
		printf("%c", 219);
	}
	
	/* last line */
	printf("\n");
	gotoxy(x, y + height);
	printf("%c", 192);
	for(i = 1; i <= width; i++) {
		printf("%c", 196);
	}
	printf("%c", 217);
}


//Prosedur dan Rumus Waktu
typedef struct {	//tipe data bentukan waktu
	int tgl, bulan, tahun, hour, min, sec;
} DateTime;

void DateTimeNow(DateTime *TglOutput) {	//prosedur waktu skrg
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	TglOutput->tgl = tm.tm_mday;
	TglOutput->bulan = tm.tm_mon+1;
	TglOutput->tahun = tm.tm_year+1900;
	TglOutput->sec = tm.tm_sec;
	TglOutput->min = tm.tm_min;
	TglOutput->hour = tm.tm_hour;
}




