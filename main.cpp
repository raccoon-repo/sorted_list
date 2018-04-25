#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;

int main() 
{

    SortedList list = SortedList(asc);
    
    list.addItem(1);
    list.addItem(3);
    list.addItem(-2);
    list.addItem(0);

    list.print(); //-2 0 1 3

    SortedList sub_list = list.subList(1, 3);
    sub_list.print(); // 0 1 3

    // SortedList sub_list1 = list.subList(-2, 9); //an exception is thrown

    list.deleteItem(0);
    list.print(); // -2 1 3

    list.addItem(6);
    list.addItem(3);

    int value = list.retreiveItem(3);
    cout << value << endl; //3

    value = list.searchItem(0);
    cout << value << endl; //-1
    

    value = list.searchItem(3);
    cout << value << endl; //2

    list.print();
    SortedList reversed = list.copyReverse();
    reversed.print();

    system("pause");
    return 0;
}