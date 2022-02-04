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

const int n;
vector<bool> isPrime(n+1, true);
vi primes;
void sieve(){
    for(int p = 2; p*p <= n; p++){
        if(!isPrime[p]){
            continue;
        }
        for(int i = p*p; i <= n; i+=p){
            isPrime[i] = false;
        }
    }
    for(int p = 2; p <= n; p++){
        if(isPrime[p]){
            primes.push_back(p);
        }
    }
}
