class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        
        stack<pair<char, int>> st;
        
        st.push({s[0], 1});
        
        int i = 1;
        while(i < n){
            
            if(!st.empty() && s[i] == st.top().first){
                auto curr = st.top();
                st.pop();
                if(curr.second + 1 < k){
                    st.push({curr.first, curr.second+1});
                }
                
            }
            else{
                st.push({s[i], 1});
            }
            i++;
        }
        
        string res = "";
        while(!st.empty()){
            //cout<<st.top().first<<endl;
            res += string(st.top().second, st.top().first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};



