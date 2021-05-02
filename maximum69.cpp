#include <stdio.h>
#include <math.h>
#include <assert.h>

int ipow(int base, int exp);
int DigitLength(int n);
int DigitDecimalPlace(int n, int dp);

int main(){

    int num = 9999;

    int num_length = DigitLength(num);

    int highest = -1;
    for (int i = 0; i < num_length; i++) // verify and check highest 6
    {
        int ddp = DigitDecimalPlace(num, ipow(10, i));
        assert(ddp == 6 || ddp == 9); // if there is a digit that is not a 6 or a 9, abort.
        if (ddp == 6 && i > highest)
        {
            highest = i;
        }
    }

    int value = 0;
    if (highest >= 0)
    {        
        for (int i = 0; i < num_length; i++)
        {
            if (i == highest) 
            {
                value += ipow(10, i) * 9;
            }
            else
            {
                value += DigitDecimalPlace(num, ipow(10, i)) * ipow(10, i);
            }
        }        
    }
    else 
    {
        value = num;
    }
    printf("%i\n",value);
    return 0;    
}

// Get an int based power
int ipow(int base, int exp){
    if (exp == 0)
    {
        return 1;   // for this case, when the exponent is 0, return a 1.
    }
    else 
    {
        int val = base;
        for(int i = 1; i < exp; i++){
            val *= base;
        }
        return val;
    }
}

// Get the length of an integer
int DigitLength(int n)
{
    int d = 1, r = 1, i = 1; //divisor, result, iterations  
    while(n / d >= 10)
    {
        r = n/d;
        i++;
        d *= 10;
    }
    return i;
}

// Return the digit at the nth decimal place
int DigitDecimalPlace(int n, int dp)
{
    assert(dp > 0);
    return (n / dp) % 10;
}
