/*
Author:		����ȣ
Date:		2020 05 02
Contents:	
			�л� ���� �Է� ���α׷�
Algorithm:
			&&����
			�߰���� 20%
			�⸻��� 40% 
			�������� 40%
			 
			1. �л��� �̸��� �Է¹���
			2. �߰����, �⸻��� ������ �Է¹���
			3. ���������� �Է¹���
				3-1 ������ ������ ������ �� �ִ�.
			4. ����� ����Ѵ�.

version 0.0.2 
			vector Ÿ���� ����Ͽ� ������ ���� �ٷ��
*/

#include <iostream>
#include <iomanip>
#include <ios>
#include <String>
#include <vector>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::streamsize; using std::setprecision;

int main()
{
	//1. �̸��� �Է¹���
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	//2. �߰����, �⸻��� ������ �Է¹���
	cout << "Please enter midterm and final exam grades: ";
	
	double mid, fin;
	cin >> mid >> fin;

	//3. ���� ������ �Է¹���
	cout << "Enter all your homwork grades, followed by end of file: crtl + c";

	int numOfHw = 0;
	double sumHw = 0;
	double hw;

	while (cin >> hw) {
		++numOfHw;
		sumHw += hw;
		cout << numOfHw << ", " << sumHw << endl;
	}

	//4. ����� �����
	streamsize prec = cout.precision(3);//�Ҽ��� ���ڸ����� ���
	
	cout << name << "'s grade is " << setprecision(3)
		<< 0.2 * mid + 0.4 * fin + sumHw / numOfHw 
		<< setprecision(prec) << endl;

	return 0;
}