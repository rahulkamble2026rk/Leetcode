class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {     
        int H1ofe1 = stoi(event1[0].substr(0, 2));
        int M1ofe1 = stoi(event1[0].substr(3, 2));
        int H2ofe1 = stoi(event1[1].substr(0, 2));
        int M2ofe1 = stoi(event1[1].substr(3, 2));
        
        int H1ofe2 = stoi(event2[0].substr(0, 2));
        int M1ofe2 = stoi(event2[0].substr(3, 2));
        int H2ofe2 = stoi(event2[1].substr(0, 2));
        int M2ofe2 = stoi(event2[1].substr(3, 2));

        int start1 = H1ofe1 * 60 + M1ofe1;
        int end1 = H2ofe1 * 60 + M2ofe1;
        int start2 = H1ofe2 * 60 + M1ofe2;
        int end2 = H2ofe2 * 60 + M2ofe2;

        return max(start1,start2)<=min(end1,end2);
    }
};
