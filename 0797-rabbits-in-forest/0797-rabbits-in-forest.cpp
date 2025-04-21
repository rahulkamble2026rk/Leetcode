class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
        int ans=0; 
        map<int,int>stdmap; 
        for(int i=0;i<answers.size();i++)
        { 
            if(answers[i]==0)
            {
                ans+=1; 
                
            } 
            else 
            {
                stdmap[answers[i]]++;  
                if(stdmap[answers[i]]==answers[i]+1)
                {
                    ans+=(answers[i]+1); 
                    stdmap[answers[i]]=0;
                } 
            
            }

        } 

        for(const auto &i:stdmap)
        {
            int groupSize = i.first + 1;
            int count = i.second;
            int groups = (count + i.first) / groupSize; // ceil(count / groupSize)
            ans += groups * groupSize; 
        } 
        return ans;
    }
};