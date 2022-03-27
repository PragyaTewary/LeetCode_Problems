class Solution {
    public int countCollisions(String str) {
        
        int n = str.length();
        int r = 0;
        int s = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            
            if(str.charAt(i) == 'R'){
                
                r++;
                s =0;
            }
            else if(str.charAt(i) == 'S'){
                if(r > 0){
                    ans += r;
                }
                s = 1;
                r =0;
            }
            else{
                if(r > 0)
                {
                    ans += r+1;
                    s = 1;
                     
                }
                else if(s > 0){
                    ans++;
                }
                r = 0;
                
            }
        }
        if(r > 0 && s > 0){
            ans += r;
        }
        return ans;
    }
}