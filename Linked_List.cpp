#include<iostream>
using namespace std;
class LinkedList
{
private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* head;
public:
	LinkedList() 
	{
		head = nullptr;
	}
	
	void addhead(int a)
	{
		Node* newhead = new Node();
		newhead->data = a;
		newhead->next = head;
		head = newhead;
	}

	//add a new node after data b
	void addNode(int a, int b)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == b)
			{
				Node* nextNode = temp->next;
				Node* newNode = new Node();
				temp->next = newNode;
				newNode->data = a;
				newNode->next =nextNode;
				return;
			}
			temp = temp->next;
		}
	}

	void delNode(int a)
	{
		Node* temp = head;
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		if (head->data == a)
		{
			temp =head;
			head = head->next;
			delete temp;
			return;
		}
		Node* preNode = head;
		while (preNode->next != nullptr)
		{
			if (preNode->next->data == a)
			{
				temp = preNode->next;
				preNode->next = temp->next;
				delete temp;
				temp = nullptr;
				return;
			}
			preNode = preNode->next;
		}
	}

	void printlist()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

	//release the memory automatically
	~LinkedList()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			Node* nextNode = temp->next;
			delete temp;
			temp = nextNode;
		}
		head = nullptr;
		cout << "The memory has been released" << endl;
	}
};

int main()
{
	LinkedList myList;
	myList.addhead(10);
	myList.addhead(20);
	myList.addhead(30);
	myList.addhead(40);
	myList.addhead(50);
	myList.printlist();
	myList.delNode(30);
	myList.printlist();
	myList.addNode(100, 50);
	myList.addNode(300, 40);
	myList.printlist();

	return 0;
}