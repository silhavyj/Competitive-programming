class Solution {
public:
set<pair<int,int>> used;

int ori(int x1, int y1,
		int x2, int y2,
		int x3, int y3) {
					
	int o = (y2-y1)*(x3-x2)-(x2-x1)*(y3-y2);
	if (o == 0)
		return 0;
	return o > 0 ? 1 : 2;
}

bool inBetween(int px, int py,
			   int ix, int iy,
			   int qx, int qy) {
    bool a = ix >= px && ix <= qx || ix <= px && ix>= qx;
    bool b = iy >= py && iy <= qy || iy <= py && iy >= qy;
    return a && b;
}

vector<vector<int>> outerTrees(vector<vector<int>>& points) {
	if (points.size() < 3)
		return points;
			
	vector<vector<int>> res;
	int l = 0, p, q;
	
	for (int i = 1; i < points.size(); i++)
		if (points[i][0] < points[l][0])
			l = i;
	
	p = l;
	do {
		res.push_back({points[p][0], points[p][1]});
		used.insert(make_pair(points[p][0], points[p][1]));
		q = (p+1) % points.size();
		
		for (int i = 0; i < points.size(); i++)
			if (ori(points[p][0], points[p][1],
					points[i][0], points[i][1],
					points[q][0], points[q][1]) == 2) {
				q = i;
			}
			
		for (int i = 0; i < points.size(); i++) {
            if (i != p &&
				i != q &&
				ori(points[p][0], points[p][1], points[i][0], points[i][1], points[q][0], points[q][1]) == 0 &&
				inBetween(points[p][0], points[p][1], points[i][0], points[i][1], points[q][0], points[q][1])) {
				
				pair<int,int> pp = make_pair(points[i][0], points[i][1]);
				if (used.find(pp) == used.end()) {
            		res.push_back({points[i][0], points[i][1]});
            		used.insert(pp);
            	}
            }
        }
		p = q;
			
	} while (p != l);
		
	return res;
}
};
