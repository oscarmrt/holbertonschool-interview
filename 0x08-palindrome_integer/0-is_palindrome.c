#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long reverse = 0;
    unsigned long remainder;
    unsigned long cp = n;

    while (n != 0)
    {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }
    if (cp == reverse)
        return (1);
    else
        return 0;
}
