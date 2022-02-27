class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
        {
            return 0;
        }
        if(n==2 && nums[0] == nums[1])
        {
            return 1;
        }
        unordered_map<int, int> evenIdxFreq;
        unordered_map<int, int> oddIdxFreq;
        
        for(int i=0; i<n; i++)
        {
            if(i%2 == 0)
            {
                evenIdxFreq[nums[i]]++;
            }
            else{
                oddIdxFreq[nums[i]]++;
            }
        }
        int maxEven = 0;
        int maxEvenVal = 0;
        int secondMaxEven = 0;
        for(auto val: evenIdxFreq)
        {
            if(val.second > maxEven)
            {
                secondMaxEven = maxEven;
                maxEven = val.second;
                maxEvenVal = val.first;
            }
            else if(val.second > secondMaxEven)
            {
                secondMaxEven = val.second;
            }
        }
        int maxOdd = 0;
        int maxOddVal = 0;
        int secondMaxOdd = 0;
        for(auto val: oddIdxFreq)
        {
            if(val.second > maxOdd)
            {
                secondMaxOdd = maxOdd;
                maxOdd = val.second;
                maxOddVal = val.first;
            }
            else if(val.second > secondMaxOdd)
            {
                secondMaxOdd = val.second;
            }
        }
        if(maxEvenVal != maxOddVal)
        {
            return (n- maxEven - maxOdd);
        }

        int pans1 = n - maxEven - secondMaxOdd;
        int pans2 = n - maxOdd - secondMaxEven;
        return min(pans1, pans2);
    }
};