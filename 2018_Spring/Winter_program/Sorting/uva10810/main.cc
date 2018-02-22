#include <cstdio>
#include <cstdlib>

long long int swap_count=0;

void merge(int *arr,int head,int mid,int tail){
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    // 2 new arr
    int A[lenA], B[lenB];
    int i,j,k;

    for(i=0;i<lenA;i++)
        A[i] = arr[head+i];
    for(j=0;j<lenB;j++)
        B[j] = arr[mid+1+j];

    // merge
    i=0,j=0,k=head;
    while(i < lenA && j < lenB){
        if(A[i] < B[j]){
            arr[k]=A[i];
            i++;
        }
        else{
            arr[k]=B[j];
            j++;
            swap_count+=lenA-i;
        }
        k++;
    }
    // check the rest
    while(i < lenA){
        arr[k]=A[i];
        i++;
        k++;
    }
    while(j < lenB){
        arr[k]=B[j];
        j++;
        k++;
    }
}

void ultra_msort(int *arr,int head, int tail){
    if(head < tail){
        int mid = (head+tail)/2;
        ultra_msort(arr,head,mid);
        ultra_msort(arr,mid+1,tail);
        merge(arr,head,mid,tail);
    }
}

void print(const int *arr,int length){
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    // read 
    int c,flag=0,arr_size=0,index=0;
    int *dyn_arr;
    while(scanf("%d",&c)){
        if(!flag){
            if(c == 0){
                return 0;
            }
            arr_size = c;
            dyn_arr = (int *)malloc(arr_size*sizeof(int));
            flag = 1;
        }
        else{
            dyn_arr[index] = c;
            index++;
            // when integer array is complete 
            if(index == arr_size){
                // do the flip operation
                ultra_msort(dyn_arr,0,arr_size-1);
                // print(dyn_arr,arr_size);
                printf("%lld\n",swap_count);
                swap_count=0;
                // reset flags
                flag = 0;
                index = 0;
            }
        }
    }
}