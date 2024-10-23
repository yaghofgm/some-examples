// #include "genericSet.hpp"
#include "Ordered_set.hpp"
#include "Unordered_set.hpp"

// void  Set<T>::insert(T e){
//     assert(elts_size<CAPACITY && "Tried to add a 101st element");
//     if (!contains(e) && elts_size<CAPACITY) //only one of each element, since set
//         elts[elts_size++] = e;
// }

template <typename T>
using Set = Ordered_set<T>;

int main() {
    Set<int> intSet; // we define the type of set we want here
    intSet.insert(1);
    intSet.insert(2);
    intSet.insert(3);

    std::cout << "Set elements: " << intSet << std::endl;

    Set<string>  stringSet;
    stringSet.insert("Myrtle");
    stringSet.insert("Banana");
    stringSet.insert("Maçã");

    std::cout << "Set elements: " << stringSet << std::endl;

    //what if i wanted something with whatever type I have?
    
    return 0;
}