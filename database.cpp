#include <stdio.h>
#include <iostream>
#include <clocale>
#include <string.h>
#include "conio.h"
#include "assert.h"
#include <locale>
#include <iomanip> 
#include <windows.h> 
#include <fstream>
#pragma warning(disable:4996)
using namespace std;
#define inp setlocale (LC_ALL,"rus")
#define outp setlocale (LC_ALL,"rus_rus.866")
struct Transport
{
	char car[23];		// марка машины
	string name;	// владелец
	int mile;		//Пробег
	int power; //мощность двигателя
};

void check() {
	FILE* f;
	f = fopen("C:\\Users\\baiko_d0rw3wh\\Desktop\\Transport.txt", "r");
	if (f == NULL)
	cout << "Файл пуст" << endl;
}

void prin_hand()
{
	cout << " Автомобиль             Владелец          Пробег        Мощность двигателя " << endl;
    cout << "---------------------------------------------------------------------------" << endl;
}

void prin_all()
{
	ifstream f("Transport.txt");
	char ch;
	while (f.get(ch))
	{
		cout << ch;
		if (!f.putback(ch))
		{
			cerr << "error";
		}
		f.get(ch);
	}
	cout << "\0";
	f.close();
	cout << "\n";
	cout << "---------------------------------------------------------------------------\n" << endl;
	int t = 1;
	FILE* pr;
	pr = fopen("Transport.txt", "r");
	if (pr != NULL)
	{
		while (!feof(pr))
		{
			ch = getc(pr);
			if ((ch == '\n') || (ch == '\0'))
				t++;
		}
		fclose(pr);
		if ((t % 10) < 5 && (t % 10) > 1 && (t < 10))
			cout << "В базе данных " << t << " записи";
		else cout << "В базе данных " << t << " записей";
	}
	cout << "\n";
}

void add() {
	char car[23];
	char name[19];
	char mile[14];
	char power[19];
	cout << "Введите автомобиль" << endl;
	cin >> car;
	cout << "Введите владельца" << endl;
	cin >> name;
	setlocale(LC_ALL, "Russian");
	char N1[23];
	OemToCharBuff(name, N1, 19);
	cout << "Введите пробег" << endl;
	cin >> mile;
	cout << "Введите мощность" << endl;
	cin >> power;//24 18 14 19
	ofstream myfile;
	myfile.open("Transport.txt", ios::out | ios::app);
	myfile << setiosflags(ios::left)<<"\n "<<setw(23)<< car << resetiosflags(ios::left) << setiosflags(ios::left)<<setw(18) << N1 << resetiosflags(ios::left) << setiosflags(ios::left)<<setw(14) << mile<< resetiosflags(ios::left) << setiosflags(ios::left) << setw(19) << power << resetiosflags(ios::left);
	myfile.close();
	cout << "---------------------------------------------------------------------------\n" << endl;
	cout << "Запись в файл закончена" << endl;
}
  
void searchmodel()
{
	string car;
	cout << "Введите полное название автомобиля " << endl;
	outp;
	cin >> car;
	inp;
	FILE* pr;
	int t = 1;
	char ch;
	int i;
	pr = fopen("Transport.txt", "r");
	if (pr != NULL)
	{
		while (!feof(pr))
		{
			ch = getc(pr);
			if ((ch == '\n') || (ch == '\0'))
				t++;
		}
		fclose(pr);
	}
	ifstream myfile("Transport.txt",ios::in);
	Transport* tr = new Transport[1000];
	for (i = 0; i<t; ++i)
	{
		myfile >> tr[i].car;
		myfile >> tr[i].name;
		setlocale (LC_CTYPE, "");
		myfile >> tr[i].mile;
		myfile >> tr[i].power;
		if (tr[i].car == car)
		{
			cout << "Данным автомобилем владеет " << tr[i].name << endl;
		}
	}
	myfile.close();
}
	
void searchowner() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, ".1251");
	string name;
	cout << "Введите полное имя владельца " << endl;
	cin >> name;
	FILE* pr;
	int t = 1;
	char ch;
	int i;
	pr = fopen("Transport.txt", "r");
	if (pr != NULL)
	{
		while (!feof(pr))
		{
			ch = getc(pr);
			if ((ch == '\n') || (ch == '\0'))
				t++;
		}
		fclose(pr);
	}
	ifstream myfile("Transport.txt", ios::in);
	Transport *tr = new Transport[1000];
	for (i = 0; i<t; ++i)
	{
		inp;
		myfile >> tr[i].car;
		myfile >> tr[i].name;
		setlocale(LC_CTYPE, "");
		myfile >> tr[i].mile;
		myfile >> tr[i].power;
		if (tr[i].name == name)
		{
			cout << "У данного владельца имеется автомобиль " << tr[i].car << " с пробегом " << tr[i].mile <<" км и мощностью " <<tr[i].power<<" л. с."<< endl;
		}
	}
	myfile.close();
}

void exit()
{
	exit('0');
}

int main()
{
	inp;
	cout << "---------------------------------------------------------------------------"<<endl;
	cout << "Напишите, что вы хотите сделать с базой данных:  " << endl;
	cout << "w-вывести всю базу данных, a-добавить элемент,  " << endl;
	cout << "sm-поиск по марке, so-поиск по владельцу, ex-выход" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	while (1) {
		string m;
		cin >> m; 
		if (m == "w")
		{
			check();
			prin_hand();
			prin_all();
		}

		if (m == "a")
		{
			add();
		}

		if (m == "sm")
		{
			searchmodel();
		}

		if (m == "so")
		{
			searchowner();
		}

		if (m == "ex")
		{
			
			exit();
		}

		if ((m != "w") && (m != "a") && (m != "sm") && (m != "so") && (m != "ex"))
		{
			cout << "Такой команды нет. Попробуйте ввести снова" << endl;
		}
		cout << "---------------------------------------------------------------------------" << endl;
		system("pause >> NUL");
	}
}
