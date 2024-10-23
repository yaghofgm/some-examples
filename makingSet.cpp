#include <iostream>
#include <cstddef> //for size_t
#include <cassert>

using namespace std;


class Set{
public:
    Set(): elts_size(0){}
    void  insert(int e){
        assert(elts_size<CAPACITY && "Tried to add a 101st element");
        if (!contains(e) && elts_size<CAPACITY) //only one of each element, since set
            elts[elts_size++] = e;
    }
    void remove(int e){
        int target = index_of(e);
        if (target == -1) return; //do nothing, say nothing ("removed")
        elts_size--; //decreases the counter
        elts[target] = elts[elts_size]; 
    }
    bool contains (int e) const{
        return index_of(e) != -1;
    }
    size_t size() const{
        return elts_size;
    }
    friend std::ostream& operator<<(std::ostream& os, const Set &s); //we can access the private elemnts outside
private: 
    static const int CAPACITY = 100; //100 is a magic number 
    int elts[CAPACITY]; 
    size_t elts_size;

    //EFFECTS: returns -1 if does not find, else returns the index
    int index_of(int e) const{
        for (int i = 0; i<static_cast<int>(elts_size);i++){
            if (elts[i] == e) return i; //found, gets the first one that appears
        }
        return -1; //not found 
    };
};

std::ostream& operator<<(std::ostream& os, const Set &s){
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
}

int main() {
    Set mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    std::cout << "Set elements: " << mySet << std::endl;

    return 0;
}