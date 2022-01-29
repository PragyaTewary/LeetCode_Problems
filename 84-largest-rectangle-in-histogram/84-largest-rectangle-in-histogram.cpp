class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        
        
        int i;
        int ans = 0;
        for(i=0; i<n; i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int curr = st.top();
                st.pop();
                int j = st.empty()? -1: st.top();
                int area = heights[curr]*(i-j-1);
                ans = max(ans, area);
            }
            st.push(i);
        }
        
        while(!st.empty())
        {
            int curr = st.top();
            st.pop();
            int j = st.empty()? -1: st.top();
            int area = heights[curr]*(i-j-1);
            ans = max(ans, area);
        }
        
        return ans;
    }
};