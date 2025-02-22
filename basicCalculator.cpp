#include <iostream>
using namespace std;

class temp{
public:
    int a, b, c;
    char op;
    void getvalue1();
    void getvalue2();
    void getoperator();
    void add();
    void sub();
    void mul();
    void div();
} obj;

int main()
{
    cout << "-----------Basic Calculator-------------" << endl;
    obj.getvalue1();
    while (1)
    {
        obj.getoperator();
        if (obj.op == '=')
        {
            cout << "\nFinal Answer is: " << obj.a << endl;
            return 1;
        }
        obj.getvalue2();
        if (obj.op == '+')
        {
            obj.add();
        }
        if (obj.op == '-')
        {
            obj.sub();
        }
        if (obj.op == '*')
        {
            obj.mul();
        }
        if (obj.op == '/')
        {
            obj.div();
        }
    }
    return 0;
}
void temp::getvalue1()
{
    cout << "Enter the value : ";
    cin >> a;
}
void temp::getvalue2()
{
    cout << "Enter the value : ";
    cin >> b;
}
void temp::getoperator()
{
    cout << "Enter Operator: ";
    cin >> op;
}
void temp::add()
{
    c = a + b;
    cout << a << " + " << b << " == " << c << endl;
    a = c;
    b = 0;
}
void temp::sub()
{
    c = a - b;
    cout << a << " - " << b << " == " << c << endl;
    a = c;
    b = 0;
}
void temp::mul()
{
    c = a * b;
    cout << a << " * " << b << " == " << c << endl;
    a = c;
    b = 0;
}
void temp::div()
{
    c = a / b;
    cout << a << " / " << b << " == " << c << endl;
    a = c;
    b = 0;
}
