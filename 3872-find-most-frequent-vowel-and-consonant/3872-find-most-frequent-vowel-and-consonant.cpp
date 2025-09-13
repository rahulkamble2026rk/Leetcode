class Solution {
public:
    int maxFreqSum(string s)  
    {
        map<char,int>stdmap1; //for vowels 
        map<char,int>stdmap2; //for consonants  
        int vowelMax=0; 
        int consenetMax=0; 


        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i] =='i' || s[i]=='o' || s[i]=='u')
            {
                stdmap1[s[i]]++; 
                vowelMax=max(vowelMax,stdmap1[s[i]]); 
            } 
            else 
            {
                stdmap2[s[i]]++; 
                consenetMax=max(consenetMax,stdmap2[s[i]]);
            }
        }  

        return (vowelMax + consenetMax);

    }
};