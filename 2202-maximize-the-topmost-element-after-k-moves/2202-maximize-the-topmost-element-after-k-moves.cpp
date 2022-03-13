class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        if(k==0)
        {
            return nums[0];
        }
        
        int n = nums.size();

        if(n == 1)
        {
            if(k%2 == 0)
            {
                return nums[0];
            }
            return -1;
        }
        int ans = -1;
        int i;
        for(i=0; i<n; i++)
        {
            if(k == 1)
            {
                break;
            }
            ans = max(ans, nums[i]);
            k--;
        }
        int val = (i+1<n) ? nums[i+1] : -1;
        return max(ans, val);
    }
};