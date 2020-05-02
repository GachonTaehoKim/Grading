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

version 1.0.0
		- ����ü�� ����Ͽ� �������� �л��� ������ �ٷ�
		- ����ü ��뿡 ���� �Լ� �Ű����� ����

*/
#include <algorithm>
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
using std::max;

/* ����ü */
struct Student_info {
	string name;
	double mid, fin;
	vector<double> homework;
};

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

//ver 1.0.0 �߰� �Լ�
istream& read(istream& is, Student_info& s) {
	//�л��� �̸�, �߰�/�⸻ ������ �о� ����
	is >> s.name >> s.mid >> s.fin;
	read_hw(is, s.homework);
	return is;
}
bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

//Overloading 
double grade(const Student_info& s) {
	return grade(s.mid, s.fin, s.homework);
}

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	//�л� �̸��� ��� ������ �о� �����ϰ� ���� �� �̸��� ã��.
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//�л� ������ ���ĺ� ������ ����
	sort(students.begin(), students.end(), compare);
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		//�̸��� ������ ������ �����Ͽ� maxlen + 1 ���� ���ڸ� ���
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
		
		//���� ������ ����Ͽ� ���
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}

 