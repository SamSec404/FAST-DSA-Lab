#include<iostream>
using namespace std;

class Queue{
	
	int size;
	int * arr;
	int * rear;
	int * front;
	int existingElements;
public:
	Queue(int n) {
		size = n;
		arr = new int[size];
		existingElements = 0;
		front = arr;
		rear = arr;
	}
	bool isFull() {
		if (size == existingElements) {
			return true;
		}
		return false;
	}
	
	bool isEmpty() {
		if (existingElements == 0) {
			return true;
		}
		return false;
	}
	
	void enqueue(int n) {
		if (isFull()) {
			cout<<"The queue is full"<<endl;
			return;
		}
		if (existingElements == 0) {
			rear = front = arr;
			*rear = n;
			++existingElements;
			return;
		}
		if (rear == (arr+size-1)){
			if (front!=arr) {
				rear = arr;
				*rear = n;
				++existingElements;
				return;
			}
		}
		++rear; 
		*rear = n;
		++existingElements;
	}
	
	void dequeue() {
		if (isEmpty()) {
			cout<<"The queue is empty";
			return; 
		}
		if (front == (arr+size-1)) {
			front = arr;
			existingElements--;
			return;
		}
		front++;
		--existingElements;
	}
	void print(){
        if(isEmpty()){
            cout<<"Empty queue"<<endl;
            return;
        }
//        int *temp=arr;
        
        for(int * i=front;i<(arr+existingElements);i++){
            cout<<*i<<" ";
        }
    }
    
    void printRear() {
    	if (isEmpty()) {
    		cout<<"The queue is empty"<<endl;
			return;
		}
		cout<<endl;
		cout<<"The rear is "<<*rear;
	}
	
};

int main() {

	Queue obj = Queue(5);
	obj.enqueue(5);
	obj.enqueue(8);
	obj.enqueue(9);
	obj.enqueue(2);
	obj.enqueue(1);
	obj.dequeue();
	obj.enqueue(7);
	obj.print();
	obj.printRear();

return 0;
}
