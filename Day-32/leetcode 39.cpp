class Solution {
public:

    double solve(unordered_map<string, unordered_map<string, double>> &graph, string src, string dest, unordered_set<string> &visited){
        if(graph[src].find(dest) != graph[src].end()) return graph[src][dest];

        for(auto node : graph[src]){
            if(visited.find(node.first) == visited.end()){
                visited.insert(node.first);
                double val = solve(graph, node.first, dest, visited);

                if(val){
                    graph[src][dest] = node.second * val;
                    return graph[src][dest];
                }
            }
        }
        return 0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adjList;

        for(int i=0; i<equations.size(); i++){
            adjList[equations[i][0]][equations[i][1]] = values[i];
            adjList[equations[i][1]][equations[i][0]] = double(1 / values[i]);
        }

        // finding queries
        vector<double> ans(queries.size());
        for(auto query : queries){
            unordered_set<string> visited;

            if(query[0] == query[1]){
                ans.push_back(1.0);
                continue;
            }
            else if(adjList.find(query[0] == adjList.end()) || adjList.find(query[1] == adjList.end())){
                ans.push_back(-1.0);
                continue;
            }

            else{
                ans.push_back(solve(adjList, query[0], query[1], visited));
            }
        }
    }
};