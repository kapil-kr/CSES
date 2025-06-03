#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(x), x.end()
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
    int n;
    cin>>n;
    if(n == 3 || n==2)
        cout<<"NO SOLUTION";
    else if (n == 4)
    {
        cout<<"3 1 4 2";
    }
    else {
        for(int i=1; i<=n; i+=2) {
            cout<<i<<" ";
        }
        for(int i=2; i<=n; i+=2) {
            cout<<i<<" ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}