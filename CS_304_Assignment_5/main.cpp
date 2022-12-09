#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <map>

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

    void print_number_of_words_for_each_letter() {
        map<char, int> m;
        for (word i: word_vector) {
            char first_character = toupper(i.get_value().at(0));
            m[first_character] +=1;
        }
        for (auto const& [key, val] : m)
        {
                cout << key<< ':' << val << endl;
        }
        }
    };

//int argc, char *argv[]
int main() {
    unsigned int number_of_characters = 0;
    unsigned int number_of_lines = 1;
    string file_name;
//    if(argc == 1) {
//        cout << "Enter at least one file as the command line argument. Please try the program again." << endl;
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
    file_stream.open(file_name, ios::in);
    if(file_stream.fail()){
        cout << "File does not exist. Please try again." << endl;
        sleep(2);
        exit(0);
    }
    string current_word;
    char *line = new char[1];

//C:\Users\lawve\Desktop\test.txt
    while (true) {
            if (file_stream.peek() == 32 || file_stream.peek() == 10 || file_stream.peek() == -1) {
                if(file_stream.peek() == -1) {
                    if (current_word == "") {
                        delete[] line;
                        break;
                    }
                    else{
                        word new_word = word(current_word);
                        my_word_list.add_word(new_word);
                        delete[] line;
                        break;
                    }

                }

                // newline
                else if (file_stream.peek() == 10) {
                    if (current_word == "") {
                        int x = file_stream.get(); // consumes the newline character
                        number_of_lines++;
                        number_of_characters++;
                        delete[] line;
                        line = new char[1];
                        continue;
                    }
                    else {
                        word new_word = word(current_word);
                        my_word_list.add_word(new_word);
                        int x = file_stream.get(); // consumes the newline
                        current_word = ""; // sets the current word back to empty string
                        number_of_lines++;
                        number_of_characters++;
                        delete[] line;
                        line = new char[1];
                        continue;
                    }
                }

                else if (file_stream.peek() == 32) {
                    if (current_word == "") {
                        int x = file_stream.get(); // consumes the whitespace
                        number_of_characters++;
                        continue;
                    }
                    else {
                        word new_word = word(current_word);
                        my_word_list.add_word(new_word);
                        int x = file_stream.get(); // consumes the whitespace
                        current_word = ""; // sets the current word back to empty string
                        number_of_characters++;
                        continue;
                    }
                }
            }
            char current_char = file_stream.get();
            number_of_characters++;
            current_word += current_char;
        }
        if (number_of_characters == 0) {
            number_of_lines = 0;
        }
        cout << "Name of file: " << file_name << endl;
        cout << "Number of words: " << my_word_list.get_number_of_words() << endl;
        cout << "Number of characters: " << number_of_characters << endl;
        cout << "Number of lines: " << number_of_lines << endl;

        cout << "Number of words beginning with each letter: " << endl;
        cout << "------------------------------------------" << endl;
        my_word_list.print_number_of_words_for_each_letter();
//    }
        return 0;
    }

//        int peek_value = file_stream.peek();
//        switch (peek_value) {
//            case 32: {
//                if (current_word == "") {
//                    int x = file_stream.get(); // consumes the whitespace
//                    number_of_characters++;
//                    continue;
//                }
//                word new_word = word(current_word);
//                my_word_list.add_word(new_word);
//                int x = file_stream.get(); // consumes the whitespace
//                current_word = ""; // sets the current word back to empty string
//                number_of_characters++;
//                continue;
//            }
//            case 10: {
//                if (current_word == "") {
//                    int x = file_stream.get(); // consumes the newline character
//                    number_of_lines++;
//                    number_of_characters++;
//                    continue;
//                }
//                word new_word = word(current_word);
//                my_word_list.add_word(new_word);
//                int x = file_stream.get(); // consumes the newline
//                current_word = ""; // sets the current word back to empty string
//                number_of_lines++;
//                number_of_characters++;
//                continue;
//            }
//            case -1: {
//                if (current_word == "") {
//                    processing_done = true;
//                    break;
//                }
//                word new_word = word(current_word);
//                my_word_list.add_word(new_word);
//                processing_done = true;
//                break;
//            }
//            default:
//                char current_char = file_stream.get();
//                number_of_characters++;
//                current_word += current_char;

//        }

