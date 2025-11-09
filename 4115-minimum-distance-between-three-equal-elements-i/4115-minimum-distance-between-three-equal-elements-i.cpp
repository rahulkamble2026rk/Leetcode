class Solution {
public:
    int minimumDistance(vector<int>& nums)  
    {
        //Given an array of nums , a tuple (i,j,k) of 3 dictinct indices is good if nums[i]==nums[j]==nums[k] 

        int mini=1e9;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    int x=nums[i];
                    int y=nums[j]; 
                    int z=nums[k]; 

                    if(x==y && y==z && x==z)
                    {   
                        int ind=abs(i-j)+abs(j-k)+abs(k-i);
                        mini=min(mini,ind);
                    }
                }
            }
        }  

        if(mini==1e9)
        {
            return -1;
        }

        return mini;
    }
};