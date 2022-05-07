#include <iostream>
#include  <conio.h>
#include <Windows.h>

using namespace std;

bool stream;
bool flag;
bool flag_oof;
const int width = 40;
const int height = 20;
int x, y;
int funX, funY;


void start() {
	stream = true;
	flag_oof = true;
	x = 10;
	y = 10;
	funX = 1;
	funY = 13;
	system("color 07");
}

void funEx() {  //function example
	char heh;
	cout << "C:\\Users\\Алексей\\Desktop \n\n";
	cout << "Enter any key 2 exit: ";
	cin >> heh;
	flag_oof = true;
}

void graphic() {  
	for (int i = 0; i < width+1; i++) {
		cout << "X";
	}
	cout << "\n";

	for (int n = 0; n < height; n++) {
		for (int m = 0; m < width; m++) {
			if (m == 0 or m == width - 1) {
				cout << "X";
			}
			if (n == x and m == y) {
				cout << 'u';
			}
			else if (n == funX and m == funY) {
				cout << '@';
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}

	for (int i = 0; i < width+1; i++) {
		cout << "X";
	}
	cout << "\n";
}

void danger() {
	if (x <= -1 or y >= width or y <= -1 or x >= height) {
		system("color 0c");
	}
	else {
		system("color 07");
	}
}

void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			y--;
			system("cls");
			break;
		case 's':
			x++;
			system("cls");
			break;
		case 'd':
			y++;
			system("cls");
			break;
		case 'w':
			x--;
			system("cls");
			break;
		case 'z':
			system("cls");
			stream = false;
			break;
		}
		graphic();	
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	start();
	graphic();
	while (stream == true) {
		danger();
		input();
		if (x == funX and y == funY) {
			system("color 02");
			flag_oof = false;
			while (flag_oof == false) {
				funEx();
				y++;
				system("color 07");
				system("cls");
				graphic();
			}
		}
	}

	return 0;
}