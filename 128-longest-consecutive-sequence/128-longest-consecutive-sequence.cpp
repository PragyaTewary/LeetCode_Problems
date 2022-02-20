class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, bool> map;
        for(int i=0; i<nums.size(); i++)
        {
            map[nums[i]] = true;
        }
        
        for(int val : nums)
        {
            if(map.find(val-1) != map.end())
                map[val] = false;
        }
        
        
        int maxlen = 0;
        //int maxstart = 0;
        
        for(int val : nums)
        {
            if(map[val] == true)
            {
                int templen = 1;
                int tempstart = val;
                while(map.find(tempstart + templen) != map.end())
                {
                    templen++;
                }
                maxlen = max(maxlen, templen);
                //maxstart = max(maxstart, tempstart);
            }
        }
        
        return maxlen;
    }
};