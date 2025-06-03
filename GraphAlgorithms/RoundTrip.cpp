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
bool cycle = false;
int cycleAt = -1;

bool dfs(vi graph[], vector<bool> &visited, unordered_map<int, int> &path, 
                        int start, int prev) {
    visited[start] = true;
    for(int c : graph[start]) {
        if(!cycle) {
            if(!visited[c]) {
                path[c] = start;
                dfs(graph, visited, path, c, start);
            } 
            else if(visited[c] && c != prev) {
                path[c] = start;
                cycle = true;
                cycleAt = start;
                return true;
            }
        }
    }
    if (cycle)
        return true;
    else
        return false;
}

void solve() {
    int n,m, a,b;
    cin>>n>>m;
    vi graph[n+1];
    vector<bool> visited(n+1, false);
    unordered_map<int, int> path;
    bool possible = false;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
       if(!cycle && !visited[i]) {
            possible = dfs(graph, visited, path, i, i);
       }
    }
    if(possible) {
        int j = cycleAt;
        vi ans; int len=1;
        while(path[j] != cycleAt) {
            ans.push_back(j);
            j = path[j];
            len++;
        }
        ans.push_back(j);
        ans.push_back(cycleAt);
        cout<<len+1<<endl;
        printall(ans);
    } else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("E:/CSES/DynamicProgramming/test_input.txt", "r", stdin);
    // freopen("E:/CSES/DynamicProgramming/test_output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}