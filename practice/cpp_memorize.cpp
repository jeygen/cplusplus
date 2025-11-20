///////////////////
/// Containers
///
v.push_back(x); 
v.emplace_back(x); 
//  emplace_back lets you construct the element directly inside the container, potentially saving a copy/move; push_back inserts an already‑created object. Use emplace_back when you can supply constructor arguments and want the most efficient insertion.
    std::vector<Person> v;

    std::cout << "=== push_back ===\n";
    Person p("Alice", 30);          // ctor once
    v.push_back(p);                 // copy
    v.push_back(Person("Bob",25));  // ctor + move (temporary)

    std::cout << "\n=== emplace_back ===\n";
    v.emplace_back("Carol", 22);    // ctor only, no extra copy/move
    v.emplace_back(std::move(p));  // uses move‑ctor directly (no copy)
    
// emplace_back does the same logical thing (adds an element to the end of the container), but when you need a brand‑new object it can be faster because it builds that object directly inside the container’s storage.
    
v.insert(it, x);
     std::vector<int> v = {10, 20, 30, 40};

    // 1. Find 30 and insert 25 before it
    auto it = std::find(v.begin(), v.end(), 30);
    if (it != v.end())
        it = v.insert(it, 25);          // v = {10,20,25,30,40}

    // 2. Insert three copies of 99 after the newly inserted 25
    v.insert(it + 2, 3, 99);            // v = {10,20,25,30,99,99,99,40}

    // 3. Append a range from another container
    std::vector<int> extra = {1,2,3};
    v.insert(v.end(), extra.begin(), extra.end());

    // Print result
    for (int x : v) std::cout << x << ' ';
    // Output: 10 20 25 30 99 99 99 40 1 2 3
    
v.erase(it); 
//If you simply want to delete the first occurrence of 30:
	auto it = std::find(v.begin(), v.end(), 30);
	if (it != v.end())
    v.erase(it);          // removes only the element equal to 30
    // returns it of next element in vector if you want to assign it to something
//If you need to delete all occurrences of 30 you can use the remove‑erase idiom:
	v.erase(std::remove(v.begin(), v.end(), 30), v.end());

    
v.clear(); 
v.size(); 
v.empty();


for (auto& x : v) {} 

v.begin(); v.end(); v.rbegin(); v.rend();

v.find(k);  // returns it
v.count(k); // returns 0 or 1 if present at all

    std::unordered_map<std::string, int> ages = {
        {"Alice", 30},
        {"Bob", 25}
    };

    // idiomatic find usage
    if (auto it = ages.find("Alice"); it != ages.end()) {   // C++17 init-if
        std::cout << "Alice is " << it->second << " years old.\n";
    } else {
        std::cout << "Alice not found.\n";
    }

    // idiomatic count usage (useful for quick existence checks)
    if (ages.count("Charlie")) {
        std::cout << "Charlie exists in map.\n";
    } else {
        std::cout << "Charlie not found.\n";
    }


m[key] = val; 
m.insert({k, v}); 
m.emplace(k, v); 


std::pair<int,int> p = {1,2}; // 1 entry unordered_map kinda
auto p = std::make_pair(1,2); 
std::tie(a,b) = p; //
std::get<0>(t);
#include <utility>  // for std::pair, std::make_pair, std::tie

    // direct init
    std::pair<int, int> p = {1, 2};

    // idiomatic: use make_pair (type deduced)
    auto p2 = std::make_pair(3, 4);

    // structured bindings (C++17)
    auto [x, y] = p2;
    std::cout << x << ", " << y << '\n'; // 3, 4

    // std::tie for unpacking existing pair
    int a, b;
    std::tie(a, b) = p;   // assigns a=1, b=2

    // std::get<N> for tuple-like access
    std::cout << std::get<0>(p) << '\n'; // prints 1


