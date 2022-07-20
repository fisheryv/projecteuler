/** 
 * Largest prime factor
 * 
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143?
 */
#include <cstdio>
#include <cmath>

bool isPrime(long long n)
{
    for (int i = 2; i <= ceil(sqrt(n)); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long n = 600851475143;
    long factor = 2;
    for (int i = 2; i <= ceil(sqrt(n)); i++)
    {
        if (n % i == 0)
        {
            if (isPrime(n/i))
            {
                printf("%lld", n/i);
                return 0;
            }
            if (isPrime(i))
            {
                factor = i;
            }
        }
    }
    printf("%ld", factor);
    return 0;
}