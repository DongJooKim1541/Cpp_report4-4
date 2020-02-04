#include <iostream>
using namespace std;
const int DEFAULT_ARR_SIZE = 4;
class IntDA {
public:
	int size;
	int* p;
	IntDA();
	IntDA(int num);
	IntDA(const IntDA& d);
	~IntDA();
	IntDA operator=(IntDA& op2);
	double calcAVG();
	bool operator==(IntDA& op2);
};
IntDA::IntDA() {
	cout << "인자 없는 생성자" << endl;
	size = DEFAULT_ARR_SIZE;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		*(p + i) = 0;
		//p[i] = 0;
	}
}
IntDA::IntDA(int num) {
	cout << "인자 있는 생성자" << endl;
	size = num;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		*(p + i) = 0;
	}
}
IntDA::IntDA(const IntDA& d) {
	cout << "깊은 복사 생성자" << endl;
	size = d.size;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		p[i] = d.p[i];
	}
}
IntDA::~IntDA() {
	cout << "소멸자" << endl;
	if (p) {
		delete[] p;
		p = NULL;
	}
}
IntDA IntDA::operator=(IntDA& op2) {	//a=b => a.operator=(b)
	if (this != &op2) {
		delete[] p;
		size = op2.size;
		p = new int[size];
		for (int i = 0; i < size; i++) {
			p[i] = op2.p[i];
		}
	}
	return *this;
}
double IntDA::calcAVG() {
	double d = 0;
	for (int i = 0; i < size; i++) {
		d += p[i];
	}
	return d / size*1.0;//형 변환
}
bool IntDA::operator==(IntDA& op2) {
	int count = 0;
	for (int i = 0; i < op2.size; i++) {
		if (p[i] != op2.p[i]) {
			count++;
		}
	}
	if (count == 0) return true;
	else return false;
}
//int IntDA::calcMAX() {
//
//}
int main() {
	IntDA d1;
	int num;
	cout << "크기 : ";
	cin >> num;
	IntDA d2(num);
	for (int i = 0; i < num; i++) {
		cout << "입력 : ";
		cin >> d2.p[i];
	}
	cout << "d2.p : " << d2.p << endl;
	cout << "평균 : " << d2.calcAVG() << endl;
	IntDA d3(d2);
	cout << "d3.p : " << d3.p << endl;
	cout << "평균 : " << d3.calcAVG() << endl;
	d1 = d2;
	cout << "d1.p : " << d1.p << endl;
	cout << "평균 : " << d1.calcAVG() << endl;
	for (int i = 0; i < num; i++) {
		cout << "d1.p[" << i << "] : " << d1.p[i] << endl;
	}
	if (d1 == d2) {
		cout << "동일한 IntDA 객체" << endl;
	}
	else {
		cout << "상이한 IntDA 객체" << endl;
	}
	return 0;
}