#pragma once 
#include<windows.h> 
#include<iostream> 
#include<conio.h>
#include<iomanip>
using namespace std ;  
// cai dat do hoa trong c++ 
void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 
 
void TextColor(int x)//X la ma mau
{
     HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
} 
//file nay chi dung de tao do hoa khong dung vao muc dich nao khac  