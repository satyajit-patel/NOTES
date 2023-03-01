#include<bits/stdc++.h>
using namespace std;

void merge(int i, int mid , int j, int arr[]){
    int N1 = mid - i + 1;
    int N2 = j - mid;
    int A1[N1] , A2[N2];
    for(int k = 0 ; k < N1 ; k++){
        A1[k] = arr[k + i];

    }


    for(int k = 0 ; k < N2 ; k++){
        A2[k] = arr[k + mid + 1];
    }


    int x = 0 , y = 0;
    int z = i;
    while(x < N1 and y < N2){
        if(A1[x] <= A2[y]){
            arr[z++] = A1[x++];
        }else{
            arr[z++] = A2[y++];
        }
    }
    while(x < N1){
        arr[z++] = A1[x++];
    }
    while(y < N2){
        arr[z++] = A2[y++];
    }



    return;
}

void divide(int i, int j, int arr[]){
    
    if(i >= j){
        return;
    }
    int mid = (i + j) >> 1;
    divide(i , mid, arr);
    divide(mid + 1 , j , arr);
    merge(i , mid , j, arr);
}

int main(){
    int N = 8;
    int arr[] = {8,7,6,5,4,3,2,1};
    divide(0 , 7 , arr);
    cout<<"\nsorted\n";
    for(int i = 0 ; i < N ; i++) cout << arr[i] << " ";
    return 0;
}
 
