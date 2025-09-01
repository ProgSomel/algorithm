# 9_1 Limitations of Dijkstra and Why we need Bellman-Ford

## Limitations of Dijkstra
If there is a cycle --> Dijkstra can work
If there is a negative weight --> Dijkstra can also work
**But if both present in same time then Dijkstra can not work**
Means if there is **Negative Weighted Cycle(cycle's total weight is Negative)** then it will not work --> It falls into infinite loop

## Why we need Bellman-Ford
To solve this problem we can use Bellman-Ford