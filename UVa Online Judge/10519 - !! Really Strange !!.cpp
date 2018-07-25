#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string longDivision(string number, int divisor){
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
       temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx){
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    if (ans.length() == 0)
        return "0";
    return ans;
}

string multiplication(string s1, string s2){
    int a[101],b[101],ans[201]={0};
    int i,j=0,tmp;
    int l1 = s1.length();
    int l2 = s2.length();
    for(i = l1-1,j=0;i>=0;i--,j++){
        a[j] = s1[i]-'0';
    }
    for(i = l2-1,j=0;i>=0;i--,j++){
        b[j] = s2[i]-'0';
    }
    for(i = 0;i < l2;i++){
        for(j = 0;j < l1;j++){
            ans[i+j] += b[i]*a[j];
        }
    }
    for(i = 0;i < l1+l2;i++){
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0;i--){
        if(ans[i] > 0)
            break;
    }
    string answer="";
    for(;i >= 0;i--){
        answer += ans[i]+'0';
    }
    return answer;
}

int main()
{
    string n;
    while(cin >> n){
        if(n.length()==1 && n[0]=='0'){
            cout << 1 << endl;
            continue;
        }
        if(n.length()==1 && n[0]=='1'){
            cout << 2 << endl;
            continue;
        }

        string m = n;
        int carry = 1;
        for(int i=m.length()-1; i>=0; i--){
            if(carry){
                if(m[i]=='0'){
                    m[i]='9';
                }else{
                    m[i]--;
                    carry=0;
                }
            }
        }
        string ss2 = multiplication(n,m);
        carry = 2;
        for(int i=ss2.length()-1; i>=0; i--){
            if(carry==2){
                if(ss2[i]=='9')
                    ss2[i]='1', carry=1;
                else if(ss2[i]=='8')
                    ss2[i]='0', carry=1;
                else{
                    ss2[i]++;
                    ss2[i]++;
                    carry=0;
                }
            }
            if(carry==1){
                if(ss2[i]=='9'){
                    ss2[i]='0';
                }else{
                    ss2[i]++;
                    carry=0;
                }
            }
        }
        cout << ss2 << endl;
    }
    return 0;
}
