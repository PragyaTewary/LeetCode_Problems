class Solution {
public:
    
    int prefixCount(vector<string>& words, string pref) {
        
        int c = 0;
        
        for(int i=0; i<words.size(); i++)
        {
            c += words[i].find(pref) == 0;
        }
        return c;
    }
};