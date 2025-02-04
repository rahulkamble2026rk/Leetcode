class NumArray {
public: 
    vector<int>vct;
    NumArray(vector<int>& nums) 
    {  
        vct.resize(nums.size(),0); 
        vct[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            vct[i]=nums[i]+vct[i-1];
        }
    }
    
    int sumRange(int left, int right) 
    {
           if (left == 0) return vct[right]; 
        return vct[right] - vct[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */