#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define all(a) begin(a), end(a)
#define sort(a) sort(all(a))
vi parent;
vi sz;
void init(int n){
    for(int i = 0; i < n; i++){
        parent.push_back(i);
        sz.push_back(1);
    }
}
int find(int node){
    if(parent[node] != node){
        parent[node] = find(parent[node]);
    }
    return parent[node];
}
void merge(int nodeA, int nodeB){
    int repA = find(nodeA);
    int repB = find(nodeB);
    if(sz[repA] > sz[repB]){
        parent[repB] = parent[repA];
        sz[repA] = sz[repA]+sz[repB];
    } else {
        parent[repA] = parent[repB];
        sz[repB] = sz[repA]+sz[repB];
    }
}
