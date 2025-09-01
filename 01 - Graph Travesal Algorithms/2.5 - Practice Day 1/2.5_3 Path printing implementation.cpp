#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1005];
int level[1005];
int parent[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while(!q.empty()){
        int par = q.front();
        q.pop();
        for(int child : adj_list[par]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                level[child] = level[par]+1;
                parent[child] = par;
            }else continue;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    int src, dist;
    cin >> src >> dist;
    bfs(src);

    vector<int> path;

    int node = dist;
    while(node!=-1){
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());
    for(int val : path){
        cout << val << " ";
    }
    return 0;
}

//! Input
// 7 7
// 0 1
// 1 3
// 3 2
// 1 4
// 3 5
// 2 5
// 5 6
// 0
// 6
//? output
// 0 1 3 5 6