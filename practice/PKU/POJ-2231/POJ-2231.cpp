#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 10005

using namespace std;

int main(void) {
    long long int cow[MAX], moo[MAX], result = 0;
    int N;

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; ++i)
            scanf("%lld", &cow[i]);

        // Sort all the cow by position
        sort(cow, cow + N);
        
        // Initialize the first cow's moo
        for (int i = 1; i < N; ++i)
            moo[0] += (cow[i] - cow[0]);
        
        // Calculate the cows' moo without the first one
        result = moo[0];
        for (int i = 1; i < N; ++i) {
            moo[i] = moo[i - 1] - (N - i - 1) * (cow[i] - cow[i - 1]) + (i - 1) * (cow[i] - cow[i - 1]);
            result += (moo[i]);
        }

        // Print the result
        printf("%lld\n", result);
    }

    return 0;
}