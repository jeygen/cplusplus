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

