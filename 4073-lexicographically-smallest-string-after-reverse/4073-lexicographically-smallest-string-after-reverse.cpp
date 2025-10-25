class Solution {
public:
    string lexSmallest(string s)  
    {
        //You must perfrom exacelty one operation by choosing any integer k , 
        // such that 1<=k<=n , you can either reverse the first k characters of s , or reverse the last k characters of s , return the smallest stirng , after the exactly one such operation 
        
        vector<string>vct; 
        int n=s.size();  
for (int k = 1; k <= n; k++) {
            // Option 1: Reverse first k characters
            string a = s;
            reverse(a.begin(), a.begin() + k);
            vct.push_back(a);

            // Option 2: Reverse last k characters
            string b = s;
            reverse(b.end() - k, b.end());
            vct.push_back(b);
        }  
        sort(vct.begin(),vct.end()); 
        return vct[0];
    }
};