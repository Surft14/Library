#pragma once
#include <string>
#include <iostream>
using namespace std;
class Book
{
public:
	void SetNameBook(string NameBook);
	void SetAuthor(string Author);
	void SetYearPublication(int YearPublication);
    void SetISBN(string ISBN);
    string GetNameBook();
    string GetAuthor();
    int GetYearPublication();
    string GetISBN();
private:
    string ISBN;
    string NameBook;
    string Author;
    int YearPublication;
};