class Solution {
public:
    int minimumSum(int num) 
    {
        vector<int> arr;
        while(num)
        {
            arr.push_back(num%10);
            num /= 10;
        }
        sort(arr.begin(), arr.end());
        int n1 = 0;
        int n2 = 0;
        for(int i=0; i<3; i+=2)
        {
            n1 = n1*10 + arr[i];
            n2 = n2*10 + arr[i+1];
        }
        return n1+n2;
    }
};