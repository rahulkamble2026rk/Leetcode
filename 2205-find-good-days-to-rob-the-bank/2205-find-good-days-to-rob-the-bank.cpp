// class Solution {
// public:
//     vector<int> goodDaysToRobBank(vector<int>& security, int time) 
//     {
//         if(time==0)
//         {
//           vector<int>vct; 
//           for(int i=0;i<security.size();i++)
//           {
//             vct.push_back(i);
//           } 
//           return vct;
//         } 
         
//         int start=0; 
//         int ind=start+time; 
//         int end=ind+time; 
//         vector<int>store;
//         while(end<security.size())
//         {     
//             int secondstart=start;  
//             int secondend=end; 
//             while(secondstart<ind && secondend>ind)
//             {
//                 if(security[secondstart]>=security[secondstart+1]&& security[secondend]>=security[secondend-1])
//                 {  
//                     secondstart++;
//                     secondend--;
//                 } 
//                 else
//                 {
//                     ind++; 
//                     start++; 
//                     end++; 
//                     break;
//                 }
//             } 
//             if(secondstart==ind && secondend==ind)
//             {  
//                 store.push_back(ind);
//                 ind++; 
//                 start++; 
//                 end++; 
               
//             }  

//         } 
//         return store;
//     }
// };


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) 
    {
        if(time==0)
        {
          vector<int>vct; 
          for(int i=0;i<security.size();i++)
          {
            vct.push_back(i);
          } 
          return vct;
        }  

        vector<int>increasing(security.size(),0); 
        vector<int>decreasing(security.size(),0); 
         
         int n=security.size();
        for(int i=1;i<n;i++)
        {
            if (security[i] <= security[i - 1]) {
                increasing[i]=increasing[i-1]+1;
            } 
        } 

        for(int i=n-2;i>=0;i--)
        {
            if (security[i] <= security[i + 1]) {
                decreasing[i]=decreasing[i+1]+1;
            } 
        }  

        vector<int>store;
        for(int i=time;i<n-time;i++)
        {
            if(time<=increasing[i]&& time<=decreasing[i])
            {
                store.push_back(i);
            }
        } 
        return store;
    }
};