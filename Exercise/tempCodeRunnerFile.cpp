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

class queue {
    Node *head;
    Node *ptr;
    public:
        queue (){
            this->head = nullptr;
        }

        queue& queue::enqueue(int data){
            head = new Node(data, head);
            return *this;
        }

        queue& queue::dequeue(){
            head = head->getNext();
            return *this;
        }

        void firstPrint(){
            cout << head->getData() << endl;
        }

};

int main (){
    int n; cin >> n;
    while (n>0){
        queue test;
        int choice; cin >> choice;
        if (choice == 1) {int a; cin >> a; test.enqueue(a);}
        else if (choice == 2) {test.dequeue();}
        else test.firstPrint();
        n--;
    }
}