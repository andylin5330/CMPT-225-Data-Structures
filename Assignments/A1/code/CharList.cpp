#include "CharList.h"

// is the list empty?
bool CharList::empty(){
    return head == NULL;
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
    Node* current = head->next;
    if (size() == 1){
        if (current-> element == c){
            head = NULL;
            cnt--;
        }     
    }
    else{
        if(current -> element == c){
            current -> pre -> next = current -> next;
            current -> next -> pre = current -> pre;
            head = current -> next;
            cnt--;
        }
        else{
            current = head;
            while (current != NULL){
                if (current -> element == c){
                    current -> pre -> next = current -> next;
                    current -> next -> pre = current -> pre;
                    cnt--;
                    break;
                }
                current = current -> next;
            }
        } 
    }
}


// delete the nth occurance of c. Do nothing if c does not occur n times.
void CharList::remove(char c, int n){
    Node* current = head->next;
    int count = 0;
    if (size == 1){
        if (head -> element == c){
            current -> pre -> next = current -> next;
            current -> next -> pre = current -> pre;
            cnt--;
        }     
    }
    else{  
        while (current != NULL){
            if (current -> element == c){
                count ++;
                if (count == n){
                    current -> pre -> next = current -> next;
                    current -> next -> pre = current -> pre;
                    cnt--;
                    break;
                }
                
            }
            current = current -> next;
        }
        
    }
}

// return the list as a string.
string CharList::toString(){
    char arr[size()];
    //char* arr = new char();
    Node* current = head;
    int i = 0;
    while(current != NULL){
        arr[i] = current -> element;
        current = current -> next;
        //cout << arr[i] << endl;
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
    while(!empty()){
        current = head -> next;
        remove(head -> element);
        head = current;
    }
    delete head;
    delete tail;
} 