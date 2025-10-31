class Solution {
public:
    int longestBalanced(vector<int>& nums)  
    {
        //subarray is continogous part of the array , we have to return the longest balaced subarray where the no. of the odd numbers =no. of the even numbers 

        //sliding window here ;; 

    
        int maxi=0;
        for(int i=0;i<nums.size();i++) 
        {    
            set<int>even_set; 
            set<int>odd_set;   
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]%2==0)
                {
                    even_set.insert(nums[j]);
                } 
                else 
                {
                    odd_set.insert(nums[j]);
                } 

                if(even_set.size() == odd_set.size())
                {
                    maxi=max(maxi,j-i+1);
                }
            }
            
        } 

        return maxi; 

        
    }
};