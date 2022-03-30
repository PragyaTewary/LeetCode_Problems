class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        
        int m = mat.size();
        int n = mat[0].size();
        int l = 0;
        int h = m*n - 1;
        
        while(l <= h){
            
            int mid = l + (h-l)/2;
            int r = mid/n;
            int c = mid - (r*n);
            if(mat[r][c] == t){
                return true;
            }
            else if(mat[r][c] < t){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return false; 
    }
    // 0 - 11
    // 5 -- 5/c, 5%r
    
    // 1 3 5 7 
    //     m = 1
    //     n = 4
    //     r = 0
    //     c = mid+m%n 
};