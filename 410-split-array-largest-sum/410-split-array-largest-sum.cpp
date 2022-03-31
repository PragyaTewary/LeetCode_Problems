class Solution {
public:
    
    bool pos(int m, vector<int>& nums, int k){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > m)
            {
                return false;
            }
            if(sum + nums[i]  > m){
                k--;
                if(k <= 0){
                    return false;
                }
                sum = 0;
            }
            sum += nums[i];
    
            
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        long sum = 0;
        
        for(auto v :  nums){
            sum += v;
        }
        
        int l = nums[0];
        int h = sum;
        
        int ans = h;
        while(l <= h){
            
            int m = l + (h-l)/2;
            if(pos(m, nums, k)){
                ans = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};