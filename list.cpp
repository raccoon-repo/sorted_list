#include "list.h"
#include <iostream>
using namespace std;

SortedList::SortedList(Order o) {
    count = 0;
    head = new node;
    order = o;
}

void SortedList::set_before_head(int item) {
    node * item_node = new node;
    item_node->value = item;
    item_node->next = head;
    head = item_node;
    count++;
}

SortedList::~SortedList() {
    node * t1 = head;
    node * t2;
    while (t1) {
        t2 = t1;
        t1 = t1->next;
        delete t2;    
    }
}

void SortedList::addItem(int item) {
    if (count == 0) {
        count++;
        head->value = item;
        return;
    }

    if (head->value >= item && order == asc) {
        set_before_head(item);
        return;
    } else if (head->value <= item && order == desc) {
        set_before_head(item);
        return;
    }

    node * current = head;
    node * prev = head;
    node * item_node;

    if (order == asc) {
        while (current && item > current->value) {
            prev = current;
            current = current->next;
        }
    } else if (order == desc) {
        while (current && item < current->value) {
            prev = current;
            current = current->next;
        }
    }

    item_node = new node;
    item_node->value = item;

    prev->next = item_node;
    item_node->next = current;
    count++;
}

int SortedList::deleteItem(int item) {
    node * current = head;
    node * prev = current;
    if (count == 0) {
        throw invalid_argument("list is empty");
    }

    while (current && current->value != item) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        cout << "list doesn't contain " << item;
        return item;
    } else {
        while (current && current->value == item) {
            prev->next = current->next;
            delete current;
            current = prev->next;
            count--;
        }

        return item;
    }

}

int SortedList::retreiveItem(int idx) const {

    if (idx >= count)
        throw std::out_of_range("index is out of range");
    node * temp = head;
    int c = 0;

    while (c != idx) { c++; temp = temp->next; } 
    return temp->value;
}

int SortedList::searchItem(int item) const {
    node * temp = head;
    int index = 0;

    while (temp && temp->value != item) {
        temp = temp->next;
        index++;
    }

    if (!temp)
        return -1;
    else
        return index;
}

void SortedList::print() {
    node * temp = head;
    int c = 0;

    while (temp && c < count) {
        cout << temp->value << " ";
        temp = temp->next;
    }

    cout << endl;
}

SortedList SortedList::subList(int begin, int end) {
    SortedList resultList(asc);

    if (begin > end || begin < 0) {
        throw std::out_of_range("begin must be less than end and must be a positive integer");
    }

    if (end >= count) {
        end = count - 1;
    }


    node * start = head;

    int t = 0;
    while (t < count && t < begin) {
        start = start->next;
        t++;
    }

    node * temp = resultList.head;

    while (t <= end) {
        temp->value = start->value;
        start = start->next;
        
        if (t < end)
            temp->next = new node;
        temp = temp->next;
        t++;
    }

    return resultList;
}

SortedList SortedList::copyReverse() {
    SortedList reversed(desc);
    node * iterator = head;
    while (iterator) {
        reversed.addItem(iterator->value);
        iterator = iterator->next;
    }

    return reversed;
}
