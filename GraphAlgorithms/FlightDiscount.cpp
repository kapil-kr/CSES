#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define printall(x) for(int i=0; i<x.size(); i++) cout<<x[i]<<" ";
#define PI 3.1415926535897932384626

typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef pair<int,int> pi;
typedef pair<long, long> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;

const int mod = 1e9+7;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void dfs(vi graph[], vector<bool> &visited, int start) {
    visited[start] = true;
    for(auto e: graph[start]) {
        if(!visited[e])
            dfs(graph, visited, e);
    }
}

void solve() {
    int n,m, a, b, c;
    cin>>n>>m;
    vpi graph[n+1];
    for( int i=0; i<m; i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    priority_queue<pi, vpi, greater<int>> Q;
    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("E:/CSES/GraphAlgorithms/test_input.txt", "r", stdin);
    // freopen("E:/CSES/GraphAlgorithms/test_output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}