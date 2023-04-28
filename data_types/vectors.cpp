#include <vectors>
#include <iostream>
using namespace std

/*
 * Vectors are dynamic arrays
 *
 * They are in the std lib 
 *  push_back(element): Adds an element to the end of the vector.
    pop_back(): Removes the last element of the vector.
    size(): Returns the number of elements in the vector.
    empty(): Returns whether the vector is empty.
    clear(): Removes all elements from the vector.
    resize(new_size): Changes the size of the vector to the specified value.
    capacity(): Returns the number of elements that the vector can store before needing to reallocate memory.
    reserve(new_capacity): Reserve a specific size of memory to avoid frequent reallocation
    operator[] (index) : access the element at index
    at(index): access the element at index, with range check
    begin(): Returns an iterator pointing to the first element in the vector.
    end(): Returns an iterator pointing to the last element in the vector.
    erase(position): Removes the element at the specified position from the vector.
    insert(position, element): Inserts an element at the specified position in the vector.
    assign(count, value): Assigns the specified value to the specified number of elements in the vector.
    swap(other_vector): Swaps the elements of the vector with the elements of another vector.
*/ 
  
int main() {

  // initializer list
  vector<int> vector1 = {1, 2, 3, 4, 5};

  // uniform initialization, nicer syntax way
  vector<int> vector2{6, 7, 8, 9, 10};

  // method 3
  vector<int> vector3(5, 12); // size 5, all value is 12

  cout << "vector1 = ";

  // ranged loop
  for (const int& i : vector1) { //int& i is creating a reference var, ref cant change where they point, its like/is an alias, diff than "address of" usage
    cout << i << "  ";
  }

  cout << "\nvector2 = ";

  // ranged loop
  for (const int& i : vector2) {
    cout << i << "  ";
  }

