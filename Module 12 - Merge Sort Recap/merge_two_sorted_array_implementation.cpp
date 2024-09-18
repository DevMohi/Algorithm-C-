#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m,int r)
{
    int leftSize = m-l+1;
    int rightSize = r-m;
    int L[leftSize],R[rightSize];
    int k=0;
    for(int i=l;i<=m;i++)
    {
        L[k]=a[i];
        k++;
    }
    k=0;
    for(int i=m+1;i<=r;i++)
    {
        R[k]=a[i];
        k++;
    }

    //For printing 
    // for(int i=0; i<leftSize; i++){
    //     cout<<L[i]<<" ";
    // }

    int i=0,j=0;
    // int cur=0; // either set it to 0 or set it to l 
    int cur = l; 
    while(i<leftSize && j<rightSize)
    {
        if(L[i] <= R[j])
        {
            a[cur]=L[i];
            i++;
        }
        else 
        {
            a[cur]=R[j];
            j++;
        }
        cur++;
    }
    //This two conditions are used if i and j ends and jodi i<leftSize or r<rightSize aita hoi because one the condition might end and baki value gulo copy kort hoite pare 
    while(i<leftSize)
    {
        a[cur]=L[i];
        i++;
        cur++;
    }

    while(j<rightSize)
    {
        a[cur]=R[j];
        j++;
        cur++;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    merge(a,0,3,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}