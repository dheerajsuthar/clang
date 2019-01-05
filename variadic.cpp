#include <cstdarg>
#include <cstdio>

// count -> number of arguments
// ... -> arguments
double average(int count, ...)
{
    va_list ap;
    double total = 0.0;

    va_start(ap, count);
    for (int i = 0; i < count; i++)
    {
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total / count;
}

// Dup of printf
// fmt-> format
// ...-> what to print
int log(const char *fmt, ...)
{
    va_list ap;
    // second argument -> last param to avoid
    va_start(ap, fmt);
    int rc = vfprintf(stdout, fmt, ap);
    va_end(ap);
    return rc;
}

int main(int argc, char const *argv[])
{
    log("Hello world\n");
    log("Average is %lf\n", average(2, 5, 6, 9));
    return 0;
}
