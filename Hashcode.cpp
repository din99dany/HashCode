#include <iostream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector> 
#include <numeric>
#include<cstdio>


int viz[100005];

class Book
{
public:

    int m_score;
    int m_id;

    Book() {
    }

    Book(int score, int id)
    {
        m_score = score;
        m_id = id;
    }


    inline int GetScore() { return m_score; }
    inline void SetScore(int newScore) { m_score = newScore; }

    inline int GetId() { return m_id; }
    inline void SetId(int newId) { m_id = newId; }

};

class Library
{
public:

    int Number_of_books;
    int Time_sign_up_process;
    int Books_shipped;
    std::vector<Book> Books;

    Library() {}

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
    
    double get_score()
    {
        std::vector<Book> ship;
        int size = Books.size();
        int number_to_be_shipped = 0;


        for (int i = 0; i < size; i++)
        {
            if (viz[Books[i].m_id] == 0)
            {
                number_to_be_shipped++;
                ship.push_back(Books[i]);
            }

        }

        double Sum = 0;
        size = ship.size();
        for (int i = 0; i < size; i++)
        {
             Sum = Sum + ship[i].m_score;
        }

        Sum = Sum / (number_to_be_shipped / Books_shipped + Time_sign_up_process);
        return Sum;
    }

};

class Res
{
public:
    int IDs;
    int Nr_books;
    std::vector<int> to_be_scanned;

    Res() {}
    Res(int id, int nr)
    {
        IDs = id;
        Nr_books = nr;
    }

    void add_book(int id)
    {
        to_be_scanned.push_back(id);
    }
};

std::vector<Book> marchez_carti(Library x, int timp_ramas)
{
    int zile_scanare;
    std::vector<Book> carti_trimise;
    std::vector<Book> ship;
    int number_to_be_shipped = 0;
    int size = x.Books.size();


    for (int i = 0; i < size; i++)
    {
        if (viz[x.Books[i].m_id] == 0)
        {
            number_to_be_shipped++;
            ship.push_back(x.Books[i]);
        }

    }


    if( (double(number_to_be_shipped)/ x.Books_shipped)== number_to_be_shipped / x.Books_shipped)
        zile_scanare = number_to_be_shipped / x.Books_shipped;
    else
        zile_scanare = number_to_be_shipped / x.Books_shipped +1;


    if (zile_scanare < timp_ramas)
    {
        carti_trimise = ship;
        for (int i = 0; i < ship.size(); i++)
        {
            viz[ship[i].m_id] = 1;
        }
    }
    else
    {
        for (int i = 0; i < x.Books_shipped*timp_ramas; i++)
        {
            carti_trimise.push_back(ship[i]);
            viz[ship[i].m_id] = 1;
        }
    }
    return carti_trimise;
}


int main()
{
    int noOfBooks, noOfLibraries, noOfDays;
    std::cin >> noOfBooks >> noOfLibraries >> noOfDays;

    std::vector<Book> books;
    std::vector<Library> libraries;

    for (int i = 0; i < noOfBooks; ++i)
    {
        int score;
        std::cin >> score;
        books.push_back(Book(score, i));
    }

    for (int i = 0; i < noOfLibraries; ++i)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        Library toAddLib(x, y, z);

        std::vector< Book > toAddBooks;
        for (int j = 0; j < x; ++j)
        {
            int idToAdd;
            std::cin >> idToAdd;
            toAddBooks.push_back(books[idToAdd]);
        }
        toAddLib.add_books(toAddBooks);
        libraries.push_back(toAddLib);
    }



    return 0;
}