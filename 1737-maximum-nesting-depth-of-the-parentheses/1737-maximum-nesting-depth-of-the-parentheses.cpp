class Solution {
public:
    int maxDepth(string s)  
    {   
        int sum=0; 
        int maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            { 
                sum++;
                maxi=max(maxi,sum);
            }
            else if(s[i]==')')
            {
                sum--;
            }
        } 
        return maxi;
    }
};