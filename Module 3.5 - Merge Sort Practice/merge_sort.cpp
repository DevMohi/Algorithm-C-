// #include <vector>
// #include <limits.h> // for INT_MAX

// void merge(vector<int> & arr, int l, int r, int mid){
//     int leftSize = mid - l + 1;
//     int L[leftSize + 1];

//     int rightSize = r - mid;
//     int R[rightSize + 1];

//     for(int i=l, j=0; i<=mid; i++, j++){
//         L[j] = arr[i];
//     }
//     for(int i = mid + 1 , j=0; i<=r; i++, j++){
//         R[j] = arr[i];
//     }

//     L[leftSize] = INT_MAX;
//     R[rightSize] = INT_MAX;


//     int lp =0, rp =0;
//     for (int i = l; i <= r; i++) {
//         if(L[lp] <= R[rp]){
//             arr[i] = L[lp];
//             lp++;
//         }
//         else{
//             arr[i] = R[rp];
//             rp++; 
//         }
//     }
// }

// void mergeSort(vector<int> & arr, int l, int r){
//     if(l == r) return;
//     int mid = (l+r)/2;
//     mergeSort(arr , l, mid );
//     mergeSort(arr, mid+1,r);
//     merge(arr, l,r,mid);

// }

// void mergeSort(vector < int > & arr, int n) {
//     // Write your code here.
//     //Array given and n 

//     mergeSort(arr , 0 , n - 1); 
    
// }