/////////////
/// algorithms
///
std::find(b,e,x); 
std::count(b,e,x); 
std::binary_search(b,e,x);
std::min(a,b); 
std::max(a,b); 
std::min_element(b,e); 
std::max_element(b,e);
std::sort(b,e); 
std::sort(b,e,cmp); 
std::reverse(b,e); 
std::unique(b,e);
std::for_each(b,e,f); 
std::transform(b,e,dest,f); 
std::accumulate(b,e,0);
std::set_union(b1,e1,b2,e2,dest); 
std::set_intersection(b1,e1,b2,e2,dest); 
std::merge(b1,e1,b2,e2,dest);
std::remove(b,e,x); 
std::remove_if(b,e,pred); 
std::replace(b,e,x,y); 
std::replace_if(b,e,pred,y);

#include <iostream>
#include <vector>
#include <algorithm> // find, count, sort, min/max_element, binary_search
#include <numeric>   // for accumulate if needed later

int main() {
    // std::find(b,e,x);  // linear search; returns iterator (or end)
    std::vector<int> v1 = {5, 7, 7, 9};
    if (auto it = std::find(v1.begin(), v1.end(), 7); it != v1.end())
        std::cout << "found at idx " << std::distance(v1.begin(), it) << '\n';

    // std::count(b,e,x);  // count occurrences (linear)
    std::vector<int> v2 = {5, 7, 7, 9};
    std::cout << std::count(v2.begin(), v2.end(), 7) << " copies of 7\n";

    // std::binary_search(b,e,x);  // O(log N) membership test; RANGE MUST BE SORTED
    std::vector<int> v3 = {9, 7, 5, 7};
    std::sort(v3.begin(), v3.end());                     // required
    if (std::binary_search(v3.begin(), v3.end(), 7))     // true if any 7 exists
        std::cout << "7 present\n";

    // std::min(a,b);  // returns the smaller; watch mixed types
    int a = 3, b = 5;
    std::cout << std::min(a, b) << '\n';

    // std::max(a,b);  // returns the larger
    std::cout << std::max(a, b) << '\n';

    // std::min_element(b,e);  // iterator to smallest element
    std::vector<int> v4 = {5, 7, 2, 9};
    auto it_min = std::min_element(v4.begin(), v4.end());
    if (it_min != v4.end()) std::cout << *it_min << '\n';       // prints 2

    // std::max_element(b,e);  // iterator to largest element
    auto it_max = std::max_element(v4.begin(), v4.end());
    if (it_max != v4.end()) std::cout << *it_max << '\n';       // prints 9

    // std::sort(b,e);  // ascending, strict-weak-order, random-access iters
    std::vector<int> v5 = {5, 7, 2, 9};
    std::sort(v5.begin(), v5.end());                     // v = {2,5,7,9}
    for (int x : v5) std::cout << x << ' '; std::cout << '\n';

    // std::sort(b,e,cmp);  // custom comparator (e.g., descending)
    std::vector<int> v6 = {5, 7, 2, 9};
    std::sort(v6.begin(), v6.end(), [](int x, int y){ return x > y; }); // desc
    for (int x : v6) std::cout << x << ' '; std::cout << '\n';
}



#include <iostream>
#include <vector>
#include <algorithm> // reverse, unique, for_each, transform, set ops, remove, replace
#include <numeric>   // accumulate
#include <iterator>  // back_inserter

