class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>&num, int target) 
    {
      vector<vector<int>>vct; 
    vector<int>ans; 
    int n=num.size(); 
    generate(num,n,target,vct,ans); 
    for (auto& combination : vct) {  
        sort(combination.begin(), combination.end());  // Sort each combination
    } 
  
    set<vector<int>>st(vct.begin(),vct.end()); 
     vct.assign(st.begin(), st.end()); 
     return vct;
    } 
    void generate(vector<int>num,int n,int target,vector<vector<int>>&vct,vector<int>&ans )
{ 
      if(target==0)
      {
        vct.push_back(ans);
        return;
      } 
      if (target < 0) 
      {
        return;
      }
      for(int i=0;i<num.size();i++)
      {  
          ans.push_back(num[i]);
         generate(num,n,target-num[i],vct,ans);  
         ans.pop_back();
        
      }
}
}; 