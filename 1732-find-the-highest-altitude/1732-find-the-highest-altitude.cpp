class Solution {
public:
    int largestAltitude(vector<int>& gain)  
    {
        //there are n+1 points at diff. altitudes , biker starts his trip on point 0 with altitude equal 0 

        //gain where gain[i] is the net gain altiude bw points i and i+1 , for 0<=i<n 
        //we have to return the highest altitude of a point 
         
        
          vector<int>vct; 
          vct.push_back(0);
          for(int i=0;i<gain.size();i++)
          {
             int newValue=vct.back()+gain[i]; 
             vct.push_back(newValue);
          }  
          return *max_element(vct.begin(),vct.end());
    }
};