#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //freopen("ethan_finds_the_shortest_path.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t=1, T;
    cin >> T;
    while(t<=T){
        int n,k;
        cin >> n >> k;
        int a = (k*(k-1)/2) - k - ((k-n)*(k-n+1)/2);
        if(k<=n) a = (k*(k-1)/2 - k);
        cout << "Case #" << t << ": " << max(a,0) << endl;

        if(a<=0){
            cout << 1 << endl;
            cout << 1 << " " << n << " " << 1 << endl;
            t++;
            continue;
        }

        cout << min(n,k) << endl;
        cout << 1 << " " << n << " " << k << endl;
        int i;
        int K = k;
        for(i=1; i<min(n,k)-1; i++){
            cout << i << " " << i+1 << " " << --K << endl;
        }
        cout << i << " " << n << " " << --K << endl;
        t++;
    }

    return 0;
}
