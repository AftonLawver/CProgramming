#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>

using namespace std;

class word {
private:
    string value;
    int count;
    int location_first_occurrence;

public:
    word(string value, int location_first_occurrence) {
        this->value = value;
        this->count = 1;
        this->location_first_occurrence = location_first_occurrence;
    }

    string get_value() {
        return value;
    }

    void set_value(string word_value) {
        value = word_value;
    }

    int get_count() {
        return count;
    }

    void set_count(int occurrences) {
        count = occurrences;
    }

    void increment_count() {
        count++;
    }

    int get_location_of_first_occurrence() {
        return location_first_occurrence;
    }

    void set_location_of_first_occurrence(int location) {
        location_first_occurrence = location;
    }
};

class word_list {
private:
    int number_of_words = 0;
    vector<word> word_vector;
public:
    void add_word(word my_word) {
        for(int i=0; i < word_vector.size(); i++) {
            if (word_vector[i].get_value() == my_word.get_value()) {
                word_vector[i].increment_count();
                return;
            }
        }
        word_vector.push_back(my_word);
        number_of_words++;
    }

    word remove_word() {
        word last_word = word_vector.back();
        word_vector.pop_back();
        number_of_words--;
        return last_word;
    }

    word get_word_at_index(int index) {
        return word_vector.at(index);
    }

    int get_number_of_words() {
        return number_of_words;
    }

    void sort_by_count() {
        // Sort by using bubble sort
        for (int i = 0; i<word_vector.size(); i++) {
            for(int j = 0; j<word_vector.size()-i-1; j++) {
                if(word_vector.at(j).get_count()>word_vector.at(j+1).get_count()){
                    word temp_word = word_vector.at(j);
                    word_vector.at(j) = word_vector.at(j+1);
                    word_vector.at(j+1) = temp_word;
                }
            }
        }
    }

    void sort_by_first_location() {
        // sort by using bubble sort
        for (int i = 0; i<word_vector.size(); i++) {
            for(int j = 0; j<word_vector.size()-i-1; j++) {
                if(word_vector.at(j).get_location_of_first_occurrence()>word_vector.at(j+1).get_location_of_first_occurrence()){
                    word temp_word = word_vector.at(j);
                    word_vector.at(j) = word_vector.at(j+1);
                    word_vector.at(j+1) = temp_word;
                }
            }
        }

    }

};

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Enter one command line argument as the filename. Please try the program again." << endl;
        sleep(2);
        exit(0);
    }
    cout << "Number of args: " << argc << endl;
    string file_name = argv[1];
    int location=0;


    word_list my_word_list;
    fstream file_stream;
    file_stream.open(file_name,ios::in);
    string current_word;

    while(true) {
        if (file_stream.peek() == 32 || file_stream.peek() == 10 || file_stream.peek() == -1) {
            word new_word = word(current_word,location);
            location ++; // location will only change for every word.
            my_word_list.add_word(new_word);
            int x = file_stream.get(); // consumes the whitespace or newline
            if (x == -1) {
                break;
            }
            current_word = "";
            continue;
        }
        char current_char = file_stream.get();
        if (current_char == -1) {
            break;
        }
        current_word += current_char;
    }

    my_word_list.sort_by_count();
    cout << "Words sorted by number of occurrences" << endl;
    cout << "-------------------------------------" << endl;
    for(int i = 0; i<my_word_list.get_number_of_words(); i++) {
        word the_word = my_word_list.get_word_at_index(i);
        cout << the_word.get_value() << ": " << the_word.get_count() << endl;
    }

    cout << endl;
    my_word_list.sort_by_first_location();
    cout << "Words sorted by first location" << endl;
    cout << "-------------------------------------" << endl;
    for(int i = 0; i<my_word_list.get_number_of_words(); i++) {
        word the_word = my_word_list.get_word_at_index(i);
        cout << the_word.get_value() << ": " << the_word.get_location_of_first_occurrence() << endl;
    }
    return 0;
}



















