#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Book.h"
using namespace std;

class LibraryClass
{
private:
    vector<Book> books;
public:
    void AddBook(string NameBook, string Author, int YearPublication, string ISBN);
    void PrintBooks();
    void DeleteBook(string ISBN);
    void FindBook(string Author);
    void SavetoFaile(string path);
    void Downloadfromfile(string path);
    void SavetoCache();
    void DowlondfromCache();
    void DeleteLibrary();
};