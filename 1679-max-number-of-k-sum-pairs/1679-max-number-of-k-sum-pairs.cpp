class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int h = n-1;
        int res = 0;
        while(l < h){
            
            if(nums[l] + nums[h] == k){
                res++;
                l++;
                h--;
            }
            else if(nums[l]+nums[h]  > k){
                h--;
            }
            else{
                l++;
            }
        }
        
        return res;
    }
};