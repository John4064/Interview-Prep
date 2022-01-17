#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
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

class Node{
    public:
        Node* next;
        std::string value;
        Node(std::string input){
            value=input;
            next= nullptr;
        }
};
class LinkedList{
    public:
        Node* head;

        LinkedList(){
            head = nullptr;
        }

        /**
        * @param: a single linked list
        * @brief: This function reverses a linked list
        */
        void reverseLL(){
            Node* current = head;
            Node* prev = nullptr;
            Node* next = nullptr;
            while(current != nullptr){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
        void printL(){
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->value << ' ';
                temp= temp->next;
            }
        }

        void add(std::string data){
            if(head == nullptr){
                Node n1 = Node(data);
                head=&n1;
            }else{
                //Linked LIst Appendd
                Node* temp = head;
                //BUGGY AF
                while(temp->next != nullptr){
                    temp = temp->next;
                    cout <<"CRASH";
                }
                Node newNod = Node(data);
                temp->next = &newNod;

            }
            //printL();
        }
};
//Just a test function to test our reverse linkedlist
void testReverse(){
    //Linked Lists
    LinkedList ll;
    /*
    Node n1 = Node("ABC");
    Node n2 = Node("DEF");
    Node n3 = Node("GHI");
    Node n4 = Node("JKL");
    Node n5 = Node("MNO");
    ll.head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
     */
    ll.add("ABC");
    ll.add("DEF");
    //ll.add("GHI");
    //ll.add("JKL");
    //ll.add("MNO");
    //ll.reverseLL();
    ll.printL();

}

void selecSort(int* myArr,int size){

    for(int i =0;i <size;i++){
        for(int k = i+1;k<size+1;k++){
            if(myArr[i]>myArr[k]){
                int temp = myArr[i];
                myArr[i]=myArr[k];
                myArr[k]=temp;
            }
        }
    }
    return;
}

void bubbleSort(int* arr, int size){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


int* merge(int* arr,int size, int left, int mid){
    return arr;
}
int* mergeSort(int* arr, int size, int left){
    int right = size;
    int middle = (right-left)/2;
    //first half

    //second half

    //merge the two

    return arr;
}

void printArr(int arr[],int size){
    for(int i =0;i < size; i++){
        cout << arr[i] << ' ';
    }
}

void testSorts(){
    int myArr[] = {4,5,9,1,6,6,55,0,-2,183,3,21,4,5,4,1,61,2,73,32,-22,13,13,241,4,5,92,13,64,66,33,10,-32,143,5,21};
    auto start = chrono::high_resolution_clock::now();
    //bubbleSort(myArr,24);
    int* testArr;
    //testArr = mergeSort(myArr, 36,0);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
    printArr(myArr,36);
    //*.000001 for seconds
    cout << "\nThe Execution Time for it was "<< duration.count() << " microSeconds"<<std::endl;

}

int main() {
    testReverse();
    cout << '\n';
    return 0;
}
