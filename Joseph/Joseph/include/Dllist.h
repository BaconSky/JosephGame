#ifndef DLLIST_H
#define DLLIST_H

#include <Node.h>

class Dllist
{
typedef Node *NodePtr;

/*
    typedef int Data;
    typedef struct Elem Node;
    typedef Node *NodePtr;
    struct Elem
    {
        Data val;
        NodePtr next, prev;
    };
*/


    NodePtr head;
    NodePtr curNode;


    public:
        Dllist();
        virtual ~Dllist();

        void addAtBeginning(Data v);
        void deleteV(Data val);

        int getListLen();
        Data getHead();

        void resetCur();
        Data getCur();
        void advanceCur(int steps);



        void print();

    protected:

    private:
};

#endif // DLLIST_H
