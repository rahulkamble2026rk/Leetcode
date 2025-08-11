class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)  
    {
    //    set<vector<int>>st; 
    //     vector<int>temp; 
    //     st.insert(temp); 

    //    for(int i=0;i<nums.size();i++)
    //    {   
    //     vector<int>vct; 

    //     for(int j=i;j<nums.size();j++)
    //     {
    //         vct.push_back(nums[j]); 
    //         st.insert(vct);
    //     }
    //    } 

    //    vector<vector<int>>ans(st.begin(),st.end()); 
    //    return ans; 


    //Here we have to find the subsets ,so means either we have to take that element or we have to leave that element  

    vector<vector<int>>ans; 
    vector<int>ds; 
    sort(nums.begin(),nums.end()); 

    find_subsets(0,nums,ds,ans); 
    return ans;

    } 

    void find_subsets(int ind,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
    {
        ans.push_back(ds); 
//i != ind → Not the first element at this level → If same as previous → Skip it.
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1])
            {
                continue;
            } 
            ds.push_back(nums[i]); 
            find_subsets(i+1,nums,ds,ans); 
            ds.pop_back();
        }
    }
};