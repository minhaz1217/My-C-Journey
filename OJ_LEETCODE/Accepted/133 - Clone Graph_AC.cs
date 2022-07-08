/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 133. Clone Graph
Problem Link: https://leetcode.com/problems/clone-graph/
Date : 08 / Jul / 2022

Comment: Just created a copy dictionary and from it created the graph. Be careful when the initial graph is null.
*/

public class Solution {
    Dictionary<Node,Node> copyNodes = new Dictionary<Node,Node>();
    public Node DeepCopy(Node source){
        if(source != null && !copyNodes.ContainsKey(source)){
            var copy = new Node(source.val);
            copyNodes[source] = copy;
            for(int i=0;i<source.neighbors.Count;i++){
                copy.neighbors.Add(DeepCopy(source.neighbors[i]));
            }
            return copy;
        }else{
            return copyNodes[source];
        }
    }
    public Node CloneGraph(Node node) {
        if(node == null){
            return null;
        }
        return DeepCopy(node);
    }
}
