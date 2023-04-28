class Person {
public:
    // Constructor, ':' and '{}' is used to auto fill attributes, can also
    Person(std::string name, int age) : name_{name}, age_{age}, is_student_{false} {
        // constructor body, can also be empty
        // this->age = 12; // this with a pointer is also used in c++
    }

    // Destructor, after out of scope or deleted/freed? then deconstructed
    ~Person() {
        std::cout << "Destroying Person object for " << name_ << std::endl;
      
        /*
        Could inlcude more steps, but usually default decon is enough. Empty body decon = default decon. Frees resources.
        
        std::ofstream log_file("person.log", std::ios::app);
        log_file << "Destroying Person object for " << name_ << " with age " << age_ << std::endl;
        log_file.close();
        */
    }

private:
    std::string name_;
    int age_;
    bool is_student_;
};
