class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    { 
        int r=0,l=0,maxsize=0; 
      vector<int> vct(128, 0); 
        while(r<s.size())
        {
           if(vct[s[r]]==0)
           {
            vct[s[r]]+=1; 
            r++; 
             maxsize=max(maxsize,r-l);
           } 
           else 
           {
            vct[s[l]]-=1;
                l++;
            } 
       
        } 
      return maxsize;
    }
};