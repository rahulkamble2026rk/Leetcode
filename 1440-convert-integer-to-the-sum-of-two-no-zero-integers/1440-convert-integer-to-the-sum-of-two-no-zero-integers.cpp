class Solution {
public:
    vector<int> getNoZeroIntegers(int n)  
    {
        //we have to return such two numbers which having the sum as the n and outoff that no must contain the zero: 

        int sum=n; 
        vector<int>vct;
        for(int i=1;i<n;i++)
        {
            sum-=i; 
            if(sum%10==0 || check_zero(sum) ||check_zero(i))
            {  
                sum=n;
                continue; 
            } 
            else 
            {
                vct.push_back(i); 
                vct.push_back(sum); 
                break;
            }
        } 
        return vct;
    } 

    bool check_zero(int num)
    {
        while(num>0)
        {
            int rem=num%10; 
            if(rem==0)
            {
                return true;
            } 
            num/=10;
        } 
        return false;
    }
};