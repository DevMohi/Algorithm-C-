#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N];


int findLeft(int arr[] , int n , int x){
    int l = 0;
    int r = n - 1;
    int ans  = -1;

    while(l <= r){
        int mid = (l + r)/2;
        if(arr[mid] == x){
            ans = mid;
            r = mid - 1; //Traverse through left to find occurence. 
        }
        else if(arr[mid] > x){
            r = mid -1;
        } 
        else{
            l  = mid + 1;
        }
    }

    return ans; 
}

int findRight(int arr[] , int n , int x){
    int l = 0;
    int r = n - 1;
    int ans  = -1;

    while(l <= r){
        int mid = (l + r)/2;
        if(arr[mid] == x){
            ans = mid;
            l = mid + 1; //Traverse through right to find occurence. 
        }
        else if(arr[mid] > x){
            r = mid -1;
        } 
        else{
            l  = mid + 1;
        }
    }
    return ans; 
}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int x;
    cin>>x;

    if(findLeft(arr,n,x) != findRight(arr,n,x)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}