// class Solution {
// public:
//     int maxTwoEvents(vector<vector<int>>& events)  
//     {  
//         map<pair<int,int>,int>stdmap; 
//         for(int i=0;i<events.size();i++)
//         {   
//             pair<int,int>pt={events[i][0],events[i][1]}; 
//             stdmap[pt]=events[i][2];
//         }
        
//         //now interate and check whether the next value is present or not in the map 

//         for(auto it=stdmap.begin();it!=stdmap.end();it++)
//         {
//             it->first
//         }



//     } 
//     bool static compare(vector<int>event_first,vector<int>event_second) 
//     {
//         if(event_first[0]>event_second[0])
//         {
//             return false;
//         } 
//         else if(event_first[0]<event_second[0]) 
//         {
//             if(event_first[1]>event_second[1])
//             {
//                 return false;
//             }
//         }
//     }

// };


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<array<int, 3>> times;
        for (auto& e : events) {
            // 1 denotes start time.
            times.push_back({e[0], 1, e[2]});
            // 0 denotes end time.
            times.push_back({e[1] + 1, 0, e[2]});
        }
        int ans = 0, maxValue = 0;
        sort(begin(times), end(times));
        for (auto& timeValue : times) {
            // If current time is a start time, find maximum sum of maximum end
            // time till now.
            if (timeValue[1]) {
                ans = max(ans, timeValue[2] + maxValue);
            } else {
                maxValue = max(maxValue, timeValue[2]);
            }
        }
        return ans;
    }
};