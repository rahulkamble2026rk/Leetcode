class Solution {
public:
    int search(vector<int>& nums, int target)  
    { 
        
        // auto it = find(nums.begin(), nums.end(), target);
        // if (it != nums.end()) {
        //     return distance(nums.begin(), it);
        // }
        // return -1; 


        //logic: idantigy the which part is either sorted , left or right beacause outoff 2 , one part will be definelty sorted 

        int high=nums.size()-1; 
        int low=0; 
        return checkfound(low,high,target,nums);
    } 

    int checkfound(int low ,int high , int target,vector<int>&nums)
    {    
        while(low<=high)
        {
        int mid=(low+high)/2; 
        if(nums[mid]==target)
        {
            return mid;
        }

        //check which part is sorted ,either left or right 
        if(nums[low]<=nums[mid]) //left part is sorted
        {
            //check whther the element is actually present in the left side or not 
            if(nums[low]<=target && nums[mid]>=target)
            {
                high=mid-1;
            } 
            else   //means your element is present in the right side , what we assume that is wrong so increase the value of low 
            {
                low=mid+1; //finding in the right side;
            }
        }  
        else    //right part is sorted
        {

            if(nums[mid]<=target && nums[high]>=target)
            {
                //if the part is present at the right side
                 low=mid+1;
            } 
            else
            {
                high=mid-1;
            }
        } 
       
        }
         return -1; 
    }
    
};