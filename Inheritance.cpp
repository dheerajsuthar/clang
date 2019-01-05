#include <iostream>
using namespace std;
class Animal
{
  private:
    string _name;
    string _class;
    Animal() {}

  protected:
    Animal(string n, string c) : _name(n), _class(c) {}

  public:
    virtual void intro()
    {
        cout << _name << " belongs to " << _class << endl;
    }
    inline string getName() const { return _name; }
    inline string getClass() const { return _class; }
};

class Lion : public Animal
{
  private:
    int _legs;

  public:
    Lion(string n, string c, int f) : Animal(n, c), _legs(f) {}
    void intro()
    {
        cout << getName() << " belongs to " << getClass() << " and has " << _legs << " legs." << endl;
    }
};

int main(int argc, char const *argv[])
{
    Lion l("Alex", "feline", 4);
    Animal &a = l; // or Animal *a = &l
    l.intro();
    a.intro();
    return 0;
}
