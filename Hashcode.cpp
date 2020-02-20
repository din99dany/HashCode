#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility> 

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
        to_be_scanned.push_back(id);
    }
};

std::vector<Res> Rezultate;

int main()
{
    return 0;
}