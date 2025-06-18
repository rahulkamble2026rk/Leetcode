class Solution {
public:
    int search(vector<int>& nums, int target)  
    {
        int n=nums.size(); 
        int low=0; 
        int high=n-1; 

        while(high>=low)
        {
            int mid=(low+high)/2; 
            if(target==nums[mid])
            {
                return mid;
            } 
            else if(target>nums[mid]) //if the target is present at the right side of the mid
            {
                low=mid+1;
            } 
            else                 //if the target value is present at the left side of the mid
            {
                high=mid-1;
            }
        }
        return -1;
    }
};