#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 20005

using namespace std;

int main(void) {
    int N, S, cow[MAX];

    while (scanf("%d %d", &N, &S) != EOF) {
        for (int i = 0; i < N; ++i)
            scanf("%d", &cow[i]);

        // Sort the cow in length
        sort(cow, cow + N);

        int tmp = N, result = 0;
        for (int i = 0; i < tmp; ++i) {
            for (int j = i + 1; j < tmp; ++j) {
                if (cow[i] + cow[j] <= S)
                    ++result;
                else {
                    tmp = j;
                    break;
                }
            }
        }

        // Print the result
        printf("%d\n", result);
    }

    return 0;
}