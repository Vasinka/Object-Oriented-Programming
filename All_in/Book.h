#include<iostream>
class Book {
private:
char * title;
int pagesCount;
public:
    Book();
    ~Book();
    Book (conts Book &);
    Book &operator=(const Book&);
    void setTitle(const char*);
    void setPagesCount(int);
    const char* getTitle()const;
    int getPagesCount)const;
    friend ostream&operator<<(ostream& constBook&);
    friend istream&operator>>(istream& Book&);
    friend bool operator>(const Book&, const Book&);
    friend bool operator<(const Book&, const Book&);
    };

