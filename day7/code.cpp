// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     ifstream file("input.txt");
//     string line;
//     vector<string> lines;
//     while(getline(file , line)){
//         lines.push_back(line);
//     }
//     int count = 0;
//     int n = lines.size();
//     int m = lines[0].size();
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<m;j++){
//             if(lines[i][j]=='|'){
//                 if(lines[i+1][j]=='^'){
//                     count++;
//                     if(j>=1){
//                         lines[i+1][j-1]='|';
//                     }
//                     if(j<m-1){
//                         lines[i+1][j+1]='|';
//                     }
//                 }else{
//                     lines[i+1][j]='|';
//                 }
//             }else if(lines[i][j]=='S'){
//                 lines[i+1][j]='|';
//             }
//         }
//     }
//     cout<<count;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt");
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    int n = lines.size();
    int m = lines[0].size();
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    int s = lines[0].find('S');
    dp[0][s] = 1; 

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == 0) continue;
            if (lines[i+1][j] == '^') {
                if (j > 0) {
                    dp[i+1][j-1] += dp[i][j];
                }
                if (j < m-1) {
                    dp[i+1][j+1] += dp[i][j];
                }
            } 
            else {
                dp[i+1][j] += dp[i][j];
            }
        }
    }

    long long total = 0;
    for (int j = 0; j < m; j++)
        total += dp[n-1][j];

    cout << total << endl;
    return 0;
}
