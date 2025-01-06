// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) 
//     {
//         int n=nums.size(); 
//         int countodd=0; 
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i;j<n;j++)
//             {
//                 if(count(nums,i,j)==k)
//                 {
//                    countodd++;
//                 }
//             }
//         } 
//         return countodd;
//     } 
//     int count(vector<int>nums,int start,int n)
//     {   
//         int sum=0;
//         for(int i=start;i<=n;i++)
//         {
//             if(nums[i]%2)
//             {
//                 sum++;
//             }
//         } 
//         return sum;
//     }
// }; 

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    { 
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                nums[i]=0;
            } 
            else 
            {
                nums[i]=1;
            }
        }
        
        return countarray(nums,k)-countarray(nums,k-1);  //let's consider as 1-0=1
    } 
    int countarray(vector<int>nums,int k)
    {
        if(k<0)
        {
            return 0;
        } 
      
         int sum=0; 
        int left=0; 
        int right=0; 
        int count=0;   
        
        while(right<nums.size())
        {
            sum+=nums[right];    
            while (sum>k)
            {
                sum=sum-nums[left];  
                left=left+1;    //shrik the window
            }
             
          count+=(right-left+1);   //this is used for the couting the subarray which are get form due to the right and left 
          right++;
        } 
        return count; 
    }
};