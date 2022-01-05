// Amazing article to check out: https://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html
// simple video to preface article: https://www.youtube.com/watch?v=PZRI1IfStY0

// a double is the same as a float, but has twice as many bits to store data in
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() 
{
    float test = 41.75f; 
    char result[sizeof(float)];

    // all of the binary stored as chars
    memcpy(result, &test, sizeof(test));

    char c;
    unsigned int i;
    for (int n = 0; n < sizeof(float); n++) {
        c = result[n];
        i = (unsigned int)c;
        printf("%u\n", i);
    }

    // this will print out 0 0 39 66
    // 00000000 00000000 00100111 01000010
    // this is the binary representation of 41.75 as a float
    // signed bit is 0
    // exponent is -127
    // mantissa is 0000000 00100111 01000010 = 1/1024 * 
    // (-1)^0 * (2^-127) * 
    // I'm gonna be honest, this makes zero sense and I'm gonna stop coding this bullshit rn lol
    // I did what I needed in order to understand floating point a bit better and I'm not gonna deal with
    // figuring out how this cancerous blob of 1s and 0s is equal to 41.75. GG floating point, hope to never think about
    // you again XD

    return 0;  
}