int main() {
    // std::reverse(b,e);  // reverses in place
    std::vector<int> v1 = {1, 2, 3, 4};
    std::reverse(v1.begin(), v1.end());                  // v1 = {4,3,2,1}
    for (int x : v1) std::cout << x << ' '; std::cout << '\n';

    // std::unique(b,e);  // removes consecutive duplicates, returns new end
    std::vector<int> v2 = {1,1,2,2,3,3,3,4};
    auto new_end = std::unique(v2.begin(), v2.end());    // v2 = {1,2,3,4,?,?}
    v2.erase(new_end, v2.end());                         // erase garbage tail
    for (int x : v2) std::cout << x << ' '; std::cout << '\n';

    // std::for_each(b,e,f);  // apply f to each element
    std::vector<int> v3 = {1,2,3};
    std::for_each(v3.begin(), v3.end(), [](int& x){ x *= 2; }); // double each
    for (int x : v3) std::cout << x << ' '; std::cout << '\n';

    // std::transform(b,e,dest,f);  // apply f and store results
    std::vector<int> v4 = {1,2,3,4};
    std::vector<int> out;
    std::transform(v4.begin(), v4.end(), std::back_inserter(out),
                   [](int x){ return x * x; });          // squares
    for (int x : out) std::cout << x << ' '; std::cout << '\n';

    // std::accumulate(b,e,0);  // sum elements; 0 = initial value
    std::vector<int> v5 = {1,2,3,4};
    int sum = std::accumulate(v5.begin(), v5.end(), 0);
    std::cout << "sum = " << sum << '\n';

    // std::set_union(b1,e1,b2,e2,dest);  // requires sorted ranges
    std::vector<int> a = {1,2,4};
    std::vector<int> b = {2,3,5};
    std::vector<int> uni;
    std::set_union(a.begin(), a.end(), b.begin(), b.end(),
                   std::back_inserter(uni));             // union = {1,2,3,4,5}
    for (int x : uni) std::cout << x << ' '; std::cout << '\n';

    // std::set_intersection(b1,e1,b2,e2,dest);  // sorted ranges
    std::vector<int> inter;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                          std::back_inserter(inter));    // {2}
    for (int x : inter) std::cout << x << ' '; std::cout << '\n';

    // std::merge(b1,e1,b2,e2,dest);  // merge sorted ranges (duplicates kept)
    std::vector<int> merged;
    std::merge(a.begin(), a.end(), b.begin(), b.end(),
               std::back_inserter(merged));              // {1,2,2,3,4,5}
    for (int x : merged) std::cout << x << ' '; std::cout << '\n';

    // std::remove(b,e,x);  // remove all matching x; returns new end (erase idiom)
    std::vector<int> v6 = {1,2,3,2,4,2,5};
    v6.erase(std::remove(v6.begin(), v6.end(), 2), v6.end()); // remove all 2s
    for (int x : v6) std::cout << x << ' '; std::cout << '\n';

    // std::remove_if(b,e,pred);  // remove elements matching predicate
    std::vector<int> v7 = {1,2,3,4,5,6};
    v7.erase(std::remove_if(v7.begin(), v7.end(),
                            [](int x){ return x % 2 == 0; }), v7.end()); // remove evens
    for (int x : v7) std::cout << x << ' '; std::cout << '\n';

    // std::replace(b,e,x,y);  // replace all x with y
    std::vector<int> v8 = {1,2,2,3};
    std::replace(v8.begin(), v8.end(), 2, 9);            // {1,9,9,3}
    for (int x : v8) std::cout << x << ' '; std::cout << '\n';

    // std::replace_if(b,e,pred,y);  // replace all satisfying pred
    std::vector<int> v9 = {1,2,3,4,5};
    std::replace_if(v9.begin(), v9.end(),
                    [](int x){ return x > 3; }, 0);      // {1,2,3,0,0}
    for (int x : v9) std::cout << x << ' '; std::cout << '\n';
}

//////////////
/// pointers
///
#include <iostream>
#include <memory> // unique_ptr, shared_ptr, weak_ptr

struct Foo {
    int x;
    Foo(int n) : x(n) { std::cout << "Foo(" << x << ") constructed\n"; }
    ~Foo() { std::cout << "Foo(" << x << ") destroyed\n"; }
};

