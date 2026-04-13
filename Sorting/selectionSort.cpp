#include<iostream>
using namespace std;

int main(){
    int arr[8]={23, 45, 65, 78, 23, 65, 43, 78};
    int n = 8;

    for(int i=0 ; i< n-1 ; i++){
        int min_idx = i;

        for (int j=i+1; j<n ; j++){
            if(arr[j] < arr[min_idx]){  
                min_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    cout<<"Sorted Array: ";
    for(int i=0 ; i< n ; i++ ){
        cout<< arr[i] << " ";
    }

    return 0;
}