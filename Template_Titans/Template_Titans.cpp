#include <iostream>
#include "the_vector.h"
#include "Book.h"
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

HANDLE coll = GetStdHandle(STD_OUTPUT_HANDLE);

template <class R>
ostream& operator <<(ostream& os, const the_vector<R>& v);
ostream& operator <<(ostream& os, const Book& b);
inline void header();
void nchars_line(int n, char c);
void end();
//void hello();


int main()
{
    the_vector<Book> library(0);
    the_vector<string> authors(0), genres(0);
    int choose;
    //hello();

    do
    {
        header();
        cout << "\t==> To explore the library enter number 1 \n\n";
        cout << "\t==> To Add book enter number 2\n\n";
        cout << "\t==> To Remove book , author , or genre enter number 3\n\n";
        cout << "\t==> To search for book , author , genre enter number 4\n\n";
        cout << "\t==> To exit the library enter number 5\n\n";
        nchars_line(115, '-');
        cout << "Enter you choice : ";
        cin >> choose;
        while (choose > 5 || 0 >= choose)
        {
            cout << "\n Wrong enter , please try again : ";
            cin >> choose;
        }
        system("cls");
        header();
        switch (choose) {
        case 1:
            if (library.get_size() == 0)
            {
                SetConsoleTextAttribute(coll, 14);
                cout << "\n\n\t\t\t\t The libraray is empty , please add book first. \n\n";
                nchars_line(115, '-');
                SetConsoleTextAttribute(coll, 7);
                cout << "\nEnter any key to continue : ";
                char x; cin >> x;
                system("cls");
            }
            else
            {
                cout << library;
                SetConsoleTextAttribute(coll, 7);
                cout << "\t==> To order by author enter number 1 \n\n";
                cout << "\t==> To order by genre enter number 2\n\n";
                cout << "\t==> To order by availability enter number 3\n\n";
                cout << "\t==> To rotate the list enter number 4\n\n";
                cout << "\t==> To inverse the list enter number 5\n\n";
                cout << "\t==> Enter number 6 to continue : ";
                int x; cin >> x;
                while (x > 6 || 0 >= x)
                {
                    cout << "\n Wrong enter , please try again : ";
                    cin >> x;
                }
                system("cls");
                header();
                switch (x) {
                case 1:
                    for (int i = 0; i < authors.get_size(); i++)
                        for (int r = 0; r < library.get_size(); r++)
                            if (authors[i] == library[r].get_author())
                                cout << library[r];
                    cout << "\t==> Enter number any key to continue : ";
                    char x; cin >> x;
                    system("cls");
                    break;
                case 2:
                    for (int i = 0; i < authors.get_size(); i++)
                        for (int r = 0; r < library.get_size(); r++)
                            if (genres[i] == library[r].get_genre())
                                cout << library[r];
                    cout << "\t==> Enter number any key to continue : ";
                    char h; cin >> h;
                    system("cls");
                    break;

                case 3:
                    for (int i = 0; i < authors.get_size(); i++)
                            if (library[i].get_availability() == true)
                                cout << library[i];
                    cout << "\t==> Enter number any key to continue : ";
                    char m; cin >> m;
                    system("cls");
                    break;

                case 4:
                    library.right_rotate();
                    cout << library;
                    cout << "\t==> Enter number any key to continue : ";
                    char o; cin >> o;
                    system("cls");
                    break;

                case 5:
                    library.inverse();
                    cout << library;
                    cout << "\t==> Enter number any key to continue : ";
                    char k; cin >> k;
                    system("cls");
                    break;

                }
                system("cls");
            }
            break;
        case 2:
        {
            string title, author, genre;
            int availability;
            cout << "Enter the title : ";
            SetConsoleTextAttribute(coll, 12);
            cin >> title;
            SetConsoleTextAttribute(coll, 7);
            cout << "\nEnter the Author : ";
            SetConsoleTextAttribute(coll, 12);
            cin >> author;
            SetConsoleTextAttribute(coll, 7);
            cout << "\nEnter the Genre : ";
            SetConsoleTextAttribute(coll, 12);
            cin >> genre;
            SetConsoleTextAttribute(coll, 7);
            cout << "\nEnter the Availability (1 for true and 0 for false) : ";
            SetConsoleTextAttribute(coll, 12);
            cin >> availability;
            SetConsoleTextAttribute(coll, 2);
            cout << " \n\t\t\t\t\tsaved \n";
            SetConsoleTextAttribute(coll, 7);
            Sleep(3000);
            system("cls");

            Book inbook(title, author, genre, availability);
            library.add_element(inbook);
            authors.add_element(author);
            genres.add_element(genre);
            break;
        }

        case 3:
            cout << "\t==> To remove a book enter number 1\n\n";
            cout << "\t==> To remove an author enter number 2\n\n";
            cout << "\t==> To remove a genre enter number 3 \n\n";
            cout << "\t==> Enter number 4 to continue : ";
            int f; cin >> f;
            while (f > 4 || 0 >= f)
            {
                cout << "\n Wrong enter , please try again : ";
                cin >> f;
            }
            system("cls");
            header();
            switch (f) {
            case 1:
            {
                string title;
                cout << "Enter the title : ";
                SetConsoleTextAttribute(coll, 12);
                cin >> title;
                SetConsoleTextAttribute(coll, 7);
                for (int i = 0; i < library.get_size(); i++)
                    if (library[i].get_title() == title)
                    {
                        library.remove_indix(i);
                        SetConsoleTextAttribute(coll, 2);
                        cout << " \n\t\t\t\t\Deleted \n";
                        SetConsoleTextAttribute(coll, 7);
                        Sleep(3000);
                    }
                system("cls");
                break;
            }
            case 2:
            {
                string author;
                cout << "Enter the Author : ";
                SetConsoleTextAttribute(coll, 12);
                cin >> author;
                SetConsoleTextAttribute(coll, 7);
                for (int i = 0; i < library.get_size(); i++)
                    if (library[i].get_author() == author)
                    {
                        library.remove_indix(i);
                        authors.remove_value(author);
                        SetConsoleTextAttribute(coll, 2);
                        cout << " \n\t\t\t\t\Deleted \n";
                        SetConsoleTextAttribute(coll, 7);
                        Sleep(3000);
                    }
                system("cls");
                break;
            }
            case 3:
            {
                string genre;
                cout << "Enter the Genre : ";
                SetConsoleTextAttribute(coll, 12);
                cin >> genre;
                SetConsoleTextAttribute(coll, 7);
                for (int i = 0; i < library.get_size(); i++)
                    if (library[i].get_genre() == genre)
                    {
                        library.remove_indix(i);
                        genres.remove_value(genre);
                        SetConsoleTextAttribute(coll, 2);
                        cout << " \n\t\t\t\t\Deleted \n";
                        SetConsoleTextAttribute(coll, 7);
                        Sleep(3000);
                    }
                system("cls");
                break;
            }

            }
            break;
        case 4:
        {
            cout << "\t==> To search for book enter number 1\n\n";
            cout << "\t==> To search for author enter number 2\n\n";
            cout << "\t==> To search for genre enter number 3 \n\n";
            cout << "\t==> Enter number 4 to continue : ";
            int f; cin >> f;
            while (f > 4 || 0 >= f)
            {
                cout << "\n Wrong enter , please try again : ";
                cin >> f;
            }
            system("cls");
            header();
            switch (f) {
            case 1:
            {
                string title;
                cout << "Enter the title : ";
                SetConsoleTextAttribute(coll, 12);
                cin >> title;
                SetConsoleTextAttribute(coll, 7);
                system("cls");
                header();
                for (int i = 0; i < library.get_size(); i++)
                    if (library[i].get_title() == title)
                    {
                        cout << library[i];
                    }
                        cout << "\t==> Enter number any key to continue : ";
                        char b; cin >> b;
                system("cls");
                break;
            }
            case 2:
            {
                string author;
                cout << "Enter the author : ";
                SetConsoleTextAttribute(coll, 12);
                cin >> author;
                SetConsoleTextAttribute(coll, 7);
                system("cls");
                header();
                for (int i = 0; i < library.get_size(); i++)
                    if (library[i].get_author() == author)
                    {
                        cout << library[i];
                    }
                cout << "\t==> Enter number any key to continue : ";
                char b; cin >> b;
                system("cls");
                break;
            }
            case 3:
            {
                string genre;
                cout << "Enter the genre : ";
                SetConsoleTextAttribute(coll, 12);
                cin >> genre;
                SetConsoleTextAttribute(coll, 7);
                system("cls");
                header();
                for (int i = 0; i < library.get_size(); i++)
                    if (library[i].get_genre() == genre)
                    {
                        cout << library[i];
                    }
                cout << "\t==> Enter number any key to continue : ";
                char b; cin >> b;
                system("cls");
                break;
            }
            break;
            }
        default:
            break;
        }
        }
        
    } while (choose != 5);
    system("cls");
    end();


}


