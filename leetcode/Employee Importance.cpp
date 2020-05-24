/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_set<int> visited; 
    
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        if (visited.find(id) != visited.end())
            return 0;
        for (auto e : employees)
            if (e->id == id) {
                ans += e->importance;
                visited.insert(e->id);
                for (int n : e->subordinates)
                    ans += getImportance(employees, n);
            }
        return ans;
    }
};
