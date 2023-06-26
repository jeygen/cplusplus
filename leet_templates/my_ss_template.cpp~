#include <vector>
#include <string>

int find_long_ss_before_repeated_char(string s) {
	// basic ss set-up
	std::vector<int> ascii_tracker(128, 0);
	int counter=0, begin_window_index=0, end_window_index=0, sub_len=0;
	
	// some q, initialize ascii_tracker here
	// could be for(auto c : s) {ascii_tracker[c]++;}

	while(end_window_index < s.size()) {
		// check num of occurences for end of window
		// counter alerts that the char has repeated
		if (ascii_tracker[s[end_index]] > 0) counter++;

		// count occurence of char	
		ascii_tacker[s[end_window_index]]++;
		// increment end index
		end_window_index++;
			
        // If counter is greater than 0, encountered a repeated character
        while(counter > 0) {
			// slide begin of window to where rep occurs
            // decrease the count of the character at begin_window_index in the ascii_tracker vector
            ascii_tracker[s[begin_window_index]]--;
            // if the character at begin_window_index is the one that has repeated, decrease counter
            if (ascii_tracker[s[begin_window_index]] > 0) {
                counter--;
            }
            // move the beginning of the window to the right
            begin_window_index++;
        }

        // calculate the length of the current substring and update sub_len if necessary
        int current_sub_len = end_window_index - begin_window_index;
        if (current_sub_len > sub_len) {
            sub_len = current_sub_len;
        }
    }

    // after the end of the while loop, sub_len will hold the length of the longest substring without repeating characters
    return sub_len;
}

		
	
	

	


