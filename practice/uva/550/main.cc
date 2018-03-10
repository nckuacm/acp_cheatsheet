#include <cstdio>

int carry=0,len=0,x;

int main()
{
    int base, digit, sec;
    while (scanf("%d%d%d", &base, &digit, &sec) != EOF){
        carry = 0, len = 0, x = digit;
        while (1){
            int tmp = x * sec + carry;
            carry = tmp / base;
            x = tmp % base;
            len++;
            if (carry == 0 && x == digit) break;
        }
        printf("%d\n", len);
    }
    return 0;
}