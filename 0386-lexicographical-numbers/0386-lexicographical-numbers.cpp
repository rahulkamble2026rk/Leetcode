class Solution {
public: 
  static bool compare(string x,string y)
         {
            return x<y;
         }
    vector<int> lexicalOrder(int n) 
    {
        vector<string>str; 
        vector<int>vct;
        

        string ptr=""; 
        for(int i=1;i<=n;i++)
        {
           ptr+=to_string(i); 
           str.push_back(ptr); 
           ptr.erase(); 
        }  
         
        sort(str.begin(),str.end(),compare); 
         
        for(int i=0;i<str.size();i++)
        {
             vct.push_back(stoi(str[i]));
        } 
        return vct;
    }
};
