class Solution {
public:
        
    struct Point {
        int pos;
        bool end;
        int vec;
    };
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        vector<Point> points;
        int a=0, b=0;
        int ai=0, bi=0;
        bool open1=false, open2=false;
        int start=-1;
        
        while (a < A.size() && b < B.size()) {
            if (A[a][ai] == B[b][bi]) {
                if (ai==0) {
                    points.push_back({A[a][ai],ai==1,1});
                    if (++ai==2) {
                        a++;
                        ai=0;
                    }   
                }
                else {
                    points.push_back({B[b][bi],bi==1,2});
                    if (++bi==2) {
                        b++;
                        bi=0;
                    }
                }
                continue;
            }
            if (A[a][ai] < B[b][bi]) {
                points.push_back({A[a][ai],ai==1,1});
                if (++ai==2) {
                    a++;
                    ai=0;
                }
            }
            else {
                points.push_back({B[b][bi],bi==1,2});
                if (++bi==2) {
                    b++;
                    bi=0;
                }
            }
        }
        while (a < A.size()) {
            points.push_back({A[a][ai],ai==1,1});
            if (++ai==2) {
                a++;
                ai=0;
            }
        }
        while (b < B.size()) {
            points.push_back({B[b][bi],bi==1,2});
            if (++bi==2) {
                b++;
                bi=0;
            }
        }
        for (Point p : points) {
            if (p.end==0 && p.vec==1) open1 = true;
            if (p.end==0 && p.vec==2) open2 = true;
            if (open1 && open2) {
                if (start == -1)
                    start = p.pos;
                else {
                    ans.push_back({start,p.pos});
                    start = -1; 
                }
            }
            if (p.end==1 && p.vec==2) open2 = false;
            if (p.end==1 && p.vec==1) open1 = false;
        }
        return ans;
    }
};
