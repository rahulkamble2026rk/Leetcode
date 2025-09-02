// class Solution {
// public:
//     int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {  

//         //ste1: firstly calculate the overall area of the reactangle: 
//         //to find teh height of the rectangle:  (ay2-ay1) * (ax2-ax1)  
//         int area1=(ax2-ax1)*(ay2-ay1); 
//         int area2=(bx2-bx1)*(by2-by1);   

//         int total_area=area1+area2;

//         int first_rect_x=ax2;
//         int first_rect_y=ay1;

//         int second_rect_x=bx1;
//         int second_rect_y=by2; 

//         //step2:checking whether there is overlapping or not:  
//         if( ( (ax2>=second_rect_x && ay2>=second_rect_y) || (ax2<=second_rect_x && ay2<=second_rect_y) )  && ( (first_rect_x >=bx1 && first_rect_y >=by1) || ( first_rect_x<=bx1 && first_rect_y<=by1) ) ) 
//         {
//             int x1=max(ax1,second_rect_x); 
//             int y1=min(ay1,second_rect_y); 

//             int x2=min(first_rect_x,bx1); 
//             int y2=max(by1,first_rect_y); 

//             int area3=abs(x2-x1)*abs(y2-y1); 

//             return (total_area-area3);
//         } 

//         return total_area;

//     }
// };


class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {  
        int area1 = (ax2 - ax1) * (ay2 - ay1); 
        int area2 = (bx2 - bx1) * (by2 - by1);   
        int total_area = area1 + area2;

        if (ax2 > bx1 && bx2 > ax1 && ay2 > by1 && by2 > ay1) {
            int x1 = max(ax1, bx1); 
            int x2 = min(ax2, bx2); 
            int y1 = max(ay1, by1); 
            int y2 = min(ay2, by2); 
            int area3 = (x2 - x1) * (y2 - y1); 
            return (total_area - area3);
        }

        return total_area;
    }
};