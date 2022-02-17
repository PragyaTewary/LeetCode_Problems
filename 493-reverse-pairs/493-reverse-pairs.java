class Solution {
    public void merge(int[] count, int[] arr, int l, int m, int h)
    {
        int i = l;
        int j = m+1;

        while(i <= m)
        {
            while(j<=h && (arr[i] > (2l*arr[j])))
            {
                j++;
            }
            count[0] += (j-m-1);
            i++;
        }
        
        
        int[] temp = new int[h-l+1];
        i = l;
        j = m+1;
        int len = 0;
        while(i <= m && j <= h)
        {
            if(arr[i] <= arr[j])
            {
                temp[len++] = arr[i++];
            }
            else
            {
                temp[len++] = arr[j++];
            }
        }
        while(i<=m)
        {
            temp[len++] = arr[i++];
        }
        while(j<=h)
        {
            temp[len++] = arr[j++];
        }
        
        len = 0;
        for(int k=l; k<=h; k++)
        {
            arr[k] = temp[len++]; 
        }
        
        
    }
    public void mergeSort(int[] count, int[] arr, int l, int h)
    {
        if(l >= h)
            return;
        int m =  (l + h)/2;
        mergeSort(count, arr, l, m);
        mergeSort(count, arr, m+1, h);
        merge(count, arr, l, m, h);
    }
    public int reversePairs(int[] arr) {
        
        int n = arr.length;
        int[] count = new int[1];
        
        mergeSort(count, arr, 0, n-1);
        
        return Math.max(count[0],0);
    }
    //2 3 4  1 5
}