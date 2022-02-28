class Solution {
public:
    int minSteps(string s, string t) {

        int* arr = new int[26];
        int n = s.length();
        for(int i=0; i<26; i++)
        {
            arr[i] = 0;
        }
        for(int i=0; i<n; i++)
        {
            arr[s[i]-'a']++;
        }
        
        int ans = 0;
        int m = t.length();
        
        for(int i=0; i<m; i++)
        {
            arr[t[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            ans += abs(arr[i]);
        }
        
        return ans;
    }
};