#include <iostream>
using namespace std;

class List {

    private:
    struct Node 
    {
        char c;
        Node* next;
    };
    Node* head;

    public:
    List() { head = nullptr; }
    ~List() { clear(); }
    void clear() { Node* temp = nullptr; while (head != nullptr){ temp = head; head = head->next; delete temp; } }
    void print() const;
    void insert(char c);

};

void List::print() const {

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->c << " ";
        temp = temp->next; 
    }

    cout << endl;
}

void List::insert(char c) { 
// create temporary pointers n, p, and q.
Node* n, *p, *q;  // n = new node, p = next node, q = trailing node

p = head;
q = nullptr;
n = new Node;

n->c = c;
n->next = nullptr;
// while p is not nullptr and c is "greater than" the character in 
// the node pointed at by p...
while (p != nullptr && p->c < c) {q = p; p = p->next;}
// check q, if it's nullptr, then the new node goes at the front.
if (q == nullptr) 
// update the new node's next pointer to head.
{ n->next = head; 
// then, update the head pointer to point to the new node.
head = n; }
// otherwise, it goes somewhere else.  q and p point to the nodes the new node goes in between.
// unless it goes at the end, then p will be set to nullptr 
else { q->next = n; 
// use q to update the trailing node's next to the new node
n->next = p; } 
// use n to update the new node's next pointer to point to what p is pointing to.

// we're done!

}

int main() {
    // Create the List object.
    List list;
    
    // add a few characters to the list.
    list.insert('h');
    list.insert('e');
    list.insert('l');
    list.insert('l');
    list.insert('o');
    list.insert(' ');
    list.insert('w');
    list.insert('o');
    list.insert('r');
    list.insert('l');
    list.insert('d');
    
    // print the contents of the list by calling print
    list.print();
    
    // empty the list by calling clear
    list.clear();
    
    // print the contents of the list
    cout << "List after clear function has been called : \n";
    list.print();
    
    return 0;
}