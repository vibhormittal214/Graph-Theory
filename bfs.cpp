#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int front=-1,rear=-1;
int queue1[MAX];
int state[MAX];
int underflow(){
   if(front==-1 || front==rear+1)
    return 1;
   else
    return 0;

}
int full(){
    if(rear==MAX-1)
        return 1;
    else
        return 0;
}
int pop(){
   if(underflow()){
    return -999;
   }
   else{
        int item;
      item=queue1[front];
      front=front+1;
      return item;
   }
}
void insert1(int item){
    if(full())
    return;
    if(front==-1)
        front=0;
    rear=rear+1;
    queue1[rear]=item;
    //cout<<item;
}

int main(){
    int *m;
    int j;
    for(j=0;j<9;j++)
        state[j]=0;
     int arr[9][9]={0,1,0,1,1,0,0,0,0,
                    0,0,1,0,1,0,0,0,0,
                    0,0,0,0,0,1,0,0,0,
                    0,0,0,0,1,0,1,0,0,
                    0,0,0,0,0,1,0,1,0,
                    0,0,0,0,0,0,0,0,0,
                    0,0,0,0,1,0,0,1,0,
                    0,0,0,0,0,1,0,0,1,
                    0,0,0,0,0,0,0,0,0};
    int *visited;
    visited=new int[8];
    int vis=0;
    int current=0;
    insert1(0);
    int i;
    while(!underflow()){
        current=pop();
        cout<<current<<" ";
        state[current]=2;
        for(i=0;i<9;i++){
            if(arr[current][i]==1 && state[i]==0){
                    insert1(i);
                    //cout<<i;
                    state[i]=1;
            }
        }
    }
    return 0;
}
