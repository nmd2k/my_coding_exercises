#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;
    public:
        Node (int _data, Node* _next) {
            this->data = _data;
            this->next = _next;
        } 
        
        int getData(){
            return this->data;
        }

        void setData(int _data){
            this->data = _data;
        }
        
        Node* getNext(){
            return this->next;
        }

        void setNext(Node* _next){
            this->next = _next;
        }
};

Node* enqueue(Node* tail, Node* head, int data){
    bool isEmpty = tail == nullptr;
    tail = new Node(data, tail);
    
    if (isEmpty) head = tail;
    return tail;
}

Node* dequeue(Node* head, Node* tail){
    
    return head;
}

void printhead(Node* head){
    if (head != nullptr){cout << head->getData() << endl;}
    else cout << "nullptr" << endl;
}

int main (){
    int n; cin >> n;
    Node* tail = nullptr;
    Node*head = nullptr;
    while (n-- >0){
        int choice; cin >> choice;
        if (choice == 1) {
            int a; cin >> a;
            tail = enqueue(tail, head, a);
        }
        else if (choice == 2) {
            head = dequeue(head, tail);
        }
        else {
            printtail(head);
        }
    }
    return 0;
}