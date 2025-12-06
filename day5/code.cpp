#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("input.txt");
    string line;
    int count=0;
    vector<pair<long long , long long>> range;
    while(getline(file , line)){
        if(line.find('-')!=string::npos){
            int pos = line.find('-');
            long long s = stoll(line.substr(0 , pos));
            long long e = stoll(line.substr(pos+1));
            range.push_back({s,e});
        }else{
            break;
        }
    }
    int n = range.size();
    while(getline(file , line)){
        long long value = stoll(line);
        for(int i = 0; i < n ; i++){
            if(value>=range[i].first && value<=range[i].second){
                count++;
                break;
            }
        }
    }
    sort(range.begin(), range.end());
    vector<pair<long long,long long>> merged;
    for (pair<long long,long long> p : range) {
        if (merged.empty() || p.first > merged.back().second + 1) {
            merged.push_back(p);
        } else {
            merged.back().second = max(merged.back().second, p.second);
        }
    }
    n = merged.size();
    long long v=0;
    for(int i=0;i<n;i++){
        v+=merged[i].second- merged[i].first + 1; 
    }
    cout<<count<<endl;
    cout<<v;
    return 0;
}