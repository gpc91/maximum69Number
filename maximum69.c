#include <math.h>
#include <assert.h>

int maximum69Number (int num){
    assert(num >= 6);
    int h = -1;
    for (int i = 0; i <= log10(num); i++)
    {
        int d = num / ((int)pow(10, i)) % 10;
        assert(d == 6 || d == 9);
        if (d == 6 && i > h)
        {
            h = i;
        }
    }
    
    int v = 0;
    if (h >= 0)
    {
        for (int i = 0; i <= log10(num); i++)
        {
            if (i == h)
            {
                v += (int)pow(10,i) * 9;
            }
            else
            {
                v += (int)(num / (int)pow(10,i)) % 10 * (int)pow(10, i);
            }
        }
    }
    else 
    {
        v = num;
    }
    return v;
}
