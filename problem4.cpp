/**
 * Largest palindrome product
 *
 * A palindromic number reads the same both ways. 
 * The largest palindrome made from the product of 
 * two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of 
 * two 3-digit numbers.
 */
#include <cstdio>
#include <cmath>

bool isPalindrome(long n)
{
    while (n > 9)
    {
        long a = n % 10;
        long b = n / 10;
        int p = 0;
        while (b > 9)
        {
            b /= 10;
            p++;
        }
        if (a == b)
        {
            n /= 10;
            n %= long(pow(10, p));
            if (n == 0)
            {
                return true;
            }
            int digit = int(floor(log10(n))) + 1;
            // printf("%ld\n", n);
            // printf("%d %d\n", digit, p);
            while (digit < p)
            {
                if (n % 10 != 0)
                {
                    return false;
                }
                n /= 10;
                digit++;
            }
            // printf("%ld\n", n);
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long max = 0;
    int l = 0;
    int i1, j1;
    for(int i = 999; i >= 100; i--)
    {
        for(int j = 999; j >= i; j--)
        {
            long p = i * j;
            if(isPalindrome(p))
            {
                if(p > max)
                {
                    max = p;
                    i1 = i;
                    j1 = j;
                    l = int(ceil(sqrt(max)));
                    break;
                }
            }
            if (i < l && j < l)
            {
                break;
            }
        }
    }
    printf("%d * %d = %ld", i1, j1, max);
    return 0;
}
