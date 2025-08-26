class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions)  
    {
        //first element is represent the length , and second represent the width of the rectangle width of the rectangle i  

        int ind=0; 
        double mini=-1; 

        for(int i=0;i<dimensions.size();i++)
        {
            if(mini<calculate_dimension(dimensions[i][0],dimensions[i][1]))
            {
                mini=calculate_dimension(dimensions[i][0],dimensions[i][1]);
                ind=i;
            } 
            else if(mini==calculate_dimension(dimensions[i][0],dimensions[i][1]))
            {
                if(dimensions[i][0]* dimensions[i][1]>dimensions[ind][0]*dimensions[ind][1])
                {
                    ind=i;
                }
            }
        } 
       
       cout<<dimensions[ind][0]<<"-> "<<dimensions[ind][1]<<endl;
        return dimensions[ind][0]*dimensions[ind][1];
    } 

    double calculate_dimension(int x,int y)
    {
        double result=sqrt(pow(x,2)+pow(y,2)); 
        return result;
    }
};