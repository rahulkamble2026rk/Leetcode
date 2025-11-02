class Solution {
public:
    long long maxProduct(vector<int>& nums)  
    {
        //1.sort to karna hi hai , and check in the top how 

        //At the end , product must be maximum so take the absoulte values

        vector<int>vct; 
        for(int i=0;i<nums.size();i++)
        {
            vct.push_back(abs(nums[i])); 
        } 

        sort(vct.rbegin(),vct.rend()); 

        long long ans=1e5L*vct[0]*vct[1]; 
        return ans;
    }
};