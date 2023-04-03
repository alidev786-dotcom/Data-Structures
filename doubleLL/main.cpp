#include<iostream>
using namespace std;


class Node
{
	public:
		int data;
		Node* next;
		Node* previous;

	Node()
	{
		this->data = -1;
		this->next = this->previous = nullptr;
	}
	Node(int d)
	{
		this->data = d;
		this->next = nullptr;
		this->previous = nullptr;
	}
};

class DoubleLL
{
	public:
		Node* head; 
		DoubleLL()
		{
			this->head = nullptr;
		}
		void insertAtEnd(int data)
		{
			//making new node
			Node* newNode = new Node(data);
			//if list is empty
			if (this->head == nullptr)
			{
				this->head = newNode;
			}
			//if list is not empty
			else
			{
				Node* temp = this->head;
				while (temp->next!=nullptr)
				{
					temp = temp->next;
				}
				temp->next = newNode;
				newNode->previous = temp;
			}
		}
		void insetAtStart(int data)
		{
			Node* newNode = new Node(data);
			//if list is empty
			if (this->head == nullptr)
			{
				this->head = newNode;
			}
			else
			{
				newNode->next = this->head; 
				this->head->previous = newNode;
				this->head = newNode;
			}
		}
		void insertAfter(int data, int newData)
		{
			Node* forward = nullptr;
			Node* newNode = new Node(newData);
			Node* temp = this->head;
			while (temp != nullptr)
			{
				if (temp->data == data)
				{
					if (temp->next == nullptr)
					{
						temp->next = newNode;
						newNode->previous = temp;
						return;
					}
					forward = temp->next;
					temp->next = newNode;
					newNode->previous = temp;

					newNode->next = forward;
					forward->previous = newNode;
					return;
				}
				temp = temp->next;
			}
		}
		void insertBefore(int data, int newData)
		{
			Node* newNode = new Node(newData);
			Node* temp = this->head;
			Node* prev = nullptr;
			while (temp != nullptr)
			{
				//if found
				if (temp->data == data)
				{
					if (temp->previous == nullptr)
					{
						temp->previous = newNode;
						newNode->next = temp;
						this->head = newNode;
					}
					else
					{
						prev = temp->previous;
						newNode->next = temp;
						temp->previous = newNode;

						prev->next = newNode;
						newNode->previous = prev;
					}
				}
				temp = temp->next;
			}
		}
		void deleteAtStart()
		{
			if (this->head == nullptr)
			{
				cout << "list is empty" << endl;
			}
			else
			{
				Node* nodeToBeDeleted = this->head;
				this->head = this->head->next;
				delete nodeToBeDeleted;
			}
		}
		void deleteAtEnd()
		{
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
			}
			else
			{
				Node* temp = this->head;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->previous->next = nullptr;
				delete temp;
			}
		}
		void deleteAfter(int data)
		{
			Node* temp = this->head;
			Node* forward = nullptr;
			while (temp->next != nullptr)
			{
				if (temp->data == data)
				{
					//if it is last node
					if (temp->next->next == nullptr)
					{
						temp->next = nullptr;
						delete temp->next;
						return;
					}
					//if not the last node
					else
					{
						Node* toBeDeleted = temp->next;
						temp->next = toBeDeleted->next;
						toBeDeleted->next->previous = temp;
						delete toBeDeleted;
					}
				}
				temp = temp->next;
			}
		}
		void deleteBefore(int data)
		{
			//if list is empty
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
			}
			//list is not empty
			else
			{
				Node* temp = this->head;
				while (temp != nullptr)
				{
					if (temp->data == data)
					{
						//if node to be deleted is the first node
						if (temp->previous->previous == nullptr)
						{
							Node* toBeDeleted = this->head;
							this->head = this->head->next;
							delete toBeDeleted;
							return;
						}
						else
						{
							Node* toBeDeleted = temp->previous;
							temp->previous = toBeDeleted->previous;
							toBeDeleted->previous->next = temp;
							delete toBeDeleted;
							return;
						}
					}
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
				Node* nextNode = NULL;
				Node* current = head;
				Node* tail = nullptr; 
				/* swap next and prev for all nodes of
				doubly linked list */
				while (current != NULL)
				{
					nextNode = current->next;
					current->next = current->previous;
					current->previous = nextNode;

					tail = current;
					current = nextNode;
				}

				/* Before changing the head, check for the cases like empty
					list and list with only one node */
				this->head = tail;
			}
		}
		void displayList()
		{
			if (this->head == nullptr)
			{
				cout << "This list is empty!" << endl;
				return;
			}
			else
			{
				Node* temp = this->head;
				while (temp != nullptr)
				{
					cout << temp->data << "\t";
					temp = temp->next;
				}
			}
		}
};


int main()
{
	DoubleLL myList;
	myList.insertAtEnd(2);
	myList.insertAtEnd(10);
	myList.insertAtEnd(-11);
	myList.insetAtStart(100);
	myList.insetAtStart(110);
	myList.insertBefore(-11,36);
	myList.displayList();
	cout << endl;
	myList.reverseList();
	myList.displayList();
	return 0;
}