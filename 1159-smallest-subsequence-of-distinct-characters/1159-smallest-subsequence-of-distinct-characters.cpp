class Solution {
public:
    string smallestSubsequence(string s) 
    {
        vector<int>freq(26,0);  //to keep the single occuramce's of the charcters only we use the freq 
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        } 

        vector<bool>seen(26,false); 
        stack<char>stk; 
        for(int i=0;i<s.size();i++)
        {
            if(seen[s[i]-'a'])
            {
                freq[s[i]-'a']--; 
                continue;   
            } 

            while(!stk.empty()&& s[i]<stk.top() && freq[stk.top()-'a']>0)
            {
                seen[stk.top()-'a']=false; 
                stk.pop(); 
            }
            stk.push(s[i]); 
            freq[s[i]-'a']--; 
            seen[s[i]-'a']=true;
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