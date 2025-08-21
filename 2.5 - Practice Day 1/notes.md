[Practice Problems Link](https://docs.google.com/document/d/1PyDLefzBJ0s9ob5MxfFxUcTM5RB1UaQF/edit?tab=t.0)

```c++
#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        cout << parent << " ";
        for(int child : adj_list[parent]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
            }else continue;
        }
        cout << endl;
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
    int src, dist;
    cin >> src >> dist;
    bfs(src);

    if(visited[dist]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
```
