class Solution {
public:
    int maxProduct(vector<int>& nums)  
    {
        int maxProd=nums[0]; 
        int maxSoFar=nums[0]; 
        int minSoFar=nums[0]; 

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(maxSoFar,minSoFar);
            }  

             maxSoFar = max(nums[i], maxSoFar * nums[i]);
            minSoFar = min(nums[i], minSoFar * nums[i]);

            maxProd = max(maxProd, maxSoFar);

        } 
        return maxProd;
    }
};