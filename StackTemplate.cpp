#include <iostream>
using namespace std;

class CException : public exception
{
  private:
    const char *_s;

  public:
    CException(const char *message) : _s(message) {}
    virtual const char *what() const throw() { return _s; }
};

template <typename S>
class Stack
{
    S *_items;
    int _tos;
    int _size;
    Stack() {}

  public:
    Stack(int size) : _size(size)
    {
        _items = new S[size];
    }
    ~Stack() { delete[] _items; }
    bool isEmpty()
    {
        return (_tos == 0);
    }
    bool isFull()
    {
        return (_tos == _size);
    }
    int pop()
    {
        cout << "debug: pop: " << _tos << endl;
        if (isEmpty())
        {
            throw CException("Stack empty!");
        }
        return _items[_tos--];
    }
    void push(const S &item)
    {
        cout << "debug: push: " << _tos << endl;
        if (_tos == _size)
        {
            throw CException("Stack full!");
        }
        _items[++_tos] = item;
    }
};

int main(int argc, char const *argv[])
{
    try
    {
        Stack<int> stck(3);
        for (int i = 0; i < 3; i++)
        {
            stck.push(i);
        }
        cout << stck.pop() << endl;
        cout << stck.pop() << endl;
        cout << stck.pop() << endl;
        // cout << stck.pop() << endl;
    }
    catch (CException e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
