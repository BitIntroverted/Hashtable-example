/*
 * 	Name: Lukas Friedrich
 * 	Hashtable header
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASHTABLESIZE 15

#include "linkedlist.h"

class Hashtable : public LinkedList {

    public:

        Hashtable();
        ~Hashtable();

        bool insertEntry(int, string*);
        string getData(int);
        bool removeEntry(int);
        int getCount();
        void printTable();

    private:

        int count;
        LinkedList* hashtable[HASHTABLESIZE];

        int hash(int);

};

#endif /*HASHTABLE_H*/
