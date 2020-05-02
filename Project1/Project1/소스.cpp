/*
Author:		김태호
Date:		2020 05 02
Contents:	
			학생 성적 입력 프로그램
Algorithm:
			&&참고
			중간고사 20%
			기말고사 40% 
			과제점수 40%
			 
			1. 학생의 이름을 입력받음
			2. 중간고사, 기말고사 점수를 입력받음
			3. 과제점수를 입력받음 
				3-1 과제의 갯수는 변동할 수 있다.
			4. 결과를 출력한다.

version 1.0.0
		- 구조체를 사용하여 여러명의 학생의 정보를 다룸
		- 구조체 사용에 따른 함수 매개변수 변경

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

/* 구조체 */
struct Student_info {
	string name;
	double mid, fin;
	vector<double> homework;
};

/* 함수 */
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
		//이전 내용 제거
		homework.clear();

		//과제 점수를 읽음
		double hw;

		while (in >> hw) {
			homework.push_back(hw);
		}
		//다음 학생의 점수 입력 작업을 고려해 스트림을 지움
		in.clear();
	}
	return in;
}

//ver 1.0.0 추가 함수
istream& read(istream& is, Student_info& s) {
	//학생의 이름, 중간/기말 점수를 읽어 저장
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

	//학생 이름과 모든 점수를 읽어 저장하고 가장 긴 이름을 찾음.
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//학생 정보를 알파벳 순으로 정렬
	sort(students.begin(), students.end(), compare);
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		//이름과 오른쪽 공백을 포함하여 maxlen + 1 개의 문자를 출력
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
		
		//최종 점수를 계산하여 출력
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

 