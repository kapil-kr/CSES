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

int dfs(vi tree[], int start, int prev, vi &height, vi&height2) {
    vi tempHeights;
    for(int child: tree[start]) {
        if(child != prev) {
            //sum =  max(dfs(tree, child, start, height, height2), sum);
            int h = dfs(tree, child, start, height, height2);
            tempHeights.push_back(h);
        }
    }

    if(tempHeights.size() > 0) {
        sort(tempHeights.begin(), tempHeights.end(), greater<int>());
        height[start] = tempHeights[0] +1;
        if(tempHeights.size() > 1)
            height2[start] = tempHeights[1] +1;
        return height[start];
    }
    else
    {
        return 0;
    }
}

// BFS suited well
vi calcDistances(vi tree[], int start, vi height, vi height2) {
    //<child, parent>
    queue<pi> table;
    unordered_map<int, int> pathNode;
    vi distances(height.size());
    table.push({start,start});
    while (!table.empty()) {
        pi r = table.front();
        table.pop();
        int maxHeight =INT_MIN;
        int pNode;
        for(int child: tree[r.first]) {
            if(height[child] > maxHeight) {
                    maxHeight = height[child];
                    pNode = child;
                }
            if(child != r.second) {
                //maxHeight = max(height[child], maxHeight);
                table.push({child, r.first});
            }
        }
        if(pathNode[pNode] == r.first) {
            cout<<"    "<<r.first<<" "<<pNode<<endl;
            distances[r.first] =  height2[pNode]+1;
        } else
        {
            cout<<"11111111  "<<r.first<<pNode<<endl;
            distances[r.first] = height[pNode] +1;
        }
        pathNode[r.first] = pNode;
    }
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
    vi height2(n+1, 0);
    dfs(tree, 1, 1, height, height2);
    printall(height);
    cout<<endl;
    printall(height2);
    cout<<endl;
    vi distances = calcDistances(tree, 1, height, height2);
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