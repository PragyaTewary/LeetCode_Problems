class Solution {
public:
    bool check(int idx, vector<int> keyIdx, int k)
    {
        for(int i=0; i<keyIdx.size(); i++)
        {
            if(abs(idx - keyIdx[i]) <= k)
            {
                return true;
            }
        }
        return false;
    }
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        int n = nums.size();
        
        vector<int> ans;
        vector<int> keyIdx; 
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == key)
            {
                keyIdx.push_back(i);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(check(i, keyIdx, k))
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};