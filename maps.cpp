/*
maps are sorted by key, ascending - rb tree (balanced binary)
unordered are not - hash table
both only get 1 value per key but can cheat with vectors
multimap allow for multiple values per key
multimap can also be unordered
*/

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

int main() {
    std::unordered_map<std::string, int> my_map;

    // Insert key-value pairs into the map
    my_map["apple"] = 1;
    my_map["banana"] = 2;
    my_map["cherry"] = 3;

    // Access the values using keys
    std::cout << "apple = " << my_map["apple"] << "\n";
    std::cout << "banana = " << my_map["banana"] << "\n";
    std::cout << "cherry = " << my_map["cherry"] << "\n";

    // Iterate over all elements in the map
    for (const auto& pair : my_map) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << "\n";
    }

    std::map<std::string, int> my_map;

    // Insert key-value pairs into the map
    my_map["apple"] = 1;
    my_map["banana"] = 2;
    my_map["cherry"] = 3;

    // Access the values using keys
    std::cout << "apple = " << my_map["apple"] << "\n";
    std::cout << "banana = " << my_map["banana"] << "\n";
    std::cout << "cherry = " << my_map["cherry"] << "\n";

    // Iterate over all elements in the map
    for (const auto& pair : my_map) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << "\n";
    }

	std::unordered_map<std::string, std::vector<int>> my_map;

    // Insert values into the map
    my_map["apple"].push_back(1);
    my_map["apple"].push_back(2);
    my_map["apple"].push_back(3);

    // Access the values using keys
    for (const auto& value : my_map["apple"]) {
        std::cout << value << "\n";
    }

    // Iterate over all elements in the map
    for (const auto& pair : my_map) {
        std::cout << "Key: " << pair.first << ", Values: ";
        for (const auto& value : pair.second) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    std::multimap<std::string, int> my_map;

    // Insert key-value pairs into the multimap
    my_map.insert(std::make_pair("apple", 1));
    my_map.insert(std::make_pair("banana", 2));
    my_map.insert(std::make_pair("apple", 3));
    my_map.insert(std::make_pair("banana", 4));
    my_map.insert(std::make_pair("cherry", 5));
    my_map.insert(std::make_pair("banana", 6));
    my_map.insert(std::make_pair("apple", 7));

    // Iterate over all elements in the multimap
    for (const auto& pair : my_map) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << "\n";
    }

    // Get range of values for a specific key
    auto range = my_map.equal_range("apple");
    for (auto i = range.first; i != range.second; ++i) {
        std::cout << "Value for key 'apple': " << i->second << "\n";
    }

    return 0;
}

