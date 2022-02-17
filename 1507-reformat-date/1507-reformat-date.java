class Solution {
    public String reformatDate(String date) {
        
        String day = date.substring(0, 2);
        
        if(!Character.isDigit(day.charAt(1)))
        {
            day = "0" + day.charAt(0);
        }
        String[] mon = new String[]{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; 
        
        HashMap<String, Integer> map = new HashMap<>();
        
        for(int i=1; i<13; i++)
        {
            map.put(mon[i-1], i);
        }
        
        int n = date.length();
        String year = date.substring(n-4, n);
        
        String month = date.substring(n-8, n-5);

        String m = String.valueOf(map.get(month));
        if(m.length() < 2)
        {
            m = "0" + m;
        }
        String res = year + "-" + m + "-" + day;
        
        return res;
    }
}