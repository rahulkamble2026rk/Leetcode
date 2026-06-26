class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target)  
    {
        //givean an array nums and integer target  
        // return the no. of the subarrays of nums in which target is the majority element: (majority element of subarray that striclty more than half of the times in the subarray) 

        int count=0;
        for(int i=0;i<nums.size();i++)
            {   
                
                int targetCount=0; 
                int totalCount=0;
                for(int j=i;j<nums.size();j++)
                    {
                       totalCount++;
                        if(nums[j]==target)
                        {
                            targetCount++;
                        }

                        if(targetCount>totalCount/2)
                        {
                            count++;
                        }
                        
                    } 
                
            } 

        return count;

        
    }  

    // bool count_array(vector<int>&vct,int target)
    // {
    //     map<int,int>stdmap;  
    //     int n=vct.size();
    //     for(int i=0;i<vct.size();i++)
    //         {
    //             stdmap[vct[i]]++;
    //         } 

    //     if(stdmap[target]>(n/2))
    //     {
    //         return true;
    //     } 
    //     return false;
    // }
};