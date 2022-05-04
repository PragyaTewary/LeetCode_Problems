class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int res = -1;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        int moves[4][2] {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            for(auto move: moves){
                
                int dx = x + move[0];
                int dy = y + move[1];
                
                if(dx <0 || dy <0 || dx >= m || dy >= n){
                    continue;
                }
                
                if(dist[dx][dy] > 1+dist[x][y]){
                    dist[dx][dy] = 1+dist[x][y];
                    q.push({dx,dy});
                    res = max(res, dist[dx][dy]);
                }
            }
        }
        
        return res;
    }
};