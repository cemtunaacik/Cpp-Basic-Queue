#include<iostream>
using namespace std;

#define size 5

struct queue{
	int data[size];
	int head = -1;
	int tail = -1;
	
	void enqueue(){
		if (tail < size - 1){
			int value;
			cout << "\nEnter the element you want to enqueue -> ";
			cin >> value;
			if (head == -1){
				head++;
				tail++;
				data[head] = value;
			}
			else{
				tail++;
				data[tail] = value;
			}
		cout << "\nElement has been enqueued\n";
		}
		else
			cout << "\nQueue is full (enqueue)\n";
	}
	void dequeue(){
		if (head == -1)
			cout << "\nQueue is already empty (dequeue)\n";
		else if (head == tail){
			cout << endl << data[head] <<" has been deququed and queue is now empty\n";
			head = -1;
			tail = -1;
		}
		//else if (head != -1){
		else{
			cout << endl << data[head] <<" has been dequeued\n";
			head++;
		}
	}
	void clear(){
		head = -1;
		tail = -1;
		cout << "\nQueue has been cleared\n";
	}
	void front(){
		if (head != -1)
			cout << "\nThe head of the queue is " << data[head] << endl;
		else
			cout << "\nQueue is empty (front)\n";
	}	
	void print(){
		if(head == -1)
			cout << "\nQueue is empty (print)\n";
		else{
			int i = head;
			while (i <= tail){
				cout << endl << i - head + 1 << ". Element -> " << data[i];
				i++;
			}
			cout << endl;
		}

	}
	void status(){
		if (head != -1)
			cout << "\nQueue contains " << tail - head + 1 << " element(s) and has " << size - tail - 1 << " empty slots\n";
		else
			cout << "\nQueue is empty and has " << size << " empty slots\n";
	}
};

int main(){
	queue example;
	int menu = 1;
	while (menu){
		cout << "\n0 - Quit\n1 - Enqueue\n2 - Dequeue\n3 - Clear\n4 - Front\n5 - Print\n6 - Status\nYour input -> ";
		cin >> menu;
		switch (menu){
			case 0:
				cout << "\nQuitting...\n";
				break;
			case 1:
				example.enqueue();
				break;
			case 2:
				example.dequeue();
				break;
			case 3:
				example.clear();
				break;
			case 4:
				example.front();
				break;
			case 5:
				example.print();
				break;
			case 6:
				example.status();
				break;
			default:
				cout << "\nPlease enter a valid input\n";
		}
	}
}

