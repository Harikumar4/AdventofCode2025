#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("input.txt");
    string line;
    long long value;
    long long sum=0;
    // while(getline(file , line)){
    //     char maxs = *max_element(line.begin() , line.end());
    //     int pos = line.find(maxs);
    //     if(pos==line.length()-1){
    //         char maxm = *max_element(line.begin() , line.end() - 1);
    //         value  = (maxm - '0') * 10 + (maxs - '0');
    //     }else{
    //         char maxm = *max_element(line.begin()+pos+1 , line.end());
    //         value  = (maxs - '0') * 10 + (maxm - '0');
    //     }
    //     sum+=value;
        
    // }
    while (getline(file, line)) {
        string number = "";
        int pos = -1;
        int k = 12;
        int n = line.size();

        for (int i = 0; i < k; i++) {
            int remaining = k - (i + 1);
            int start = pos + 1;
            int end = n - remaining;
            auto it = max_element(line.begin() + start, line.begin() + end);
            number += *it;
            pos = distance(line.begin(), it);
        }

        value = stoll(number);
        sum += value;
    }
    cout<<sum;
    return 0;
}