class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
       int ans=0; 
       int i=0,j=0;  
       int num=0; //Imagine this is like we take the one whole set of the 0 , like 00000000000
       for(i=0;i<nums.size();i++)
       {
            while((num & nums[i])!=0)    //jab tak & of the numbers is not equal to zero then upto that continue the loop
            {
                num^=nums[j];   //1^1=0; 
                j++;
            } 
            //no problem  
            num|=nums[i];  //setting bits inside num 
            ans=max(ans,i-j+1);
       }
        return ans;
    } 

    //T.C: Log(n)
};