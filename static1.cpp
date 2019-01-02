// Why static
// From lynda.com
// static helps in creating objects in non-stack location
// useful for large object. Persisted across functions. Thus
// need to be made const if any alterations from callee are to
// be disallowed

#include <iostream>
#include <string>
using namespace std;
const string &cheer()
{
    // Don't do this. Stack variables get destroyed leaving
    // refrences to them dangling.
    // string cheer = "Hello World!";
    static string cheer = "Hello World!";
    return cheer;
}

int main(int argc, char const *argv[])
{
    const string &s = cheer();
    cout << s << endl;

    // Not allowed
    // s.append("Extra");
    // s = cheer();
    // cout << s << endl;
    return 0;
}
