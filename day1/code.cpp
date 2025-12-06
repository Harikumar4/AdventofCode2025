#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node (int x){
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
typedef struct Node* node;

node insertatend(node head , int value){
    node curr = head;
    node newone = new Node(value);
    while(curr->next!=nullptr){
        curr = curr->next;
    }
    curr->next = newone;
    curr->next->prev = curr;
    return head;
}

node moveright(node curr,int pos,int* c){
    int count=0;
    while(count!=pos){
        curr = curr->next;
        count++;
        if(curr->data ==0){
            (*c)++;
        }
    }
    
    return curr;
}

node moveleft(node curr,int pos,int* c){
    int count=0;
    while(count!=pos){
        curr = curr->prev;
        count++;
        if(curr->data ==0){
            (*c)++;
        }
    }

    return curr;
}

int main(){
    ifstream file("input.txt");
    string line;
    int pos=50;
    node head = new Node(0);
    node tail = head;
    node curr = head;
    for(int i=1;i<100;i++){
        insertatend(head , i);
    }
    for(int i=0;i<99;i++){
        tail = tail->next;
        if(i==49){
            curr = tail;
        }
    }
    int count=0;
    tail->next = head;
    head->prev = tail;
    while(getline(file , line)){
        char direction = line[0];
        int value = stoi(line.substr(1));
        if(direction == 'L'){
            curr = moveleft(curr , value,&count);
        }else{
            curr = moveright(curr , value,&count);
        }
    }
    cout<<count;
    file.close();
    return 0;
}