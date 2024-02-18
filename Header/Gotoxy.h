void gotoxy(int x,int y){
	
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X=x;
    dwCursorPosition.Y=y;
    hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
