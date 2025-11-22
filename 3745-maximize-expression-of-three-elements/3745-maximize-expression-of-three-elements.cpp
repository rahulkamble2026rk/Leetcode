class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums)  
    {
        //from array u have to choose three distinct element in such manner  
    
         sort(nums.rbegin(),nums.rend()); 
         int sum=nums[0]+nums[1]-(nums[nums.size()-1]); 
         return sum;
    }
};