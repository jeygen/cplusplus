#include <fstream>  // needed for ifstream
#include <iostream> // needed for cout

int main() {
    // Create an ifstream object and open a file
    std::ifstream file("example.txt");

    // Check if the file was successfully opened
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    // Read data from the file using the >> operator
    int x;
    file >> x; // read an integer from the file
    std::cout << "Read value: " << x << std::endl;

    std::string line;
    std::getline(file, line); // read a line from the file
    std::cout << "Read line: " << line << std::endl;


	 std::vector<int> integers;
    int x;
    while (file >> x) { // read integers until end of file
        integers.push_back(x);
    }
    std::cout << "Read " << integers.size() << " integers:" << std::endl;
    for (int i : integers) {
        std::cout << i << std::endl;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) { // read lines until end of file
        lines.push_back(line);
    }
    std::cout << "Read " << lines.size() << " lines:" << std::endl;
    for (const std::string& l : lines) {
        std::cout << l << std::endl;
    }

	// file uses overloaded operator to just know data type
    int x;
    double y;
    char c;
    std::string s;

    file >> x; // read an integer
    file >> y; // read a double
    file >> c; // read a character
    file >> s; // read a string

    std::cout << "Read values: " << x << ", " << y << ", " << c << ", " << s << std::endl;

    // Close the file
    file.close();
    return 0;
}


