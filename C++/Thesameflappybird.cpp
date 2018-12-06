#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace std;
void huongdan();
void menu();
void thucthi();
void resizeConsole(int width, int height);
void XoaManHinh();
void VeMap();
void InMap();
void VeChim(int x, int y);
void XoaChim(int x, int y);
void DiChuyenChim(int &x, int y);
 
void VeOngCong(int x, int y);
void XoaOngCong(int x, int y);
void DiChuyenOngCong(int x, int &y);
 
void KiemTraVaCham(int x, int y, int x1, int y1);
 
int a;  
 
 
 
int main()
{
	system("color 0d");
	menu();
	thucthi();
	system("cls");
	Sleep(1000);
	// resizeConsole(600,500);
	VeMap();
	int x = 15,y = 1;//bien cua mac dinh khoi tao cho chim
	VeChim(x,y);
	int x1,y1 = 10;
	srand(time(0));//reset thoi gian
	x1 = 9 + rand() % 12;
	while(true)
	{
		if(y1 < -2)
		{
			srand(time(0));//reset thoi gian
			x1 = 9 + rand() % 12;
			y1 = 15;
		}
		VeOngCong(x1,y1);
		XoaManHinh();
		InMap();
		Sleep(150);
		DiChuyenChim(x,y);
		DiChuyenOngCong(x1,y1);
		XoaOngCong(x1,y1);
		KiemTraVaCham(x,y,x1,y1);
	}
 
	system("pause");
	return 0;
 
}
 
void menu()
{
	cout << "\n\n\n\t\t====Chao Mung ban toi game flaby bird cua toi!!!=== "; Sleep(300);
	cout << "\n\n\t1. Nhan de choi ngay !!"; Sleep(300);
	cout << "\n\t2. Nhan de xem huong dan cach choi!!"; Sleep(300);
	cout << "\n\t3. Nhan de thoat!! "; Sleep(300);
	cout << "\n\n\n           Lua chon cua ban: ";
	cin >> a;
}
 
 
void thucthi()
{
	if (a == 1)
	{
		return;
	}
	else if (a == 2)
	{
 
		huongdan();
	}
	else if (a == 3)
	{
		exit(0);
	}
}
 
void huongdan()
{
	Sleep(200);
	system("cls");
	Sleep(300);
	cout << "\n\t\tChao mung ban toi huong dan tro choi chim bay cua toi\n\t\t that la don gian chi can nhan dau cach de tranh cac o thoi !! chuc ban thanh cong";
	int b;
	cout << "\n\n\n\t\t NHap phim bat ki de bat dau choi di ban!!";
	cin >> b;
}
 
// Hàm thay d?i kích c? c?a khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
 
// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle
 
		(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
 
char map[40][20];
void VeMap()
{
	for (int i = 1; i < 29; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			map[0][j] = '-';
			map[29][j] = '-';
			map[i][j] = ' ';
		}
	}
}
 
void InMap()
{
	for (int i = 0; i < 30; i++)
	{
		cout << "\t";
		for (int j = 0; j < 15; j++)
		{
 
			cout << map[i][j];
		}
		cout << endl;
	}
}
 
void VeChim(int x, int y)
{
	map[x][y] = 'O';
	map[x + 1][y] = '-';
	map[x][y + 1] = '|';
	map[x][y - 1] = '|';
}
void XoaChim(int x, int y)
{
	map[x][y] = ' ';
	map[x + 1][y] = ' ';
	map[x][y + 1] = ' ';
	map[x][y - 1] = ' ';
}
 
 
void VeOngCong(int x, int y) // 8 < x < 21
{
	for (int i = 1; i < x; i++)
	{
		map[i][y + 2] = '|';
		map[i][y - 2] = '|';
	}
	map[x][y - 1] = map[x][y] = map[x][y + 1] = map[x + 6][y - 1] = map[x + 6][y] = map[x + 6][y + 1] = '-';
	for (int i = x + 7; i < 29; i++)
	{
		map[i][y + 2] = '|';
		map[i][y - 2] = '|';
	}
}
 
void XoaOngCong(int x, int y)
{
	for (int i = 1; i < x; i++)
	{
		map[i][y + 2] = ' ';
		map[i][y - 2] = ' ';
	}
	map[x][y - 1] = map[x][y] = map[x][y + 1] = map[x + 6][y - 1] = map[x + 6][y] = map[x + 6][y + 1] = ' ';
	for (int i = x + 7; i < 29; i++)
	{
		map[i][y + 2] = ' ';
		map[i][y - 2] = ' ';
	}
}
 
void DiChuyenChim(int &x, int y)
{
	//chim t? roi
	XoaChim(x, y);
	x++;//do tr?c ox hu?ng xu?ng
	VeChim(x, y);
	if (GetAsyncKeyState(VK_SPACE))
	{
		XoaChim(x, y);
		x -= 3;
		VeChim(x, y);
	}
 
}
 
void DiChuyenOngCong(int x, int &y)
{
	XoaOngCong(x, y);
	y--;
	VeOngCong(x, y);
}
 
void KiemTraVaCham(int x, int y, int x1, int y1)
{
	if (x < 1 || x > 27) // kiem tra chim roi san choi
	{
		cout << "\a";
		exit(0);
	}
	if (((y + 1) == (y1 - 2) && (x + 1) == x1) || ((y - 1) == (y1 + 2) && ((x + 1) == x1)) || (y >= (y1 - 1) && y <= (y1 + 1) && (x - 1) <= x1)) //Kiem tra cham tren
	{
		cout << "\a";
		exit(0);
	}
	if (((y + 1) == (y1 - 2) && (x - 1) == (x1 + 7)) || ((y - 1) == (y1 + 2) && ((x - 1) == (x1 + 7))) || (y >= (y1 - 1) && y <= (y1 + 1) && (x + 1) >= (x1 + 7)))//kiem tra cham duoi
	{
		cout << "\a";
		exit(0);
	}
}
