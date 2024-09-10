// class Solution {
// public:
//     void merge(vector<int> & nums, int l , int r , int mid){
//         int leftSize = mid - l + 1;
//         int rightSize = r - mid;

//         int L[leftSize + 1];
//         int R[rightSize + 1];

//         for(int i=l, j = 0 ; i<=mid; i++,j++){
//             L[j] = nums[i];
//         }
//         for(int i = mid + 1, j = 0; i<=r; i++,j++){
//             R[j] = nums[i];
//         }
//         L[leftSize] = INT_MAX;
//         R[rightSize] = INT_MAX;

//         int lp =0; 
//         int rp=0; 
//         for(int i = l; i<=r; i++){
//             if(L[lp] < R[rp]){
//                 nums[i] = L[lp];
//                 lp++;
//             }
//             else{
//                 nums[i] = R[rp];
//                 rp++; 
//             }
//         }
//     }

//     void mergeSort(vector<int> & nums, int l , int r){
//         if(l == r) return;
//         int mid = (l + r) / 2 ; 
//         mergeSort(nums, l , mid);
//         mergeSort(nums , mid + 1 , r);
//         merge(nums, l , r, mid);
//     }

//     vector<int> sortArray(vector<int>& nums) {
//         mergeSort(nums, 0 , nums.size() - 1);
//         return nums; 
//     }
// };