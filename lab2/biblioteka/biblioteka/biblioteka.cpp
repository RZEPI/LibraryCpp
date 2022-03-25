#include <iostream>
#include "Book.h"
#include "Library.h"

using namespace std;

/*ostream& operator<<(ostream& ostr, const Book& book)
{
    ostr << "Ksiazka " << book.GetTitle() << " autorstwa " << book.GetAuthor() << "\n";
    return ostr;
}*/
ostream& operator<<(ostream& ostr, const Library& lib)
{
    for (int i = 0; i < lib.GetSize(); i++)
    {
        ostr << "Ksiazka " << lib[i].GetTitle() << " autorstwa " << lib[i].GetAuthor() << "\n";
    }
        
    return ostr;
}


int main()
{
    /*string a = "Edgar Allan Poe", t = "Czarny kot";
    Book e;
    cout << "e: " << e << endl;
    Book b1 = { a, t };
    cout << "b1: " << b1 << endl;
    Book b2 = { "Fodor Dostojewski","Biesy"};
    cout << "b2: " << b2 << endl;
    Book b3 = b1;
    cout << "b3: " << b3 << " b1: " << b1 << endl;
    e = move(b2);
    cout << "e: " << e << " b2:" << b2 << endl;
    e.SetAuthor("Lew Tolstoj");
    cout << "e: " << e << endl;
    e.SetTitle("Spowiedz");
    cout << "e: " << e << endl;

    cout << "\n\n\n\n\n"; //2 część instrukcji */

    Library e;
    cout << "e: " << e << endl;
    //3-5 książek
    Library l1 = { {"Ernest Hamingway", "Stary czlowiek i morze"},
    {"Franz Kafka", "Proces"},
    {"Fiodor Dostojewski", "Bracia Karamazow"} };
    cout << "l1: " << l1 << endl;
    Library l2(2);
    cout << "l2: " << l2 << endl;
    l2[0] = { "George Orwell", "Folwark zwierzecy" };
    l2[1] = { "Stanislaw Witkiewicz", "Szewcy" };
    cout << "l2: " << l2 << endl;
    e = move(l2);// w tym miejscu jest problem !!!
    cout << "e: " << e << " l2: " << l2 << endl;
    l1[0] = move(e[1]);
    cout << "l1: " << l1 << " e: " << e << endl; 

    return 0;
}

