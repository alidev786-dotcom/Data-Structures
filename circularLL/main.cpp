#include<iostream>
using namespace std;


class Node
{
	public:
		int data;
		Node* next;
		Node()
		{
			this->data = -1;
			this->next = nullptr;
		}
		Node(int data)
		{
			this->data = data;
			this->next = nullptr;
		}
};

class CircularLL
{
	public:
		Node* head;
		Node* tail;
		CircularLL()
		{
			this->head = this->tail = nullptr;
		}
		void insertAtLast(int data)
		{
			Node* newNode = new Node(data);
			//if list is empty
			if (this->head == nullptr)
			{
				this->head = newNode;
				this->tail = newNode;
				newNode->next = this->head;
			}
			else
			{
				//using tail
				/*this->tail->next = newNode;
				this->tail = newNode;
				newNode->next = this->head;*/

				//without using tail
				Node* temp = this->head;
				while (temp->next != this->head)
				{
					temp = temp->next;
				}
				temp->next = newNode;
				newNode->next = this->head;
				this->tail = newNode;
			}
		}
		void insertAtFirst(int data)
		{
			//making new node
			Node* newNode = new Node(data);
			//if list is empty
			if (this->head == nullptr)
			{
				this->head = newNode;
				this->tail = newNode;
				newNode->next = this->head;
			}
			//if list is not empty
			else
			{
				newNode->next = this->head;
				this->head = newNode;
				tail->next = this->head; 
			}
		}
		void insertAfter(int data, int newData)
		{
			Node* newNode = new Node(newData);
			//if list is empty
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
			}
			else
			{
				Node* temp = this->head;
				while (temp->next != this->head)
				{
					if (temp->data == data)
					{
						Node* nextNode = temp->next;
						temp->next = newNode;
						newNode->next = nextNode;
						return;
					}
					temp = temp->next;
				}
				//checking if user wants to insert after last node
				if (temp->data == data)
				{
					temp->next = newNode;
					newNode->next = this->head;
					this->tail = newNode;
				}
			}
		}
		void insertBefore(int data, int newData)
		{
			Node* newNode = new Node(newData);
			//if list is empty
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
			}
			else
			{
				Node* temp = this->head;
				Node* previous = this->head;
				while (temp->next != this->head)
				{
					if (temp->data == data)
					{
						//if first node is to be inserted
						if (temp == this->head)
						{
							this->insertAtFirst(newData);
							return;
						}
						else
						{
							previous->next = newNode;
							newNode->next = temp;
							return;
						}
					}
					previous = temp;
					temp = temp->next;
				}
				if (temp->data == data)
				{
					previous->next = newNode;
					newNode->next = temp;
				}
			}
		}
		void deleteAtFirst()
		{
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
			}
			else
			{
				//if 1 element is to be deleted
				if (this->head->next == this->head)
				{
					delete this->head;
					this->head = this->tail = nullptr;
					return;
				}
				Node* toBeDeleted = this->head;
				this->head = this->head->next;
				this->tail->next = this->head;
				delete toBeDeleted;
			}
		}
		void deleteAtLast()
		{
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
			}
			else
			{
				//if 1 element is to be deleted
				if (this->head->next == this->head)
				{
					delete this->head;
					this->head = this->tail = nullptr;
					return;
				}
				Node* temp = this->head;
				Node* previous = this->head;
				while (temp->next != this->head)
				{
					previous = temp;
					temp = temp->next;
				}
				//temp is last node and previous is second last node
				Node* toBeDeleted = temp;
				this->tail = previous;
				previous->next = this->head;
				delete toBeDeleted;
			}
		}
		void deleteAfter(int data)
		{
			//if list is empty
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
			}
			//if list is not empty
			else
			{
				Node* temp = this->head;
				while (temp->next != this->head)
				{
					if (temp->data == data)
					{
						Node* nextNode = temp->next->next;
						Node* toBeDeleted = temp->next;
						temp->next = nextNode;
						delete toBeDeleted;
						return;
					}
					temp = temp->next;
				}
				if (temp->data == data)
				{
					this->deleteAtFirst();
				}
			}
		}
		void deleteBefore(int data)
		{
			//if list is empty
			if(this->head==nullptr)
			{
				cout << "List is empty!" << endl;
			}
			else
			{
				Node* temp = this->head;
				Node* previous = this->head;
				while (temp->next != this->head)
				{
					if (temp->next->data == data)
					{
						//checking if first element is to be deleted
						if (temp == this->head)
						{
							deleteAtFirst();
							return;
						}
						Node* toBeDeleted = temp;
						previous->next = temp->next;
						delete toBeDeleted;
						return;
					}
					previous = temp;
					temp = temp->next;
				}
			}
		}
		void reverseList()
		{
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
			}
			else
			{
				Node* temp = this->head;
				Node* previous=nullptr; Node* nextNode = nullptr;
				do
				{
					nextNode = temp->next;
					temp->next = previous;
					previous = temp;
					temp = nextNode;
				} while (temp != this->head);
				temp = this->head;
				this->head = this->tail;
				this->tail = temp;
				this->tail->next = this->head;
			}
		}
		void displayList()
		{
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
			}
			else
			{
				Node* temp = this->head; 
				while (temp->next != this->head)
				{
					cout << temp->data << "\t";
					temp = temp->next;
				}
				cout << temp->data << "\t";
			}
		}
};


int main()
{
	CircularLL myList;
	myList.insertAtLast(2);
	myList.insertAtLast(3);
	myList.insertAtLast(9);
	myList.insertAtLast(110);
	myList.insertAtLast(200);
	myList.insertAtLast(300);
	myList.insertAtFirst(33);
	myList.insertAtFirst(36);
	myList.insertAfter(-300, -33);
	myList.insertAtFirst(450);
	myList.insertBefore(300, -500);
	myList.displayList(); cout << endl;
	myList.reverseList();
	cout << endl;
	myList.displayList(); cout << endl;
	//myList.deleteBefore(-33);
	return 0;
}