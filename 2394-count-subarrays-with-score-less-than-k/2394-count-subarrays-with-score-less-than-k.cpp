// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, long long k) 
//     {
//           long long ans=0; 
//           for(int i=0;i<nums.size();i++)
//           {    
//             long long sum=0; 
//             for(int j=i;j<nums.size();j++)
//             {     
//                 long long res=abs(i-j)+1; 
                
//                 sum+=nums[j]; 
//                 long long res2=res*sum; 
//                 if(res2<k) 
//                 {
//                     ans++; 
//                 }  
//                 else
//                 {
//                     break;
//                 } 
//             }
//           } 
//           return ans;
//     }
// }; 

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {  
         long long ans=0; 
          long long cs=0;  
          int i=0; 
          int j=0; 
        int n=nums.size();
        while(j<n)
        {
            cs+=nums[j]; 
            //make window valid  
            while(cs*(j-i+1)>=k) 
            {
                cs-=nums[i]; 
                i++;
            }   

            //capture  
            ans+=(j-i+1);
            j++;
        } 
        return ans;
        
    }  
};