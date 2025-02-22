#include <iostream>
#include <fstream>
using namespace std;

class temp
{
public:
    string name, id, authorname, search;
    fstream file;
    void showallbooks();
    void addbooks();
    void extractbooks();
} obj;

int main()
{
    char choice;
    cout << "-----------------------" << endl;
    cout << "1-Show all Books! " << endl;
    cout << "2-Add(admin)Books! " << endl;
    cout << "3-Extract Book! " << endl;
    cout << "4-Exit! " << endl;
    cout << "-----------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.showallbooks();
        break;
    case '2':
        cin.ignore();
        obj.addbooks();
        break;
    case '3':
        cin.ignore();
        obj.extractbooks();
        break;
    case '4':
        return 0;
        break;
    default:
        cout << "invalid choice! " << endl;
    }
}
void temp::addbooks()
{
    cout << "\nEnter Book Id: ";
    getline(cin, id);
    cout << "Enter Book name: ";
    getline(cin, name);
    cout << "Enter Author name: ";
    getline(cin, authorname);
    file.open("Bookdata.txt", ios::out | ios::app);
    file << id << "*" << name << "*" << authorname <<endl;
    file.close();
}
void temp::showallbooks()
{
    file.open("Bookdata.txt", ios::in);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, authorname, '\n');
    cout << "\t\tBook Id"<< "\t\t"<< "Book Name"<< "\t\t"<< "Author Name";
    while (!file.eof())
    {
    cout << "\t\t" << id << "\t\t" << name << "\t\t" << authorname << endl;
     getline(file, id, '*');
     getline(file, name, '*');
     getline(file, authorname, '\n');
    }
   
    file.close();
}

void temp::extractbooks()
{
    showallbooks();
    file.open("Bookdata.txt", ios::in);
    cout << "Enter your search: ";
    getline(cin, search);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, authorname, '\n');
    while (!file.eof())
    {
        if (id == search)
        {
            cout << "Sucessfully Extracted! " << endl;
            cout << "\t\t" << id << "\t\t" << name << "\t\t" << authorname << endl;
        }
        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, authorname, '\n');   
    }
    file.close();
}