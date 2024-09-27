//Also known as divide and conquer 

#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l,int m , int r){
    int leftSize = m - l + 1;
    int rightSize = r-m;

    int L[leftSize],R[rightSize];

    int k = 0;
    for(int i=l; i<=m; i++){
        L[k] = a[i];
        k++;
    }
    k = 0;
    for(int i= m + 1; i<=r; i++){
        R[k] = a[i];
        k++;
    }

    //Take two pointers S FINAL
    int i =0, j =0;
    int cur = l; 

    //Dunota valid index thaka lagbe to compare
    while(i<leftSize && j<rightSize){
        if(L[i] <= R[j]){
            a[cur] = L[i];
            i++;
        }
        else{
            a[cur] = R[j];
            j++;
        }
        cur++; 
    }

    while(i<leftSize){
        a[cur] = L[i];
        i++;
        cur++;
    }
    while(r<rightSize){
        a[cur] = R[j];
        j++;
        cur++; 
    }
}

void mergeSort(int a[], int l, int r){
    int mid = (l+r)/2;
    if(l<r){
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        // cout<<"This";
        // cout<<endl;
        // for(int i=l; i<=mid; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl; 
        // for(int i=mid+1; i<=r; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl; 
        merge(a,l,mid,r);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    mergeSort(a,0, n-1);
    for(int i=0; i<n; i++){ 
        cout<<a[i]<<" ";
    }
    return 0;
}

// 10 
// 15 4 3 9 2 8 10 12 6 1   LAST BREAK  2 i swear