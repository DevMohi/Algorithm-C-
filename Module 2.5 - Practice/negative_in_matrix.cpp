// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();
//         cout<<row<<endl; 
//         cout<<col<<endl;
//         int cnt = 0;
//         for(int i=0;i<row;i++) {
//             for(int j=0;j<col;j++) {
//                 cout<<grid[i][j]<<" ";
//                 if(grid[i][j] < 0) {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };