class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums)  
    {
        vector<int>increasing; 
        for(int i=0;i<nums.size()-1;i++)
        {
            if((nums[i+1]-nums[i])>0)
            {
                increasing.push_back(1);
            } 
            else 
            {
                increasing.push_back(0);
            }
        } 


        vector<int>decreasing; 
        for(int i=0;i<nums.size()-1;i++)
        {
            if((nums[i+1]-nums[i])<0)
            {
                decreasing.push_back(1);
            } 
            else 
            {
                decreasing.push_back(0);
            }
        } 

         
         int increasecontinue1=0;  
         int maxi=0; 
         int decreasecontinue1=0; 

         for(int i=0;i<increasing.size();i++)
         {
            if(increasing[i]==1)
            {
                increasecontinue1++; 
                maxi=max(increasecontinue1,maxi);
            } 
            else 
            {
                increasecontinue1=0;
            }
         }

        int maxi2=0; 

        
         for(int i=0;i<decreasing.size();i++)
         {
            if(decreasing[i]==1)
            {
                decreasecontinue1++; 
                maxi2=max(decreasecontinue1,maxi2);
            } 
            else 
            {
                decreasecontinue1=0;
            }
         } 
         return maxi>=maxi2?maxi+1:maxi2+1;
    } 
};