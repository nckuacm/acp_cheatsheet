#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 10005

using namespace std;

int main(void) {
    int N, milk[MAX];

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; ++i)
            scanf("%d", &milk[i]);
        
        // Sort all the cow by milk
        sort(milk, milk + N);

        // Print the result without considering when the number of cow is even.
        printf("%d\n", milk[N / 2]);
    }

    return 0;
}