class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold)  
    {
        int left=0;   
        int right=k-1; 
        int initial_sum=0; 
        for(int i=0;i<k;i++)
        {
            initial_sum+=arr[i];
        } 

        int n=arr.size(); 

        int count=0;
        while(left<n-k)
        {
            if( ((initial_sum) /k)>=threshold) 
            {   
                count++;
            } 
            right++; 
            initial_sum-=arr[left];
            initial_sum+=arr[right]; 
            left++;
        }  

                initial_sum=0; 
             for(int i=left;i<=right;i++)
                {
                    initial_sum+=arr[i];
                }  

                 if( ((initial_sum) /k)>=threshold) 
               {    
                    count++;
               }
        return count;
    }
};