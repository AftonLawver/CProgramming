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
    word(string value) {
        this->value = value;
        this->count = 1;
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
//int argc, char *argv[]
int main() {
    string file_name;
//    if(argc == 1) {
//        cout << "Enter at least one command line argument as the filename. Please try the program again." << endl;
//        sleep(2);
//        exit(0);
//    }
//    cout << "Number of args: " << argc << endl;
    cout << "Enter filename:" << endl;
//    for (int i=1; i<argc; i++) {
//        string file_name = argv[i];
    cin >> file_name;
        word_list my_word_list;
        fstream file_stream;
        file_stream.open(file_name,ios::in);
        string current_word;

        while(true) {
            if (file_stream.peek() == 32 || file_stream.peek() == 10 || file_stream.peek() == -1) {
                if(file_stream.peek() == -1) {
                    break;
                }
                word new_word = word(current_word);
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
        cout << "Number of words: " << my_word_list.get_number_of_words() << endl;
//    }
    return 0;
}



















