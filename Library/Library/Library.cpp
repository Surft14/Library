#include <iostream>
#include <conio.h>
#include "Book.h"
#include "LibraryClass.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    LibraryClass lib;
    string ISBN;
    string NameBook;
    string Author;
    string path;
    int YearPublication;
    int value;
    lib.DowlondfromCache();
    while (true)
    {
        system("cls");
        cout << "Привет  пользователь это электронная библиотекаc. Здесь ты сможешь вести заметку книг которые ты прочел, читаеншь  или хочешь прочесть" << endl;
        cout << "Пожалуйста выберите что вы хотите сделать и введите число: " << endl;
        cout << "1 добавить книгу в библиотеку:" << endl;
        cout << "2 удалить гнигу" << endl;
        cout << "3 найти книгу" << endl;
        cout << "4 вывести библиотеку в консоль" << endl;
        cout << "5 сохранить в файл" << endl;
        cout << "6 скачать из файла" << endl;
        cout << "7 удалить библиотеку" << endl;
        cout << "8 Выход" << endl;
        cout << "Введите: ";
        cin >> value;
        switch (value)
        {
        case 1:
            cout << "Если вы хотите добавить книгу то введите название книги ее автора год выпуска и номер ISBN(на англиском)" << endl;
            cout << "Название: ";
            cin >> NameBook;
            cout << "Автор: ";
            cin >> Author;
            cout << "Год выпуска: ";
            cin >> YearPublication;
            cout << "ISBN: ";
            cin >> ISBN;
            lib.AddBook(NameBook, Author, YearPublication, ISBN);
            lib.SavetoCache();
            ISBN = "";
            NameBook = "";
            Author = "";
            YearPublication = 0;
            cout << "Все сохранилось! нажмите любую клавишу" << endl;
            _getch();
            break;
        case 2:
            cout << endl;
            cout << "Введите номер ISBN для удаления книги:";
            cin >> ISBN;
            lib.DeleteBook(ISBN);
            lib.SavetoCache();
            cout << "Книга удалина! нажмите любую клавишу" << endl;
            _getch();
            break;
        case 3:
            cout << endl;
            cout << "Введите имя автора:";
            cin >> Author;
            lib.FindBook(Author);
            cout << "Книга найдена! нажмите любую клавишу" << endl;
            _getch();
            break;
        case 4:
            cout << endl;
            lib.PrintBooks();
            cout << "нажмите любую клавишу" << endl;
            _getch();
            break;
        case 5:
            cout << endl;
            cout << "Введите путь к файлу или его название(на англиском):" << endl;
            cin >> path;
            lib.SavetoFaile(path);
            lib.SavetoCache();
            cout << "Файл сохранен в " << path << endl;
            cout << "нажмите любую клавишу" << endl;
            _getch();
            break;
        case 6:
            cout << endl;
            cout << "Введите путь к файлу или его имя(на англиском ):" << endl;
            cin >> path;
            lib.Downloadfromfile(path);
            lib.SavetoCache();
            cout << "Книги скаченны нажмите любую клавишу" << endl;
            _getch();
            break;
        case 7:
            cout << "Вы уверенный что хотите удалить библиотеку?!" << endl;
            cout << "ДА(1) НЕТ(0): ";
            cin >> value;
            if (value == 1)
            {
                lib.DeleteLibrary();
                cout << "Библиотека удалена!" << endl;
                _getch();
            }
            else
            {
                cout << "Библиотека не удалина!";
                _getch();
            }
            break;
        case 8:
            exit(0);
        default:
            cout << "Такой функции нет";
            _getch();
            break;
        }
    }
}