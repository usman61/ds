#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {2,7,11,15};
    int target = 26, size = sizeof (arr)/sizeof(int);
    bool flag = false;
    for (int i=0; i<size-1; i++){

        for(int j=i+1; j<size; j++){
            if(arr[i]+arr[j] == target){
                cout<<"["<<i<<","<<j<<"]"<<endl;
                flag = true;
                break;
                
            }

        }
        if(flag)
        break;
    }

    
    return 0;
}