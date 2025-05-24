class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k)
    { 
        sort(nums.begin(),nums.end()); 
        int distinctCount=0;  
        int prevMax=-1e9;  //This is for storing the previos number
         
         int distinct=0;
        for (int num : nums)  
        {
           int lowerBound=num-k; 
           int upperBound=num+k; 

           if(prevMax<lowerBound)
           {
                prevMax=lowerBound; 
                distinct++;
           } 
           else if(prevMax<upperBound)
           {
            prevMax++;
            distinct++;
           }
        }

        

        return distinct;
    }
};
