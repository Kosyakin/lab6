﻿// lab 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

//сама наша функция
double func(double x1, double x2)
{
	return pow(x1, 2) - 15 * x1*x2 + 44 * x1 + pow(x2, 3) - 6 * pow(x2, 2) - 93 * x2 + 251;
}

//производная по 1-ой переменной
double dfunc1(double x1, double x2)
{
	//cout << 2 * x1 - 15 * x2 + 44 << endl;
	return 2 * x1 - 15 * x2 + 44;
}

//производная по 2-ой переменной
double dfunc2(double x1, double x2)
{
	return  3 * pow(x2, 2) - 15 * x1 - 12 * x2 - 93;
	//cout << 3 * pow(x2, 2) - 15 * x1 - 12 * x2 - 93;
}

//Градиентный метод с дроблением
void Gradient(double x1, double x2)
{
	double eps = 0.1, part = 0.001;
	int count = 0;
	ofstream temp_file;
	temp_file.open("vect.txt");
	temp_file << "# x1\tx2" << endl;
	temp_file << x1 << "\t" << x2 << endl;
	do
	{
		double a = abs(dfunc1(x1, x2) + dfunc2(x1, x2));
		while (func(x1 - part * dfunc1(x1, x2), x2 - part * dfunc2(x1, x2)) > func(x1, x2) - eps * part * a * a)
			part *= 0.001;
		count++;
		x1 -= part * dfunc1(x1, x2);
		x2 -= part * dfunc2(x1, x2);
		temp_file << x1 << "\t" << x2 << endl;
	} while (sqrt(pow(dfunc1(x1, x2), 2) + pow(dfunc2(x1, x2), 2)) > eps);


	temp_file.close();

	cout << "\n Gradient method with step splitting\n";
	cout << "\n";
	cout << " iterations: " << count << "\n"<< endl;
	cout << " At x1 = " << x1 << "\t    x2 = " << x2 << "\n\n The minimum is equal to:\t" << func(x1, x2) << endl;

}



int main(void)
{
	Gradient(10, 4);
	return 0;
}
