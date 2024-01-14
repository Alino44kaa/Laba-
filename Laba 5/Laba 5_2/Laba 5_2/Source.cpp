// 5_2.cpp : �������� �������� ����, �������� � ������� ����� ��������� �����
//�����.


#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    ofstream inputFile("D:\\����� �����\\������� 3 ���� 2\\�����\\Laba 5\\Laba 5_2\\x64\\Debug\\input.txt");

    ofstream outputFile("D:\\����� �����\\������� 3 ���� 2\\�����\\Laba 5\\Laba 5_2\\x64\\Debug\\output.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        srand(static_cast<unsigned int>(time(0)));

        for (int i = 0; i < 100; i++) {
            int number = rand() % 101 - 50;
            inputFile << number << endl;
        }
        inputFile.close();

        vector<int> numbers;
        ifstream inputFileRead("D:\\����� �����\\������� 3 ���� 2\\�����\\Laba 5\\Laba 5_2\\x64\\Debug\\input.txt");
        int number;

        while (inputFileRead >> number) {
            numbers.push_back(number);
        }
        inputFileRead.close();

        int lastNumber = numbers[numbers.size() - 1];

        for (int i = 0; i < numbers.size(); i++)
        {
            numbers[i] = numbers[i] + lastNumber;
        }

        for (int i = 0; i < numbers.size(); i++) {
            outputFile << numbers[i] << endl;
        }
        outputFile.close();

        cout << "�������������� ���������. ��������� ������� � ���� output.txt." << endl;
    }
    else {
        cout << "�� ������� ������� �����." << endl;
    }

    return 0;
}



