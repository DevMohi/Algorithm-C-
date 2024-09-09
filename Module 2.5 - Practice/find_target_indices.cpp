// class Solution {
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
            //Complexity O(n*2)
//         vector<int> p;
//         //Swapping done 
//         for(int i=0 ;i<nums.size() - 1; i++){
//             for(int j = i+1; j<nums.size(); j++){
//                 if(nums[i] > nums [j]){
//                     swap(nums[i] , nums[j]);
//                 }
//             }
//         }

//         for(int i=0 ;i<nums.size(); i++){
//             if(target == nums[i]){
//                 p.push_back(i);
//             }
//         }
        
//         return p; 
//     }
// };