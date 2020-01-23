#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <string>
using namespace std;

class MyString {
private:
	string s;
	char *arr;
	int currLen;
	int capacity;
	char *temp;
	void ensureCapacity();

public:
	MyString();// first constructor
	MyString(string s);// second constructor
	MyString(const MyString & s);// copy constructor
	int getLen();// returning length
	friend ostream& operator<<(ostream&out, const MyString&o);//toString
	MyString operator+(const MyString & rhs);// concate method pt2
	bool operator==(const MyString & rhs);// equals method
	int operator<(const MyString & rhs);// compareTo method
	int operator>(const MyString & rhs); // compareTo method
	char get(int input); // get character at specific index
	MyString toUpper(); //change characters to all uppercase
	MyString toLower(); //change characters to all lowercase
	MyString substring(int index); // substring that takes one input
	MyString mySubstring(int n, int m); // substring method that takes two inputs
	int indexOf(MyString input); // indexOf function
};

#endif //MyString 
