#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double sTd(string s){
    double d;
    stringstream ss(s);
    ss >> d;
    return d;
}

template <typename T> string tostr(const T& t) {
   ostringstream os;
   os<<t;
   return os.str();
}

double rec(string s){
    int n = s.length();
    for (int i=0; i<n; i++){
        if (!isdigit(s[i]) && s[i]!='-' && s[i]!='.') break;
        if (i+1 == n) return sTd(s);
    }
    for (int i=0; i<n; i++){
        if (s[i] == '^'){
            return pow ( rec(s.substr(0, i)), rec(s.substr(i+1)));
        }
    }
    for (int i=n-1; i>=0; i--){
        if (s[i] == '*'){
            return rec(s.substr(i+1)) * rec(s.substr(0, i));
        }
    }
    for (int i=n-1; i>=0; i--){
        if (s[i] == '+'){
            return rec(s.substr(i+1)) + rec(s.substr(0, i));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //freopen("interception.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t=1, T;
    cin >> T;
    while(t<=T){
        int n;
        cin >> n;
        int p[n+1];
        for(int i=0; i<=n; i++){
            cin >> p[i];
        }
        cout << "Case #" << t << ": ";
        if(n%2){
            cout << 1 << '\n' << 0.0 << endl;
        }else{
            cout << 0 << endl;
        }

        t++;
    }

    return 0;
}
