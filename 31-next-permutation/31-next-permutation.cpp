class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // 1 2 3 4 5
        // 1 2 3 5 4
        // 1 2 5 3 4 6
        // 1 2 5 3 6 4
        // 6 4 3 5 2 1
        // 6 4 5 1 2 3
        
        int n = nums.size();
        int i;
        for(i=n-2; i>= 0; i--){
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        if(i >= 0){
            int j = n-1;
            while(i<j && nums[j] <= nums[i]){
                j--;
            }
            swap(nums[j], nums[i]);
        }
        if(i < n-1)
        reverse(nums.begin()+i+1, nums.end());
    }
};