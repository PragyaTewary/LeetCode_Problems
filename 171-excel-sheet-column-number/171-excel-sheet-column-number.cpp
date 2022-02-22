class Solution {
public:
    int titleToNumber(string col) {
        
        //pos[B] + 26*pos[A]
        //pos[Y] + 26*pos[Z]
        
        int n = col.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            //cout
            ans = ans*26 + (col[i] - 'A' + 1);
        }
        return ans;
    }
};