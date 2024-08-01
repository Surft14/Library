#include "LibraryClass.h"
#include "Book.h"
void LibraryClass::AddBook(string NameBook, string Author, int YearPublication, string ISBN)
{
    Book book;
    book.SetAuthor(Author);
    book.SetNameBook(NameBook);
    book.SetISBN(ISBN);
    book.SetYearPublication(YearPublication);

    books.push_back(book);
}
void LibraryClass::PrintBooks()
{
    cout << endl;
    cout << "Books: " << endl;
    for (auto& book : books)
    {
        cout << book.GetNameBook() << " " << book.GetAuthor() << " " << book.GetYearPublication() << " " << book.GetISBN() << endl;
    }
}
void LibraryClass::DeleteBook(string ISBN)
{
    books.erase(remove_if(books.begin(), books.end(), [ISBN](Book& b) {return b.GetISBN() == ISBN; }), books.end());
}
void LibraryClass::FindBook(string Author)
{
    for (auto& book : books)
    {
        if (book.GetAuthor() == Author)
        {
            cout << endl;
            cout << book.GetNameBook() << ", " << book.GetAuthor() << ", " << book.GetYearPublication() << ", " << book.GetISBN() << endl;
        }
    }
}
void LibraryClass::SavetoFaile(string path)
{
    ofstream fout;
    fout.open(path);
    for (auto& book : books)
    {
        fout << book.GetNameBook() << " " << book.GetAuthor() << " " << book.GetYearPublication() << " " << book.GetISBN() << endl;
    }
    fout.close();
}
void LibraryClass::SavetoCache()
{
    ofstream fout;
    fout.open("Cache.txt");
    for (auto& book : books)
    {
        fout << book.GetNameBook() << "\n" << book.GetAuthor() << "\n" << book.GetYearPublication() << "\n" << book.GetISBN() << endl;
    }
    fout.close();
}
void LibraryClass::DowlondfromCache()
{
    ifstream fin; 
    fin.open("Cache.txt");
    if (!fin.is_open()) 
    {
        ofstream fout; 
        fout.open("Cache.txt");
        fout.close();
    }
    else
    {
        string ISBN;
        string NameBook; 
        string Author; 
        string YearPublication; 
        Book book; 
        while (!fin.eof()) 
        {
            ISBN = ""; 
            NameBook = ""; 
            Author = ""; 
            YearPublication = ""; 
            fin >> NameBook;
            if (NameBook.empty())
            {
                break;
            }
            book.SetNameBook(NameBook); 
            fin >> Author; 
            book.SetAuthor(Author); 
            fin >> YearPublication; 
            book.SetYearPublication(stoi(YearPublication)); 
            fin >> ISBN; 
            book.SetISBN(ISBN);
            books.push_back(book);
        }
    }
}
void LibraryClass::DeleteLibrary()
{
    if (books.empty())
    {
        return;
    }
    else
    {
        books.clear();
        ofstream fout;
        fout.open("Cache.txt");
        fout << "";
        fout.close();
    }
}
void LibraryClass::Downloadfromfile(string path)
{
    ifstream fin;
    fin.open(path);
    if (!fin.is_open())
    {
        cout << "Error open file!" << endl;
    }
    else
    {
        string ISBN;
        string NameBook;
        string Author;
        string YearPublication;
        Book book;
        while (!fin.eof())
        {
            ISBN = "";
            NameBook = "";
            Author = "";
            YearPublication = "";
            getline(fin, NameBook);
            book.SetNameBook(NameBook);
            getline(fin, Author);
            book.SetAuthor(Author);
            getline(fin, YearPublication);
            book.SetYearPublication(stoi(YearPublication));
            getline(fin, ISBN);
            book.SetISBN(ISBN);
            books.push_back(book);
        }
    }
}