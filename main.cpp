#include <iostream>
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



int main()
{
    return 0;
}