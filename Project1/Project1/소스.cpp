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

	int numOfHw = 0;
	double sumHw = 0;
	double hw;

	while (cin >> hw) {
		++numOfHw;
		sumHw += hw;
		cout << numOfHw << ", " << sumHw << endl;
	}

	//4. 결과를 출력함
	streamsize prec = cout.precision(3);//소수점 세자리까지 출력
	
	cout << name << "'s grade is " << setprecision(3)
		<< 0.2 * mid + 0.4 * fin + sumHw / numOfHw 
		<< setprecision(prec) << endl;

	return 0;
}