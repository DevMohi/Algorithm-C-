// class Solution {
// public:
//     int maximumCount(vector<int>& nums) {
//         int l = 0; 
//         int h = nums.size() - 1;
        
//         // Binary search to find the end of the negative numbers
//         while (l <= h) {
//             int mid = (l + h) / 2;
//             if (nums[mid] < 0) {
//                 l = mid + 1;  // move right because mid is negative, and we want the end of negative numbers
//             } else {
//                 h = mid - 1;  // move left because mid is non-negative
//             }
//         }

//         // After binary search, `h` will point to the last negative number
//         // `l` will point to the first non-negative number (which could be 0 or a positive number)

//         // Skip over all zeros to count only positive numbers
//         while (l < nums.size() && nums[l] == 0) {
//             l++;  // move `l` to the first positive number
//         }

//         // Now, `l` points to the first positive number, or it's beyond the array if there are no positives
//         int pos = nums.size() - l;  // Count of positive numbers is the remaining elements from index `l`
//         int neg = h + 1;  // Count of negative numbers is everything up to index `h`

//         // Return the maximum between the count of positive and negative numbers
//         return max(pos, neg);
//     }
// };