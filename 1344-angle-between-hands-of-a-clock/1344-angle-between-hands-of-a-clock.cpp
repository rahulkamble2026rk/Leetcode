class Solution {
public:
    double angleClock(int h, int m) 
    {  
        double hrAngle=0.5*(h*60+m); 
         
        double minAngle=6*m; 

        double angle=fabs(hrAngle-minAngle); 

        return getMin(360.0-angle,angle);
    }  

    double getMin(double x, double y) {
    return (x < y) ? x : y;
}

};