// class CountIntervals {
// public: 
//     vector<vector<int>>vct;  
//       bool isMerged;
//     CountIntervals() 
//     {
//        isMerged=false;
//     }
//     void add(int left, int right) 
//     {
//         vector<int>temp={left,right}; 
//         vct.push_back(temp); 
//         isMerged=false;
//     }
    
//     int count() 
//     {    
//          if(!isMerged)
//          {
//             mergeIntervals();
//          }
//           int sum=0;
//         for(int i=0;i<vct.size();i++)
//         {   
          
//             sum=sum+(vct[i][1]-vct[i][0]+1);
//         } 
//         return sum;
//     } 
//       void mergeIntervals() 
//       { 
//          vector<vector<int>>merge;
//         if(vct.size()==0)
//         {
//             return;
//         }
//         sort(vct.begin(),vct.end());
//         vector<int>temp=vct[0];
//         for(int i=0;i<vct.size();i++)
//         {
//             if(temp[1]>=vct[i][0])
//             {
//                 temp[1]=max(temp[1],vct[i][1]);
//             } 
//             else 
//             {
//                 merge.push_back(temp); 
//                 temp=vct[i];
//             }
//         } 
//         merge.push_back(temp); 
//         vct = merge;
//          isMerged = true;
//       }


// };

// /**
//  * Your CountIntervals object will be instantiated and called as such:
//  * CountIntervals* obj = new CountIntervals();
//  * obj->add(left,right);
//  * int param_2 = obj->count();
//  */
 
 class CountIntervals {
public:
    map<int, int> m;
    int cnt = 0;
    void add(int left, int right) {
        auto it = m.upper_bound(left);
        if (it != begin(m) && prev(it)->second >= left)
            it = prev(it);
        for (; it != end(m) && it->first <= right; m.erase(it++)) {
            left = min(left, it->first);
            right = max(right, it->second);
            cnt -= it->second - it->first + 1;
        }
        cnt += right - left + 1;
        m[left] = right;
    }
    int count() { return cnt; }
};