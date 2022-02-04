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

// On a tree
void dfs1(int curr, int prev, vvi &adj){
    for(int next : adj[curr]){
        if(next != prev){
            dfs1(next, curr, adj);
        }
    }
}

// Not on a tree
void dfs2(int curr, vvi &adj, vi &visited){
    visited[curr] = true;
    for(int next : adj[curr]){
        if(!visited[next]){
            dfs2(next, adj, visited);
        }
    }
}

// Weighted tree
void dfs3(int curr, int prev, vector<vector<pii>> &adj){
    for(auto p : adj[curr]){
        int next = p.first;
        int w = p.second;
        if(next != prev){
            dfs3(next, curr, adj);
        }
    }
}

// Weighted non-tree
void dfs4(int curr, vector<vector<pii>> &adj, vi &visited){
    visited[curr] = true;
    for(auto p : adj[curr]){
        int next = p.first;
        int w = p.second;
        if(!visited[next]){
            dfs4(next, adj, visited);
        }
    }
}
