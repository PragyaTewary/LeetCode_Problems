class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = s.length();
        int j=0;
        for(int i=0; j<n && i < t.length(); i++)
        {
            if(s[j] == t[i])
            {
                j++;
            }
        }
        if(j == n)
            return true;
        return false;
    }
};