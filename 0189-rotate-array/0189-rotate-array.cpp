class Solution {
public:
    void rotate(vector<int>& nums, int k)  
    {
        //rotating array formula: in the right direction: 
        //int new_ind=(ind+k)%size; 

        vector<int>vct(nums.size(),0); 
        int size=nums.size(); 
        
        for(int i=0;i<nums.size();i++)
        {  
            int new_ind=(i+k)%size;
            vct[new_ind]=nums[i];
        } 
        nums=vct;
    }
};