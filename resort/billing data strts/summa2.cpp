#include<iostream>
using namespace std;

/* Linked list structure */
struct list {
	int data;
	struct list *next;
} *node = NULL, *first = NULL, *last = NULL, *node1 = NULL;

class linkedlist {
	public: 

		/* Function for create/insert node in Linked list */
		void insert() {
			list *addNew = new list;
			cout << "Enter value for the node:" << endl;
			cin >> addNew->data;
			if(first == NULL) {
				addNew->next = NULL;
				first = addNew;
				last = addNew;
				cout << "Linked list Created!" << endl;
			}
			else {
				addNew->next = NULL;
				last->next = addNew;
				last = addNew;
				cout << "Data Inserted in the Linked list!" << endl;
			}
		}

		/* Function for Display Linked list */
	
	
		/* Function for delete node from Linked list */
		void del() {int n=0;
			int count = 0, number, i;
			for(node = first; node != NULL; node = node->next)
				count++;
			
			node = first;
			cout << "List of data in Linked list" << endl;
			while(node != NULL) {
				cout << node->data << endl;
				node = node->next;
				n++;
				if(node->data/100==2)
				{
				number=n;
				break;	
				}
			}
			node = node1 = first;
			cout << count << " nodes available here!" << endl;
			if(number != 1) {
				if(number <= count) {
					for(i = 2; i <= number; i++)
						node = node->next;
					for(i = 2; i <= number-1; i++)
						node1 = node1->next;
					node1->next = node->next;
					node->next = NULL;
					node = NULL;
				}
				else
					cout << "Invalid node number!" << endl;
			}
			else {
				first = node->next;
				node = NULL;
			}
			cout << "Node has been deleted successfully!" << endl;
	
	
			cout << "List of data in Linked list" << endl;
			while(node != NULL) {
				cout << node->data << endl;
				node = node->next;	}
	
}};

int main() {
	int op = 0;
	linkedlist llist = linkedlist();
	while(op != 4) {
		cout << "1. Insert 2. Delete 3. Display 4. Exit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> op;
		switch(op) {
			case 1:
				llist.insert();
				break;
			case 2:
				llist.del();
				break;
			case 3:
				//llist.display();
				break;
			case 4:
				cout << "Bye Bye!" << endl;
				return 0;
				break;
			default:
				cout << "Invalid choice!" << endl;
		}
	}
	return 0;
}

