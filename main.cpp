/*
 * 	Name: Lukas Friedrich
 * 	This program creates a hashtable of dynamiclly allocated linkedlist objects
 */

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now we have two parallel arrays with ids and strings for test data.
     */
    
    Hashtable hashtable;
    
    // show it is empty by calling getCount and printTable
    cout << "Count: " << hashtable.getCount() << endl;
    cout << endl << "Empty: " << endl;
    hashtable.printTable();
    
    // try and put ALL the test data into the table and show what happens
    cout << "Inserting Test Data..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        if (hashtable.insertEntry(ids[i], &strs[i])) {
            cout << "success. entry inserted." << endl;
            cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
        } else {
            cout << "failed. table is likely full or bad input." << endl;
        }
    }
    cout << endl;


    // robust test, can handle all use cases.

    /*
     * Retrieve all the test data from the table one at time
     */
    cout << "Retrieving Test Data on at a time..." << endl;
    string temp = "";
    for (int i = 0; i < testdatasize; i++) {
        temp = hashtable.getData(ids[i]);

        if (temp != "") {
            cout << "success: " << ids[i] << ": " << temp << endl;
        } else {
            cout << "failed: " << ids[i] << " is not in the table." << endl;
        }
    }
    cout << endl;
    cout << endl << "Populated: " << endl;
    hashtable.printTable();

    /*
     * Remove all the test data from the table one at time
     */
    cout << "Removing Test Data one at a time..." << endl;
    bool removed;
    for (int i = 0; i < testdatasize; i++) {
        removed = hashtable.removeEntry(ids[i]);

        if (removed) {
            cout << "success: " << ids[i] << ": removed" << endl;
        } else {
            cout << "failed: " << ids[i] << " is not in the table." << endl;
        }
    }
    cout << endl << "Empty: " << endl;
    hashtable.printTable();

    // Put half the test data into the table
    cout << "Inserting Test Data..." << endl;
    for (int i = 0; i < testdatasize/2; i++) {
        if (hashtable.insertEntry(ids[i], &strs[i])) {
            cout << "success. entry inserted." << endl;
            cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
        } else {
            cout << "failed. table is likely full or bad input." << endl;
        }
    }
    cout << endl;


    //Random testing

    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < TESTCASES; i++) {
        int pos = rand() % testdatasize;
        switch (choice) {
            case 1:
                //PRINT LIST
                hashtable.printTable();
                break;
            case 2:
                // INSERT
                if (hashtable.insertEntry(ids[pos], &strs[pos])) {
                cout << "success. entry inserted." << endl;
                }
                break;
            case 3: //DO NOTHING
            case 4:
                // REMOVE
                removed = hashtable.removeEntry(ids[pos]);
                if (removed) {
                    cout << "success: " << ids[pos] << ": removed" << endl;
                } else {
                    cout << "failed: " << ids[pos] << " is not in the table." << endl;
                }
                break;
            case 5:
                // GET DATA
                temp = hashtable.getData(ids[pos]);

                if (temp != "") {
                    cout << "success: " << ids[pos] << ": " << temp << endl;
                } else {
                    cout << "failed: " << ids[pos] << " is not in the table." << endl;
                }
                break;
            case 6:
                // GET COUNT
                cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
                break;
        }
        choice = rand() % CHOICES + 1;
    }

    // try and put ALL the test data into the table twice (duplicate testing)
    cout << "Inserting Test Data..." << endl;
    for (int i = 0; i < testdatasize*2; i++) {
        int pos = rand() % testdatasize;
        if (hashtable.insertEntry(ids[pos], &strs[pos])) {
            cout << "success. entry inserted." << endl;
            cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
        } else {
            cout << "failed. table is likely full or bad input : " << ids[pos] << endl;
        }
    }
    cout << endl;
        
    
    
    
    return 0;
}
