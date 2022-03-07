class Solution {
public:
    vector<int> countBits(int n) {
        
        if(n == 0)
        {
            return {0}; 
        }
        vector<int> res(n+1, 0);
        
        res[1] = 1;
        int p2 = 1;
        //int prev =1;
        for(int i=2; i<=n; i++)
        {
            if(i == p2*2)
            {
                p2 = i;
            }
            res[i] = res[i-p2] + 1;
        }
        
        return res;
    }
};