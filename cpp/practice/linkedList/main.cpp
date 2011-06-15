#include <iostream>
#include "LinkedList.h"

int main(){
    LinkedList ll = LinkedList();

    Node *n;
    for (int i=0; i<10; i++){
        n = new Node(i);
        ll.addAtEnd(n);
    }

    ll.print(ll.head);
}
