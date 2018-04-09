#include <cstdio>
#include <iostream>
#include <queue>

#define MAX 30

using namespace std;

bool map[MAX][MAX], isVisited[MAX];
int N;

void DFS(int m) {
    // Let the all the repeater which can be set into same channel into queue
    int queue[MAX];
    int tail = 1;

    // Let the current repeater into the queue
    queue[tail] = m;
    for (int i = m + 1; i <= N; ++i) {
        // Find the possible channels which is not near by the repeater
        if (!isVisited[i] && !map[m][i]) {
            bool isAdd = 1;

            for (int j = 1; j <= tail; ++j) {
                if (map[i][queue[j]]) {
                    isAdd = false;
                    break;
                }
            }

            if (isAdd) {
                queue[++tail] = i;
                isVisited[i] = 1;
            }
        }
    }
}

int main(void) {
    while(scanf("%d", &N) != EOF && N != 0) {
        // Initialize the array to store all the repeater
        memset(map, false, sizeof(map));
        memset(isVisited, false, sizeof(isVisited));

        for (int i = 1; i <= N; ++i) {
            char str[MAX];
            scanf("%s", str);

            // Store the map as the index 0 become 'A'
            for (int j = 2; str[j] != 0; ++j)
                map[i][str[j] - 'A' + 1] = 1;
        }

        int result = 0;
        for (int i = 1; i <= N; ++i) {
            if (!isVisited[i]) {
                isVisited[i] = 1;
                DFS(i);
                ++result;
            }
        }

        if (result == 1)
            printf("%d channel needed.\n", result);
        else
            printf("%d channels needed.\n", result);
    }

    return 0;
}