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
    int n, m, k;
    int num, count = 0;
    int loc;
    cin>>n;
    cin>>m;
    cin>>k;
    vi demand, apartments, visited;
    for(int i=0; i<n; i++) {
        cin>>num;
        demand.push_back(num);
    }
    sortall(demand);
    for(int i =0; i<m; i++) {
        cin>>num;
        apartments.push_back(num);
    }
    sortall(apartments);
    int i =0, j=0;
    while(i<n && j<m) {
        if(demand[i] + k >= apartments[j] && demand[i] - k <= apartments[j]) {
            count++;
            i++;
            j++;
        }
        else
        {
            if(apartments[j] > demand[i] + k)
                i++;
            else 
                if(apartments[j] < demand[i] - k)
                {
                    j++;        
                }
            
        }
    }
    cout<<count;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // In case reading from file
    //freopen("E:/CSES/SOrtingSearching/test_input.txt", "r", stdin);
    //freopen("E:/CSES/SOrtingSearching/test_output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}