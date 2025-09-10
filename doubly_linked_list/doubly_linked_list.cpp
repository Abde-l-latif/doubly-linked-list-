#include <iostream>

using namespace std; 

template <typename T> 

class Node {
	
public : 
	T value; 
	Node<T>* next; 
	Node<T>* previous; 
};

template <typename O>

class doubly_linked_list {

private :

	Node<O>* _Head;

	Node<O>* _Tail;

	bool _is_head_empty()
	{
		return _Head == NULL; 
	}

public : 

	doubly_linked_list() : _Head(NULL) , _Tail(NULL) {};

	void insert_at_beginning(O value)
	{
		Node <O>* new_node = new Node<O>(); 

		new_node->previous = NULL; 

		new_node->value = value; 

		if (_is_head_empty())
		{
			new_node->next = NULL;
			_Head = _Tail = new_node; 
			return;
		}

		new_node->next = _Head; 

		_Head->previous = new_node; 

		_Head = new_node; 

	}

	void normal_print()
	{
		if (_is_head_empty())
			return; 

		Node<O>* temp = _Head;
		while (temp != NULL) {
			cout << temp->value << " >> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

	Node <O>* find(O value)
	{
		if (_is_head_empty())
			return NULL; 

		Node <O>* current = _Head;

		while (current != NULL)
		{
			if (current->value == value)
				return current; 
			current = current->next; 
		}

		return NULL; 
	}

	void insert_after(O after , O value)
	{
		if (_is_head_empty())
			return ;

		Node <O>* after_node = find(after); 

		if (after_node == NULL)    
			return;

		Node <O>* new_node = new Node<O>();

		new_node->value = value;

		new_node->previous = after_node;

		new_node->next = after_node->next;


		if (after_node->next != NULL)
			after_node->next->previous = new_node;

		after_node->next = new_node; 
	}

	void insert_at_the_end(O value)
	{
		Node <O>* new_node = new Node<O>();

		new_node->value = value;

		new_node->next = NULL; 

		if (_is_head_empty()) {
			new_node->previous = NULL;
			_Head = _Tail = new_node; 
			return;
		}
		
		new_node->previous = _Tail;
		_Tail->next = new_node;
		_Tail = new_node; 
	}

	void reverse_print()
	{
		if (_Tail == NULL)
			return;

		Node<O>* temp = _Tail;
		while (temp != NULL) {
			cout << temp->value << " << ";
			temp = temp->previous;
		}
		cout << "NULL" << endl;
	}

	void delete_node(O value)
	{
		if (_is_head_empty())
			return; 

		Node <O>* get_node = find(value); 

		if (get_node == NULL)
		{
			cout << "Node not found !!" << endl; 
			return;
		}

		if (get_node->next == NULL && get_node->previous != NULL)
		{
			get_node->previous->next = NULL; 
			_Tail = get_node->previous;
			delete get_node; 
			return;
		}

		if (get_node->next != NULL && get_node->previous == NULL)
		{
			_Head = get_node->next;
			get_node->next->previous = NULL; 
			delete get_node;
			return;
		}

		if (get_node->next != NULL && get_node->previous != NULL)
		{
			get_node->previous->next = get_node->next; 
			get_node->next->previous = get_node->previous;
			delete get_node;
			return; 
		}

		_Head = _Tail = NULL;
		delete get_node;
		
	}

	void delete_first_node()
	{
		if (_is_head_empty())
		{
			return; 
		}

		Node<O>* current = _Head; 

		if (current->next == NULL)
		{
			_Head = _Tail = NULL; 
			delete current; 
			return; 
		}

		_Head = current->next; 
		_Head->previous = NULL;
		delete current;
	}

	void delete_last_node()
	{
		if (_is_head_empty())
		{
			return;
		}

		Node<O>* current = _Tail;

		if (current->previous == NULL)
		{
			_Head = _Tail = NULL;
			delete current;
			return;
		}

		_Tail = current->previous;
		_Tail->next = NULL;
		delete current;
	}

	~doubly_linked_list()
	{
		Node <O>* current;

		while (_Head != NULL)
		{
			current = _Head; 
			_Head = _Head->next;
			delete current;
		}

		_Tail = NULL;

		if (_is_head_empty())
			cout << "Linked list is empty !!" << endl;
	}
};

int main()
{
	doubly_linked_list <int> doubly_list; 

	doubly_list.insert_at_beginning(10); 
	doubly_list.insert_at_beginning(20);
	doubly_list.insert_at_beginning(30);
	doubly_list.insert_at_beginning(40);

	doubly_list.insert_after(40, 35);

	doubly_list.insert_at_the_end(90);

	doubly_list.delete_first_node();

	doubly_list.delete_last_node(); 

	doubly_list.normal_print();

	doubly_list.reverse_print();

	cout << doubly_list.find(30)->value << endl;
		
	return 0; 
}
