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

version 0.0.2 
			vector 타입을 사용하여 데이터 집단 다루기

version 0.0.3
			함수를 추가하여 구현하기

			+추가된 함수
			1.double median(vector<double> homework);
				- 입력받는 숙제점수(집단 데이터)의 중앙값을 구하는 함수

			2.double grade(double mid, double fin, double homwork);
			3.double grade(double mid, double fin, const vector<double>&);
				- 최종적인 점수를 반환하는 함수
		
			4.istream& read_hw(istream& in, vector<double>& homework);
				- 숙제점수를 읽는 함수
				
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

int main()
{
	//1. 이름을 입력받음
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	//2. 중간고사, 기말고사 성적을 입력받음
	cout << "Please enter midterm and final exam grades: ";
	double mid, fin;
	cin >> mid >> fin;

	//3. 과제 점수를 입력받음
	cout << "Enter all your homwork grades, followed by end of file: crtl + c";

	//숙제점수를 저장하는 vector 
	vector<double> homework;

	read_hw(cin, homework);

	//종합점수를 계산해 생성
	try {
		double fin_grade = grade(mid, fin, homework);
		streamsize prec = cout.precision(3);//소수점 세자리까지 출력

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

