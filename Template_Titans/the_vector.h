#pragma once
#include <iostream>
#include <stdexcept>
#include "Book.h"


using namespace std;

template <class R>
class the_vector
{
private:
	R* arr = nullptr;
	int size;
	int capacity;
public:

	the_vector(int n) : size(n) {
		(n < 0) ? n = 0 : 1;
		capacity = size + 10;
		arr = new R[capacity];
	}

	//========================================================
	~the_vector(){
		delete[] arr;
	}

	//=========================================================================
	R& operator [](int idx) {
		if (idx < 0 || idx >= size) 
			throw out_of_range("Index out of bounds");

		return arr[idx];
	}

	//==========================================================================
	int get_size() const {
		return size;
	}

	//===========================================================================

	template<class T>
	friend ostream& operator << (ostream& os, const the_vector<T>& v);

	//===========================================================================

	void expand_capacity() {
		capacity *= 2;
		R* arr2 = new R[capacity];
		for (int i = 0; i < size; i++)
			arr2[i] = arr[i];
		swap(arr, arr2);
		delete [] arr2;
	}

	//==============================================================================

	void add_element(R value) {
		if(size == capacity)
			expand_capacity();
		arr[size++] = value;
	}

	//===============================================================================

	void remove_indix(int idx) {
		if(0> idx || idx >= size)
			throw out_of_range("Index out of bounds");
			for (int i = idx; i < size - 1; i++)
			{
				if (idx == (size - 1))
					break;
				arr[i] = arr[i + 1];
			}
		size--;
	}

	//===============================================================================

	int find(R value) {
		for (int i = 0; i < size; i++)
			if (arr[i] == value)
			{
				improve_search(i);
				return i;
			}
		return -1;
	}

	//==================================================================================

	int remove_value(R value) {
		int s = find(value);
		if (s == -1)
			return 0;

	    remove_indix(s);
		return 1;
	}

	//====================================================================================

	void insert(int idx, R value) {
		if (0 > idx || idx >= size)
			throw out_of_range("Index out of bounds");

		for(int i = (size); i >= idx; i--)
			arr[i] = arr[i - 1];

		arr[idx] = value;
		size++;
	}

	//=======================================================================================

	void improve_search(int idx) {
		if (idx == 0)
			return ;
		/*R in = arr[idx];
		arr[idx] = arr[idx - 1];
		arr[idx - 1] = in;*/
		swap(arr[idx], arr[idx - 1]);
	}

	//=========================================================================================

	void right_rotate() {
		R in = arr[size - 1];
		for (int i = size - 1; i > 0; i--)
			arr[i] = arr[i - 1];
		arr[0] = in;
	}

	//============================================================================================

	void right_rotate(int n) {
		n = n % size;
		for (int i = 1; i <= n; i++)
			right_rotate();
	}

	//=============================================================================================

	void inverse() {
		R* arr2 = new R[capacity];
		for (int i = 0; i < size; i++)
			arr2[i] = arr[size-i-1];
		swap(arr, arr2);
		delete[] arr2;
	}

	//==============================================================================================

	R get_value (int idx) {
		return arr[idx];
	}
	
};