int main() {
    // std::unique_ptr<T> p = std::make_unique<T>(args...);
    // Owns a single object exclusively. Auto-deletes when out of scope.
    auto p = std::make_unique<Foo>(42);
    std::cout << "p->x = " << p->x << '\n';

    // p.get();  // get raw pointer (non-owning)
    Foo* raw = p.get();
    std::cout << "raw->x = " << raw->x << '\n';

    // p.release();  // releases ownership; caller must delete manually
    Foo* leaked = p.release();   // p now holds nullptr
    std::cout << "p after release = " << (p ? "valid" : "null") << '\n';
    delete leaked;               // must manually clean up

    // p.reset();  // deletes owned object and sets to nullptr (safe cleanup)
    p = std::make_unique<Foo>(100);
    p.reset();                   // calls Foo destructor

    // std::shared_ptr<T> sp = std::make_shared<T>(args...);
    // Reference-counted ownership; multiple shared_ptrs can share same object
    auto sp1 = std::make_shared<Foo>(7);
    {
        auto sp2 = sp1;          // increases ref count
        std::cout << "use_count = " << sp1.use_count() << '\n'; // 2
    }                            // sp2 destroyed -> count decreases
    std::cout << "use_count = " << sp1.use_count() << '\n';     // 1

    // std::weak_ptr<T> wp = sp;  // non-owning reference; avoids cycles
    std::weak_ptr<Foo> wp = sp1;
    if (auto s = wp.lock()) {    // lock() -> shared_ptr if still alive
        std::cout << "locked Foo.x = " << s->x << '\n';
    }

    sp1.reset();                 // deletes Foo (no more shared owners)
    if (wp.expired())
        std::cout << "Foo expired\n";
}

// add raw pointers


/////////
/// functional utility
///

#include <iostream>
#include <functional>   // std::function, std::bind, std::ref
#include <utility>      // std::move, std::forward, std::swap
#include <optional>     // std::optional
#include <variant>      // std::variant
#include <any>          // std::any
#include <string>       // std::string
#include <thread>       // std::thread
#include <mutex>        // std::mutex, std::lock_guard

// --- helper to demo perfect forwarding ---
void consume(const std::string& s) { std::cout << "consume lvalue: " << s << '\n'; }
void consume(std::string&& s)      { std::cout << "consume rvalue: " << s << '\n'; }

template <class T>
void relay(T&& t) {                  // t is a forwarding reference
    consume(std::forward<T>(t));     // preserves value category
}

int main() {
    // std::function<int(int)> f = [](int x){return x*x;}; auto g = std::bind(f,2);
    std::function<int(int)> f = [](int x){ return x * x; };
    auto g = std::bind(f, 2);                    // binds first arg = 2; g() -> f(2)
    std::cout << "g() = " << g() << '\n';       // 4  (note: prefer lambdas over bind in modern code)

    // auto& r = std::ref(obj);  // wrap an lvalue so APIs take it by ref (e.g., in std::function)
    int obj = 10;
    auto rw = std::ref(obj);                     // reference_wrapper<int>
    rw.get() = 20;                               // modifies obj
    std::cout << "obj via ref = " << obj << '\n';

    // std::move(x);  // cast to rvalue to enable moves
    std::string s1 = "hello", s2 = std::move(s1); // s1 moved-from
    std::cout << "s2=" << s2 << " s1(size)=" << s1.size() << '\n';

    // std::forward<T>(x);  // perfect-forward inside templates (see relay)
    std::string name = "world";
    relay(name);                 // lvalue path
    relay(std::string("WORLD")); // rvalue path

    // std::swap(a,b);  // noexcept swap where possible
    int a = 1, b = 2; std::swap(a, b);
    std::cout << "a=" << a << " b=" << b << '\n';

    // std::optional<int> o = 5; o.value(); o.has_value();
    std::optional<int> o = 5;
    if (o.has_value()) std::cout << "opt=" << o.value() << '\n';
    o.reset(); // no value now

    // std::variant<int,string> v = "hi"; std::get<string>(v);
    std::variant<int, std::string> v = std::string("hi");
    std::cout << "variant str = " << std::get<std::string>(v) << '\n';
    v = 123; // now holds int

    // std::any a = 42; std::any_cast<int>(a);
    std::any anyv = 42;
    std::cout << "any int = " << std::any_cast<int>(anyv) << '\n';
    anyv = std::string("txt");
    std::cout << "any str = " << std::any_cast<std::string>(anyv) << '\n';

    // std::thread t(func); t.join(); std::mutex m; std::lock_guard<std::mutex> lg(m);
    int counter = 0;
    std::mutex m;
    auto work = [&]{
        for (int i = 0; i < 1000; ++i) {
            std::lock_guard<std::mutex> lg(m);  // RAII lock
            ++counter;
        }
    };
    std::thread t(work);
    work();           // main thread does same work
    t.join();         // wait for worker
    std::cout << "counter=" << counter << '\n'; // should be 2000
}

