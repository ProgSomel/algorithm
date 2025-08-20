# 1_5 Adjacency Matrix Implementation
## Adjacency Matrix for Undirected Graph
```c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         adj_mat[i][j] = 0;
    //     }
    // }
    memset(adj_mat, 0, sizeof(adj_mat)); //? Same as Above for loop
    //? Making diagonal values to 1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) adj_mat[i][j] = 1;
        }
    }
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```
```bash
//Input
5 5
0 1
0 2
3 0
1 3
3 4

//output
1 1 1 1 0 
1 1 0 1 0 
1 0 1 0 0 
1 1 0 1 1 
0 0 0 1 1 
```

**------------------------------------------------------------------------------------------------------------**

```c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         adj_mat[i][j] = 0;
    //     }
    // }
    memset(adj_mat, 0, sizeof(adj_mat)); //? Same as Above for loop
    //? Making diagonal values to 1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) adj_mat[i][j] = 1;
        }
    }
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```
```bash
//Input
5 5
0 1
0 2
3 0
1 3
3 4

//output
1 1 1 0 0 
0 1 0 1 0 
0 0 1 0 0 
1 0 0 1 1 
0 0 0 0 1
```