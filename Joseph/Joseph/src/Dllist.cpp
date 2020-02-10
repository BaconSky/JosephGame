#include "Dllist.h"
#include <cstddef>
#include <iostream>

using namespace std;

Dllist::Dllist()
{
    head = NULL;
    curNode = NULL;
}

Dllist::~Dllist()
{
    //dtor
}



void Dllist::addAtBeginning(Data v) {
    NodePtr newNode = new Node;
    newNode->val = v;
    newNode->prev=NULL;
    newNode->next=head;
    if (head != NULL) {
        head->prev= newNode;
    }
    head=newNode;
}


void Dllist::deleteV(Data val) {
    if (head==NULL) return;
    NodePtr headcopy = head;
    // stergere cap lista – tratat separat
    if (headcopy->val==val) {
        head = head->next;
        if(head!=NULL) head->prev=NULL;
        delete headcopy;
        return;
    }

    while (true) {
        if (headcopy->val!=val){
            if (headcopy->next==NULL) break;
            headcopy=headcopy->next;
        } else {
            if (headcopy->next!=NULL) (headcopy->next)->prev=headcopy->prev;
            if (headcopy->prev!=NULL) (headcopy->prev)->next=headcopy->next;
            delete headcopy;
            return;
        }
    }

 /*
    while (headcopy->next!=NULL) {
        if (headcopy->val!=val){
            headcopy=headcopy->next;
        } else {
            if (headcopy->next!=NULL) (headcopy->next)->prev=headcopy->prev;
            if (headcopy->prev!=NULL) (headcopy->prev)->next=headcopy->next;
            delete headcopy;
            return;
        }
    }
*/
}


void Dllist::resetCur() {
    curNode = head;
}


Data Dllist::getCur() {
    return curNode->val;
}

Data Dllist::getHead() {
    if (head == NULL) return -1;
    else return head->val;
}


void Dllist::advanceCur(int steps) {
    if (curNode == NULL) return;
    for (int i=0; i<steps; i++) {
        if (curNode->next == NULL) curNode = head;
        else curNode = curNode->next;
    }
}


int Dllist::getListLen() {
    if (head == NULL) return 0;
    NodePtr headcopy = head;
    int cnt = 1;
    while (headcopy->next != NULL) {
        cnt++;
        headcopy = headcopy->next;
    }
    return cnt;
}




void Dllist::print() {
    Node *headcopy=head;
    while (headcopy!=NULL) {
        cout << headcopy->val << " ";
        headcopy=headcopy->next;
    }
    cout << endl;
}
