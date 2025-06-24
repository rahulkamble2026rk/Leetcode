class Solution {
public:
    vector<string> divideString(string s, int k, char fill)  
    { 
        vector<string>vct; 
        int count=0;  
        int rem=s.size()%k; 
        int finalrem=k-rem; 
        string str="";
         if(rem!=0)
         {
             for(int i=1;i<=finalrem;i++)
            {
                s.push_back(fill);
            }
         } 

         for(int i=0;i<s.size();i+=k) 
         {
                vct.push_back(s.substr(i,k)); 
         } 
         return vct;
        
       
      
        
    }
};