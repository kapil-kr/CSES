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
    ll row, col;
    cin>>row>>col;
    if(col > row) {
        ll nE = 2*col -1;
        ll nCov = ((col-1) * (1+ (nE - 2)))/2;
        if(col%2 == 0) {
            cout<<nCov+row<<endl;
        }
        else
        {
            cout<<nCov+nE-row+1<<endl;
        }
    }
    else
    {
        ll nE = 2*row -1;
        ll nCov = ((row-1) * (1+ (nE - 2)))/2;
        if(row%2 != 0) {
            cout<<nCov+col<<endl;
        }
        else
        {
            cout<<nCov+nE-col+1<<endl;
        }
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}