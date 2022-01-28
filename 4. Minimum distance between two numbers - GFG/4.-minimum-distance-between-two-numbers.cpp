// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) 
    {
        int ans = INT_MAX;
        int dx = -1;
        int dy = -1;
        for(int i=0; i<n; i++)
        {
            if(arr[i] == x)
            {
                if(dy != -1)
                {
                    ans = min(i-dy, ans);
                    dy = -1;
                }
                dx = i;
            }
            else if(arr[i] == y)
            {
                if(dx != -1)
                {
                    ans = min(i-dx, ans);
                    dx = -1;
                }
                dy = i;
            }
        }
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
  // } Driver Code Ends