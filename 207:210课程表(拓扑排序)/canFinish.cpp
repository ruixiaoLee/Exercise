class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

    void dfs(int u){ //未搜索=0，正在搜索=1，已搜索=2
        visited[u] = 1; //正在搜索=1
        for(int v: edges[u]){//该端点指向的所有端点都搜索一遍
            if(visited[v]==0){//如果指向的端点未搜索过，则搜索。已搜索则return
                dfs(v);
                if(!valid) return;
            }
            else if(visited[v]==1){//如果指向的端点正在搜索，说明有环，valid=false
                valid = false;
                return;
            }
        }
        visited[u] = 2;//已搜索完=2
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses); //初始化edges和visited端点数量
        visited.resize(numCourses);
        for(const auto& info: prerequisites){
            edges[info[1]].push_back(info[0]);//info是prerequisites里每一个vector<int>
            //edges的端点info[1]指向info[0],指向的端点可能不止一个，均储存进vector
        }
        
        for(int i=0 ; i<numCourses && valid; ++i){//遍历端点，如果小于端点数量且该端点是true(没有环)
            if(visited[i]==0) dfs(i);//如果该节点未搜索过则搜索
        }
        return valid;
    }
};