#include <iostream>
using namespace std;

class MyDeque {

    private:
    struct Node {
        int x;
        Node* next;
    };
    Node* head;

    public:
    MyDeque() { head = nullptr; }
    ~MyDeque() { clear(); }
    int front() const;
    int back() const;
    void push_back(int);
    void push_front(int);
    int size() const;
    void remove(int);
    void clear();
    friend ostream& operator<<(ostream&, const MyDeque&);

};

int MyDeque::front() const { 
    
    if (head == nullptr) { return -1; }
    return head->x;
}

int MyDeque::back() const { 
    
    if (head == nullptr) { return -1; }

    Node* search = head;
    while (search->next != nullptr) { 
        search = search->next;
    }

    return search->x;
}

void MyDeque::push_back(int v) {

    Node* newPtr, *search = head;
    newPtr = new Node;
    newPtr->x = v;
    newPtr->next = nullptr;

    if (head != nullptr) {
        while (search->next != nullptr) { 
            search = search->next;
        }
        search->next = newPtr;
    } else {
        head = newPtr;
    }
}

void MyDeque::push_front(int v) {

    Node* newPtr;
    newPtr = new Node;
    newPtr->x = v;
    newPtr->next = head;
    head = newPtr;
}

int MyDeque::size() const {
    
    Node* search = head;
    int size = 0;
    if (head == nullptr) { return size; }
    else {
        while (search != nullptr) { 
            search = search->next;
            size++;
        }
        return size;
    }
}

void MyDeque::remove(int v) {

    Node* trailing, *leading = head;
    while (leading != nullptr) {
        if (head->x == v) { trailing = head; head = head->next; delete trailing; break; }  
        else if (leading->x == v) { trailing->next = leading->next; delete leading; break; }
        else { trailing = leading; leading = leading->next; }
    }
}

void MyDeque::clear() { 

    Node* search;
    while(head != nullptr) {
        search = head;
        head = head->next;
        delete search;
    }

}

ostream& operator<<(ostream& o, const MyDeque& m) {
    
    MyDeque::Node* search = m.head;
    o << "[ ";
    
    while (search != nullptr) { 
        if (search->next == nullptr) { o << search->x << " "; }
        else { o << search->x << ", "; }
        search = search->next;
    }
    
    o << ']';

    return o;
}

int main() {

    MyDeque dq;
    int toRemove;

    dq.push_back(70);
    dq.push_back(1);
    dq.push_back(35);
    dq.push_back(68);
    dq.push_back(42);

    cout << "MyDeque contents: " << dq << endl;
    cout << "The front of MyDeque: " << dq.front() << endl;
    cout << "The back of MyDeque: " << dq.back() << endl;
    cout << "Lets add 88 to the end using push_back() " << endl;
    dq.push_back(88);
    cout << "The updated list: " << dq << endl;
    cout << "MyDeque size: " << dq.size() << endl;
    cout << "Enter a value to remove from MyDeque: ";
    cin >> toRemove;
    dq.remove(toRemove);
    cout << "The updated list: " << dq << endl;

    return 0;
}