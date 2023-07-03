// could also add vector elements to set then compare sizes but slower
// best method
bool isDuplicate(const std::vector<int>& vec) {
    std::unordered_set<int> seen;

    for (int value : vec) {
        // If value is already in the hash set, it's a duplicate
        if (seen.count(value)) {
            return true;
        }

        // Otherwise, insert it into the hash set
        seen.insert(value);
    }

    // If we reach here, there are no duplicates
    return false;
}
