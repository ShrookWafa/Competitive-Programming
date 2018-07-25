#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll H,W;
    while(cin >> H >> W && !(H==0 && W==0)){
        double x = 1.0;
        if(H==1 && W==1){
            cout << "0 1" << endl;
            continue;
        }
        while(H > (ll) ( pow( pow(W,1.0/x) +1, x) + 0.001) )
            x = x + 1.0;

        ll n = pow(W,1.0/x)+0.001;
        ll cnt;
        if(n!=1)
            cnt = (W-1)/(n-1);
        else
            cnt = x;
        ll sum = H + W;
        for(int i=1; i<x; i++){
            sum += H/(ll)(pow(n+1,i)+0.001) * (ll)(pow(n,i)+0.001);
        }
        cout << cnt << " " << sum << endl;
    }

    return 0;
}
