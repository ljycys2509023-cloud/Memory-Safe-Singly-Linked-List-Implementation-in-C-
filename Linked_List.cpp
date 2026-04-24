#include<iostream> 
#include<string> 
#include<iomanip>
using namespace std; 
class Patient { private:
	string patientID;
	string name;
	int age;
	string condition;
	int priorityLevel; public:
	Patient(string a, string b, int x, string c, int y)
	{
		patientID = a;
		name = b;
		age = x;
		condition = c;
		priorityLevel = y;
	}
	string getID() { return patientID; }
	string getName() { return name; }
	int getAge() { return age; }
	string getCondition() { return condition; }
	int getPriorityLevel() { return priorityLevel; }
	void display()
	{
		cout << left << setw(20) << "Patient ID" << ": " << patientID << endl;
		cout << left << setw(20) << "Name" << ": " << name << endl;
		cout << left << setw(20) << "Age" << ": " << age << endl;
		cout << left << setw(20) << "Condition" << ": " << condition << endl;
		cout << left << setw(20) << "Priority Level" << ": ";
		switch (priorityLevel)
		{
		case 1: cout << "Critical"; break;
		case 2: cout << "Moderate"; break;
		case 3: cout << "Mild"; break;
		}
		cout << endl;
	}
};
class PatientQueue { private:
	struct Node
	{
		Patient s;
		Node* next;
		Node(Patient patient_obj) : s(patient_obj), next(nullptr) {}
	};
	Node* head = nullptr; public:
	void enqueue(Patient p)
	{
		Node* X = new Node(p);
		if (head == nullptr || p.getPriorityLevel() < head->s.getPriorityLevel())
		{
			X->next = head;
			head = X;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr && temp->next->s.getPriorityLevel() <= X->s.getPriorityLevel())
		{
			temp = temp->next;
		}
		X->next = temp->next;
		temp->next = X;
	}
	Patient dequeue()
	{
		if (head == nullptr) {
			cout << "\n[ ERROR: No patients in queue ]" << endl;
			return Patient("0", "None", 0, "None", 3);
		}
		Node* t = head;
		Patient p = t->s;
		head = head->next;
		delete t;
		t = nullptr;
		cout << "\n" << string(20, '*') << " SERVING PATIENT " << string(20, '*') << endl;
		p.display();
		return p;
	}
	void peekFront()
	{
		if (head == nullptr) { cout << "Error, no patient" << endl; return; }
		cout << "\n[ Next in Line ]" << endl;
		head->s.display();
	}
	void displayQueue()
	{
		if (head == nullptr) { cout << "Error, no patient" << endl; return; }
		Node* temp = head;
		int count = 1;
		cout << "\n" << string(25, '=') << " CURRENT HOSPITAL QUEUE " << string(25, '=') << endl;
		cout << left << setw(8) << "Pos" << setw(20) << "Name" << setw(15) << "Patient ID" << "Priority Status" << endl;
		cout << string(70, '-') << endl;
		while (temp != nullptr)
		{
			cout << left << "No." << setw(5) << count << setw(20) << temp->s.getName() << setw(15) << temp->s.getID();
			switch (temp->s.getPriorityLevel())
			{
			case 1: cout << "(Critical)"; break;
			case 2: cout << "(Moderate)"; break;
			case 3: cout << "(Mild)"; break;
			}
			cout << endl;
			count++;
			temp = temp->next;
		}
		cout << string(70, '=') << endl;
	}
	void searchByID(string id)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->s.getID() == id)
			{
				cout << "\n[ FOUND RESULT FOR ID: " << id << " ]" << endl;
				temp->s.display();
				return;
			}
			temp = temp->next;
		}
		cout << "\n[ ERROR: Patient ID " << id << " not found ]" << endl;
	}
	~PatientQueue()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			Node* nextNode = temp->next;
			delete temp;
			temp = nextNode;
		}
		head = nullptr;
		cout << "\n[ System Info: Memory released ]" << endl;
	}
};
int main() {
	PatientQueue p;
	cout << "\n" << string(80, '#') << endl;
	cout << "### STEP 1 & 2: INITIALIZING QUEUE WITH 6 PATIENTS" << endl;
	cout << string(80, '#') << endl;
	p.enqueue(Patient("P001", "Ahmad", 25, "Critical", 1));
	p.enqueue(Patient("P002", "Siti", 40, "Mild", 3));
	p.enqueue(Patient("P003", "John", 60, "Moderate", 2));
	p.enqueue(Patient("P004", "Wong", 12, "Critical", 1));
	p.enqueue(Patient("P005", "Zali", 33, "Moderate", 2));
	p.enqueue(Patient("P006", "Tan", 55, "Mild", 3));
	p.displayQueue();
	cout << "\n" << string(80, '#') << endl;
	cout << "### STEP 3: DEQUEUE TWICE (DEMONSTRATING SERVICE)" << endl;
	cout << string(80, '#') << endl;
	p.dequeue();
	p.dequeue();
	cout << "\n" << string(80, '#') << endl;
	cout << "### STEP 4: SEARCHING FOR PATIENTS BY ID" << endl;
	cout << string(80, '#') << endl;
	cout << "Searching for P003..." << endl;
	p.searchByID("P003");
	cout << "\nSearching for P999..." << endl;
	p.searchByID("P999");
	cout << "\n" << string(80, '#') << endl;
	cout << "### STEP 5: ADDING NEW CRITICAL PATIENT (VERIFYING AUTO-SORT)" << endl;
	cout << string(80, '#') << endl;
	p.enqueue(Patient("P007", "Urgent_Ali", 20, "Critical", 1));
	p.displayQueue();
	cout << "\n" << string(80, '#') << endl;
	cout << "### STEP 6: FINAL QUEUE STATUS REPORT" << endl;
	cout << string(80, '#') << endl;
	p.displayQueue();
	return 0;
}
