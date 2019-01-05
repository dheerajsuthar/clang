#include <iostream>
#include <math.h>
#include <exception>
using namespace std;

class CException : public exception
{
  private:
    string message;

  public:
    CException(string message) : message(message)
    {
    }
    const char *what()
    {
        return message.c_str();
    }
    ~CException() throw() {}
};

//Interface
class Rational
{
  private:
    int _n;
    int _d;

  public:
    Rational(int num = 0, int den = 1) : _n(num), _d(den)
    {
        if (den == 0)
            throw CException("Illegal denominator!");
    }
    Rational(const Rational &rhs) : _n(rhs._n), _d(rhs._d) {}
    ~Rational() {}
    inline int numerator() { return _n; }
    inline int denominator() { return _d; }
    Rational operator=(const Rational &);
    Rational operator+(const Rational &) const;
    Rational operator-(const Rational &) const;
    Rational operator*(const Rational &)const;
    Rational operator/(const Rational &) const;

    // Compound operators
    // Check implmentations to see why they are clearly more
    // efficient than their non-compound versions
    Rational &operator+=(const Rational &);
    Rational &operator-=(const Rational &);
    Rational &operator*=(const Rational &);
    Rational &operator/=(const Rational &);

    // Increment/Decrement
    // Pre-increment is much efficient than Post.
    Rational &operator++(int);
    Rational operator++();

    friend ostream &operator<<(ostream &, const Rational &);
};

//Implementation
Rational Rational::operator=(const Rational &rhs)
{
    if (this != &rhs)
    {
        this->_n = rhs._n;
        this->_d = rhs._d;
    }
    //for chaining
    return *this;
}

Rational Rational::operator+(const Rational &rhs) const
{
    return Rational(_n * rhs._d + _d * rhs._n, _d * rhs._d);
}
Rational Rational::operator-(const Rational &rhs) const
{
    return Rational(_n * rhs._d - _d * rhs._n, _d * rhs._d);
}
Rational Rational::operator*(const Rational &rhs) const
{
    return Rational(_n * rhs._n, _d * rhs._d);
}
Rational Rational::operator/(const Rational &rhs) const
{
    return Rational(_n * rhs._d, _d * rhs._n);
}

Rational &Rational::operator+=(const Rational &rhs)
{
    this->_n = _n * rhs._d + _d * rhs._n;
    this->_d = _d * rhs._d;
    return *this;
}

Rational &Rational::operator-=(const Rational &rhs)
{
    this->_n = _n * rhs._d - _d * rhs._n;
    this->_d = _d * rhs._d;
    return *this;
}

Rational &Rational::operator*=(const Rational &rhs)
{
    this->_n *= rhs._n;
    this->_d *= rhs._d;
    return *this;
}

Rational &Rational::operator/=(const Rational &rhs)
{
    this->_n *= rhs._d;
    this->_d *= rhs._n;
    return *this;
}

Rational &Rational::operator++(int)
{
    this->_n += this->_d;
    return *this;
}

Rational Rational::operator++()
{
    Rational temp = *this;
    this->_n += this->_d;
    return temp;
}

ostream &operator<<(ostream &out, const Rational &r)
{
    out << r._n << "/" << r._d;
    return out;
}

int main()
{
    try
    {
        Rational a(3, 4), b(5, 6);
        cout << a + b << endl;
        cout << a - b << endl;
        Rational c = a;
        cout << c << endl;
        cout << c * Rational(b) << endl;
        a += b;
        cout << a << endl;
        a++;
        cout << a << endl;
        ++a;
        cout << a << endl;
    }
    catch (CException e)
    {
        cout << e.what() << endl;
    }
}