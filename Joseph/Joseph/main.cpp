#include <iostream>
#include "Dllist.h"

using namespace std;



int JosephGame(int n, int steps) {
    Dllist dllist;

    for (int i=0; i<n; i++) dllist.addAtBeginning(i);
    cout << "List "; dllist.print();

    dllist.resetCur();
    while(dllist.getListLen() > 1) {
        dllist.advanceCur(steps);
        Data cur = dllist.getCur();
        cout << "execute " << cur << endl;
        dllist.deleteV(cur);
        cout << "List "; dllist.print();
    }
    cout << "survivor " << dllist.getHead() << endl;
    return (dllist.getHead());

}







int main()
{



    Dllist dllist;
    //cout << "ListLen = " << dllist.getListLen() << endl;

    dllist.addAtBeginning(0);
    //cout << "ListLen = " << dllist.getListLen() << endl;
    dllist.addAtBeginning(5);
    dllist.addAtBeginning(7);
    dllist.print();
    dllist.deleteV(7);
    dllist.print();
    //cout << "ListLen = " << dllist.getListLen() << endl;
    dllist.resetCur();
    //cout << "cur = " << dllist.getCur() << endl;
    dllist.advanceCur(1);
    //cout << "cur = " << dllist.getCur() << endl;
    Data cur = dllist.getCur();
    //cout << "cur = " << dllist.getCur() << endl;



    JosephGame(15, 5);


    return 0;
}
