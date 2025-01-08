class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words)  
    {  
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(isPrefixAndSuffix(words[i],words[j]))
                {
                    count++; 
                }
            }
        } 
        return count;
    } 
    bool isPrefixAndSuffix(string str1,string str2)
    { 
        int n = str1.size();
        int m = str2.size();

        
        if (m >= n) {
            return (str2.substr(0, n) == str1 && str2.substr(m - n,n) == str1);
        }
        return false;
           
    }
};