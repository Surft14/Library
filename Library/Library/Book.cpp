#include "Book.h"
void Book::SetNameBook(string NameBook)
{
    this->NameBook = NameBook;
}
void Book::SetAuthor(string Author)
{
    this->Author = Author;
}
void Book::SetYearPublication(int YearPublication)
{
    this->YearPublication = YearPublication;
}
void Book::SetISBN(string ISBN)
{
    this->ISBN = ISBN;
}
string Book::GetNameBook()
{
    return this->NameBook;
}
string Book::GetAuthor()
{
    return this->Author;
}
int Book::GetYearPublication()
{
    return this->YearPublication;
}
string Book::GetISBN()
{
    return this->ISBN;
}