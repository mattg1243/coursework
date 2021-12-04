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

int main() {

    return 0;
}