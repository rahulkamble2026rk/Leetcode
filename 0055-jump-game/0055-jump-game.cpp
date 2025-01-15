// class Solution {
// public:
//     bool canJump(vector<int>& nums) 
//     { 
//         if(nums.size()==1)
//         {
//             return true;
//         }
//         int x=nums[1];   
//         int n=nums.size();
//         int ind=0;
//         while(x!=0&&ind<n-1)
//         {    
//             ind=ind+x; 
//              if (ind >= n - 1) 
//             {
//                 return true;
//             }
//             x=nums[ind];   
           
//         }  
//         return ind >= n - 1;
//     }
// }; 

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {  
        int maxval=0; 
        for(int i=0;i<nums.size();i++)
        {
            if(i>maxval)
            {
                return false;
            } 
            maxval=max(maxval,i+nums[i]); 
        } 
        return true;
    }
};