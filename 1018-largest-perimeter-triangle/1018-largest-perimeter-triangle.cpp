class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        //Here we have to take the subset bits , index: 0,1,2 : 0,1,3 :  
        sort(nums.rbegin(),nums.rend());   
        int maxi=0;

        for(int i=0;i<nums.size()-2;i++)
        {
            int a=nums[i]; 
            int b=nums[i+1]; 
            int c=nums[i+2]; 

            if(b+c>a)
            {
                maxi=max(maxi,b+c+a);
            }
        }  
        return maxi;
    }
};