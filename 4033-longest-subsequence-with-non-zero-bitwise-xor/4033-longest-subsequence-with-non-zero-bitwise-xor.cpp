class Solution {
public:
    int longestSubsequence(vector<int>& nums)  
    {
        //step1: if the XOR all elements in the array is non zero then return the original size of the array if not then check again

        //step2: whether all elements in the array are zero then return 0 
        // step 3: if not then by removing atleast one element as well it will work 


         int XOR=0; 
         for(int i:nums)
         {
            XOR^=i;
         } 

         if(XOR>0)
         {
            return nums.size();
         } 

         bool flag=false;
         for(int i=0;i<nums.size();i++)
         {
            if(nums[i]!=0)
            {
                flag=true;
            }
         } 

         if(flag==false)
         {
            return 0;
         } 
         return nums.size()-1;
    }
};