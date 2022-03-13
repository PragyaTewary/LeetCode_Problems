class Solution {
public:
   
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
        
        
        int last = 0;
        for(int ind : keyIdx){
            int i = max(last,ind-k);
            for(; i <= ind+k && i < n; i++){
                ans.push_back(i);
            }
            last = i;
        }
        
        return ans;
    }
};