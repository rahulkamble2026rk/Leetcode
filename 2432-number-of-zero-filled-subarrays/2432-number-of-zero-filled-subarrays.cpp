class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)  
    {
        long long totalCount=0;  
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
            } 
            else 
            {
                totalCount=totalCount+sum(count); 
                count=0;
            }
        } 

        totalCount=totalCount+sum(count); 
        return totalCount;
    } 

    long long sum(int n)
    {
        long long sum=0; 
        for(long long i=1;i<=n;i++)
        {
            sum+=i;
        } 
        return sum;
    }
};