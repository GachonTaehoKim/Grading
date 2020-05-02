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
#include <algorithm>//sorting
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::sort; using std::vector;
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

	vector<double> homework;

	//int numOfHw = 0;
	//double sumHw = 0;
	double hw;

	while (cin >> hw) {
		homework.push_back(hw);
		//++numOfHw;
		//sumHw += hw;
		//cout << numOfHw << ", " << sumHw << endl;
	}
	/* ���� ������ �Է� ������ Ȯ��*/
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	//�Էµ� ���� ������ ����
	if (size == 0) {
		cout << endl << "You must enter your grades.\nPlease try again." << endl;
		return 1;
	}//if ends

	//�Էµ� ���� ó���ϴ� ����
	else {
		//���� ����
		sort(homework.begin(), homework.end());

	}//else ends

	//���� ������ �߾Ӱ� ���ϱ�
	vec_sz mid = size / 2;
	double hwMedian;

	//���� ������ 
	hwMedian = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];


	//4. ���� �������� �� �����
	streamsize prec = cout.precision(3);//�Ҽ��� ���ڸ����� ���
	
	cout << name << "'s grade is " << setprecision(3)
		<< 0.2 * mid + 0.4 * fin + 0.4 * hwMedian
		<< setprecision(prec) << endl;

	return 0;
}