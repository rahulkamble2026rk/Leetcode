class Solution {
public:
    int countTriples(int n)  
    {
            
          vector<int>vct; 
          set<int>st; 
          for(int i=1;i<=n;i++)
          {
            vct.push_back(i*i); 
            st.insert(i*i);
          }  

            int size=vct.size(); 
            int count=0;
          for(int i=size-1;i>=0;i--)
          {
                int num=vct[i]; 
                for(int j=i-1;j>=0;j--)
                {
                    int first_num=vct[j]; 
                    if(st.count(num-first_num))
                    {
                        count++; 
                       
                    }
                }
          } 
          return count;
    }
};