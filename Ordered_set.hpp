#include <iostream>
#include <cstddef> //for size_t
#include <cassert>

using namespace std;

#ifndef SET_H //to define only once
#define SET_H
#define NDEBUG //disable assert()

template <typename T>
class Ordered_set{
public:
    Ordered_set(): elts_size(0), elts_capacity(CAPACITY_DEFAULT) {
        assert(check_invariant());
        }
    Ordered_set(int cap):elts_size(0),elts_capacity(cap){
        //create new dynamic array of size cap
        assert(check_invariant());
        elts = new int[cap];
    }
    ~Ordered_set(){
        delete[] elts; //for deleting arrays on dtor
    }
    void  insert(T e){ //binary search, since sorted
        //will be pushing forward from the middle 
       //assuming that the sorted work, keep sorted
        assert(elts_size<CAPACITY && "Tried to add a 101st element");
        assert(check_invariant());
        if (index_of(e) != -1) return; //present
        int gap = elts_size;
        while (gap>0 && v<elts[gap-1]){
            elts[gap] = elts[gap-1]; //we are pushing those forward
            gap--;
        }
        elts[gap] = e;
        elts_size++; 
        assert(check_invariant());
    };
    void remove(T e){
        // assuming the sorted works
        assert(check_invariant());
        size_t i = index_of(e);
        if (i == -1) return; //do nothing, say nothing ("removed")
        elts_size--;
        while (i < elts_size-1){
            elts[i] = elts[i+1];
            i++
        }
        assert(check_invariant());
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
    static const int CAPACITY_DEFAULT = 100; //100 is a magic number 
    size_t elts_size;
    int elts_capacity; //use dynamic memory so as to not make it be magic number 
    T* elts; //pointer to dynamic array
    

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

    //EFFECTS: returns true if the rep. invariant holds. 
    //check that it is ordered from smallest to biggest and no repeated,
    // because the size is handled by the memory alloc
    bool check_invariant() const{
        for (int i=0; i<elts_size-1;i++){
            if (elts[i]>=elts[i+1]){
                return false;
            }
        }
        return true;
    }
};

//we could declare the friend function outside as well, 
//but we would need the template <typename T> immediately above it

#endif

