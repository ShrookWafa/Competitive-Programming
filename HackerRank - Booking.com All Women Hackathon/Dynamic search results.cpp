#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the solve function below.
int solve(vector<int> list1, vector<int> list2) {
    map<int,int>mp1,mp2,special;
    vector<int>l1,l2;

    int sol=0;
    int n = list1.size(), m = list2.size();
    for(int i=0; i<n; i++){
        mp1[list1[i]]=1;
    }
    for(int i=0; i<m; i++){
        if(!mp1[list2[i]]) sol++;
        else l2.push_back(list2[i]);
        mp2[list2[i]]=1;
    }
    for(int i=0; i<n; i++){
        if(!mp2[list1[i]]) sol++;
        else l1.push_back(list1[i]);
    }

    n = l1.size();
    vector<int>arr;
    for(int i=0; i<n; i++){
        special[l2[i]]=i;
    }
    for(int i=0; i<n; i++){
        arr.push_back(special[l1[i]]);
    }
    set<int> st;
    set<int>::iterator it;
    st.clear();
    for(int i=0; i<n; i++) {
      st.insert(arr[i]);
      it=st.find(arr[i]);
      it++;
      if(it!=st.end()) st.erase(it);
    }
    //cout<<st.size()<<endl;

    return sol+(n-st.size());

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split(rtrim(nm_temp));

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string list1_temp_temp;
    getline(cin, list1_temp_temp);

    vector<string> list1_temp = split(rtrim(list1_temp_temp));

    vector<int> list1(n);

    for (int i = 0; i < n; i++) {
        int list1_item = stoi(list1_temp[i]);

        list1[i] = list1_item;
    }

    string list2_temp_temp;
    getline(cin, list2_temp_temp);

    vector<string> list2_temp = split(rtrim(list2_temp_temp));

    vector<int> list2(m);

    for (int i = 0; i < m; i++) {
        int list2_item = stoi(list2_temp[i]);

        list2[i] = list2_item;
    }

    int result = solve(list1, list2);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
