#include <iostream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility> 
#include <cstdio>
#define NMAX 500001
std::vector<bool> WasScaned( NMAX, false );
int viz[NMAX];

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

bool CmpBooks( Book a, Book b )
{
    if ( a.GetScore() < b.GetScore() )
        return true;
    return false;
}

class Library
{   
public:

    int Number_of_books;
    int Time_sign_up_process;
    int Books_shipped;
    int id;
    std::vector<Book> Books;

    Library(){}

    Library(int mid, int number_books, int time_sign_up, int number_books_ship)
    {
        Number_of_books = number_books;
        Time_sign_up_process = time_sign_up;
        Books_shipped = number_books_ship;
        id = mid;
    }

    void add_books(std::vector<Book> carti)
    {
        Books = carti;
    }

    void SortBooks()
    {
        std::sort( Books.begin(), Books.end(), CmpBooks );
    }

    int get_score()
    {
        int Sum = 0;
        int size = Books.size();
        for (int i = 0; i < size; i++)
        {
            if (viz[Books[i].m_id] != 1)
            {
                Sum = Sum + Books[i].m_score;
            }
        }
        return Sum;
    }

};

bool cmpLibs( Library a, Library b )
{

    if ( a.get_score() > b.get_score() )
        return true;
    return false;
}

class Res
{
public:
    int IDs;
    int Nr_books;
    std::vector<int> to_be_scanned;

    Res(){}
    Res(int id, int nr)
    {
        IDs = id;
        Nr_books = nr;
    }

    void add_book(int id)
    {   
        viz[ id ] = true;
        to_be_scanned.push_back(id);
    }

    void PrintRes()
    {   
        if ( to_be_scanned.empty() )
            return;

        std::cout << IDs << " " << to_be_scanned.size() << "\n";
        for ( auto item : to_be_scanned )
        {
            std::cout<<item<<" ";
        }
        std::cout<<"\n";
    }
};


int main()
{   

    freopen("out.txt","w",stdout);
    int noOfBooks, noOfLibraries, noOfDays;
    int currentTime = 0;

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
        Library toAddLib( i, x, y, z );

        std::vector< Book > toAddBooks;
        for ( int j = 0; j < x; ++j )
        {
            int idToAdd;
            std :: cin >> idToAdd;
            toAddBooks.push_back( books[ idToAdd] );
        }
        toAddLib.add_books( toAddBooks );
        toAddLib.SortBooks();
        libraries.push_back( toAddLib );
    }

    std::sort( libraries.begin(), libraries.end(), cmpLibs );
    std::vector< Res >  finalRes;
    
    while (  currentTime <  noOfDays && !libraries.empty() )
    {   
        auto selectedLib = libraries.front();
        libraries.erase( libraries.begin() );

        int scannedBooks = 0;
        currentTime += selectedLib.Time_sign_up_process + 1;

        Res result(selectedLib.id,0);

        int copyTime = currentTime;
        while ( selectedLib.Books.size() > 0 && copyTime <  noOfDays )
        {   
            for ( int time = 0; time < selectedLib.Books_shipped && !selectedLib.Books.empty(); ++time )
            {   
                auto toAddBook = selectedLib.Books.back();

                selectedLib.Books.erase( selectedLib.Books.end() );
                if ( viz[toAddBook.GetId()] )
                {
                    time--;
                    continue;
                }
                result.add_book(toAddBook.GetId());
            }  
            copyTime++;
        }
        
        if ( !result.to_be_scanned.empty() )
            finalRes.push_back(result);

        //result.PrintRes();
        //std::sort( libraries.begin(), libraries.end(), cmpLibs );

    }
    std::cout << finalRes.size() << "\n";
    for ( auto item : finalRes )
    {
        item.PrintRes();
    }


    return 0;
}