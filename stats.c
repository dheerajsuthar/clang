#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DIGITS 10
#define LETTERS 26

void nullify(int arr[], int size);
void histogram(int arr[], int size, int start, int terminalWidth);
int getTermWidth();

int main()
{
    int digits[DIGITS];
    int letters[LETTERS];
    nullify(digits, DIGITS);
    nullify(letters, LETTERS);

    int c;
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            digits[c - '0']++;
        else if (c >= 'a' && c <= 'z')
            letters[c - 'a']++;
        else if (c >= 'A' && c <= 'Z')
            letters[c - 'A']++;
    }

    int terminalWidth = getTermWidth();
    histogram(digits, DIGITS, '0', terminalWidth);
    histogram(letters, LETTERS, 'a', terminalWidth);
}

void nullify(int arr[], int size)
{
    // alternatively can use memset
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

/**
 * Print historgram
 * 
 * arr  - data array
 * size - size of data
 * start    - starting character for printing labels e.g. '0' or 'a'
 * terminalWidth    - width of terminal
 * 
 */
void histogram(int arr[], int size, int start, int terminalWidth)
{

    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int req = size * 4;
    int batch = 1;
    int perBatch = size;
    int extras = 0;

    //create batches if terminal is smaller than the width of all array elements.
    if (terminalWidth < req)
    {
        batch = req / terminalWidth;
        perBatch = terminalWidth / 4;
        extras = (req % terminalWidth) / 4;
    }

    for (int b = 0; b <= batch; b++)
    {
        int low = b * perBatch;
        int up;

        if (b >= batch)
        {
            if (!extras)
                break;
            up = low + extras;
        }
        else
        {
            up = low + perBatch;
        }

        printf("%d, %d\n", low, up);

        for (int i = low; i < up; i++)
        {
            printf("%-4c", start++);
        }

        printf("\n");

        int s = 0;
        while (++s <= max)
        {
            for (int i = low; i < up; i++)
            {
                printf("%-4c", arr[i] >= s ? '-' : ' ');
            }
            printf("\n");
        }
    }
}

/**
 * Get terminal width from system's APIs
 * 
 * returns  - current terminal width (in columns)
 */
int getTermWidth()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}