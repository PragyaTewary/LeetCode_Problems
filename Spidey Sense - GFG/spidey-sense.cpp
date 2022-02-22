// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int m, int n) 
    { 
        vector<vector<int>> res(m,  vector<int>(n, -2));
        //unordered_set<pair<int, int>> bomb;
        queue<vector<int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 'W')
                    res[i][j] = -1;
                if(matrix[i][j] == 'B')
                {
                    res[i][j] = 0;
                    q.push({i,j, 0});
                }
            }
        }
        vector<vector<int>> moves{{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            int x = curr[0];
            int y = curr[1];
            for(int k=0; k<4; k++)
            {
                int dx = x + moves[k][0];
                int dy = y + moves[k][1];
                
                //cout<<dx<<"; "<<dy;
                if(dx >= m || dx < 0 || dy >= n || dy < 0 || res[dx][dy] != -2)
                {
                    continue;
                }
                
                res[dx][dy] = curr[2] + 1;
                q.push({dx, dy, res[dx][dy]});
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(res[i][j] == -2)
                {
                    res[i][j] = -1;
                }
            }
        }
        return res;
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends