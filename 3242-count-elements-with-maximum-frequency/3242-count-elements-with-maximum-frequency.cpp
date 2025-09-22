class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)  
    {
        // int count=0;
        //  vector<int>vct;
        //  map<int,int>stdmap;
          
        //   for(int i:nums)
        //   {
        //     stdmap[i]++;
        //   } 

        //   for(const auto & i:stdmap)
        //   {
        //      vct.push_back(i.second);
        //   } 
        //   auto max=max_element(vct.begin(),vct.end());
        //   int x=*max;  
        //   int sum=0;
        //   for(int i=0;i<vct.size();i++)
        //   {
        //         if(x==vct[i])
        //         {
        //             sum+=vct[i];
        //         }
        //   } 
        //   return sum; 
        
         int count=0;
         vector<int>vct;
         map<int,int>stdmap;
          
          for(int i:nums)
          {
            stdmap[i]++;
          } 
          int maxfreq=0;
           
           for(const auto &i:stdmap)
           {
               maxfreq=max(maxfreq,i.second);
           }  
            
             for(const auto &i:stdmap)
           {
              if( maxfreq==i.second)
              {
                count+=i.second;
              }
           }  
           
           return count;

    }
};