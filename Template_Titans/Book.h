#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Book
{
private:
	string title, author, genre;
	bool availability;
public:
	Book();
	Book(string, string, string, bool);
	bool operator == (Book&);
	friend ostream& operator << (ostream&, const Book&);

	string get_title()const;
	string get_author()const;
	string get_genre()const;
	bool get_availability()const;
};

