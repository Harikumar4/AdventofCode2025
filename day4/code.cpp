#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("input.txt");
    string line;
    vector<string> mat;
    while(getline(file , line)){
        mat.push_back(line);
    }
    vector<pair<int , int >> pos = {{-1 , -1} , {-1 , 0 } , {-1 , 1} , {0 , -1} , {0, 1} , {1 , 0 } , {1 , 1} , {1 , -1}};
    int count = 0;
    int r = mat.size();
    int c = mat[0].size();

    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < c; j++){
    //         if(mat[i][j] != '@') continue;

    //         int v = 0;
    //         for(pair<int,int> p: pos){
    //             int ni = i + p.first;
    //             int nj = j + p.second;
    //             if(ni >= 0 && ni < r && nj >= 0 && nj < c){
    //                 if(mat[ni][nj] == '@'){
    //                     v++;
    //                 }
    //             }
    //         }

    //         if(v < 4){
    //             count++;  
    //         }
    //     }
    // }
    while(true){
        vector<pair<int,int>> rem; 

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] != '@') continue;

                int v = 0;
                for(pair<int,int> p: pos){
                    int ni = i + p.first;
                    int nj = j + p.second;
                    if(ni >= 0 && ni < r && nj >= 0 && nj < c){
                        if(mat[ni][nj] == '@'){
                            v++;
                        }
                    }
                }

                if(v < 4){
                    rem.push_back({i, j});
                }
            }
        }

        if(rem.empty()) break; 
        for(pair<int,int> p : rem){
            mat[p.first][p.second] = '.';
        }

        count += rem.size();
    }

    cout << count << endl;
    return 0;
}