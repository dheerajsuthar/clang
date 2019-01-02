#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    cout << "Hello World\n";
    char name[] = "Dheeraj";
    char *p = name;
    int count = 0;
    int loopc = 0;
    while (p)
    {
        loopc++;
        if (*p == 'e')
            count++;
        cout << count << " " << *p << "\n";
        if (loopc == 12)
            break;
        p++;
    }

    cout << "count " << count << endl;
    return 0;
}
