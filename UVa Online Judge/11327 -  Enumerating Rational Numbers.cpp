#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll primes[500001],phi[500001],cum[500001];

void phi_generator(void){
   for(int i=0; i<500001; i++) primes[i]=1, phi[i]=1;
   primes[0]=primes[1]=phi[0]=0;
   for(int i=2; i<500001; i++){
        if(primes[i]){
            phi[i]=i-1;
            for(int j=i*2; j<500001; j+=i){
                primes[j]=0;
                ll n=j, pow=1;
                while(!(n%i)) pow*=i, n/=i;
                phi[j] *= (pow/i)*(i-1);
            }
        }
   }
   cum[0]=phi[0];
   for(int i=1; i<500001; i++) cum[i]=cum[i-1]+phi[i];
}

int bisearch(ll n){
    int low = 0, high = 1000001, mid;
    while(low<high){
        mid = (low+high)/2;
        if(cum[mid]==n) return mid;
        else if(cum[mid]>n) high = mid-1;
        else low = mid+1;
    }
    while(cum[mid]>n) mid--;
    while(cum[mid]<n) mid++;
    return mid;
}

ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
   //freopen("out.txt","w",stdout);

   phi_generator();
   ll n;
   while(cin >> n && n){
        if(n==1){
            cout << "0/1" << endl;
            continue;
        }
        if(n==2){
            cout << "1/1" << endl;
            continue;
        }
        n--;
        int it = bisearch(n);
        ll cnt = phi[it] - cum[it] + n;
        int i;
        for(i=1; i<it; i++){
            if(gcd(i,it)==1){
                cnt--;
            }
            if(!cnt) break;
        }
        cout << i << "/" << it << endl;


   }

    return 0;
}
