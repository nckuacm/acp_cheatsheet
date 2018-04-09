#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 100005

using namespace std;

typedef struct cow {
    int dist;
    int flower;
    double cost;
} Cow;

bool compare(Cow a, Cow b) {
    return a.cost > b.cost;
}

int main(void) {
    int N;
    long long int totalFlowerPerMin = 0, result = 0;
    Cow list[MAX];

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; ++i) {
            scanf("%d %d", &list[i].dist, &list[i].flower);
            list[i].cost = list[i].flower * 1.0 / list[i].dist;
            totalFlowerPerMin += list[i].flower;
        }

        // Sort all the cows by cost
        sort(list, list + N, compare);

        // Calculate the total cost of flowers
        for (int i = 0; i < N; ++i) {
            totalFlowerPerMin -= list[i].flower;
            result += (totalFlowerPerMin * list[i].dist * 2);
        }

        // Print the result
        printf("%lld\n", result);
    }

    return 0;
}