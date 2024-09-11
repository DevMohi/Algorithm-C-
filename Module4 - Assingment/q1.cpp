//Total time complexity - O(nlogN)
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N];

void merge(int l, int r, int mid){
    int leftSize = mid - l + 1;
    int L[leftSize + 1];

    int rightSize = r - mid;
    int R[rightSize + 1];

    for(int i=l , j = 0; i<=mid; i++, j++){
        L[j] = arr[i];
    }
    for(int i = mid + 1 , j = 0 ; i<=r; i++, j++){
        R[j] = arr[i];
    }

    L[leftSize] = INT_MIN;
    R[rightSize] = INT_MIN;

    int lp =0, rp = 0;
    for(int i=l ; i<=r; i++){
        if(L[lp] >= R[rp]){
            arr[i] = L[lp];
            lp++;
        }
        else{
            arr[i] = R[rp];
            rp++; 
        }
    }
}

void mergeSort(int l, int r){
    if(l == r) return;
    int mid = (l+r)/2;
    mergeSort(l , mid);
    mergeSort(mid+ 1,r);
    merge(l,r,mid);
}

int main(){
    int n;
    cin>>n; 

    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }

    mergeSort(0, n-1);

    for(int i=0 ;i<n; i++){
        cout<<arr[i]<<" ";
    }

    
    return 0;
}