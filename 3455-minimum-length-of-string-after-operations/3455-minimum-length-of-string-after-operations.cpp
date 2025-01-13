class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        
        if (n == 1 || n == 2) {
            return n;
        }

        vector<int>vct(26);  
        for(int i=0;i<s.size();i++)
        {
            vct[s[i]-'a']++;
        } 

        int length=0; 
        for(int i=0;i<vct.size();i++)
        {
            if(vct[i]%2)
            {
                length+=1;
            } 
            else if(vct[i]%2==0 && vct[i]>=2)
            {
                length+=2;
            }
        } 
        return length;
    }
};
