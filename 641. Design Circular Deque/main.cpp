class Node {
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
        }
};

class MyCircularDeque {
public:
    int length =0;
    int max_size;
    Node* head = nullptr;
    Node* tail = nullptr;
    MyCircularDeque(int k) {
        this->max_size = k;
    }
    
    bool insertFront(int value) {
        if(!this->isFull()){
            Node* newNode = new Node(value);
            newNode->next = nullptr;
            if(this->isEmpty()){
                this->head = newNode;
                this->tail = this->head;
            }
            else{
                newNode->next = this->head;
                this->head = newNode;  
            }
            this->length++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(!this->isFull()){
            Node* newNode = new Node(value);
            newNode->next = nullptr;
            if(this->isEmpty()){
                this->head = newNode;
                this->tail = newNode;
            }
            else{
                this->tail->next = newNode;
                this->tail = newNode;
            }
            this->length++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(this->isEmpty()) return false;
        if(this->length == 1){
            this->head = nullptr;
            this->tail = nullptr;
        }
        else{
            this->head = this->head->next;
        }
        this->length--;
        return true;
    }
    
    bool deleteLast() {
        if(this->isEmpty()) return false;
        if(this->length == 1){
            this->head = nullptr;
            this->tail = nullptr;
        }
        else{
            Node* itr = this->head;
            while(itr->next->next != nullptr){
                itr = itr->next;
            }
            this->tail = itr;
            this->tail->next = nullptr;
        }
        this-length--;
        return true;
    }
    
    int getFront() {
        if(this->isEmpty()) return -1;
        return this->head->data;
    }
    
    int getRear() {
        if(this->isEmpty()) return -1;
        return this->tail->data;
    }
    
    bool isEmpty() {
        if(this->length == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(this->length == this->max_size){
            return true;
        }
        return false;
    }
};
