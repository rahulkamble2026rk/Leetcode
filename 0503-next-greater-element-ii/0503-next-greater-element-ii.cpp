class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        vector<int> temp(nums.begin(), nums.end());  
        vector<int> ans;
        temp.insert(temp.end(), temp.begin(), temp.end()); 
        stack<int> stk; 
        int n = temp.size();  
        for(int i = n-1; i >= 0; i--)
        {
            int x = temp[i]; 
            while(!stk.empty() && x >= stk.top())  // Fix: x >= stk.top() 
            {
                stk.pop();
            } 
            if(!stk.empty())
            {  
                ans.push_back(stk.top());
            } 
            else  
            {
                ans.push_back(-1);
            } 
            stk.push(x);
        }  
        
        reverse(ans.begin(), ans.end());
        
        
        ans.resize(nums.size());  
        
        return ans;
    }
};
