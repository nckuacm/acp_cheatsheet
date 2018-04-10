#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 50005

using namespace std;

typedef struct votes {
    int vote1;
    int vote2;
    int index;
} Votes;

bool compareVote1(Votes a, Votes b) {
    return a.vote1 > b.vote1;
}

bool compareVote2(Votes a, Votes b) {
    return a.vote2 > b.vote2;
}

int main(void) {
    int N, K;
    Votes list[MAX];

    while(scanf("%d %d", &N, &K) != EOF) {
        for (int i = 0; i < N; ++i) {
            scanf("%d %d", &list[i].vote1, &list[i].vote2);
            list[i].index = i + 1;
        }
        
        // Sort all candidates
        sort(list, list + N, compareVote1);

        // Sort K highest candiadtes in the first round
        sort(list, list + K, compareVote2);

        // Print the result
        printf("%d\n", list[0].index);
    }

    return 0;
}