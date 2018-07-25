#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    while (cin >> n && n>=0){
        int mx = 0, f = 0;
        for (int i=2; i*i<=n+10; i++){
            int temp = n, cnt = 0;
            while(temp%i==1 && temp>=0){
                temp -= temp/i + 1;
                cnt++;
                if (temp%i==0 && cnt==i){
                    f = 1;
                    mx = i;
                    break;
                }
            }
        }
        if(f) printf("%d coconuts, %d people and 1 monkey\n",n,mx);
        else printf("%d coconuts, no solution\n",n);
    }
}
