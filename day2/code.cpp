#include<bits/stdc++.h>
using namespace std;

bool isRepeated(string s) {
    string t = s + s;
    size_t pos = t.find(s, 1);
    return pos != string::npos && pos < s.size();
}

int main(){
    ifstream file("input.txt");
    string line;
    long long s;
    string left;
    string right;
    long long e;
    string str;
    long long sum = 0;
    getline(file , line);
    stringstream ss(line);
    string l;
    while(getline(ss , l , ',')){
        int pos = (int)l.find('-');
        s = stoll(l.substr(0 , pos));
        e = stoll(l.substr(pos+1));
        for(long long i=s;i<=e;i++){
            str = to_string(i);
            // if (str.length() % 2 != 0) continue; 
            // left = str.substr(0 , str.length()/2);
            // right = str.substr(str.length()/2);
            // if(left==right){
            //     sum+=i;
            // }
            if(isRepeated(str)){
                sum+=i;
            }
        }
    }
    cout<<sum;
    file.close();
    return 0;
}