#pragma once
#include<iostream>
#define ElementType int

using namespace std;

class Array
{
public:
	Array(const Array &n) {
		delete contain;
		contain = nullptr;
		length = n.length;
		contain = new ElementType[length];
		for (int i = 0; i < length; i++) {
			contain[i] = n.contain[i];
		}
	}

	Array& operator=(const Array &n) {
		delete contain;
		contain = nullptr;
		length = n.length;
		contain = new ElementType[length];
		for (int i = 0; i < length; i++) {
			contain[i] = n.contain[i];
		}
		return *this;
	}

	Array(const Array &n, int start, int end) {
		delete contain;
		contain = nullptr;
		length = end - start ;
		contain = new ElementType[length];
		int j = start;
		for (int i = 0; i < length; i++) {
			contain[i] = n.contain[j];
			j++;
		}
	}

	Array(int length) {
		this->length = length;
		contain = new ElementType[length];
		for (int i = 0; i < length; i++) {
			contain[i] = 0;
		}
	}

	Array(ElementType* input, int length) {
		this->length = length;
		contain = new ElementType[length];
		for (int i = 0; i < length; i++) {
			contain[i] = input[i];
		}
	}

	~Array() {
		delete contain;
		contain = nullptr;
	}

	int getLength() const {
		return length;
	}

	ElementType* contain = nullptr;

	Array reverse() {
		for (int i = 0; i < length; i++) {
			int j = length - 1;
			int temp = contain[i];
			contain[i] = contain[j];
			contain[j] = temp;
			j--;
		}
		return *this;
	}

private:
	int length = 0;
};

ostream& operator<<(ostream& out, const Array inputs) {
	out << "[";
	for (int i = 0; i < inputs.getLength(); i++) {
		out << inputs.contain[i];
		if (i != inputs.getLength() - 1) {
			out << ",";
		}
	}
	out << "]";
	return out;
}

void PrintArray(ElementType* inputs, int length) {
	cout << "[ ";
	for (int i = 0; i < length; i++) {
		cout << inputs[i];
		if (i != length - 1) {
			cout << ",";
		}
	}
	cout << "]";
}