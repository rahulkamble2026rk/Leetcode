// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) 
//     {
//         int r=0; 
//         int l=0; 
//         int n=nums.size(); 
//         int count=0;
//         for(int i=0;i<n;i++)
//         { 
//             map<int,int>stdmap;
//             for(int j=i;j<n;j++)
//             {
//                 stdmap[nums[j]]++; 
//                 if(stdmap.size()==k)
//                 {
//                     count++;
//                 } 
//                 else if(stdmap.size()>k)
//                 {
//                     break;
//                 }
//             }
//         } 
//         return count;
//     }
// }; 

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    { 
        return subarraycount(nums,k)-subarraycount(nums,k-1);  //here we are using this pattern beaucse we don't kow when to shrink the data and when to expand teh window, due to wrong expand we are missing some subarray
    } 
    int subarraycount(vector<int>&nums,int k)
    {
        int l=0; 
        int r=0;  
        int count=0;
        int n=nums.size(); 
        if(k<0)
        {
            return 0;
        }  
        map<int,int>stdmap;
        while(r<n)
        {
            stdmap[nums[r]]++; 
            while(stdmap.size()>k)
            {
               stdmap[nums[l]]--; 
                if(stdmap[nums[l]]==0)
                {
                    stdmap.erase(nums[l]); 
                } 
                l=l+1;
            }
            count+=(r-l+1);
            r+=1;
        } 
        return count;
    }
};