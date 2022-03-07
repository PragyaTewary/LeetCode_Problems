class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3)
            return 0;
        int ans = 0;
        int prev = 0;
        for(int i=2; i<n; i++)
        {
            int curr = 0;
            if(nums[i]-nums[i-1] == nums[i-1] - nums[i-2])
            {
                curr = prev + 1;
            }
            ans += curr;
            prev = curr;
        }
        
        return ans;
    }
};