//////////
/// io and strings
///
#include <iostream>
#include <fstream>   // std::ifstream, std::ofstream
#include <string>
#include <sstream>   // std::stringstream
#include <cctype>    // std::isalpha, std::isspace, std::ispunct

int main() {
    // --- numeric ↔ string conversions ---
    int n = 42;
    std::string s1 = std::to_string(n);              // number → string
    std::cout << s1 << '\n';

    std::string s2 = "123";
    int i = std::stoi(s2);                           // string → int
    float f = std::stof("3.14");                     // string → float
    double d = std::stod("2.71828");                 // string → double
    std::cout << i << ' ' << f << ' ' << d << '\n';

    // --- reading from stdin ---
    std::cout << "Enter line: ";
    std::string line;
    std::getline(std::cin, line);                    // read full line (with spaces)
    std::cout << "You typed: " << line << '\n';

    std::cout << "Press a key: ";
    char c = std::getchar();                         // get single character input
    std::cout << "\nYou pressed: " << c << '\n';

    // --- stringstream example ---
    std::stringstream ss("10 20 30");
    int a, b, c2;
    ss >> a >> b >> c2;
    std::cout << "Read: " << a << "," << b << "," << c2 << '\n';

    // --- string manipulation ---
    std::string s = "abcdef";
    std::cout << s.substr(2, 3) << '\n';             // "cde"

    std::string text = "hello world";
    auto pos = text.find("world");                   // returns index or npos
    if (pos != std::string::npos)
        std::cout << "'world' at " << pos << '\n';

    text.replace(pos, 5, "there");                   // "hello there"
    std::cout << text << '\n';

    text.erase(5, 6);                                // removes " there"
    std::cout << text << '\n';                       // "hello"

    text.insert(5, ", world!");
    std::cout << text << '\n';                       // "hello, world!"

    // --- character classification ---
    char ch1 = 'A', ch2 = ' ', ch3 = '.';
    std::cout << std::isalpha(ch1) << " "            // 1 (true)
              << std::isspace(ch2) << " "            // 1 (true)
              << std::ispunct(ch3) << '\n';          // 1 (true)

    // --- basic file handling with ifstream/ofstream ---
    {
        // write a simple text file
        std::ofstream ofs("example.txt");
        if (!ofs) {
            std::cerr << "Error opening file for writing\n";
            return 1;
        }
        ofs << "First line\nSecond line\n123 456 789\n";
    } // file auto-closes when ofs goes out of scope

    {
        // read file line by line
        std::ifstream ifs("example.txt");
        if (!ifs) {
            std::cerr << "Error opening file for reading\n";
            return 1;
        }

        std::cout << "\n--- Contents of example.txt ---\n";
        std::string file_line;
        while (std::getline(ifs, file_line))
            std::cout << file_line << '\n';
    }

    {
        // read numbers from file via stringstream
        std::ifstream ifs("example.txt");
        std::string last;
        for (std::string line; std::getline(ifs, line);)
            last = line;                             // grab last line "123 456 789"

        std::stringstream sstream(last);
        int x, y, z;
        sstream >> x >> y >> z;
        std::cout << "Numbers: " << x << "," << y << "," << z << '\n';
    }

    return 0;
}
//////////
/// error handling
///
#include <iostream>
#include <stdexcept>  // std::runtime_error, std::logic_error, std::exception

