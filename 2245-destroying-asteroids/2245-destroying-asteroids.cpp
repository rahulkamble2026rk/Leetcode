class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    { 
       sort(asteroids.begin(),asteroids.end());
         long long ans=mass;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]>ans)
            {
                return false;
            } 
            ans+=asteroids[i];
        } 

        
                return true;
    
    }
};