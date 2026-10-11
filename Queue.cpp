#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node *Front = NULL;
Node *Rear = NULL;
Node *newNode = NULL;
int queueSize = 0;  // TECHNIQUE 2: SIZE COUNTER

void enqueue(int key){

    newNode = new Node;
    newNode->data = key;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(Front == NULL){
        Front = newNode;
        Rear = newNode;
    }
    else{
        Rear->next = newNode;
        newNode->prev = Rear;
        Rear = newNode;
    }
    queueSize++;
}

void dequeue(){

    if(Front == NULL){
        cout << "The queue is empty [QUEUE UNDERFLOW]" << endl;
        return;
    }

    Node *temp = Front;

    if(Front == Rear){
        cout << "Removed: " << temp->data
             << " - the queue is now empty" << endl;
        Front = NULL;
        Rear = NULL;
        delete temp;
        queueSize--;
    }
    else{
        cout << "Removed: " << temp->data << endl;
        Front = Front->next;
        Front->prev = NULL;
        delete temp;
        queueSize--;
    }
}

void front(){
    if(Front == NULL){
        cout << "The queue is empty" << endl;
        return;
    }
    cout << "Front element: " << Front->data << endl;
}

// TECHNIQUE 1: NULL-POINTER CHECK
bool isempty(){
    if(Front == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool isSingle(){

    if(Front == Rear && Front != NULL){
        return true;
    }
    else{
        return false;
    }
}

// TECHNIQUE 2: SIZE COUNTER (empty)
bool isEmptySize(){
    return queueSize == 0;
}

// TECHNIQUE 2: SIZE COUNTER (one element)
bool isSingleSize(){
    return queueSize == 1;
}

void demonstrateProblem(){
    cout << endl;
    cout << "============================================" << endl;
    cout << "        INVESTIGATION OF THE PROBLEM" << endl;
    cout << "============================================" << endl;

    cout << endl;
    cout << "CASE 1: EMPTY QUEUE" << endl;
    cout << "Front == Rear : "
         << (Front == Rear ? "TRUE" : "FALSE") << endl;
    cout << "Front == NULL : "
         << (Front == NULL ? "TRUE" : "FALSE") << endl;

    enqueue(10);
    cout << endl;
    cout << "CASE 2: ONE ELEMENT" << endl;
    cout << "Front == Rear : "
         << (Front == Rear ? "TRUE" : "FALSE") << endl;
    cout << "Front == NULL : "
         << (Front == NULL ? "TRUE" : "FALSE") << endl;
    cout << endl;

    cout << "OBSERVATION:" << endl;
    cout << "Front == Rear is TRUE in BOTH cases." << endl;
    cout << "Therefore, Front == Rear alone" << endl;
    cout << "cannot distinguish the two states." << endl;

    cout << endl;
    cout << "SOLUTION:" << endl;
    cout << "EMPTY       : Front == NULL" << endl;
    cout << "ONE ELEMENT : Front == Rear"
         << " && Front != NULL" << endl;
    cout << endl;

    cout << "============================================" << endl;
    cout << endl;

    dequeue();
}


void checkState(){
    cout << "Queue state: ";
    if(isempty()){
        cout << "The queue is empty" << endl;
    }
    else if(isSingle()){
        cout << "The queue has exactly one element" << endl;
    }
    else{
        cout << "The queue has more than one element" << endl;
    }
}

void display(){

    Node *temp = Front;

    if(Front == NULL){

        cout << "The queue is empty" << endl;
        return;
    }

    cout << "Front to Rear: ";

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Rear to Front: ";
    temp = Rear;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void compareTechniques(){

    cout << "Pointer check: "
         << "empty = " << isempty()
         << "  single = " << isSingle()
         << endl;

    cout << "Size check: "
         << "empty = " << isEmptySize()
         << "  single = " << isSingleSize()
         << "  (size = " << queueSize << ")"
         << endl;
}

void showState(){
    checkState();
    compareTechniques();
    display();
    cout << endl;
}

int main(){

    demonstrateProblem();
    cout << "1. Empty queue" << endl;
    showState();
    dequeue();
    cout << endl;

    cout << "2. Insert one element" << endl;
    enqueue(10);
    showState();

    cout << "3. Insert more" << endl;
    enqueue(20);
    enqueue(30);
    showState();
    front();
    cout << endl;

    cout << "4. Remove down to one element" << endl;
    dequeue();
    dequeue();
    showState();

    cout << "5. Remove the last element" << endl;
    dequeue();
    showState();

    cout << "6. Insert again" << endl;
    enqueue(50);
    showState();

    return 0;
}