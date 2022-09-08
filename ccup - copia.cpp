#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define ll long long
#define ss second
#define ff first
#define FOR(x, n) for(int i = x; i < n; i++)
#define FOR2(x, n) for(int j = x; j < n; j++)
#define ROF(x, n) for(int i = x; i > n; i--)
#define pb push_back
#define sz size
#define popb pop_back
#define lin "\n"

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<int, int> mapii;
typedef map<char, int> mapci;
typedef map<string, int> mapsi;

struct UnionFind{
    vector<int> p, rank;
    void init(int n){
        rank.assign(n, 0);
        p.resize(n);
        for(int i = 0; i < n; i++)p[i] = i;
    };
    int findSet(int x){
        if(p[x] != x)return p[x] = findSet(p[x]);
        else return x;
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)
    {
        int x = findSet(i), y = findSet(j);
        if(x != y){
            if(rank[x] > rank[y])p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y])rank[y]++;
            }
        }
    }
};

struct cmp{
    bool operator()(const int &a, const int &b){
        return a > b;
    }
};



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b, t;
    cin>>t;
    while(t--){
        cin>>a>>b>>n;
        vpii v(n);
        FOR(0, n)
            cin>>v[i].ff;
        FOR(0, n)
            cin>>v[i].ss;
        sort(v.begin(), v.end());
        bool no = true;
        FOR(0, n){
            int tmp = v[i].ss + a - 1;
            b = b - (tmp / a * v[i].ff);
            if(b + v[i].ff <= 0){ no = false; break; }
        }
        cout<<(!no? "NO" : "YES")<<lin;
    }



    return 0;
}
