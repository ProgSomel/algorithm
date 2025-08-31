#include<bits/stdc++.h>
using namespace std;

int n, m;

char grid[1003][1003];
bool vis[1003][1003];
int cnt;
vector<int> area;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj){
    
    vis[si][sj] = true;
    cnt++;
    for(int i = 0; i < 4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj]=='.'){
            dfs(ci, cj);
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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j]&& grid[i][j]=='.'){
                cnt = 0;
                dfs(i, j);
                area.push_back(cnt);
            }
        }
    }
    if(area.empty()) cout << "-1";
    else{
        sort(area.begin(), area.end());
        cout << area[0];
    }
    return 0;
}