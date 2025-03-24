class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings)  
    {
        sort(meetings.begin(),meetings.end()); 
        //sorting the array : 
        vector<int>select=meetings[0];  

        vector<vector<int>>vct;
         int total=0;
        for(int i=1;i<meetings.size();i++)
        {
            if(meetings[i][0]<=select[1])
            {
                select[1]=max(meetings[i][1],select[1]);
            } 
            else
            {
                vct.push_back(select);  
                total+=(select[1]-select[0])+1; 
                cout<<"Total meet"<<total<<endl;
                select=meetings[i];
            }
        } 
        vct.push_back(select); 
        total+=(select[1]-select[0])+1;  
        cout<<"Total meet"<<total<<endl;
        return days-total;

    }
};