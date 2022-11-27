#include <iostream>
#include <math.h>
#include <ctime>
#include <fstream>
#include <windows.h>
using namespace std;

// Checking the entered data
void checkValidParams(double start, double end) {
	if (start > end) {
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //If there is an error, the text will be red
		SetConsoleTextAttribute(handle, 4);
		throw "Incorrect data!!!";
	}
}

void checkValidParams(double start, double end, double step) {
	if (step <= 0) {
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //If there is an error, the text will be red
		SetConsoleTextAttribute(handle, 4);
		throw "Incorrect data!!!";
	}
}

//Знаходження функції
double calculate(double x, int n) {
	if (x > 0) {
		double y = 1;
		if (n < 0) {
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //If there is an error, the text will be red
			SetConsoleTextAttribute(handle, 4);
			cout << "Error!!!";
			exit(0);
		}
		for (int i = 1; i <= n; i++) {
			y *= (1 / x) - (1 / i);
		}
		return y;
	}
	else {
		double y = 0;
		if (n - 1 < 0) {
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //If there is an error, the text will be red
			SetConsoleTextAttribute(handle, 4);
			cout << "Error!!!";
			exit(0);
		}
		else {
			for (int i = 0; i <= n - 1; i++) {
				for (int j = 0; j <= n - 1; j++) {
					y += 1 / (x - i + j);
				}
			}
			return y;
		}
	}
}

//Recording to disk answers
void printValues(double start, double end, double step, int n, int store) {
	ofstream fout("result.txt");
	for (double x = start; x <= end; x += step) {
		double y = calculate(x, n);
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //If the value is correct, the text will be green
		SetConsoleTextAttribute(handle, 2);
		cout << "x = " << x << "\ny = " << y << endl;
		if (store == 1) {
			fout << "x= " << x << endl;
			fout << "y= " << y << endl;
		}
	}
	if (store == 1) {
		system("notepad C:\\Users\\1\\source\\repos\\ИПЗ лаба 5\\ИПЗ лаба 5\\result.txt"); //Automatically opens a text file with a record of the answer
	}
}

int main() {
	setlocale(LC_ALL, "Ukr");
	float start, end, step;
	int n, store;
	try {
		ifstream infile("number.txt");
		//reading from a file
		infile >> start;

		infile >> end;
		checkValidParams(start, end);

		infile >> step;
		checkValidParams(start, end, step);

		infile >> n;

		cout << "If you want to save the function value, enter 1, otherwise 0: \n";
		cin >> store;
		printValues(start, end, step, n, store);
	}
	catch (const char* ex) {
		cout << ex << endl;
		return -1;
	}
	catch (...) {
		cout << "Unknown error!!!" << endl;
		return -2;
	}
}