#include <iostream>
#include "MyString.h"

using namespace std;

int main() {

	MyString obj1("Logan");
	MyString obj2("Silvey");
	MyString obj3("BRETT");
	MyString obj4("car");
	MyString obj5("racecar");

	//testing my length method
	cout << "Length of Object 1: " << obj1.getLen() << endl;
	cout << "Length of Object 2: " << obj2.getLen() << "\n" << endl;

	//testing toString method
	cout << "This is what object 1 says: " << obj1 << endl;
	cout << "This is what object 2 says: " << obj2 << "\n" <<endl;

	//testing concat method
	cout << "This will be the concatenation of two indexes: " << obj1.operator+(obj2) << "\n" << endl;

	//testing equals method
	cout << "This tests for equivalence: " << obj1.operator==(obj2) << endl;
	cout << "This tests for equivalence: " << obj1.operator==(obj3) << "\n" << endl;

	//testing compareTo method
	cout << "This is my compareTo test: " << obj2.operator<(obj1) << endl;;
	cout << "This is my compareTo test: " << obj1.operator<(obj2) << "\n" << endl;

	//testing get Method
	cout <<"This will pull an index from our object and print it:" << obj1.get(1) << "\n" << endl;

	//testing toUpper method
	cout << "This will change all characters to uppercase: " << obj1.toUpper() << "\n" << endl;

	//testing toLower method
	cout << "This will change all characters to lowercase: " << obj1.toLower() << "\n" << endl;

	//testing substring(int) method
	cout << "This will print everything starting at a specific index: " << obj1.substring(2) << "\n" << endl;

	//testing substring(int n, int m) method
	cout << "This will print everything between the two parameters: " << obj1.mySubstring(2, 4) << "\n" << endl;

	//testing indexOf method
	cout << "This is the starting index of our parameter in our MyString object: " << obj5.indexOf(obj4) << "\n" << endl;

	//testing lastIndexOf method


	//MyString w(one + two);
	//cout << one.getLen();
	//cout << one.operator==(two);
	//cout << one.operator+(two);
	//cout << one.get(1);
	//cout << two.toUpper();
	//cout << one.toLower();
	//cout << one.substring(0);

	return 0;

}