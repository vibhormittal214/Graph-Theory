#include<iostream>
using namespace std;
#define MAX 50
int front=-1;
int status[MAX];
int stack[MAX];
int isfull(){
  if(front==MAX-1)
    return 1;
  else
    return 0;
}
int isempty(){
   if(front==-1)
    return 1;
   else
    return 0;
}
void insert(int item){
   if(isfull())
    return;
   front=front+1;
   stack[front]=item;
   //cout<<stack[front];
}
int del(){
   if(isempty()){
      return -999;
   }
   else{
        int item;
        item=stack[front];
        front=front-1;
        return item;
   }
}
int main(){
    int j;
    for(j=0;j<10;j++){
        status[j]=0;
    }
    int arr[10][10]={ 0,1,0,1,0,0,0,0,0,0,
                    0,0,1,0,1,1,0,0,0,0,
                    0,0,0,1,0,1,0,0,0,0,
                    0,0,0,0,0,0,1,0,0,0,
                    0,0,0,0,0,0,0,1,0,0,
                    0,0,0,0,0,0,1,1,1,0,
                    0,0,0,0,0,0,0,0,0,1,
                    0,0,0,0,0,0,0,0,1,0,
                    0,0,0,0,0,0,0,0,0,1,
                    0,0,0,0,0,0,0,0,0,0};
    insert(0);
    int current,i;
    while(!isempty()){
        current=del();
        if(status[current]==0){
            cout<<current<<" ";
        status[current]=2;}
        for(i=10;i>=0;i--){
            if(arr[current][i]==1 && status[i]==0){
                insert(i);
            }
        }
    }
    return 0;
}
