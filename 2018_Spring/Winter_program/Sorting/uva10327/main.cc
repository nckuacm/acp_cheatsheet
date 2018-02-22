#include <cstdio>
#include <cstdlib>

void print(const int *arr,int length){
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void flip_sorting(int *arr,int len){
    int flag=0,flip_count=0;
    while(!flag){
        flag = 1;
        for(int i=0;i<len;i++){
            if(arr[i] > arr[i+1] && (i+1) != len){
                //printf("%d, %d\n",arr[i],arr[i+1]);
                // flip !
                int tmp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = tmp;
                flip_count++;
                flag=0;
                // Can delete this break to make program go faster, by UVA dashboard, the result time improve from 2.140 to 0.060
                // break;
            }
        }
    }
    printf("Minimum exchange operations : %d\n",flip_count);
}

int main(){
    int c,flag=0,arr_size=0,index=0;
    int *dyn_arr,*dyn_arr_ptr;
    while(scanf("%d",&c)!=EOF){
        if(!flag){
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
                // print(dyn_arr,arr_size);
                flip_sorting(dyn_arr,arr_size);
                // print(dyn_arr,arr_size);
                // reset flags
                flag = 0;
                index = 0;
            }
        }
    }
}