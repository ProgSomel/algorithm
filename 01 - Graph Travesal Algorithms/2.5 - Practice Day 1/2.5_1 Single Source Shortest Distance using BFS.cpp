#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1005];
int level[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for(int child : adj_list[parent]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                level[child] = level[parent]+1;
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
    int src, dist;
    cin >> src >> dist;
    bfs(src);
    for(int i = 0; i < n; i++){
        cout << i << " -> " << level[i] << endl;
    }

    cout << "shorted distance: " << level[dist] << endl;

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
//? output
// 0 -> 0
// 1 -> 1
// 2 -> 3
// 3 -> 2
// 4 -> 2
// 5 -> 3
// 6 -> 4
// shorted distance: 4