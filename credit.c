#include <cs50.h>
#include <stdio.h>

bool check_sum(long long n);
int find_len(long long n);
int main(void)
{
    long ccn;
    do
    {
        ccn = get_long("Number: ");
    }
    while (ccn < 0);

    int len = find_len(ccn);
    if ((len == 13 || len == 15 || len == 16) && check_sum(ccn) == true)
    {
        if ((ccn > 34e13 && ccn < 35e13) || (ccn > 37e13 && ccn < 38e13))

            printf ("AMEX\n");

        else if (ccn > 51e14 && ccn < 56e14)
        {
            printf ("MASTERCARD\n");
        }
        else if (ccn > 4e12 && ccn < 5e12)
        {
            printf ("VISA\n");
        }
        else if (ccn > 4e15 && ccn < 5e15)

            printf ("VISA\n");
        else
            printf ("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

int find_len(long long n)
{
    int len;
    for (len = 0; n != 0; n = n / 10)
    {
        len ++;
    }
    return len;
}

bool check_sum(long long ccn)
{
    int sum = 0;
    for (int i = 0; ccn != 0; ccn = ccn / 10, i++)
    {
        if (i % 2 == 0)
        {
            sum = sum + ccn % 10;
        }
        else
        {
            int digit = 2 * (ccn % 10);
            sum = sum + digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 0;
}
