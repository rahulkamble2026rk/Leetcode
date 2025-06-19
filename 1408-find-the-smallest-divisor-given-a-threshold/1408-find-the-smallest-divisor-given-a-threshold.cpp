class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        //one is confirm is that when ever we have to guess or choose the such values then goes use the binary search  
        int low=1; 
        int high=*max_element(nums.begin(),nums.end()); 
        int ans=high;
        while(low<=high)
        {    
            int mid=(low+high)/2;
            if(check(mid,nums,threshold))
            {
                ans=mid; 
                high=mid-1;
            } 
            else 
            {
                low=mid+1;
            } 

        }  
        return ans;
    } 

    bool check(int target,vector<int>&nums,int threshold)
    {  
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+ceil((double)nums[i]/target);
        } 
        if(sum<=threshold)
        {
            return true;
        } 
        return false;
    }
};