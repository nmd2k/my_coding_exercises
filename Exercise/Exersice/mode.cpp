#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    int count;
    struct Node* next;
    Node (int _data, int _count, Node* _next){
        this->data = _data;
        this->count = _count;
        this->next = _next;
    }
};

struct list {
    Node*head;
    Node*tail;
    list (){
        this->head = this->tail = nullptr;
    }
    list& addNumber (int _data);
};

list& list::addNumber(int _data){
	Node* newNode = new Node(_data, 1, nullptr);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	return *this;
}

void Swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

void bubbleSort(vector <int>& arr) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < arr.size()-1; i++) {
			if (arr[i] > arr[i + 1]) {
				Swap(arr[i], arr[i + 1]);
				sorted = false;
			}
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}
}
int main (){
    bool loop = false;
    int n; cin >>n;
    list arrNumb;
    vector <int> arr(n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    //arrNumb.addNumber(arr[0]);
    for (int i=0; i<n; i++){
        loop = false;
        for (Node* index = arrNumb.head; index!= nullptr; index=index->next){
            if (index->data == arr[i]) {
                loop = true;
                index->count++;
            }
        }
		if (!loop) arrNumb.addNumber(arr[i]);
    }
	//the most appear number
	Node* Max = arrNumb.head;
    for (Node* index = arrNumb.head; index!= nullptr; index=index->next){
		if (index->count > Max->count) Max = index;
    }
	vector <int> maxNumb;
	for (Node* index = arrNumb.head; index != nullptr; index = index->next) {
		if (index->count == Max->count) maxNumb.push_back(index->data);
	}
	//bubbleSort(maxNumb);
	for (int i = 0; i < maxNumb.size(); i++) {
		cout << maxNumb[i] << ' ';
	}
    return 0;
}
