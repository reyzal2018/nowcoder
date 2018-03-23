//clone-graph
//https://www.nowcoder.com/practice/5ec76def9d7b420794091727a97f0dc6
class Solution {
public:
    map<int,UndirectedGraphNode*> status;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        UndirectedGraphNode* pNewHead = new UndirectedGraphNode(node->label);
        status[node->label] = pNewHead;
        for(auto& it:node->neighbors){
            if(status.count(it->label)){
                pNewHead->neighbors.push_back(status[it->label]);
                continue;
            }
            pNewHead->neighbors.push_back(cloneGraph(it));
        }
        return pNewHead;
    }
};