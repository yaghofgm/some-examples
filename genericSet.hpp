#include <iostream>
#include <cstddef> //for size_t
#include <cassert>

using namespace std;

#ifndef SET_H //to define only once
#define SET_H

template <typename T>
class Set{
public:
    Set(): elts_size(0){}
    void  insert(T e){ 
        //will be pushing forward from the middle 
       //assuming that the sorted work, keep sorted
        assert(elts_size<CAPACITY && "Tried to add a 101st element");
        if (index_of(e) != -1) return; //present
        int gap = elts_size;
        while (gap>0 && v<elts[gap-1]){
            elts[gap] = elts[gap-1]; //we are pushing those forward
            gap--;
        }
        elts[gap] = e;
        elts_size++; 
    };
    void remove(T e){
        // assuming the sorted works
        size_t i = index_of(e);
        if (i == -1) return; //do nothing, say nothing ("removed")
        elts_size--;
        while (i < elts_size-1){
            elts[i] = elts[i+1];
            i++
        }
    };
    bool contains (T e) const{
        return index_of(e) != -1;
    };
    size_t size() const{
        return elts_size;
    };
    friend std::ostream& operator<<(std::ostream& os, const Set &s) {
        os<<"{ ";
        bool first = true;
        // for (auto el:s.elts){ 
        for (size_t i=0;i<s.elts_size;i++){
            if (first) {
                first = false; //first does not need comma
            } else {
                os <<", " ;
            }
            os<<s.elts[i];
        }
        os<<" }";
        return os;
    }; //we can access the private elemnts outside
private: 
    static const int CAPACITY = 100; //100 is a magic number 
    T elts[CAPACITY]; 
    size_t elts_size;

    //EFFECTS: returns -1 if does not find, else returns the index
    int index_of(T e) const{
        int start = 0;
        int end = elts_size;
        while (start < end){
            //find middle element
            int mid = start + (end-start)/2; //wont overflow
            if (elts[mid] == v)
                return mid;
            else if (elts[mid]> e)
                end = mid; //so as to not check twice stuff
            else 
                start = mid+1; //so as to not check twice stuff
        }
    };
};

//we could declare the friend function outside as well, 
//but we would need the template <typename T> immediately above it

#endif

