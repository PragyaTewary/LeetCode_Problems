class Solution {
public:
    int floormod(int x, int n)
    {
        return (x%n + n)%n;
    }
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> mat(n, vector<int>(n, -1));
        
        int moves[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int d = 0;
        int count = 1;
        int row = 0;
        int col = 0;
        while(count <= n*n){
            
            mat[row][col] = count++;
            
            int r = floormod(row + moves[d][0], n);
            int c = floormod(col + moves[d][1], n);
            
            if(mat[r][c] != -1)
            {
                d = (d+1)%4;
            }
            
            row = row + moves[d][0];
            col = col + moves[d][1];
            
        }
        
        return mat;
    }
};