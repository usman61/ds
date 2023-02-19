#include<stdio.h>
int second_max(int arr[],int length){
    int max,sec_max;
    max = *arr;
    sec_max = *(arr+1);
    for(int i=0; i<length;i++){
      if(*(arr+i)>max){
        sec_max = max;
        max = *(arr+i);
      }
      else if (*(arr+i)>sec_max && *(arr+i)<max){
        sec_max = *(arr+i);
      }
    
    }
    return sec_max;


}
int main(int argc, char const *argv[])
{
    int arr[] = {15,2,3,4,5,6,7,8,15,15};
    int s_max,length;
    length = sizeof(arr)/sizeof(int);
    s_max = second_max(arr,length);    
    printf("Second Max %d\n",s_max);
    return 0;
}