class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)  
    {
        //just use the appraoch which we use for the printing the LIS 

        // 1 2 4 3 5 1 
        //compare the elements from tthe current element with all previos taken element so ,
        vector<int>temp(nums.size(),1);   
        vector<int>parent(nums.size());  
        sort(nums.begin(), nums.end());

        int lastIndex=0; 

        int maxi=1;
        for(int i=0;i<nums.size();i++)
        {
            parent[i]=i; 
            for(int j=0;j<i;j++)
            {
                if((nums[i]%nums[j]==0 || nums[j]%nums[i]==0) && temp[j]+1 >temp[i])
                {
                    temp[i]=temp[j]+1;   //---> This line always contain's teh max element in the ,so temp[i] will always contain the LIS 
                    parent[i]=j;
                }
            } 

            if(temp[i]>maxi)
            {
                maxi=temp[i]; 
                lastIndex=i;
            }
            
        } 



        //reconstrucint the array : 
        vector<int>ans;  
        ans.push_back(nums[lastIndex]);
        while(parent[lastIndex]!=lastIndex)
        {   
            lastIndex=parent[lastIndex];
            ans.push_back(nums[lastIndex]);
        } 

        reverse(ans.begin(),ans.end());
        return ans;
    }
};