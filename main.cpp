#include <iostream>
#include <thread>
#include <chrono>
//#include <mutex>
using namespace std;
struct args{
    int* greg;
    int a;
};
//Our Array Mutex
mutex mtx;

void task(struct args myArg){
    //mutex
    int a =myArg.a;
    mtx.lock();
    myArg.greg[a]= a;
    mtx.unlock();
    //unlock
}
void multiT(){
    int arr [10] = {0,0,0,0,0,0,0,0,0,0};
    thread threads[10];
    for(int i = 0; i < 10; i++){
        args funArg = {arr,i};
        threads[i] = thread(task,funArg);
    }
    for(int i = 0 ; i < 10; i++){
        threads[i].join();
    }
    for(int i : arr){
        cout << i<<endl;
    }


}

int recur(int a){
    //Base condition
    if(a==0){
        return 1;
    }
    return recur(a-1)*a;
}
int binary(int arr[],int x,int high){
    int lo = 0;
    //NEed to recalculate this
    int mid = (lo+high)/2;
    while(mid>=0 && mid < high){
        if(arr[mid]==x){
            return mid;
        }else if(arr[mid]<x) {
            lo =mid;
            mid = (lo+high)/2;
        }else if(arr[mid]>x) {
            high=mid;
            mid = (lo+high)/2;
        }
    }
    //Reaches this if not found
    return -1;
}
//Function to literally just run binary search tests
void runBinary(){
    int arr[10]= {3,5,9,12,17,32,44,65,71,73};
    int high =  sizeof(arr) / sizeof(arr[0]);

    cout << "RUNNING TESTS:\n";
    cout <<"The Answer is: "<< binary(arr,71,high) << '\n';
    cout <<"The Answer is: "<< binary(arr,73,high) << '\n';
    cout <<"The Answer is: "<<  binary(arr,3,high) << '\n';
    cout <<"The Answer is: "<<  binary(arr,-1,high) << '\n';


}



int main() {
    //Linked Lists

    return 0;
}
