class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            int gcd = __gcd(nums[i], k);
            
            for(auto v :  mp)
            {
                if((1L * v.first)*gcd % k == 0)
                {
                    ans += v.second;
                }
            }
            
            mp[gcd]++;
        }
        
        return ans;
    }
};