//O (nLogN) 
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int l =0;
//         int r = nums.size() - 1;
//         int ans = -1; 
//         while(l<=r){
//             int mid = (l + r) / 2;
//             if(target == nums[mid]){
//                 cout<<mid<<" ";
//                 ans = mid; 
//                 break; 
//             }
//             else if(nums[mid] > target ){
//                 r = mid -1; 
//             }
//             else{
//                 l = mid + 1;
//             }
//         }   
//         return ans;
//     }
// };