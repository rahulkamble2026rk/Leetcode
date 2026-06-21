class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x)  
    { 

        int count=0;;
        for(int i=0;i<nums.size();i++) 
        {
            long long sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j]; 
                if(isDigitSame(sum,x))
                {
                    count++;
                }
            }
        } 
        return count;
    } 

    bool isDigitSame(long long sum,int x)
    {  
       int last=sum%10; 
       
       while(sum>=10)
       {
        sum/=10;
       } 
        
       int first=sum;

       return first==x && last==x;
    }
};