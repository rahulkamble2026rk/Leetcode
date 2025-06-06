class Solution { 

    char smallest(vector<int>&right_freq)
    {
        for(int i=0;i<26;i++)
        {
            if(right_freq[i]>0)
            {
                return char(97+i);
            } 

        }
        return 'z';
    }
public:
    string robotWithString(string s)  
    {
        //firstly find the smallest characrter from the string   
        //step1: Right-Freq Map to build the map (preprocessing step)
        int n=s.size(); 
        vector<int>right_freq(26,0);
        for(int i=0;i<n;i++)
        {
            right_freq[s[i]-'a']++;
        } 
         
         string t,res; 
         int pos=0; 
         while(pos<n)
         {
            t.push_back(s[pos]); 
            right_freq[s[pos]-'a']--; 

            while(!t.empty() && t.back()<=smallest(right_freq))
            {
                res.push_back(t.back()); 
                t.pop_back();
            } 
            pos++;
         } 
         return res;
    }
};