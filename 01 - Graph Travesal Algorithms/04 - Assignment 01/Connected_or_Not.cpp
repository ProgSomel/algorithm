#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n];
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a == b) cout << "YES" << endl;
        else{
            auto it = find(adj_list[a].begin(), adj_list[a].end(), b);
            if(it == adj_list[a].end()) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}