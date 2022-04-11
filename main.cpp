// поток ввода/вывода
#include <iostream>
#include <Windows.h>

using namespace std;

unsigned char isPow(unsigned int pow);
extern "C" { int MUL_ASM(register unsigned int a, register unsigned char b); }

template <typename T>
T getData() {
	T temp;
	cin >> temp;
	while (cin.fail() || cin.get() != '\n') {
		cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
		cin.ignore(9999, '\n');
		cin.sync();//Удалим данные из буффера
		cout << "Enter again: ";
		cin >> temp;
	}
	return temp;
}


int main() {
	register unsigned int num;
	register unsigned int checkNum;
	unsigned int mul;
	register unsigned char pow;
	cout << "First value: ";

	num = getData<unsigned int>();

	checkNum = num;
	system("cls");
	cout << "First value = " << num << endl;
	cout << "Second value: ";
	mul = getData<unsigned int>();

	system("cls");
	cout << "First value: " << num << endl << "Second value: " << mul << endl;

	pow = isPow(mul);
	if (pow == -1)
		return -1;

	//num <<= pow;

	num = MUL_ASM(num, pow);

	if (num < checkNum) {
		system("cls");
		cout << "Data was corrupted" << endl;
	}
	else {
		cout << endl << "Result = " << num << endl;
	}

	return 0;
}


unsigned char isPow(unsigned int pow) {
	register unsigned char temp = 0;

	if (((pow % 2) == 1) & (pow != 1))
		return -1;

	while (pow != 1) {
		pow /= 2;
		temp++;
	}

	if (pow > 1)
		return -1;

	return temp;
}

