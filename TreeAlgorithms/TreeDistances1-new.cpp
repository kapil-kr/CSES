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
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<long, long> pl;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<pll> vpll;

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

int dfs(vi tree[], int start, int prev, vi &height) {
    int sum = -1;
    for(int child: tree[start]) {
        if(child != prev) {
            sum =  max(dfs(tree, child, start, height), sum);
        }
    }
    sum +=1;
    height[start] = sum;
    return sum;
}

vi calcDistances(vi tree[], int start, vi height) {
    //<child, parent>
    queue<pi> table;
    unordered_map<int, int> pathNode;
    vi distances(height.size());
    vi minDistance1(height.size());
    vi minDistance2(height.size());
    minDistance1[1]=2;
    minDistance2[1]=1;
    table.push({2,1});
    table.push({3,1});
    pathNode[1] = 3;
    //table.push({start, start});

    while (!table.empty()) {
        pi r = table.front();
        table.pop();
        int maxHeight =INT_MIN;
        int pNode;
        vpi childDistances;
        for(int child: tree[r.first]) {
            childDistances.push_back({height[child], child});
            if(child != r.second) {
                table.push({child, r.first});
            }
        }
        
        if(childDistances.size() > 0) {
            sort(childDistances.begin(), childDistances.end(), greater<pi>());
            pNode = childDistances[0].second;
            minDistance1[r.first] = childDistances[0].first;
            if(childDistances.size() > 1)
                minDistance2[r.first] = childDistances[1].first;
        }

        if(pathNode[pNode] != r.first) {
            distances[r.first] = minDistance1[pNode] +1;
            minDistance1[r.first]++;
        } else {
            distances[r.first] = minDistance2[pNode] +1;
            minDistance2[r.first]++;
        }
        
        pathNode[r.first] = pNode;
    }    
    printall(minDistance1);
    cout<<endl;
    printall(minDistance2);
    cout<<endl;
    return distances;
}

// Tree Diameter DP
void solve() {
    int n, a,b;
    cin>>n;
    vi tree[n+1];
    for(int i=1; i<=n-1; i++) {
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vi height(n+1, 0);
    dfs(tree, 1, 1, height);
    printall(height);
    cout<<endl;
    vi distances = calcDistances(tree, 1, height);
    printall(distances);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("E:/CSES/TreeAlgorithms/test_input.txt", "r", stdin);
    // freopen("E:/CSES/TreeAlgorithms/test_output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}