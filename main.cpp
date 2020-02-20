#include <iostream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility> 
class Book 
{
public :

    int m_score;
    int m_id;

    Book(){
    }

    Book( int score, int id ) 
    {
        m_score = score;
        m_id = id;
    }


    inline int GetScore() { return m_score; }
    inline void SetScore( int newScore ) { m_score = newScore; }

    inline int GetId() { return m_id; }
    inline void SetId( int newId ) { m_id = newId; }

};

class Library
{   
public:

    int Number_of_books;
    int Time_sign_up_process;
    int Books_shipped;
    std::vector<Book> Books;

    Library(){}

    Library(int number_books, int time_sign_up, int number_books_ship)
    {
        Number_of_books = number_books;
        Time_sign_up_process = time_sign_up;
        Books_shipped = number_books_ship;
    }

    void add_books(std::vector<Book> carti)
    {
        Books = carti;
    }



};

int main()
{

    int noOfBooks, noOfLibraries, noOfDays;
    std::cin >> noOfBooks >> noOfLibraries >> noOfDays;

    std::vector<Book> books;
    std::vector<Library> libraries;

    for ( int i = 0; i < noOfBooks; ++i )
    {
        int score;
        std::cin >> score;
        books.push_back( Book( score, i ) );
    }

    for ( int i = 0; i < noOfLibraries; ++i )
    {
        int x, y, z;
        std :: cin >> x >> y >> z;
        Library toAddLib( x, y, z );

        std::vector< Book > toAddBooks;
        for ( int j = 0; j < x; ++j )
        {
            int idToAdd;
            std :: cin >> idToAdd;
            toAddBooks.push_back( books[ idToAdd] );
        }
        toAddLib.add_books( toAddBooks );
        libraries.push_back( toAddLib );
    }



    return 0;
}