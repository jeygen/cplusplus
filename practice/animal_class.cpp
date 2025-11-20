// make a parent animal class and some kids
// demonstrate override, overload, inheritance, polymorphism
// demonstrate virtual functions and non-virtual functions
// demonstrate encapsulation / private and public attributes
// write a main class to test classes to demonstrate above qualities

/*
 * Inheritance: Dog, Cat, Bird inherit from Animal.

Polymorphism: vector<unique_ptr<Animal>> holds different derived types; calls to speak() and move() dispatch virtually.

Override: species(), speak(), and move() in derived classes use override.

Overload: Animal::feed(int) and Animal::feed(string) (two overloads). Dog::feed(int,bool) adds another overload (note the using Animal::feed; so base overloads remain visible on Dog).

Virtual vs non-virtual: idTag() is non-virtual in Animal. Dog defines its own idTag() (hides base). Through a base pointer/reference, you get Animal::idTag(); through a Dog object, you get Dog::idTag().

Encapsulation: name_, age_, microchipId_ are private; you interact via name(), age(), birthday(), etc.

Virtual destructor: enables safe deletion through base pointers.
*/

// to run
// g++ -std=c++17 -Wall -Wextra -O2 demo_oop.cpp -o demo_oop
// ./demo_oop
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iomanip>

// --------------------------- Base class ---------------------------------
class Animal {
private:
    std::string name_;          // encapsulated (private)
    int         age_;           // encapsulated (private)
    std::string microchipId_;   // encapsulated (private)

public:
    Animal(std::string name, int age, std::string chip)
        : name_(std::move(name)), age_(age), microchipId_(std::move(chip)) {}

    virtual ~Animal() = default; // virtual destructor (polymorphic base)

    // Public "read-only" accessors (encapsulation via getters)
    const std::string& name() const { return name_; }
    int age() const { return age_; }

    // Non-virtual function (static binding): same name in derived will HIDE it, not override.
    std::string idTag() const {
        return "Animal#" + microchipId_ + " (" + name_ + ")";
    }

    // Non-virtual mutator (example of behavior not intended for polymorphism)
    void birthday() { ++age_; }

    // Virtual interface (dynamic binding)
    virtual std::string species() const { return "Animal"; }
    virtual void speak() const = 0;          // pure virtual: makes Animal abstract
    virtual void move(int meters) const {    // virtual: can override
        std::cout << name_ << " moves " << meters << "m.\n";
    }

    // Function overloading (non-virtual here)
    void feed(int grams) const {
        std::cout << name_ << " eats " << grams << "g of food.\n";
    }
    void feed(const std::string& treat) const {
        std::cout << name_ << " enjoys a treat: " << treat << ".\n";
    }
};

// --------------------------- Derived: Dog --------------------------------
class Dog : public Animal {
public:
    using Animal::Animal; // inherit constructors

    // Bring base overloads of feed into scope so we can add more overloads without hiding.
    using Animal::feed;

    // Override: dynamic dispatch through base pointer/reference
    std::string species() const override { return "Dog"; }
    void speak() const override { std::cout << name() << ": Woof!\n"; }
    void move(int meters) const override {
        std::cout << name() << " trots " << meters << "m wagging tail.\n";
    }

    // Overload (same function name, different parameter list) — NOT virtual here.
    void feed(int grams, bool highProtein) const {
        std::cout << name() << " eats " << grams << "g"
                  << (highProtein ? " (high-protein)" : "")
                  << " dog food.\n";
    }

    // Non-virtual function with same name as base non-virtual (HIDES base idTag)
    std::string idTag() const {
        return "DogTag{" + species() + ":" + name() + "}";
    }

    void fetch(const std::string& item) const {
        std::cout << name() << " fetches the " << item << ".\n";
    }
};

// --------------------------- Derived: Cat --------------------------------
class Cat : public Animal {
public:
    using Animal::Animal;

    std::string species() const override { return "Cat"; }
    void speak() const override { std::cout << name() << ": Meow.\n"; }
    // Inherit default move(int) from Animal (still virtual; not overridden)
};

// --------------------------- Derived: Bird -------------------------------
class Bird : public Animal {
public:
    using Animal::Animal;

    std::string species() const override { return "Bird"; }
    void speak() const override { std::cout << name() << ": Chirp!\n"; }
    void move(int meters) const override {
        std::cout << name() << " flies " << meters << "m.\n";
    }
};

// --------------------------- Demo / Tests --------------------------------
int main() {
    std::cout << std::boolalpha;

    // Polymorphic collection (vector of base-class pointers)
    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.emplace_back(std::make_unique<Dog>("Rex", 4, "D-001"));
    zoo.emplace_back(std::make_unique<Cat>("Mochi", 3, "C-002"));
    zoo.emplace_back(std::make_unique<Bird>("Kiwi", 1, "B-003"));

    std::cout << "=== Polymorphism via virtual functions ===\n";
    for (const auto& a : zoo) {
        std::cout << a->species() << " " << a->name() << " says: ";
        a->speak();                 // virtual: calls derived implementation
        a->move(5);                 // virtual: Dog/Bird override, Cat uses base
    }

    std::cout << "\n=== Encapsulation (private fields via public API) ===\n";
    // Direct access to name_/age_/microchipId_ is impossible here (private).
    // Use public methods instead:
    zoo[0]->birthday();
    std::cout << zoo[0]->name() << " just turned " << zoo[0]->age() << ".\n";

    std::cout << "\n=== Overloading vs overriding ===\n";
    // Overloading (same function name, different params) on the base:
    zoo[1]->feed(30);              // Animal::feed(int)
    zoo[1]->feed("salmon");        // Animal::feed(string)

    // Dog adds an extra overload feed(int,bool) that is visible on Dog objects:
    if (auto* d = dynamic_cast<Dog*>(zoo[0].get())) {
        d->feed(120, true);        // Dog-specific overload (NOT virtual)
        d->fetch("ball");          // Dog-specific method
    }

    std::cout << "\n=== Virtual vs NON-virtual binding ===\n";
    // idTag is NON-virtual in base. Dog defines a method with same name (hides base).
    // When called via BASE pointer: static binding => base version runs.
    for (const auto& a : zoo) {
        std::cout << "As Animal*: " << a->idTag() << "\n";
    }

    // When called on a DERIVED object (not through base pointer), the hidden Dog::idTag() is used.
    Dog d2("Buddy", 2, "D-777");
    Animal& ref = d2;
    std::cout << "Dog object method:         " << d2.idTag() << "\n"; // Dog::idTag (hides)
    std::cout << "Same object via Animal&:   " << ref.idTag() << "\n"; // Animal::idTag (non-virtual)

    std::cout << "\n=== Done ===\n";
    return 0;
}


