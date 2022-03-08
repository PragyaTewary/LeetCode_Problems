class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        long long sum = k*1L*(k+1)/2;
        
        set<int> st(nums.begin(), nums.end());
        
        for(auto v : st)
        {
            if(k >= v)
            {
                sum += k + 1 - v;
                k++;
            }
        }
        return sum;
    }
};