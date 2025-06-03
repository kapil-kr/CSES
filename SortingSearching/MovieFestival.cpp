#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626

typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef pair<int,int> pi;
typedef pair<long, long> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;

void solve() {
    int n, a, b;
    int count =0;
    vector<pair<int, int>> I;
    cin>>n;
    for( int i=0; i<n; i++) {
        cin>>a>>b;
        I.push_back(make_pair(b, a));
    }
    sortall(I);
    int pivot = I[0].first;
    count++;
    for(int i=1; i<n; i++) {
        if(I[i].second >= pivot) {
            pivot = I[i].first;
            count++;
        }
    }
    cout<<count;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        // In case reading from file
        // freopen("E:/CSES/SOrtingSearching/test_input.txt", "r", stdin);
        // freopen("E:/CSES/SOrtingSearching/test_output.txt", "w", stdout);
        solve();
    }

    return 0;
}