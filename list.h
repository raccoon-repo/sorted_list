#ifndef __SORTED_LIST__
#define __SORTED_LIST__

enum Order { asc, desc };

class SortedList {
    private:
        struct node * head;
        int count;
        Order order;
        void set_before_head(int);
    public:
        SortedList(Order);
        ~SortedList();

        void addItem(int);               //add item
        int deleteItem(int item);        //delete item
        int retreiveItem(int pos) const; //retrieve item at position
        int searchItem(int item) const;  //return position of the item

        SortedList subList(int, int);
        SortedList copyReverse();
            
        void print();
};

struct node {
    int value;
    struct node * next;
};


#endif