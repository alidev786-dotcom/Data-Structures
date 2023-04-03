

#include<iostream>
using namespace std;

class Node 
{
	public:
		int data;
		Node* next;
		Node(int a_data)
		{
			this->data = a_data;
			this->next = nullptr;
		}
};

class SingleLinkList 
{
	public:
		Node* head;
		SingleLinkList()
		{
			this->head = nullptr;
		}
		void displayList()
		{
			Node* temp = this->head;
			while (temp != nullptr)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
		}
		void insertAtStart(int val)
		{
			Node* newNode = new Node(val);
			//if link list is empty
			if (this->head == nullptr)
			{
				this->head = newNode;
				return;
			}
			else
			{
				newNode->next = this->head;
				this->head = newNode;
			}
		}
		void insertAtEnd(int val)
		{
			Node* newNode = new Node(val);
			//if link list is empty
			if (this->head == nullptr)
			{
				this->head = newNode;
				return;
			}
			Node* temp = this->head;
			while (temp->next!=nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
		void insertAfter(int val,int newVal)
		{
			Node* newNode = new Node(newVal);
			if (this->head == nullptr)
			{
				cout << "Error! List is empty!" << endl;
				return;
			}
			else
			{
				Node* temp = this->head;
				while(temp!=nullptr)
				{
					if (temp->data == val)
					{
						newNode->next = temp->next;
						temp->next = newNode;
					}
					temp = temp->next;
				}
			}
		}
		void insertBefore(int val,int newVal)
		{
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
				return;
			}
			else
			{
				Node* newNode = new Node(newVal);
				Node* temp = this->head;
				Node* prev = this->head;
				while (temp != nullptr)
				{
					if (temp->data == val)
					{
						newNode->next = temp;
						prev->next = newNode;
					}
					prev = temp;
					temp = temp->next;
				}
			}
		}
		void deleteAfter(int val)
		{
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
				return;
			}
			else
			{
				Node* temp = this->head;
				while (temp != nullptr)
				{
					if (temp->data == val)
					{
						if (temp->next != nullptr)
						{
							Node* toBeDeleted = temp->next;
							temp->next = temp->next->next;
							delete toBeDeleted;
						}
					}
					temp = temp->next;
				}
			}
		}
		void deleteBefore(int val)
		{
			//if list is empty
			if (this->head == nullptr)
			{
				cout << "list is empty!" << endl;
				return;
			}
			else
			{
				if (val == this->head->data)
				{
					cout << "Error in deletion!" << endl;
					return;
				}
				else if(val==this->head->next->data)
				{
					Node* toBeDeleted = this->head;
					this->head = this->head->next;
					delete toBeDeleted;
				}
				else 
				{
					Node* temp = this->head;
					while (temp != nullptr)
					{
						if (temp->next == nullptr)
						{
							return;
						}
						else if (temp->next->next == nullptr)
						{
							return;
						}
						if (val == temp->next->next->data)
						{
							Node* toBeDeleted = temp->next;
							temp->next = toBeDeleted->next;
							delete toBeDeleted;
							return;
						}
						temp = temp->next;
					}
				}
			}
		}
		void reverseList()
		{
			//if list is empty
			if (this->head == nullptr)
			{
				cout << "List is empty!" << endl;
				return;
			}
			else
			{
				Node* forward, * temp, * previous;
				temp = this->head->next;
				this->head->next = nullptr;
				previous = this->head;
				while (temp != nullptr)
				{
					forward = temp->next;
					temp->next = previous;
					previous = temp;
					temp = forward;
				}
				this->head = previous;
			}
		}
};

int main()
{
	SingleLinkList myList;
	myList.insertAtEnd(-90);
	myList.insertAtEnd(10);
	myList.insertAtEnd(-90);
	myList.insertAtStart(66);
	myList.insertAtStart(99);
	myList.insertAtEnd(101);
	myList.insertAfter(-90,11);
	myList.insertBefore(11, 36);
	myList.deleteAfter(99);
	//myList.deleteBefore(999);
	myList.displayList();
	myList.reverseList();
	cout << endl;
	myList.displayList();
	return 0;
}