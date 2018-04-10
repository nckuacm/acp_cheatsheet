#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 500005

using namespace std;

typedef struct city {
    int east;
    int west;
} City;

long long int cross = 0;

// For merge sort and need to declare in global, otherwise may TLE
int buff[MAX];

bool compare(City a, City b) {
    if (a.east == b.east)
        return a.west < b.west;
    return a.east < b.east;
}

void merge(City list[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = -1;

    while (i <= mid || j <= high) {
        if (i > mid)
            buff[++k] = list[j++].west;
        else if (j > high)
            buff[++k] = list[i++].west;
        else if (list[j].west < list[i].west) {
            buff[++k] = list[j++].west;
            cross += (mid - i + 1);
        }
        else 
            buff[++k] = list[i++].west;
    }

    k = 0;
    for (i = low; i <= high; ++i)
        list[i].west = buff[k++];
}

void mergeSort(City list[], int low, int high) {
    int mid = (low + high) / 2;

    if (low < high) {
        mergeSort(list, low, mid);
        mergeSort(list, mid + 1, high);
        merge(list, low, mid, high);
    }
}

int main(void) {
    int T, N, M, K;
    City list[MAX];

    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        cross = 0;
        scanf("%d %d %d", &N, &M, &K);
        for (int i = 0; i < K; ++i)
            scanf("%d %d", &list[i].east, &list[i].west);

        // Sort the east city in order
        sort(list, list + K, compare);

        // Use merge sort to count the number of cross
        mergeSort(list, 0, K - 1);

        // Print the result
        printf("Test case %d: %lld\n", t + 1, cross);
    }

    return 0;
}