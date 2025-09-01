#include<bits/stdc++.h>
using namespace std;

int n, m;

char grid[1005][1005];
bool vis[1005][1005];
vector<int> v;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj, int &count){
    
    vis[si][sj] = true;
    count++;
    for(int i = 0; i < 4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
            dfs(ci, cj, count);
        }
    }
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                cnt++;
                int count = 0;
                dfs(i, j, count);
                v.push_back(count);
            }
        }
    };
    if(!cnt){
        cout << "0";
    }else{
        sort(v.begin(), v.end());
        for(int val : v){
        cout << val << " ";
        }
    }
    return 0;
}