class Solution {
public:
    long long numberOfWeeks(vector<int>& arr) {
        int n = arr.size();
        int mx = *max_element(arr.begin(), arr.end());
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
        }
        
        long long int rest = sum-mx;
        return min(sum, 2*rest+1);
        
    }
};