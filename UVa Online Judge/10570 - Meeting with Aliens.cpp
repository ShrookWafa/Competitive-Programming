#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[501],cyc[501],ind[501],n;

int CW(int idx){
    for(int i=1; i<=n; i++){
        int t = i+idx;
        if(t > n) t -= n;
        cyc[t]=i;
    }
    int cnt=0;
    int vis[501]={0};
    for(int i=1; i<=n; i++){
        if(vis[i] || arr[i]==cyc[i]) continue;

        int cycle_size = 0, j=i;
        while(!vis[j]){
            vis[j]=1;
            j = ind[cyc[j]];
            cycle_size++;
        }
        cnt += (cycle_size-1);
    }

    return cnt;
}
int CCW(int idx){
    for(int i=1; i<=n; i++){
        int t = i+idx;
        if(t > n) t-=n;
        cyc[t]=n-i+1;
    }
    int cnt=0;
    int vis[501]={0};
    for(int i=1; i<=n; i++){
        if(vis[i] || arr[i]==cyc[i]) continue;

        int cycle_size = 0, j=i;
        while(!vis[j]){
            vis[j]=1;
            j = ind[cyc[j]];
            cycle_size++;
        }
        cnt += (cycle_size-1);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("out.txt","w",stdout);

    while(cin>>n && n){
        for(int i=1; i<=n; i++){
            cin >> arr[i];
            ind[arr[i]]=i;
        }
        int ans=5005;
        for(int i=0; i<n; i++){
            ans = min(ans,min(CW(i),CCW(i)));
        }
        cout << ans << endl;
    }


    return 0;
}
