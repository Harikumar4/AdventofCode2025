#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("input.txt");
    string line;
    vector<long long> row;
    vector<long long> col;
    int n=0;
    long long r , c;
    string a ,b;
    while(getline(file , line)){
        stringstream ss(line);
        getline(ss , a, ',');
        getline(ss , b);
        c = stoll(a);
        r = stoll(b);
        col.push_back(c);
        row.push_back(r);
        n++;
        cout<<c<<" "<<r<<endl;
    }
    long long maxarea = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long long area = (abs((col[i]-col[j]))+1)*(abs((row[i]-row[j]))+1);
            maxarea = max(maxarea , area);
        }
    }
    cout<<maxarea;
    
    return 0;
}