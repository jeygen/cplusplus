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
