class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        
        int left[n];
        int right[n];
        
        if(s[0] == '0')
        {
            left[0] = 0;
        }
        else
        {
            left[0] = 1;
        }
        for(int i=1; i<n; i++)
        {
            if(s[i] == '1')
                left[i] = min(left[i-1]+2, i+1);
            else
                left[i] = left[i-1];
        }
        
        if(s[n-1] == '0')
        {
            right[n-1] = 0;
        }
        else
        {
            right[n-1] = 1;
        }
        for(int i=n-2; i>=0; i--)
        {
            if(s[i] == '1')
                right[i] = min(right[i+1]+2, n-i);
            else
                right[i] = right[i+1];
        }
        
        int ans =  right[0];
        for(int i=0; i<n-1; i++)
        {
            ans = min(ans, left[i]+right[i+1]);
        }
        ans = min(ans, left[n-1]);
        return ans;
    }
};