template <class R>
ostream& operator <<(ostream& os, const the_vector<R>& v) {
    for (int i = 0; i < v.get_size(); i++)
        os << v.arr[i] << " ";
    os << "\n";
    return os;
}

//===========================================================================================

ostream& operator <<(ostream& os, const Book& b) {
	os << setw(15) << "Title : " << setw(20) << b.get_title() << endl;
	os << setw(15) << "Author : " << setw(20) << b.get_author() << endl;
	os << setw(15) << "Genre : " << setw(20) << b.get_genre() << endl;
	os << setw(15) << "Availability : " << setw(20);
	if (b.get_availability())
		os << "Available";
	else
		os << "Not available";
	os << endl;
    for (int i = 0; i < 115; ++i) {
        cout << '-';
    }
    cout << "\n";
	return os;
}

//==============================================================================================

inline void header() {
    cout << endl << setw(44);
    nchars_line(30, '-');
    cout << setw(43) << "|";
    SetConsoleTextAttribute(coll, 12);
    cout << "           Library";
    SetConsoleTextAttribute(coll, 7);
    cout << setw(13) << "|" << endl;
    nchars_line(115, '-');
    cout << endl;
}
void nchars_line(int n, char c) {
    for (int i = 0; i < n; ++i) {
        cout << c;
    }
    cout << "\n";
}


