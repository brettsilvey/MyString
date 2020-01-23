#include "MyString.h"
#include <iostream>

using namespace std;

char lowerCase[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char upperCase[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char alphabet[] = { 'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q',
					'q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z' };
//initialize array and currLen - works
MyString::MyString()
{
	arr = nullptr;
	currLen = 0;
	capacity = 0;
}

//initialize to char array - works
MyString::MyString(string s)
{
	arr = new char[s.size()];
	currLen = s.size();
	capacity = s.size();
	for (int i = 0; i < currLen; i++) {
		arr[i] = s[i];
	}
}

//copy constructor - works
MyString::MyString(const MyString & s)
{
	arr = new char[s.currLen];
	currLen = s.currLen;
	capacity = s.currLen;
	for (int i = 0; i < currLen; i++) {
		arr[i] = s.arr[i];
	}
}

// getLength Method - works
int MyString::getLen()
{
	return currLen;
}

// concate method - works
MyString MyString::operator+(const MyString & rhs)
{
	MyString result(*this);
	for (int i = 0; i < rhs.currLen; i++) {
		result.ensureCapacity();
		result.arr[result.currLen] = rhs.arr[i];
		result.currLen++;
	}
	return result;
}

// equals method - works
bool MyString::operator==(const MyString & rhs)
{
	bool eq = true;
	if (currLen != rhs.currLen) {
		eq = false;
	}
	for (int i = 0; i < rhs.currLen; i++) {
		if (arr[i] != rhs.arr[i]) {
			eq = false;
			break;
		}
	}
	return eq;
}

//comparteTo< method - works
int MyString::operator<(const MyString & rhs)
{
	int f = 0, s = 0, runtime;

	if (currLen < rhs.currLen) {
		runtime = currLen;
	}
	else {
		runtime = rhs.currLen;
	}

	for (int i = 0; i < runtime; i++) {
		if (arr[i] != rhs.arr[i]) {
			for (int j = 0; j < 52; j++) {
				if (arr[i] == alphabet[j]) {
					f = j;
				}
				if (rhs.arr[i] == alphabet[j]) {
					s = j;
				}
			}
			if (f < s) {
				return -1;
			}
			else {
				return 1;
			}
		}
	}
	return 0;
}

//compareTo> method - works
int MyString::operator>(const MyString & rhs)
{
	int f = 0, s = 0, runtime;

	if (currLen < rhs.currLen) {
		runtime = currLen;
	}
	else {
		runtime = rhs.currLen;
	}
	for (int i = 0; i < runtime; i++) {
		if (arr[i] != rhs.arr[i]) {
			for (int j = 0; j < 52; j++) {
				if (arr[i] == alphabet[j]) {
					f = j;
				}
				if (rhs.arr[i] == alphabet[j]) {
					s = j;
				}
			}
			if (f < s) {
				return 1;
			}
			else {
				return -1;
			}
		}
	}
	return 0;
}

// private ensureCapacity method  - works
void MyString::ensureCapacity()
{
	if (capacity > currLen) { return; } //checking to see if arr is already big enough
	char* temp = new char[capacity * 2];//create new temporary array
	for (int i = 0; i < currLen; i++) { //copy characters over from arr to temp
		temp[i] = arr[i];
	}
	capacity = capacity * 2; //double capacity
	delete[] arr; //delete old array
	arr = temp; //set old arr to temp
	return;
}

// get(int) - works
char MyString::get(int input)
{
	return arr[input-1];
}

// toUpper method - works
MyString MyString::toUpper()
{
	MyString upper(*this);
	for (int i = 0; i < currLen; i++) {
		for (int j = 0; j < 26; j++) {
			if (arr[i] == lowerCase[j]) {
				upper.arr[i] = upperCase[j];
				break;
			}
		}
	}
	return upper;
}

// toLower method - works
MyString MyString::toLower()
{
	MyString lower(*this);
	for (int i = 0; i < currLen; i++) {
		for (int j = 0; j < 26; j++) {
			if (arr[i] == upperCase[j]) {
				lower.arr[i] = lowerCase[j];
				break;
			}
		}
	}
	return lower;
}

//first substring method - works
MyString MyString::substring(int index)
{
	MyString substring(*this);
	MyString newSubstring("");
	newSubstring.currLen = substring.currLen - index;
	int j = 0;
	for (int i = index; i < currLen; i++) {
		newSubstring.arr[j] = substring.arr[i];
		j++;
	}
	return newSubstring;
}

//second substring method - works
MyString MyString::mySubstring(int n, int m)
{
	MyString substring(*this);
	MyString newSubstring("");
	newSubstring.currLen = m-n;
	int j = 0;
	for (int i = n; i < m; i++) {
		newSubstring.arr[j] = substring.arr[i];
		j++;
	}
	return newSubstring;


}

int MyString::indexOf(MyString input)
{
	MyString workingString(*this);
	int index = 0;
	for (int i = 0; i < workingString.currLen; i++) {
		int j = 0;
		if (workingString.arr[i] == input.arr[j]) {
			if (workingString.arr[i+1] == input.arr[j + 1]) {
				index = j - 1;
				j++;
				cout << workingString.arr[i] << endl;
			}
		}
		else if (workingString.arr[i + 1] != input.arr[j + 1]) {
			j = 0;
			index = 0;
		}
	}
	return 0;
}

// toString method
ostream & operator<<(ostream & out, const MyString & o)
{
	// TODO: insert return statement here
	string myStringObjects;
	for (int i = 0; i < o.currLen; i++) {
		myStringObjects += o.arr[i];
	}
	out << myStringObjects;
	return out;
}//toString





//ostream & operator+(const MyString & first, const MyString & second)
//{
//	MyString bigger;  //This is our new MyString object which wil contain the new array for proper sizing
//	if (first.currLen < second.currLen) {
//		bigger = second;
//	}
//	else {
//		bigger = first;
//	}
//	MyString answer(first); //create new array for concatenation
//	//answer.capacity = bigger.capacity * 2; // set the size of the answer array based on the bigger input
//	answer.ensureCapacity(); //set the array size to double using ensure capacity
//	for (int i = 0; i < second.currLen; i++) {
//		answer.ensureCapacity(); // set the array size to double using ensure capacity
//		answer.arr[answer.currLen] = second.arr[i];
//		answer.currLen++;
//	}
//	return;
//}
