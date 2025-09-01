#include<bits/stdc++.h>
using namespace std;

int n, m;
char grid[1003][1003];
bool vis[1003][1003];
int parent_i[1003][1003];
int parent_j[1003][1003];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

bool bfs(int si, int sj, int di, int dj){
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    parent_i[si][sj] = -1;
    parent_j[si][sj] = -1;
    
    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        
        if(par_i == di && par_j == dj){
            return true;
        }
        
        for(int i = 0; i < 4; i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D')){
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent_i[ci][cj] = par_i;
                parent_j[ci][cj] = par_j;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    
    int si = -1, sj = -1, di = -1, dj = -1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'R'){
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'D'){
                di = i;
                dj = j;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis[i][j] = false;
            parent_i[i][j] = -1;
            parent_j[i][j] = -1;
        }
    }
    
    if(bfs(si, sj, di, dj)){
        int ci = di, cj = dj;
        while(parent_i[ci][cj] != -1){
            int pi = parent_i[ci][cj];
            int pj = parent_j[ci][cj];
            if(grid[pi][pj] != 'R'){
                grid[pi][pj] = 'X';
            }
            ci = pi;
            cj = pj;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    return 0;
}