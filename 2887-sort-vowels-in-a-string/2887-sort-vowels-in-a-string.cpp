class Solution {
public:
    string sortVowels(string s)  
    { 
        vector<char>vct;
        for(int i=0;s[i]!='\0';i++)
        {
            if(check(s[i]))
            {
                 vct.push_back(s[i]);
            }
        } 
          
         sort(vct.begin(),vct.end()); 
         return create(s,vct);

     } 

     bool check(char ch)
     {
        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'|| ch=='u')
        {
            return true;
        } 
        return false;
     } 
      
      string create(string& str,vector<char>vct)
      {
          int k=0; 
          for(int i=0;str[i]!='\0';i++)
          {
              if(check(str[i])) 
              {
                 str[i]=vct[k]; 
                 k++;
              }
          }
          return str;
      }
};