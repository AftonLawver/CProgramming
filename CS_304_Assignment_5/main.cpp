#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>

using namespace std;

class word {
private:
    string value;
    int count;
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
};
//int argc, char *argv[]
int main() {
    int number_of_characters = 0;
    int number_of_lines = 0;
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
// cout << "File path: " << file_name << endl;
// cout << "-------------------------------" << endl
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

                else if (file_stream.peek() == 10) {
                    if (current_word == "") {
                        int x = file_stream.get(); // consumes the whitespace or newline
                        number_of_lines++;
                        number_of_characters++;
                        continue;
                    }
                    word new_word = word(current_word);
                    my_word_list.add_word(new_word);
                    int x = file_stream.get(); // consumes the whitespace or newline
                    current_word = ""; // sets the current word back to empty string
                    number_of_lines++;
                    number_of_characters++;
                    continue;
                }

                else if (file_stream.peek() == 32) {
                    if (current_word == "") {
                        int x = file_stream.get(); // consumes the whitespace or newline
                        number_of_characters++;
                        continue;
                    }
                    word new_word = word(current_word);
                    my_word_list.add_word(new_word);
                    int x = file_stream.get(); // consumes the whitespace or newline
                    current_word = ""; // sets the current word back to empty string
                    number_of_characters++;
                    continue;
                }

//                word new_word = word(current_word);
//                my_word_list.add_word(new_word);
//                int x = file_stream.get(); // consumes the whitespace or newline
//
//                current_word = ""; // sets the current word back to empty string
//                continue;
            }
            char current_char = file_stream.get();
            number_of_characters++;
            current_word += current_char;
        }
        cout << "Number of words: " << my_word_list.get_number_of_words() << endl;
        cout << "Number of characters: " << number_of_characters << endl;
        cout << "Number of lines: " << number_of_lines << endl;


//    }
    return 0;
}



















