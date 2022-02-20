class Solution {
public:
    int countEven(int n) {
        int s = 0;
        int x = n;
        while(n)
        {
            s += (n%10);
            n /= 10;
        }
        if(s%2 == 0)
        {
            return x/2;
        }
        return (x-1)/2;
    }
};