/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*,Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        if (visited.count(node))
            return visited[node]; 
        Node *curr = new Node(node->val);
        visited[node] = curr;
        for (Node *n : node->neighbors)
            curr->neighbors.push_back(cloneGraph(n));
        return curr;
    }
};