//=================================================================================================
//=================================================================================================

void end() {


    for (int i = 0; i < 10; i++)
        cout << endl;

    SetConsoleTextAttribute(coll, 2);

    cout << "\t\t\t\tTTTTT    HH   HH    AAA    N     N   K   K    SSSS\n";
    cout << "\t\t\t\t  T      HH   HH   A   A   NN    N   K  K    S    \n";
    cout << "\t\t\t\t  T      HHHHHHH   AAAAA   N N   N   KK      SSSS \n";
    cout << "\t\t\t\t  T      HH   HH   A   A   N  N  N   K  K        S\n";
    cout << "\t\t\t\t  T      HH   HH   A   A   N   N N   K   K   SSSS \n";


    Sleep(3000);
    system("cls");

    for (int i = 0; i < 10; i++)
        cout << endl;


    cout << "\t\t\t\t\tBBBBB    YY    YY   EEEEE\n";
    cout << "\t\t\t\t\tB    B    YY  YY    E     \n";
    cout << "\t\t\t\t\tB    B     YYYY     E     \n";
    cout << "\t\t\t\t\tBBBBB       YY      EEEEE \n";
    cout << "\t\t\t\t\tB    B      YY      E     \n";
    cout << "\t\t\t\t\tB    B      YY      E     \n";
    cout << "\t\t\t\t\tBBBBB       YY      EEEEE\n";

    Sleep(5000);
    system("cls");

    SetConsoleTextAttribute(coll, 7);
}


//===================================================================================

void hello() {

    for (int i = 0; i < 10; i++)
        cout << endl;

    SetConsoleTextAttribute(coll, 2);

    cout << "\t\t\t\t\tH   H    EEEEE   L       L        OOOOO \n";
    cout << "\t\t\t\t\tH   H    E       L       L       O     O \n";
    cout << "\t\t\t\t\tH   H    E       L       L       O     O \n";
    cout << "\t\t\t\t\tHHHHH    EEEEE   L       L       O     O \n";
    cout << "\t\t\t\t\tH   H    E       L       L       O     O \n";
    cout << "\t\t\t\t\tH   H    E       L       L       O     O \n";
    cout << "\t\t\t\t\tH   H    EEEEE   LLLLL   LLLLL    OOOOO \n";

    Sleep(2000);
    system("cls");


    SetConsoleTextAttribute(coll, 7);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWelcome in";
    Sleep(3000);

    system("cls");

    SetConsoleTextAttribute(coll, 12);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLibrary Management";
    Sleep(3000);

    system("cls");
}