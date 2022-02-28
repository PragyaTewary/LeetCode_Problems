class Solution {
public:
    bool check(string pre, string s)
    {
        for(int i=0; i<pre.length(); i++)
        {
            if(s[i] != pre[i])
            {
                return false;
            }
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        
        int c = 0;
        
        for(int i=0; i<words.size(); i++)
        {
            if(check(pref, words[i]))
            {
                c++;
            }
        }
        return c;
    }
};