
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

    c->append('e');
    cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
    c->insert('a');
    cout << "result: " << c -> toString() << endl;
    cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
    else {cout << "Not Empty" << endl;}
    

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
    
    

     cout << endl;
     cout << endl;
     cout << endl;
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
     c->insert('b','i');
     cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}
     c->append('a','g');
     cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}
     c->insert('a','b',1);
          cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}
     c->append('g','a',2);
               cout << "result: " << c -> toString() << endl;
     cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}
          delete c;
      //     cout << "result: " << c -> toString() << endl;
      cout << "size: " << c -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}
     
     cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    CharList* cc = new CharList("z");
    cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    if(c->empty()){cout << "Empty" << endl;}
    else {cout << "Not Empty" << endl;}
    cc->insert('a');
     cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    cc->insert('a','z');
     cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    cc->insert('b','a',1);
     cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    cc->insert('c','a',2);
     cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
     cc->insert('c','d');
     cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    cc->append('a');
         cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
     cc->append('a','b');
              cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    cc->append('a','b',2);
                  cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
 cc->append('a','b',1);
                  cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
     cc->remove('a');
                       cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    cc->remove('b');
                       cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    cc->remove('a',3);
                       cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    cc->remove('e');
                       cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    cc->remove('a',5);
                       cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
        cc->remove('a',4);
                       cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
            cc->remove('a',2);
                       cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
                cc->remove('a',1);
                       cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    cc->remove('a',1);
    cc->remove('c');
    cc->remove('c');
    cc->remove('z');
    cout << "result: " << cc -> toString() << endl;
    cout << "size: " << cc -> size() << endl;
    if(cc->empty()){cout << "Empty" << endl;}
     else {cout << "Not Empty" << endl;}
}