// a function that may throw exceptions
void risky(bool trigger_runtime) {
    if (trigger_runtime)
        throw std::runtime_error("runtime failure occurred");
    else
        throw std::logic_error("logic error occurred");
}

int main() {
    try {
        risky(true);   // change to false to trigger logic_error
    }
    catch (const std::logic_error& e) {             // catch specific first
        std::cerr << "Logic error: " << e.what() << '\n';
    }
    catch (const std::runtime_error& e) {           // catch next specific
        std::cerr << "Runtime error: " << e.what() << '\n';
    }
    catch (const std::exception& e) {               // catch all std::exceptions
        std::cerr << "Generic error: " << e.what() << '\n';
    }

    // explicit throwing examples
    try {
        throw std::runtime_error("manual runtime error");
    }
    catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << '\n';
    }

    try {
        throw std::logic_error("manual logic error");
    }
    catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << '\n';
    }

    return 0;
}
/////// lambdas
auto add = [](int a, int b) { return a + b; };
std::cout << add(3, 4); // Output: 7   
                        //
int x = 5; // can use vars in same scope
auto printX = [x]() { std::cout << x; }; // Captures x by value
printX(); // Output: 5   

// common app
std::vector<int> vec = {3, 1, 4, 1, 5};
std::sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; }); // Sort in descending order   
        
//////////
/// classes (basics, inheritance, rule-of-5, RAII, overrides)
///
#include <iostream>
#include <cstring>    // std::strlen, std::strcpy

// --- simple class with ctor/dtor, const method, operator<< ---
class Point {
    // _ non_static usually private naming convention
    int x_, y_;
public:
    Point(int x=0, int y=0) : x_(x), y_(y) {}
    int x() const { return x_; }                    // const accessor
    int y() const { return y_; } // const here means method want change member
    void move(int dx, int dy) { x_ += dx; y_ += dy; }
    // friend lets the function see Point's private data
    // osstream& os allows multiple objecs to be chained, ie printed
    // use case:
    // std::cout << "Both together: " << p1 << " & " << p2 << '\n';
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x_ << "," << p.y_ << ")";
    }
};

// --- inheritance + virtual (polymorphism) ---
struct Shape {
    virtual ~Shape() = default;            // base dtor must be virtual
                                           // cant rely on parent dtor
                                           // ensures everyhting is dtor'd
    virtual double area() const = 0;       // pure virtual
};
struct Rect : Shape {
    double w, h;
    Rect(double w, double h) : w(w), h(h) {}
    double area() const override { return w * h; }  // override keyword helps
  // const because overriding const
};
struct Circle : Shape {
    double r;
    explicit Circle(double r) : r(r) {}
    double area() const override { return 3.141592653589793 * r * r; }
};

// --- rule-of-5 demo: manual resource management (prefer std::string/unique_ptr in new code) ---
class CStr {
    char* buf;                                      // raw owning pointer (RAII)
public:
    // ctor always new object in mem
    // copy is deep copy
    // assign is like a_obj = b_obj
    // move 'steals' resources
    // rule of 3
    // manage a raw pointer, file, etc then define dtor, ctor, copy ctor
    // rule of 5
    // define move stuff if wanted
    // rule of 0 
    // dont define any and rely on RAII, use smartptr, string, vector
    explicit CStr(const char* s = "")
    : buf(new char[std::strlen(s) + 1]) { std::strcpy(buf, s); }

    ~CStr() { delete[] buf; }                       // 1) destructor

    CStr(const CStr& o)                             // 2) copy ctor
    : CStr(o.buf) {}

    CStr& operator=(const CStr& o) {                // 3) copy assign
        if (this != &o) {
            CStr tmp(o);                            // copy-and-swap
            std::swap(buf, tmp.buf);
        }
        return *this;
    }

    CStr(CStr&& o) noexcept                         // 4) move ctor
    : buf(o.buf) { o.buf = nullptr; }

