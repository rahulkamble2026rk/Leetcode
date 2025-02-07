class Solution {
public:
    int countBalls(int lowLimit, int highLimit)
    {
        map<int,int>stdmap; 
        
        for(int j=lowLimit;j<=highLimit;j++)
        {
            stdmap[sum(j)]++;
        } 
        int maxi=INT_MIN;  

        for(const auto &i:stdmap)
        {
            if(i.second>maxi)
            {
                maxi=i.second;
            }
        } 
        return maxi;

    } 
    int sum(int number)
    {
        int s=0; 
        while(number>0)
        {
            int rem=number%10; 
            s+=rem; 
            number/=10;
        } 
        return s;
    }
};