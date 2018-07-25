#include <bits/stdc++.h>

using namespace std;

bool contain(string s1, string s2){
    int i=0, j=0;
    while(1){
        if(i>=s1.length()) return true;
        if(j>=s2.length()) return false;
        if(s1[i]==s2[j]){
            i++; j++; continue;
        }
        if(i==0){
            j++; continue;
        }
        i=0;
    }
}

int main()
{
    //freopen("ethan_searches_for_a_string.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t=1, T;
    cin >> T;
    while(t<=T){
        string s1,s2="";
        cin >> s1;
        int b[26]={0},cnt=0;
        char c = s1[0];
        cout << "Case #" << t << ": ";
        int f=0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i]==c && i) f = 1;
            if(!f) s2 += s1[i];
        }
        s2 += s1;
        if(contain(s1,s2)){
            cout << "Impossible" << endl;
        }
        else {
            cout << s2 << endl;
        }
        t++;
    }
    return 0;
}