    CStr& operator=(CStr&& o) noexcept {            // 5) move assign
        if (this != &o) {
            delete[] buf;
            buf = o.buf; o.buf = nullptr;
        }
        return *this;
    }

    const char* c_str() const { return buf; }
};

// --- interface-like class and overriding ---
struct IFetcher {
    virtual ~IFetcher() = default;
    virtual int get() = 0;
};
struct ConstFetcher : IFetcher {
    int v;
    // explicit prevents ConstFetcher C = 5; style syntax
    explicit ConstFetcher(int v) : v(v) {}
    int get() override { return v; }
};

int main() {
    Point p(1,2); p.move(3,-1);
    std::cout << "Point p = " << p << '\n';

    Shape* s1 = new Rect(3,4);                      // polymorphic use (prefer smart ptrs)
    Shape* s2 = new Circle(2);
    std::cout << "rect area=" << s1->area() << " circle area=" << s2->area() << '\n';
    delete s1; delete s2;

    CStr a("hello"), b; b = a;                      // copy
    CStr c(std::move(a));                           // move
    std::cout << "CStr b=" << b.c_str() << " c=" << c.c_str() << '\n';

    ConstFetcher f(42);
    IFetcher& iface = f;
    std::cout << "IFetcher.get() = " << iface.get() << '\n';
    return 0;
}
//////////////////////////////
/// DPI-C (C/C++) side snippets for SV testbenches
///   - Build C with the simulator’s flags/includes (e.g., -fPIC -shared and svdpi.h)
///   - Use extern "C" for C++ to avoid name mangling
///   - c style linking
/// Files: dpi_c_side.c / dpi_c_side.cpp
//////////////////////////////
#include "svdpi.h"
#include <stdio.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

// --- simple function: add 2 ints ---
int c_add_ints(int a, int b) {
    return a + b;
}

// --- print message from SV ---
void c_log(const char* msg) {
    printf("[C] %s\n", msg);
    fflush(stdout);
}

// --- sum of a 1-D open array of ints ---
// SV: import "DPI-C" function int c_sum(input int arr[]);
int c_sum(const svOpenArrayHandle arr) {
    // open array utils
    int lo = svLow(arr, 1);
    int hi = svHigh(arr, 1);
    long long sum = 0;
    for (int i = lo; i <= hi; ++i) {
        int* elem_ptr = (int*)svGetArrElemPtr1(arr, i);
        sum += *elem_ptr;
    }
    return (int)sum;
}

// --- handle packed bit vectors (e.g., bit [127:0]) ---
// SV passes packed bits as svBitVecVal* (unsigned 32-bit chunks)
void c_xor128(const svBitVecVal* a, const svBitVecVal* b, svBitVecVal* out /*128 bits*/) {
    // 128 bits = 4 words of 32 bits each, little word order per LRM
    for (int w = 0; w < 4; ++w) out[w] = a[w] ^ b[w];
}

// --- chandle roundtrip (opaque pointer) ---
// SV: typedef chandle handle_t;
typedef struct { int state; } my_ctx_t;

// create a context and return as chandle
const void* c_ctx_create(int seed) {
    my_ctx_t* ctx = (my_ctx_t*)malloc(sizeof(my_ctx_t));
    ctx->state = seed;
    return (const void*)ctx; // maps to SV chandle
}

// mutate context; return new value
int c_ctx_tick(const void* h) {
    my_ctx_t* ctx = (my_ctx_t*)h;
    ctx->state = (ctx->state * 1103515245 + 12345) & 0x7fffffff;
    return ctx->state;
}

// destroy context
void c_ctx_destroy(const void* h) {
    free((void*)h);
}

// --- call back into SV (exported task/function) ---
// Declare prototypes for SV-exported symbols so we can call them from C.
extern void sv_report_from_c(int val);    // SV will 'export "DPI-C" task sv_report_from_c(int);'
void c_invoke_sv(int v) {
    sv_report_from_c(v);
}

#ifdef __cplusplus
}
#endif

