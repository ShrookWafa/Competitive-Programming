#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 100000007;
const int maxn = 10000001;
ll phi[maxn],fact[maxn];
bool prime[maxn];

void pre(void){
    memset(prime, true, sizeof prime);
    for(int p=2; p*p<maxn; p++){
        if (prime[p] == true){
            for (int i=p*2; i<maxn; i += p)
                prime[i] = false;
        }
    }
    phi[1]=fact[0]=fact[1]=1;
    for(int i=2; i<maxn; i++){
        phi[i] = (phi[i-1] * (prime[i] ? i-1 : i))%mod;
        fact[i] = (fact[i-1]*i)%mod;
    }
}

ll power(ll base, ll power) {
    ll result = 1;
    while(power > 0) {
        if(power&1)
            result = (result*base) % mod;
        base = (base * base) % mod;
        power = power / 2;
    }
    return result;
}

int main()
{
   //freopen("out.txt","w",stdout);

   pre();
   ll n, m;
   while(cin >> n >> m && (n && m)){
        cout << ((phi[m]*fact[n])%mod*power(fact[m],mod-2))%mod-1 << endl;
   }

    return 0;
}
