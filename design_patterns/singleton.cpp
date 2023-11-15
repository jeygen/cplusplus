// static member functions can be called w/ class name 
// // can only access static data and static functions

// static variables are initialized once
// // value persists inbetween calls

class Singleton {
public:
    static Singleton& Instance() {
        static Singleton instance;
        return instance;
    }
private:
	// Private constructor to prevent instantiation from outside
    Singleton() {}     
    // Prevent copy constructor
	Singleton(Singleton const&) = delete; 
	// Prevent assignment operator
    void operator=(Singleton const&) = delete; 
};

int main() {
	// get a reference to the Singleton instance
    Singleton& mySingleton = Singleton::Instance(); 
	// call a method on the Singleton instance
    mySingleton.DoSomething(); 
    return 0;
}

// this way, also works but less safe

class Singleton {
private:
    static Singleton* instance;
    
    // Private constructor to prevent direct instantiation
    Singleton() {
        // Constructor code...
    }
    
public:
    // Static method to access the singleton instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    
    // Other member functions...
};

// Initialize the static member variable
Singleton* Singleton::instance = nullptr;


// chatgpt buddy

class Singleton {
private:
    // Private Constructor
    // This prevents anyone outside the class from creating a new instance.
    Singleton() {}

    // Private Copy constructor and assignment operator
    // These are deleted to prevent copying of the singleton instance.
    // Deleting these methods ensures that you can't create a copy of the singleton.
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Static method to access the instance
    // This method is static, meaning it can be called on the class itself,
    // not on an instance of the class.
    static Singleton& getInstance() {
        // This static instance is created only once and then reused.
        // The instance is created the first time this method is called.
        // It is destroyed when the program exits.
        static Singleton instance;

        // Return a reference to the instance.
        // Returning a reference ensures that no copy of the instance is made.
        return instance;
    }
};

int main() {
    // Access the singleton instance
    // Calling getInstance() will always return the same instance.
    Singleton& s1 = Singleton::getInstance();

    // Proof that s1 and s2 refer to the same instance
    Singleton& s2 = Singleton::getInstance();
    if (&s1 == &s2) {
        // This will print, proving both references point to the same instance.
        std::cout << "s1 and s2 are the same instance" << std::endl;
    }

    return 0;
}
