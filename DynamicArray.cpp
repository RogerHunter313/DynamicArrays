#include <iostream>
using namespace std;

class DynamicArray {
    int *data;
    int nextIndex;
    int capacity; // total size of the array

public:
    DynamicArray() {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
    DynamicArray(int c) {
        data = new int[c];
        nextIndex = 0;
        capacity = c;
    }

    DynamicArray(DynamicArray const &d) { // creating out default copy constructor. notice const and reference
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
        // shallow copy this->data = d.data;
        // deep copy
        this->data = new int[d.capacity]; //don't need + 1 for null character. that is for strings
        for(int i = 0; i < d.nextIndex; i++) { // nextIndex vs. capacity? nextIndex to not waste time
            this->data[i] = d.data[i];
        }
    }

    operator=(DynamicArray const &d) {
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
        // shallow copy this->data = d.data;
        // deep copy
        this->data = new int[d.capacity]; //don't need + 1 for null character. that is for strings
        for(int i = 0; i < d.nextIndex; i++) { // nextIndex vs. capacity? nextIndex to not waste time
            this->data[i] = d.data[i];
        }
    }

    void add(int element) {
        if(nextIndex == capacity){
                int *newData = new int[2*capacity];
                for (int i=0; i<capacity; i++) {
                    newData[i] = data[i];
                }
                delete []data; //clean up the array from the heap
                data = newData;
                capacity = capacity * 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    void add(int element, int i) {
        if(i<nextIndex) {
            data[i] = element;
        } else if (i == nextIndex) {
            add(element);
        }else {
            return ; // can throw error or print an error statmeent
        }
    }

    void print() const {
        for(int i = 0; i < nextIndex; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int getElement(int i) const { //array of only positive elements
        if(i>=0 && i<nextIndex) {
            return data[i];
        }
        else {
            return -1;
        }
    }

    int getCapacity() const {
        return capacity;
    }

};

int main() {
    DynamicArray d1;  // default
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    cout << d1.getElement(2) << endl;

    d1.print();
    cout << d1.getCapacity() << endl;

    DynamicArray d2(d1);  //copy constructor called, shallow copy of the data pointer without
                            // creation of a copy constructor that implements deep copy
    DynamicArray d3; // our default constructor
    d3 = d1; // inbuilt copy assignment operator, shallow copy without operator overloading

    d1.add(100,0);
    d1.print();
    d2.print();
    d3.print();

    DynamicArray d4(100);  //parameterized
    cout << d4.getCapacity() << endl;


    return 0;
}
