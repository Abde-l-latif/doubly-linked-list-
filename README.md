📝 Doubly Linked List in C++

A generic doubly linked list implementation in C++ using templates. This project allows insertion, deletion, searching, and traversal in both directions (forward and backward).

🌟 Features

Generic Node (template) supporting any data type.

Insertions:

At the beginning (insert_at_beginning)

At the end (insert_at_the_end)

After a specific node (insert_after)

Deletions:

First node (delete_first_node)

Last node (delete_last_node)

Specific node by value (delete_node)

Traversal:

Forward (normal_print)

Reverse (reverse_print)

Search:

Find a node by value (find)

Automatic memory cleanup using destructor (~doubly_linked_list)

⚙️ Class Structure
Node Class
template <typename T>
class Node {
public:
    T value;             // Node value
    Node<T>* next;       // Pointer to next node
    Node<T>* previous;   // Pointer to previous node
};

Doubly Linked List Class
template <typename O>
class doubly_linked_list {
private:
    Node<O>* _Head; // Head of the list
    Node<O>* _Tail; // Tail of the list

    bool _is_head_empty();
public:
    doubly_linked_list();
    ~doubly_linked_list();

    void insert_at_beginning(O value);
    void insert_at_the_end(O value);
    void insert_after(O after, O value);

    void delete_first_node();
    void delete_last_node();
    void delete_node(O value);

    Node<O>* find(O value);
    void normal_print();
    void reverse_print();
};

📌 Example Usage
int main() {
    doubly_linked_list<int> list;

    list.insert_at_beginning(10);
    list.insert_at_beginning(20);
    list.insert_at_beginning(30);
    list.insert_at_beginning(40);

    list.insert_after(40, 35); // Insert 35 after 40
    list.insert_at_the_end(90); // Insert 90 at the end

    list.delete_first_node(); // Delete 40
    list.delete_last_node();  // Delete 90

    list.normal_print();  // Forward: 35 >> 30 >> 20 >> 10 >> NULL
    list.reverse_print(); // Backward: 10 << 20 << 30 << 35 << NULL

    cout << list.find(30)->value << endl; // Output: 30
    return 0;
}

💡 Notes

Uses templates to handle any data type.

Maintains _Head and _Tail for efficient insertion at both ends (O(1)).

Properly handles empty lists, single-node lists, and middle deletions.

Destructor ensures no memory leaks.

Modern C++ recommendation: use nullptr instead of NULL and avoid printing inside destructors for production code.

🔧 Future Improvements

Implement deep copy constructor and assignment operator (Rule of Three) for safe copying.

Add error handling for find() to avoid dereferencing nullptr.

Add more traversal utilities (e.g., print every nth node).

✅ Conclusion

This project demonstrates a fully functional, generic doubly linked list in C++ with all major operations, suitable for learning and practical use in data structure exercises.
