// Operator overloading using functions

#include <iostream>
using namespace std;
class A
{
    int value;

  public:
    A(int a) : value(a) {}
    // second const is for the implicit this
    // it means you can't change the members
    // of this object except mutable ones
    const int &getValue() const { return value; }
};

int operator+(const A &lhs, const A &rhs) { return lhs.getValue() + rhs.getValue(); }
int main(int argc, char const *argv[])
{
    A a(5), b(7);
    cout << a + b << endl;
    /* code */
    return 0;
}
