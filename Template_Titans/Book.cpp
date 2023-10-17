#include "Book.h"
#include <iomanip>

Book::Book():title("None") , author("None") , genre("None") , availability(false){}

Book::Book(string title, string author, string genre, bool is) :
	title(title), author(author), genre(genre), availability(is) {}

//=============================================================================

bool Book:: operator == (Book& b) {
	if (author == b.author)
		return true;
	return false;

}

//===============================================================================

//ostream& operator <<(ostream& os, const Book& b) {
//	os << "Title : " << setw(20) << b.get_title() << endl;
//	os << "Author : " << setw(20) << b.get_author() << endl;
//	os << "Genre : " << setw(20) << b.get_genre() << endl;
//	os << "Availability : " << setw(20);
//	if (b.get_availability())
//		os << "Available";
//	else
//		os << "Not available";
//	os << endl;
//	return os;
//}

//===============================================================================

string Book:: get_title()const {
	return title;
}
string Book:: get_author()const {
	return author;
}
string Book:: get_genre()const {
	return genre;
}
bool Book:: get_availability()const {
	return availability;
}
