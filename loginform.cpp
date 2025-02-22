#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string username, email, password;
    string searchname, searchpass, searchemail;
    fstream file;

public:
    void signup();
    void login();
    void forgetpassword();
} obj;

int main()
{
    char choice;
    cout << "1-Login" << endl;
    cout << "2-Sign up" << endl;
    cout << "3-Forget Password" << endl;
    cout << "4-Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.login();
        break;
    case '2':
        cin.ignore();
        obj.signup();
        break;
    case '3':
        cin.ignore();
        obj.forgetpassword();
        break;
    case '4':
        return 0;
        break;
    default:
        cout << "Invalid Selection! " << endl;
        break;
    }
}
void temp::signup()
{
    cout << "-------:Sign up Form:--------" << endl;
    cout << "\nEnter your username: ";
    getline(cin, username);
    cout << "\nEnter your Email Address: ";
    getline(cin, email);
    cout << "\nEnter your Password: ";
    getline(cin, password);
    file.open("LoginData.txt", ios::out | ios::app);
    file << username << "*" << email << "*" << password << endl;
    file.close();
}
void temp::login()
{
    cout << "-------:Login Form:--------" << endl
         << endl;
    cout << "Enter your Username: " << endl;
    getline(cin, searchname);
    cout << "Enter your Password: " << endl;
    getline(cin, searchpass);
    file.open("LoginData.txt", ios::in);
    getline(file, username, '*');
    getline(file, email, '*');
    getline(file, password, '*');
    while (!file.eof())
    {
        if (username == searchname)
        {
            if (password == searchpass)
            {
                cout << "Account Login is Successful: " << endl;
                cout << "Username: " << username << endl;
                cout << "Email: " << email << endl;
            }
            else
            {
                cout << "Your password is incorrect!" << endl;
            }
        }
        getline(file, username, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    file.close();
}
void temp::forgetpassword()
{
    cout << "\nEnter your username: ";
    getline(cin, searchname);
    cout << "\nEnter your Email: ";
    getline(cin, searchemail);

    file.open("loginData.txt", ios ::in);
    getline(file, username, '*');
    getline(file, email, '*');
    getline(file, password, '\n');
    while (!file.eof())
    {
        if (username == searchname)
        {
            if (email == searchemail)
            {
                cout << "Your Account was Found! " << endl;
                cout << "Your password is: " << password << endl;
            }
            else
            {
                cout << "Account was not Found! " << endl;
            }
        }
        getline(file, username, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    file.close();
}