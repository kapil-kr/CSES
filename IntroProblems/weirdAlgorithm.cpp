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


int main() {
    ll n;
    cin>>n;
    cout<<n <<" ";
    while(n != 1) {
        if(n%2 == 0)
            n /= 2;
        else {
            n *= 3;
            n++;
        }
        cout<<n<<" ";
    }
}