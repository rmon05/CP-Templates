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

const int N;
vi fenwick(N);
int len(int pos){
    return pos & -pos;
}
void update(int pos, int diff){
    while(pos <= N){
        fenwick[pos] += diff;
        pos += len(pos);
    }
}
int query(int pos){
    int sum = 0;
    while(pos > 0){ 
        sum += fenwick[pos];
        pos -= len(pos);
    }
    return sum;
}
