struct Node {
    int value;
    Node *nextNode;
};

Node* addNode(Node* head, int index, int value){
    //them code cua ban o day
    Node* newNode = new Node();
    newNode->value = value;
    newNode->nextNode = nullptr;
    if (head == nullptr and index == 0) {
        head = newNode;
    }
    else if (index == 0){
        newNode->nextNode = head;
        head = newNode;
    }
    else {
        Node* front = head;
        for (int i = 0; i < index-1; i++) {
            front = front->nextNode;
        }
        front->nextNode = newNode;
        Node* temp = front->nextNode;
        newNode->nextNode = temp;
        return head;
    }
}

Node* deleteNode(Node* head, int index){
    //them code cua ban o day
    Node* front = head;
	//Node* back = head->nextNode->nextNode;
	if (index != 0 and head != nullptr){
	    for (int i = 0; i < index-1; i++) {
	    	front = front->nextNode;
	    }
        Node* temp = front;
        temp = temp->nextNode;
	    front->nextNode = temp->nextNode;
	}
	else if (index == 0){
        head = head->nextNode;
    }
	return head;
}