/*
 * the compiler will generate a default constructor if not given
 */

class Example {
  int a, b;
 public:
  // default constructor
  Example() { 
    a = 0;
    b = 0;
  }

  // parameterized constructor
  Example(int x, int y) {
    a = x;
    b = y;
  }
  // copy constructor (shallow copy)
  // used when object passed by val
  // or when obj return by val
  // or when obj used to initialize obj
  Example(const Example &other) {
    a = other.a;
    b = other.b;
  }
  // other methods
  void print() {
    cout << "a: " << a << " b: " << b << endl;
  }
  //...
};

int main() {
  Example obj;   // calls the default constructor
  obj.print(); // a: 0 b: 0
  Example obj1(5,8); // calls the Parameterized constructor
  obj1.print(); // a: 5 b: 8
  Example obj2(obj1);  // calls the copy constructor
  obj2.print(); // a: 5 b: 8
  return 0;
}

