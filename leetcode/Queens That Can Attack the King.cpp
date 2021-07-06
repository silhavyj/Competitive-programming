class Solution {
    int moves[8][2] {
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {0,-1}
    };
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        int m[8][8];
        memset(m, 0, sizeof(m));
        for (auto q : queens)
            m[q[0]][q[1]] = 1;
        m[king[0]][king[1]] = 2;
        for (auto q : queens) {
            bool canAttack = false;
            for (int i = 0; i < 8 && !canAttack; i++) {
                int y=q[0]+moves[i][0], x=q[1]+moves[i][1];
                while (y >= 0 && x >= 0 && y < 8 && x < 8 && !canAttack) {
                    if (m[y][x]==2)
                        canAttack=true;
                    else if (m[y][x]==1)
                        break;
                    y += moves[i][0];
                    x += moves[i][1];
                }
            }
            if (canAttack)
                ans.push_back(q);
        }
        return ans;
    }
};
