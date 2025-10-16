#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double M_PI = 3.14159265358979323846;

int getShape();
float getWireLength();
float calculator(float wireLength, char shape);

int main()
{

	while (true) {
		int shape = getShape();
		cout << endl;
		float wireLength = getWireLength();
		float area = calculator(wireLength, shape);

		system("Pause");
		cout << "\nPress any key to continue...";
		system("cls"); // پاک کردن صفحه

	}
}

float calculator(const float wireLength, const char shape) {
	float area = 0;
	float perimeter = 0;


	switch (shape) {
	case '1': { // دایره
		float radius = wireLength / (2 * M_PI);
		area = M_PI * radius * radius;
		cout << "\nShape: Circle\n";
		cout << "Circumference = " << wireLength << endl;
		cout << "Radius = " << radius << endl;
		cout << "Area = " << area << endl << endl;
		break;
	}
	case '2': { // مربع
		float side = wireLength / 4;
		area = side * side;
		perimeter = side * 4;
		cout << "\nShape: square\n";
		cout << "Area = " << area << endl;
		cout << "perimeter = " << perimeter << endl << endl;
		break;
	}
	case '3': { // مستطیل
		float widthRatio;
		// کاربر باید مشخص کند عرض نسبت به ارتفاع چقدر است
		cout << "\nEnter width/height ratio (example: 2 means width = 2 * height): ";
		cin >> widthRatio;

		float height = wireLength / (2 * (1 + widthRatio));
		float width = widthRatio * height;
		area = width * height;

		cout << "\nShape: Rectangle\n";
		cout << "Height = " << height << endl;
		cout << "Width = " << width << endl;
		cout << "Perimeter = " << wireLength << endl;
		cout << "Area = " << area << endl << endl;
		break;
	}
	default:
		cout << "\n ERROR: Invalid choice!" << endl << endl;
		break;
	}
	return area;
}

int getShape() {
	char shape;

	bool flag = true;

	// گرفتن طول سیم از کاربر
	do {
		//نمایش ارور
		if (flag == false) {
			cout << "ERRORE: Please Enter a Number From 1 To 3" << endl << endl;
		}

		cout << "1.Circle" << endl << "2.square" << endl << "3.Rectangle" << endl << "Please choose your shape :";
		cin >> shape;
		cout << endl;
		flag = false;
		// حلقه تا وقتی ادامه پیدا میکنه کاربر ورودی درست انتخاب کنه
	} while (shape != '1' && shape != '2' && shape != '3');
	system("cls"); // پاک کردن صفحه
	return shape;
}

float getWireLength() {
	float wireLength;
	bool flag = true;

	// گرفتن طول سیم از کاربر
	do {
		//نمایش ارور
		if (flag == false) {
			cout << "ERRORE: Please Enter a Number From 0.1 To 100" << endl << endl;
		}

		cout << "Note: Enter a number between 0.1 and 100 only.\n";
		cout << "Enter Your Wire Length: ";
		cin >> wireLength;
		cout << endl;

		if (cin.fail()) { // اگر ورودی عددی نبود
			cin.clear(); // پاک کردن حالت fail
			cin.ignore(1000, '\n'); // پاک کردن بافر ورودی
			wireLength = 0; // مقدار نامعتبر
		}

		flag = false;
		// حلقه تا وقتی ادامه پیدا میکنه کاربر ورودی درست انتخاب کنه
	} while (0 >= wireLength || wireLength > 100);
	system("cls"); // پاک کردن صفحه
	return wireLength;
}

