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
	/* 과제 점수의 입력 유무를 확인*/
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	//입력된 값이 없을때 종료
	if (size == 0) {
		cout << endl << "You must enter your grades.\nPlease try again." << endl;
		return 1;
	}//if ends

	//입력된 값을 처리하는 과정
	else {
		//점수 정렬
		sort(homework.begin(), homework.end());

	}//else ends

	//과제 점수의 중앙값 구하기
	vec_sz mid = size / 2;
	double hwMedian;

	//삼항 연산자 
	hwMedian = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];


	//4. 최종 점수연산 후 출력함
	streamsize prec = cout.precision(3);//소수점 세자리까지 출력
	
	cout << name << "'s grade is " << setprecision(3)
		<< 0.2 * mid + 0.4 * fin + 0.4 * hwMedian
		<< setprecision(prec) << endl;

	return 0;
}