#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

template <typename T> string tostr(const T& t) {
   ostringstream os;
   os<<t;
   return os.str();
}

// Complete the solve function below.
string solve(vector<vector<string>> reservations) {
    int st[3][13][32],en[3][13][32];
    memset(st,0,sizeof st);
    memset(en,0,sizeof en);

    for(int i=0; i<reservations.size(); i++){
        for(int j=0; j<2; j++){
            stringstream ss(reservations[i][j]);
            int y,m,d;
            char c1,c2;
            ss >> y >> c1 >> m >> c2 >> d;
            y = y-2018;
            if(!j) st[y][m][d]++;
            else en[y][m][d]++;
        }
    }
    int cnt=0,mx=0;
    string sol;
    for(int y=0; y<3; y++){
        for(int m=1; m<=12; m++){
            for(int d=1; d<=31; d++){
                if(m==2 && d>29 && y==2) break;
                if(m==2 && d>28 && y!=2) break;
                if((m==4 || m==6 || m==9 || m==11) && d==31) break;
                cnt += st[y][m][d];
                if(mx<cnt){
                    mx = cnt;
                    sol = "";
                    sol += tostr(y+2018) + '-';
                    if(m<10) sol += '0';
                    sol += tostr(m) + '-';
                    if(d<10) sol += '0';
                    sol += tostr(d);
                }
                cnt -= en[y][m][d];
            }
        }
    }
    return sol;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<string>> reservations(n);

        for (int i = 0; i < n; i++) {
            reservations[i].resize(2);

            string reservations_row_temp_temp;
            getline(cin, reservations_row_temp_temp);

            vector<string> reservations_row_temp = split(rtrim(reservations_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                string reservations_row_item = reservations_row_temp[j];

                reservations[i][j] = reservations_row_item;
            }
        }

        string result = solve(reservations);

        fout << result << "\n";
    }

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
