class Solution {
public:
    long long smallestNumber(long long num) 
    {
        long long ans = 0;
        bool neg = false;
        if(num == 0)
            return 0;
        if(num < 0)
        {
            neg = true;
        }
        string s = ""; 
        if(neg)
        {
            num *= -1;
        }
        s = to_string(num);
        
        sort(s.begin(), s.end());
        
        int l = 0;
        if(!neg)
        {
            while(s[l] == '0')
                l++;
            s = s[l] + string(l, '0') + s.substr(l+1, s.length()-l-1);
            
            return (stoll)(s);
        }
        reverse(s.begin(), s.end());
        ans = (stoll)(s);
        ans *= -1;
        return ans;
    }
};