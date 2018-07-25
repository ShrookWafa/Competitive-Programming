#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,arr[20];
const int maxn = 100001;
int phi[maxn], primes[maxn];

void phi_generator(void){
   for(int i=0; i<maxn; i++) primes[i]=1, phi[i]=1;
   for(int i=2; i<maxn; i++){
        if(primes[i]){
            phi[i]=i-1;
            for(int j=i*2; j<maxn; j+=i){
                primes[j]=0;
                int n=j, pow=1;
                while(!(n%i)) pow*=i, n/=i;
                phi[j] *= (pow/i)*(i-1);
            }
        }
   }
}

ll power(ll base, ll power, ll mod) {
    ll result = 1;
    while(power > 0) {
        if(power&1)
            result = (result*base) % mod;
        base = (base * base) % mod;
        power = power / 2;
    }
    return result;
}

int solve(int i, int mod){
    if(i==n-1){
        return arr[i]>=mod ? arr[i]%mod+mod : arr[i];
    }
    return power(arr[i], solve(i+1, phi[mod])+phi[mod], mod);
}

int main()
{
   //freopen("out.txt","w",stdout);

   phi_generator();
   int t=1;
   while(cin >> m >> n){
        for(int i=0; i<n; i++) cin >> arr[i];
        cout << "Case #" << t << ": " << solve(0,m)%m << endl;
        t++;
   }

    return 0;
}
