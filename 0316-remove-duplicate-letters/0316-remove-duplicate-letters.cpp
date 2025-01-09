class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        } 
        stack<char>stk; 
        vector<bool>seen(26,false); 

        for(int i=0;i<s.size();i++)
        {
            if(seen[s[i]-'a'])
            {
                freq[s[i]-'a']--; 
                continue;
            } 
            while(!stk.empty() && stk.top()>s[i] && freq[stk.top()-'a']>0)
            {
                seen[stk.top()-'a']=false; 
                stk.pop();
            } 
            stk.push(s[i]); 
            seen[s[i]-'a']=true; 
            freq[s[i]-'a']--;
        } 
        string ans=""; 
        while(!stk.empty())
        {
            ans.push_back(stk.top()); 
            stk.pop();
        } 
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};