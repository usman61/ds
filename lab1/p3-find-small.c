#include <stdio.h>

int is_exist(int elem,int *p,int size){
    for (int i=0; i<size; i++){
        if (elem == *p)
        return 1;
        *p++;
    }

    return 0;

}

int find_small_val(int arr[],int size){
    int i =1;
    while(1){

        if (!is_exist(i,arr,size)){
            return i;
        }
        i++;

    }
}
int main(){


  int arr[] = {-1,5,4,3,1};

  int size=sizeof(arr)/sizeof(int);
  
  int small = find_small_val(arr,size);
 printf("The smallest +ve int %d",small);
  return 0;
}