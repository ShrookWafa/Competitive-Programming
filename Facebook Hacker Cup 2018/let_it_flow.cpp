#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

char grid[3][1001];
int mem[4][4][4][1004];
int n;
const int mod = 1e9+7;

ll solve(int prev, int cur, int i, int j){
    int &ret = mem[prev][cur][i][j];
    if(ret!=-1) return ret;

    if(i>=3 || i<0 || j>=n || j<0) return ret=0;
    if(grid[i][j]=='#') return ret=0;

    if(j==n-1 && i==2 && cur==2) return ret=1;

    //cout << prev << " " << cur << " " << i << " " << j << endl;

    ret = 0;
    if(prev==0 && cur==1) ret = (ret+solve(cur,2,i+1,j))%mod;
    if(prev==0 && cur==3) ret = (ret+solve(cur,0,i-1,j))%mod;

    if(prev==1 && cur==2) ret = (ret+(solve(cur,3,i,j+1)+solve(cur,1,i,j+1))%mod)%mod;

    if(prev==2 && cur==1) ret = (ret+solve(cur,2,i+1,j))%mod;
    if(prev==2 && cur==3) ret = (ret+solve(cur,0,i-1,j))%mod;

    if(prev==3 && cur==0) ret = (ret+(solve(cur,1,i,j+1)+solve(cur,3,i,j+1))%mod)%mod;

    return ret%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //freopen("let_it_flow.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t=1, T;
    cin >> T;
    while(t<=T){
        memset(mem,-1,sizeof mem);
        cin >> n;
        for(int i=0; i<3; i++){
            for(int j=0; j<n; j++){
                cin >> grid[i][j];
            }
        }
        cout << "Case #" << t << ": " << solve(0,1,0,0) << endl;
        t++;
    }


    return 0;
}
