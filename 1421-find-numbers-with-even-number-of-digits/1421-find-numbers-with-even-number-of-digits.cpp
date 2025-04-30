class Solution {
public:
    int findNumbers(vector<int>& nums)  
    {
        int count=0; 
        for(int i=0;i<nums.size();i++)
        {
            if(iseven(nums[i]))
            {
                count++;
            }
        } 
        return count;
    } 
    bool iseven(int sum)
    {
        int digit=0; 
        while(sum>0)
        {
            sum/=10; 
            digit++;
        }  
        return digit%2==0?true:false;

    }
};