#ifndef NODE_H
#define NODE_H

typedef int Data;

class Node
{

    public:
        Data val;
        Node * next, *prev;
        Node();
        virtual ~Node();

    protected:

    private:
};

//


#endif // NODE_H
