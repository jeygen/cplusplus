#include <vector>
#include <string>

int some_ss_q(string s) {
	// basic ss set-up

	// ascii tracker, dont think always need it
	std::vector<int> ascii_tracker(128, 0);

	// counter for given char, ss length, window pointers
	int counter=0, begin_window_index=0, end_window_index=0, sub_len=0;
	
	// sometimes initialize ascii_tracker here
	for(auto c : s) {ascii_tracker[c]++;}

	// run until end pointer so larger than string
	while(end_window_index < s.size()) {

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

		
	
	

	


