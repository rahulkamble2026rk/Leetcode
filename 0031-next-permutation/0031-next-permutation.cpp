class Solution {
public:
    void nextPermutation(vector<int>& nums)  
    {
        bool nextPermu=next_permutation(nums.begin(),nums.end()); 

        if(nextPermu)
        {
            cout<<nextPermu;
        }
    }
};