class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        int mv = *min_element(nums.begin(), nums.end());
        int ans = 0;
        sort(nums.rbegin(), nums.rend());
        int prev = nums[0];
        int c = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == mv)
            {
                ans += c;
                return ans;
            }
            else if(nums[i] == prev)
            {
               c++;
            }
            else
            {
                ans += c;
                prev = nums[i];
                c++;
            }
        }
        // unordered_map<int, int> mp;
        // for(int i=0; i<n; i++)
        // {
        //     mp[nums[i]]++;
        //     mv = min(mv, nums[i]);
        // }
        // if(mp[mv] == n)
        //     return 0;
        return ans;
        // 1 1 2 4 5 5 5 6 6
    }
};