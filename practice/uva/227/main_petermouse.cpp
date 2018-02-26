#include <cstdio>
#include <cstdlib>

void swap(char *a,char *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main()
{
    char puzzle[25];
    char ch;
    int empty_pos = 0;
    int count;
    bool illegal = false;
    int testcase = 0;
    while((ch = getchar()) != 'Z') {
        if (ch == '\n')
            continue;
        count = 0;
        empty_pos = 0;
        testcase++;
        do {
            if (ch == '\n')
                continue;
            puzzle[count] = ch;
            if (ch == ' ')
                empty_pos = count;
            count++;
        } while(count < 25 && (ch = getchar()));
        illegal = false;
        while((ch = getchar()) != '0') {
            if (ch == '\n')
                continue;
            if (!illegal) {
                switch (ch) {
                    case 'A':
                        if (empty_pos - 5 < 0) {
                            illegal = true;
                        } else {
                            swap(puzzle + empty_pos - 5, puzzle + empty_pos);
                            empty_pos -= 5;
                        }
                        break;
                    case 'B':
                        if (empty_pos + 5 >= 25) {
                            illegal = true;
                        } else {
                            swap(puzzle + empty_pos + 5, puzzle + empty_pos);
                            empty_pos += 5;
                        }
                        break;
                    case 'R':
                        if ((empty_pos % 5) == 4) {
                            illegal = true;
                        } else {
                            swap(puzzle + empty_pos + 1, puzzle + empty_pos);
                            empty_pos += 1;
                        }
                        break;
                    case 'L':
                        if ((empty_pos % 5) == 0) {
                            illegal = true;
                        } else {
                            swap(puzzle + empty_pos - 1, puzzle + empty_pos);
                            empty_pos -= 1;
                        }
                        break;
                }
            }
        }

        if (testcase > 1) {
            printf("\n");
        }
        printf("Puzzle #%d:\n", testcase);
        if (illegal) {
            printf("This puzzle has no final configuration.\n");
        } else {
            for (int i = 0; i < 25; i++) {
                if (i % 5 == 0) {
                    printf("%c", puzzle[i]);
                } else {
                    printf(" %c", puzzle[i]);
                    if (i % 5 == 4) {
                        printf("\n");
                    }
                }
            }
        }
    }
    return 0;
}