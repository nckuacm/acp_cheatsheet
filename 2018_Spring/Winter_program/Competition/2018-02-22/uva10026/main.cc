#include <cstdio>
#include <algorithm>

struct JOB{
    double panelty;
    int order;
};

bool compare(JOB a, JOB b){
    return a.panelty > b.panelty;
}

int main(){
    int total;
    // Get total case
    scanf("%d",&total);
    
    // pop out each case
    while(total--){
        // get Jobs numbers
        int N;
        scanf("%d",&N);
        // allocated
        int *time_arr = (int *)malloc(N*sizeof(int));
        int *fine_arr = (int *)malloc(N*sizeof(int));
        JOB *job_q = (JOB *)malloc(N*sizeof(JOB));
        // Get N pairs
        for(int i=0;i<N;i++){
            scanf("%d %d",&time_arr[i],&fine_arr[i]);
            // add to job queue
            job_q[i].panelty = fine_arr[i]*1.0 / time_arr[i];
            job_q[i].order = i+1;
        }
        std::sort(job_q,job_q+N,compare);

        printf("%d",job_q[0].order);
        for(int i=1;i<N;i++)
            printf(" %d",job_q[i].order);
        printf("\n");
        
        // skip the last one
        if(total)
            printf("\n");
    }
    return 0;
}