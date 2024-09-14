#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 +7;

vector<int> arr(N);
vector<int> arr2(N);

void merge(vector<int> &arr, int m, vector<int> &arr2 , int n, vector<int> &result){
    int i =0;
    int j =0;
    int k =0;
    
    while(i<n && j<m){
        if(arr[i] > arr2[j]){
            result[k] = arr[i];
            k++;
            i++;
        }
        else{
            result[k] = arr2[j];
            k++;
            j++;
        }
    }
    //After the loop ends after sorted , this two condition will copy the rest 
    while(i<n){
        result[k] = arr[i];
        k++;
        i++;
    }

    while(j<m){
        result[k] = arr2[j];
        k++;
        j++;
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    int m;
    cin>>m;

    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }

    vector<int> result(n+m); 

    merge(arr,n,arr2,m, result);

    for(int i=0;i<n + m;i++){
        cout<<result[i]<<" ";
    }
    


    return 0;
}