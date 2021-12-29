
#include <iostream>
#include "CharList.h"

using namespace std;

int main(int argc, char** argv) {
	CharList* c = new CharList("abd");
	cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}

	c->insert('c', 'd');
	cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
    else {cout << "Not Empty" << endl;}
//test A & I
    c->append('e');
    cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
    c->insert('a');
    cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
    else {cout << "Not Empty" << endl;}
    
//test A & I letter
    c->append('e', 'd');
    cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
     c->append('f', 'l');
     cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
     c->insert('b', 'c');
    cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
     c->insert('g', 'k');
cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
     if(c->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}

// //test A & I letter n
     c->append('h', 'd', 1);
     cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
     c->append('c', 'b', 1);
     c->insert('i', 'c', 2);
          cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
     c->insert('d', 'c', 2);
     cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
     if(c->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}
    
    
// //delete
     c->remove('a',1);
     cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
     c->remove('a', 1);
          cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
     c->remove('b', 1);
     cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
     c->remove('b', 3);
          cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
     c->remove('c');
      cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
     c->remove('l');
     cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
     if(c->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}
    
     c->remove('d');
     cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
      c->remove('a');
      cout << "result: " << c -> toString() << endl;
      cout << "size: " << c -> size() << endl;
      c->remove('e');
     cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}
     c->remove('b',1);
      cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}
    
//     c->remove('a');
//     c->remove('b');
//     c->remove('c');
//     c->remove('d');
//     c->remove('e');
//     c->remove('f');
//     c->remove('g');
//     c->remove('h');
//     cout << "result: " << c -> toString() << endl;
//     cout << "size: " << c -> size() << endl;
//     if(c->empty()){cout << "Empty" << endl;}
//     else {cout << "Not Empty" << endl;}
//      c->remove('i');
//     cout << "result: " << c -> toString() << endl;
//     cout << "size: " << c -> size() << endl;
//     if(c->empty()){cout << "Empty" << endl;}
//     else {cout << "Not Empty" << endl;}
    
//     delete c;
    
//     CharList* cc = new CharList("z");
//     cout << "result: " << c -> toString() << endl;
//     cout << "size: " << c -> size() << endl;
//     if(c->empty()){cout << "Empty" << endl;}
//     else {cout << "Not Empty" << endl;}
    
//     delete cc;
}