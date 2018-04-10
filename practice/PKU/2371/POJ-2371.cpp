#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 100005

using namespace std;

int main(void) {
    int N, K, index, list[MAX];
    
    while (cin >> N) {
        for (int i = 0; i < N; ++i)
            cin >> list[i];

        // Sort the number of database
        sort(list, list + N);

        // Read the separated symbols
        char separate[10];
        cin >> separate;

        // Query the number of database and print the result
        scanf("%d", &K);
        while (K--) {
            scanf("%d", &index);
            printf("%d\n", list[index - 1]);
        }
    }

    return 0;
}