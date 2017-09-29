#include <bits/stdc++.h> 
using namespace std;

const int MAX_N = 20000 +3;
const int INF = 0x3f3f3f3f;
int n;
vector<int> tree[MAX_N]; // tree[i]表示节点i的相邻节点
int d[MAX_N]; // d[i]表示以i为根的子树的节点个数
 
int minNode;        //重心节点
int minBalance;     //最小的最大孩子数
 
void dfs(int node, int parent) // node and its parent
{
    d[node] = 1; // the node itself
    int maxSubTree = 0; // subtree that has the most number of nodes
    for (int i:tree[node]){
        if (i==parent) continue;
        dfs(son,node);
        d[node]+=d[son];
        maxSubTree = max(maxSubTree, d[son]);
    }
    maxSubTree = max(maxSubTree, n - d[node]); // "upside substree with (N - d[node]) nodes"
    if (maxSubTree < minBalance){
        minBalance = maxSubTree;
        minNode = node;
    }
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (int i = 1; i < N; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        minNode = 0;
        minBalance = INF;
        dfs(1, 0); // fist node as root
        printf("%d %d\n", minNode, minBalance);
    }
    return 0;
}
