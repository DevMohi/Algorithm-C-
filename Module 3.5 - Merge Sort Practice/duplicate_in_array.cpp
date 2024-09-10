// #include <bits/stdc++.h>


// void merge(vector<int> &arr, int l, int r, int mid){
// 	int leftSize = mid - l + 1;
// 	int rightSize = r - mid;

// 	int L[leftSize + 1];
// 	int R[rightSize + 1];

// 	for(int i=l,j=0; i<=mid; i++,j++){
// 		L[j] = arr[i];
		
// 	}
// 	for(int i = mid + 1 , j = 0; i<=r; i++,j++){
// 		R[j] = arr[i];
		
// 	}
// 	L[leftSize] = INT_MAX;
// 	R[rightSize] = INT_MAX;


// 	int lp=0, rp =0;
// 	for(int i=l; i<=r; i++){
// 		if(L[lp] <= R[rp]){
// 			arr[i] = L[lp];
// 			lp++;
// 		}
// 		else{
// 			arr[i] = R[rp];
// 			rp++;
// 		}
// 	}
// }

// void mergeSort(vector<int> & arr, int l , int r){
// 	if(l == r) return; 
// 	int mid = (l+r)/2;
// 	mergeSort(arr,l,mid);
// 	mergeSort(arr,mid+1,r);

// 	merge(arr, l, r, mid);
// }

// int findDuplicate(vector<int> &arr, int n){
// 	// Write your code here.

// 	//complexity of mergeSort is O(nlogN)
// 	mergeSort(arr, 0 , n-1);

// 	//Complexity for this is O(N)
// 	for (int i = 1; i < n; i++) {
//         if (arr[i] == arr[i - 1]) {
//             return arr[i]; // Return the duplicate element
//         }
//     }

// 	//DUe to dominance the time complexity for this O(nlogN)


// 	return 10; 
// }
