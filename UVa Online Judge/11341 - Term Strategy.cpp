#include <bits/stdc++.h>
using namespace std;


main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        int a[n][m+1], dp[n][m+1]; //dp -> course:remainingHours
        
        for(int i=0; i<n; i++){
            dp[i][0] = -1e9;
            for(int j=1; j<=m; j++){
                cin >> a[i][j];
                dp[i][j] = -1e9;
            }
        }
        // first course's dp is the grade value
        for(int j=1; j<=m; j++){
            dp[0][m-j] = a[0][j];
            if(a[0][j] < 5) dp[0][m-j] = -1e9;
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<=m; j++){
                for(int k=j; k<=m; k++){
                    dp[i][k-j] = max(dp[i][k-j], dp[i-1][k] + a[i][j]);
                    if(a[i][j]<5) dp[i][k-j] = -1e9;
                }
            }
        }

        int mx = 0;
        for(int j=0; j<=m; j++){
            mx = max(mx, dp[n-1][j]);
        }

        if(mx == 0) cout << "Peter, you shouldn't have played billiard that much." << endl;
        else cout << fixed << setprecision(2) << "Maximal possible average mark - " << (double)mx/(double)n + 1e-8 << ".\n";
        // stupid double addition at the end

    }

}
