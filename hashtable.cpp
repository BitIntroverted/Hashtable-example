/*
 * 	Name: Lukas Friedrich
 * 	Hashtable class
 */ 

#include "hashtable.h"

Hashtable::Hashtable() {
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i] = new LinkedList;
    }
}

Hashtable::~Hashtable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        if (hashtable[i]) {
            delete hashtable[i];
        }
    }
}

/************************************
 * Private
 ************************************/
int Hashtable::hash(int id) {
    return id % HASHTABLESIZE;
}

/************************************
 * Public
 ************************************/

 bool Hashtable::insertEntry(int id, string* info){
     bool inserted = false;
     int hashedID = hash(id);
     if(hashtable[hashedID]->addNode(id, info)){
        inserted = true;
        count++;
     }
     return inserted;
 }

 string Hashtable::getData(int id){
     string ret = "";
     int hashedID = hash(id);
     Data* tempNode = new Data;

     if(hashtable[hashedID]->getNode(id, tempNode)){
        ret = tempNode->data;
     }
    delete tempNode;
    return ret;
 }

 bool Hashtable::removeEntry(int id){
     bool removed = false;
     int hashedID = hash(id);
     if(hashtable[hashedID]->deleteNode(id)){
            removed = false;
            count--;
         }
     return removed;
 }

 int Hashtable::getCount(){
     return count;
 }

 void Hashtable::printTable(){
    for (int i = 0; i < HASHTABLESIZE; i++) {
        cout << "Entry " << i+1 << " ";
        hashtable[i]->printList();
        cout << endl; 
    }
 }