#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
    freopen("out.txt", "w", stdout);

    int n, m;
    while(cin >> n >> m){
        ll a[n][m], dp[n][m], trace[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> a[i][j];
                if(j==m-1) dp[i][j] = a[i][j];
                else dp[i][j] = 1e12;
            }
        }

        if(n==1){
            ll total = 0;
            for(int j=0; j<m; j++){
                total += a[0][j];
            }
            for(int j=0; j<m; j++){
                cout << "1";
                if(j < m-1) cout << " ";
            }
            cout << endl;

            cout << total << endl;

            continue;
        }

        for(int j=m-2; j>=0; j--){
            for(int i=0; i<n; i++){
                // at the beginning, set the best path to be coming from
                // the same row then check for better ones
                ll val = dp[i][j+1];
                trace[i][j] = i;
                // get minimum back value and its index
                if(i==0){
                    if(val > dp[i+1][j+1]){ // i+1 is fine because n > 1 at this point
                        val = dp[i+1][j+1];
                        trace[i][j] = i+1;
                    }
                    if(val > dp[n-1][j+1]){
                        val = dp[n-1][j+1];
                        trace[i][j] = n-1;
                    }
                }else if(i==n-1){
                    if(val >= dp[i-1][j+1]){// i-1 is fine also because n > 1
                        val = dp[i-1][j+1];
                        trace[i][j] = i-1;
                    }
                    if(val >= dp[0][j+1]){
                        val = dp[0][j+1];
                        trace[i][j] = 0;
                    }
                }else{
                    if(val > dp[i+1][j+1]){
                        val = dp[i+1][j+1];
                        trace[i][j] = i+1;
                    }
                    if(val >= dp[i-1][j+1]){
                        val = dp[i-1][j+1];
                        trace[i][j] = i-1;
                    }
                }

                dp[i][j] = val + a[i][j];
            }
        }
        // check from starting point that lead to minimum value
        // we made the computation from the back in order to get
        // the lexicographically smallest path
        int start;
        ll mn = 1e12;
        for(int i=0; i<n; i++){
            if(mn > dp[i][0]){
                mn = dp[i][0];
                start = i;
            }
        }

        // + 1 becase we're zero indexed
        cout << start + 1;
        for(int j=0; j<m-1; j++){
            cout << " " << trace[start][j] + 1;
            start = trace[start][j];
        }
        cout << endl;

        cout << mn << endl;
    }
}
