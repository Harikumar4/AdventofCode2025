// #include<bits/stdc++.h>
// using namespace std;

// void appendvector(vector<int>& num , string s){
//     stringstream ss(s);
//     int n;
//     while(ss >> n){
//         num.push_back(n);
//     }
// }
// void appendvectoroperator(vector<char>& arr , string s){
//     stringstream ss(s);
//     char c;
//     while(ss >> c){
//         arr.push_back(c);
//     }
// }
// int main(){
//     ifstream file("input.txt");
//     string line;
//     vector<int> num1;
//     vector<int> num2;
//     vector<int> num3;
//     vector<int> num4;
//     vector<char> op;
//     getline(file , line);
//     appendvector(num1 , line);
//     getline(file , line);
//     appendvector(num2 , line);
//     getline(file , line);
//     appendvector(num3 , line);
//     getline(file , line);
//     appendvector(num4 , line);
//     getline(file , line);
//     appendvectoroperator(op , line);
//     long long total = 0;
//     for(int i = 0; i < num1.size(); i++){
//         long long value = 1;
//         if(op[i] == '+'){
//             value = num1[i] + num2[i] + num3[i] + num4[i];
//         } else{
//             value = num1[i];
//             value *= num2[i];
//             value *= num3[i];
//             value *= num4[i];


//         }
//         total += value;
//     }
//     cout << total;


//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("input.txt");
    string line;
    vector<string> grid;
    while(getline(file,line)){
        if(!line.empty()){
            reverse(line.begin(),line.end());
            grid.push_back(line);
        }
    }
    int rows = grid.size();
    int cols = 0;
    for(auto &s:grid) {
        cols = max(cols,(int)s.size());
    }
    for(auto &s:grid) {
        if((int)s.size()<cols) {
            s += string(cols - s.size(),' ');
        }
    }

    long long total = 0;
    vector<long long> nums;

    for(int c=0;c<cols;c++){
        string num_str = "";
        char op = '?';

        for(int r=0;r<rows;r++){
            char ch = grid[r][c];
            if(isdigit(ch)){
                num_str.push_back(ch);
            }
            else if(ch=='+' || ch=='*') {
                op = ch;
            }
        }

        if(num_str=="") continue;

        long long num = stoll(num_str);
        nums.push_back(num);

        if(op=='+' || op=='*'){
            long long value = (op=='+')?0:1;
            for(long long x:nums){
                if(op=='+') {
                    value += x;
                }
                else{
                    value *= x;
                }
                    
            }
            total += value;
            nums.clear();
        }
    }

    cout << total;
    return 0;
}
