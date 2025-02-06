class Solution {
public:
    int tupleSameProduct(vector<int>& nums)  
    {
        map<int,int>freq; 
        //step1:formation of the unqiue pair  
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                freq[nums[i]*nums[j]]++;
            }
        } 
         
         int sum=0;
        for(const auto &i:freq)
        {
            if(i.second>1)
            {
                sum+=8*(i.second * (i.second - 1)) / 2;
            }
        } 
        return sum;
    } 
    
};