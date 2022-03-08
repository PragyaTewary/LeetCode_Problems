class Solution {
public:
    vector<string> cellsInRange(string s) {
        
        vector<string> res;
        
        string t = "";
        for(char ch = s[0]; ch<=s[3]; ch++)
        {
            t += ch;
            for(char i = s[1]; i<=s[4]; i++)
            {
                t += i;
                res.push_back(t);
                t.pop_back();
            }
            t.pop_back();
        }
        return res;
    }
};