// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k)  
//     {
//         long long ans=0;  
//         int n=nums.size();   
//         int size=n-1;
//         int maxi=*max_element(nums.begin(),nums.end()); 

//         for(int i=0;i<n;i++)
//         {   
//             unordered_map<int,int>stdmap; 
//             for(int j=i;j<n;j++)
//             {
//                 stdmap[nums[j]]++; 
//                 if(stdmap[maxi]>=k)
//                 {
//                     ans+=(size-j+1); 
//                     break;
//                 }
//             }
//         } 
//         return ans;
//     }
// }; 


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k)  
    {
        long long ans=0;  
        int n=nums.size();    
        int left=0; 
        int countMax=0;
        int maxi=*max_element(nums.begin(),nums.end()); 

         for(int right=0;right<n;right++)
         {
            if(nums[right]==maxi)
            {
                countMax++;
            } 

            while(countMax>=k)
            {
                ans+=(n-right); 
                if(nums[left]==maxi)
                {
                    countMax--;
                } 
                left++;
            }
         } 
         return ans; 
    }
};