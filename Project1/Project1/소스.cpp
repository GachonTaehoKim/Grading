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

version 0.0.3
			�Լ��� �߰��Ͽ� �����ϱ�

			+�߰��� �Լ�
			1.double median(vector<double> homework);
				- �Է¹޴� ��������(���� ������)�� �߾Ӱ��� ���ϴ� �Լ�

			2.double grade(double mid, double fin, double homwork);
			3.double grade(double mid, double fin, const vector<double>&);
				- �������� ������ ��ȯ�ϴ� �Լ�
		
			4.istream& read_hw(istream& in, vector<double>& homework);
				- ���������� �д� �Լ�
				
*/
#include <algorithm>//sorting
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::sort; using std::vector;
using std::cout; using std::cin;
using std::endl; using std::string;
using std::streamsize; using std::setprecision;
using std::domain_error; using std::istream;

/* �Լ� */
double median(vector<double> homework) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	if (size == 0)	{ throw domain_error("Median of an empty vector"); }
	else			{ sort(homework.begin(), homework.end()); }

	vec_sz mid = size / 2;
	return size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];
}

double grade(double mid, double fin, double homwork) {
	return 0.2 * mid + 0.4 * fin + 0.4 * homwork;
}

double grade(double mid, double fin, const vector<double>& hw) {
	if (hw.size() == 0) {
		throw domain_error("Student has done no homework");
	}
	return grade(mid, fin, median(hw));
}

istream& read_hw(istream& in, vector<double>& homework) {
	if (in) {
		//���� ���� ����
		homework.clear();

		//���� ������ ����
		double hw;

		while (in >> hw) {
			homework.push_back(hw);
		}
		//���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����
		in.clear();
	}
	return in;
}

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

	//���������� �����ϴ� vector 
	vector<double> homework;

	read_hw(cin, homework);

	//���������� ����� ����
	try {
		double fin_grade = grade(mid, fin, homework);
		streamsize prec = cout.precision(3);//�Ҽ��� ���ڸ����� ���

		cout << name << "'s grade is " << setprecision(3)
			<< fin_grade << setprecision(prec) << endl;
	}//try ends
	catch (domain_error) {
		cout << endl << "You must enter your grades."
			"\nPlease try again." << endl;
		return 1;
	}//catch ends
	
	return 0;
}

