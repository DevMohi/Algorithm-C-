#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N];

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int x;
    cin>>x;

    bool flag = false;
    int l = 0;
    int r = n - 1;
    int fidx = 0;

    while(l <= r){
        int mid = (l + r)/2;
        if(arr[mid] == x){
            flag = true;
            fidx = mid;
            break;
        }
        else if(arr[mid] > x){
            r = mid -1;
        } 
        else{
            l  = mid + 1;
        }
    }

    if(!flag){
        cout<<"Not found";
    }
    else{
        cout<<fidx<<" ";
    }
    
    return 0;
}