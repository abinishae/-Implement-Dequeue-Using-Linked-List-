#include <bits/stdc++.h>
using namespace std;

// Node of a doubly linked list
struct Node {
    int data;
    Node* prev, *next;
    // Function to get a new node
    static Node* getnode(int data) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
};

// A structure to represent a deque
class Deque {
    Node* front;
    Node* rear;
    int Size;

  public:
    Deque() {
        front = rear = NULL;
        Size = 0;
    }

    // Operations on Deque
    void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    bool isEmpty();
};

// Function to check whether deque
// is empty or not
bool Deque::isEmpty() {
    return (front == NULL);
}

// Function to return the element
// at the front end
int Deque::getFront() {
    // If deque is empty, then returns
    // garbage value
    if (isEmpty()) return -1;
    return front->data;
}

// Function to return the element
// at the rear end
int Deque::getRear() {
    // If deque is empty, then returns
    // garbage value
    if (isEmpty()) return -1;
    return rear->data;
}

void Deque::insertFront(int d) {
    Node* t = new Node;
   t->next =  t->prev = NULL;
   t->data = d;
    if(front)
   { t->next = front;
     front->prev = t;
  }
    front = t;
    if(! rear)
    rear = t;
    
}

// Function to insert an element
// at the rear end
void Deque::insertRear(int d) {
      Node* t = new Node;
   t->next =  t->prev = NULL;
   t->data = d;
    if(rear)
   { rear->next = t;
     t->prev = rear;
  }
    rear = t;
    if(! front)
    front = t;
    
}

// Function to delete the element
// from the front end
void Deque::deleteFront() {
    if(!front) return;
    if(front == rear){front = rear = NULL;return;}
    front = front->next;
    front->prev = NULL;
    
}

// Function to delete the element
// from the rear end
void Deque::deleteRear() {
    if(!rear) return;
     if(front == rear){front = rear = NULL; return;}
    rear = rear->prev;
    rear->next = NULL;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Deque dq;

        while (q--) {

            string qt;
            cin >> qt;

            if (qt == "ir") {
                int data;
                cin >> data;
                dq.insertRear(data);
            } else if (qt == "if") {
                int data;
                cin >> data;
                dq.insertFront(data);

            } else if (qt == "dr") {
                dq.deleteRear();
            } else if (qt == "df") {
                dq.deleteFront();
            }
        }

        cout << dq.getFront() << endl;
        cout << dq.getRear() << endl;
    }
    return 0;
}
