#include "CharList.h"

// is the list empty?
bool CharList::empty(){
    if (size() == 0){
        return true;
    }
    else{
        return false;
    }
} 

// the number of elements in the list
int CharList::size(){
    return cnt;
}

// inserts the character c at the front of the list
 void CharList::insert(char c){
    Node* new_node = new Node;
    new_node->element = c;
    if (head == NULL){
        new_node -> pre = NULL;
        new_node -> next = NULL;
        head = new_node;
        tail = new_node;
    }
    else{
        head -> pre = new_node;
        new_node -> pre = NULL;
        new_node -> next = head;
        head = new_node;
    }
    cnt++;
}


// inserts the character c at the back of the list
void CharList::append(char c){  
    Node* new_node = new Node;
    new_node -> element = c;
    if (head == NULL){
        head = new_node;
        tail = new_node;
        new_node -> pre = NULL;
        new_node -> next = NULL;
    }
    else{
        tail -> next = new_node;
        new_node -> pre = tail;
        new_node -> next = NULL;
        tail = new_node;
    }
    cnt ++;
}

// inserts c immediately before the first occurance of d, or at the end of the list if d does not occur.
void CharList::insert(char c, char d){
    if(head == NULL){
        append(c);
        return;
    }
    if(head -> element == d){
        insert(c);
        return;
    }
    Node* new_node = new Node;
    new_node -> element = c;
    Node* current = head;
    while(current != NULL){
        if(current -> element == d){
            new_node -> next = current;
            new_node -> pre = current -> pre;
            current -> pre -> next = new_node; 
            current -> pre = new_node;
            cnt ++;
            return;
        }
        current = current -> next;
    } 
    append(c);
}


// inserts c immediately after the first occurance of d, or at the end of the list if d does not occur.
void CharList::append(char c, char d){
    if(head == NULL){
        append(c);
        return;
    }
    if (tail -> element == d){
        append(c);
        return;
    }
    Node* new_node = new Node;
    new_node -> element = c;
    Node* current = head;
    while(current != NULL){
        if(current -> element == d){
            new_node -> pre = current;
            new_node -> next = current -> next;
            current -> next -> pre = new_node; 
            current -> next = new_node;
            cnt ++;
            return;
        }
        current = current -> next;
    } 
    append(c);
}

// inserts c immediately before the nth occurance of d, or at the end of the list if d does not occur n times.
void CharList::insert(char c, char d, int n){
    if(head == NULL){
        append(c);
        return;
    }
    if(head -> element == d){
        insert(c);
        return;
    }
    int count = 0;
    Node* new_node = new Node;
    new_node -> element = c;
    Node* current = head;
    while(current != NULL){
        if(current -> element == d){
            count = count + 1;
            if (count == n){
                new_node -> next = current;
                new_node -> pre = current -> pre;
                current -> pre -> next = new_node; 
                current -> pre = new_node;
                cnt ++;
                return;
            }
            
        }
        current = current -> next;
    } 
    append(c);
} 

// inserts c immediately after the nth occurance of d, or at the end of the list if d does not occur n times.
void CharList::append(char c, char d, int n){
    if(head == NULL){
        append(c);
        return;
    }
    if (tail -> element == d){
        append(c);
        return;
    }
    int count = 0;
    Node* new_node = new Node;
    new_node -> element = c;
    Node* current = head;
    while(current != NULL){
        if(current -> element == d){
            count = count + 1;
            if (count == n){   
                new_node -> pre = current;
                new_node -> next = current -> next;
                current -> next -> pre = new_node; 
                current -> next = new_node;
                cnt ++;
                return;
            }
           
        }
        current = current -> next;
    } 
    append(c);
} 



// delete the first occurance of character c. Do nothing if c does not occur.
void CharList::remove(char c){
    remove(c,1);
}


// delete the nth occurance of c. Do nothing if c does not occur n times.
void CharList::remove(char c, int n){
    Node* current = head;
    int count = 0;
    while (current != NULL){
        if (current -> element == c){
            count ++; 
        }
        if (count == n){
            if (size()==1){
                head = NULL;
                tail = NULL;
                delete current;
                cnt --;
            }
            else if(current == head){
                current -> next -> pre = NULL;
                head = current -> next;
                delete current;
                cnt --;
            }
            else if(current == tail){
                current -> pre -> next = NULL;
                tail = current -> pre;
                delete current;
                cnt --;
            }
            else{
                current -> pre -> next = current -> next;
                current -> next -> pre = current -> pre;
                cnt--;
            }
            break;
        }
        current = current -> next;
    }
}

// return the list as a string.
string CharList::toString(){
    char arr[size()];
    Node* current = head;
    int i = 0;
    while(current != NULL){
        arr[i] = current -> element;
        current = current -> next;
        i++;
    }  
    arr[i] = '\0';
    string s = arr;
    return s;
} 

// constructor. Initializes the list to the contents of the string.
CharList::CharList(string s){
    cnt = 0;
    head = NULL;
    tail = NULL;
    for (int i = 0; i<s.length(); i++){   
        append(s[i]);
    }
} 


// destructor. Returns all memory in the list.
CharList::~CharList(){
    Node* current = head;
    while(current != NULL){
        current = current -> next;
        delete current;
        cnt --;
    }
    head = NULL;
    tail = NULL;

} 