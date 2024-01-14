// 5

//1. Написать программу, печатающую все вводимые символы в нижнем
//регистре.В строку выводится символ, шестнадцатеричный и восьмеричный код.

#include<iostream>
#include <iomanip>
using namespace std;

void allprog()
{
	char data[1000];
	cin >> data;
	for (int i = 0; i < strlen(data); i++)
	{
		data[i] = tolower(data[i]);
	}
	cout << data << endl << endl;

	for (int i = 0; i < strlen(data); i++)
	{
		cout << data[i] << " 0x" << setw(1) << hex << (int)data[i] << " ";
		cout << " 0x" << setw(1) << oct << (int)data[i] << endl;
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	allprog();
}
