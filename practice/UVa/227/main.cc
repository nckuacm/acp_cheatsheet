#include <cstdio>

// using 1-dim array
char puzzle[25];

void swap(char *a,char *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main(){
    // count -> index; empty_pos -> record empty position
    int count=0,empty_pos=0,next_pos=0,illegal=0,iterative=1;
    char ch;
    // get the puzzle, and instruction
    while((ch=getchar()) != 'Z'){
        if(count<25){
            // can't just use numbers to do ! <- fix this input
            if(ch != '\n'){
                if(ch == 32){
                    // if get "space", put it into puzzle if it is legal
                    if(count%5!=0 || count==0 || count==5 || count==10 || count== 15 || count == 20){
                        empty_pos=count;
                        //printf("%d, %d\n",iterative,empty_pos);
                        puzzle[count]=ch;
                        count++;
                    }
                }
                else if(ch <= 90 && ch >= 65){
                    // put legal character into 
                    puzzle[count]=ch;
                    count++;
                }
            }
            //printf("%d\n",count);
        }
        else{
            // instruction
            if(ch == 'Z'){
                // end 
                break;
            }
            else{
                // read this instruction 
                switch(ch){
                    case 'A':
                        // square above the empty position moves
                        next_pos=((empty_pos/5)-1)*5+(empty_pos%5);
                        if(next_pos<0){
                            illegal=1;
                            continue;
                        }
                        swap((puzzle+empty_pos),(puzzle+next_pos));
                        // update empty_pos
                        empty_pos=next_pos;
                        break;
                    case 'B':
                        // square below the empty position moves
                        next_pos=((empty_pos/5)+1)*5+(empty_pos%5);
                        if(next_pos>24){
                            illegal=1;
                            continue;
                        }
                        swap((puzzle+empty_pos),(puzzle+next_pos));
                        // update empty_pos
                        empty_pos=next_pos;
                        break;
                    case 'R':
                        // square right the empty position moves
                        next_pos=(empty_pos/5)*5+(empty_pos%5+1);
                        if((empty_pos%5+1)>4){
                            illegal=1;
                            continue;
                        }
                        swap((puzzle+empty_pos),(puzzle+next_pos));
                        // update empty_pos
                        empty_pos=next_pos;
                        break;
                    case 'L':
                        // square right the empty position moves
                        next_pos=(empty_pos/5)*5+(empty_pos%5-1);
                        if((empty_pos%5-1)<0){
                            illegal=1;
                            continue;
                        }
                        swap((puzzle+empty_pos),(puzzle+next_pos));
                        // update empty_pos
                        empty_pos=next_pos;
                        break;
                    case 48:
                        count=0;
                        empty_pos=0;
                        if((iterative-1)) printf("\n");
                        printf("Puzzle #%d:\n",iterative);
                        if(illegal){
                            printf("This puzzle has no final configuration.\n");
                            illegal=0;
                        }
                        else{
                            // print current result
                            for(int i=0;i<25;i+=5){
                                printf("%c %c %c %c %c\n",puzzle[i],puzzle[i+1],puzzle[i+2],puzzle[i+3],puzzle[i+4]);
                            }
                        }
                        // inc iterative
                        iterative++;
                        break;
                    default:
                        // if illegal instruction get in, do illegal
                        if(ch != '\n'){
                            illegal=1;
                            continue;
                        }
                        break;
                }
            }
        }
    }
}