class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int c = 0;
        for(int i=n-1; i>=1; i--)
        {
            if(nums[i] != nums[i-1])
            {
                ans += n-i;
            }
        }
        return ans;
    }
};