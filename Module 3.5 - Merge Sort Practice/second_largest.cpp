// // 1. Merge Sort Complexity:
// // Merge Sort is a divide-and-conquer algorithm that has a time complexity of O(N log N), where N is the number of elements in the array.

// // Dividing the Array: The array is repeatedly divided in half, which takes log N steps.
// // Merging: Each merge step processes all N elements, leading to N log N time overall.
// // 2. Finding the Second-Largest Element:
// // After sorting the array, you traverse it once from the second-to-last element to find the first distinct element smaller than the largest. This takes linear time, O(N).

// // 3. Total Time Complexity:
// // Sorting (Merge Sort): O(N log N)
// // Finding the Second Largest: O(N)
// // Thus, the total time complexity is dominated by the sorting step, which is O(N log N).

// #include <bits/stdc++.h> 

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

// int findSecondLargest(int n, vector<int> &arr)
// {
//     // Write your code here.
//     mergeSort(arr , 0 , n - 1); 
//     int largest = arr[n - 1];
    
//     // Traverse from the second-to-last element to find the second-largest
//     for (int i = n - 2; i >= 0; i--) {
//         if (arr[i] != largest) {
//             return arr[i]; // The first element smaller than the largest
//         }
//     }

//     // If no second-largest element is found (all elements are the same)
//     return -1;

// }