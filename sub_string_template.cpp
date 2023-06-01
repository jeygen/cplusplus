// any spare d's are now sub string length

int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin_index=0, end_index=0; //two pointers, one point to tail and one head
        int sub_len; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end_index<s.size()){

            if(map[s[end_index++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update sub_len here if finding minimum*/

                //increase begin_index to make it invalid/valid again
                
                if(map[s[begin_index++]]++ ?){ /*modify counter here*/ }
            }  

            /* update sub_len here if finding maximum*/
        }
        return sub_len;
  }

// Longest pattern, no char repeats
int lengthOfLongestSubstring(string s) {
    vector<int> map(128, 0); // make dynamic array of 128 as asci is 0-127
    int counter = 0;
    int begin_index = 0, end_index = 0, sub_len = 0;

    while (end_index < s.size()) {
		// this syntax is increment everytime its run, counter iff success
        if (map[s[end_index]]++ > 0) counter++;
        end_index++;

        while (counter > 0) {
            if (map[s[begin_index]]-- > 1) counter--;
            begin_index++;
        }
        sub_len = max(sub_len, end_index - begin_index); // Update d here if finding maximum
    }
    return sub_len;
}

// longest with at most 2 sub_lenistinct chars
int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> map(128, 0);
        int counter=0, begin_index=0, end_index=0, sub_len=0; 
        while(end_index<s.size()){
            if(map[s[end_index++]]++==0) counter++;
            while(counter>2) if(map[s[begin_index++]]--==1) counter--;
            sub_len=max(sub_len, end_index-begin_index);
        }
        return sub_len;
}

// return size of window that contains 2 given strings
string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin_index=0, end_index=0, sub_len=INT_MAX, head=0;
        while(end_index<s.size()){
            if(map[s[end_index++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end_index-begin_index<sub_len)  sub_len=end_index-(head=begin_index);
                if(map[s[begin_index++]]++==0) counter++;  //make it invalid
            }  
        }
        return sub_len==INT_MAX? "":s.substr(head, d);
}


