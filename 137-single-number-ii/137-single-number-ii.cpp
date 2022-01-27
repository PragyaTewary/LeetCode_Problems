class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
    
        int tn = INT_MAX; // Count of bits in each place if divisible by 3 will be on otherwise off.
        // For negative values we need to take tn = -1
        tn = -1;
        int tnp1 = 0;   // Count of bits in each place if divisible by 3 leaves remainder 1 will be on otherwise off.
        int tnp2 = 0;    // Count of bits in each place if divisible by 3 leaves remainder 2 will be on otherwise off.
        
        for(int i=0; i<n; i++)
        {
            int cwtn = (tn & nums[i]); // bits common with tn
            int cwtnp1 = (tnp1 & nums[i]); // bits common with tnp1
            int cwtnp2 = (tnp2 & nums[i]); // bits common with tnp2
            
            tn = tn & (~cwtn);
            tnp1 = tnp1 | (cwtn);
            
            tnp1 = tnp1 & (~cwtnp1);
            tnp2 = tnp2 | (cwtnp1);
            
            tnp2 = tnp2 & (~cwtnp2);
            tn = tn | (cwtnp2);
        }
        
        return tnp1; 
    }
};