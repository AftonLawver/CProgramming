#include <iostream>
#include <random>
#include <unistd.h>

using namespace std;

char ** generate_grid(int input_grid_size);
void print_grid(char **input_grid, int input_grid_size);
void populate_result_grid(char ** result_grid, int input_grid_size);

int main() {
    int grid_size = 8;
    int guess_count = 24;

    char ** guess_grid = generate_grid(grid_size);
    char ** result_grid = generate_grid(grid_size);
    populate_result_grid(result_grid, grid_size);

    cout << "Result grid:" << endl;
    print_grid(result_grid, grid_size);

    while (guess_count > 0) {

        int x_coordinate, y_coordinate;
        cout << "Enter an x-coordinate:";
        while ((!(cin >> x_coordinate)) || x_coordinate < 0 || x_coordinate > grid_size-1) {
            cout << "Invalid..Please enter an x-coordinate between 0 and " << grid_size - 1 << ":";
            cin.clear();
            cin.ignore(100, '\n');
            guess_count--;
        }
        cout << "Enter a y-coordinate:";
        while ((!(cin >> y_coordinate)) || y_coordinate < 0 || y_coordinate > grid_size-1) {
            cout << "Invalid..Please enter a y-coordinate between 0 and " << grid_size - 1 << ":";
            cin.clear();
            cin.ignore(100, '\n');
            guess_count--;
        }
        guess_count--;

        if (result_grid[y_coordinate][x_coordinate] == 'O') {
            guess_grid[y_coordinate][x_coordinate] = 'O';
            result_grid[y_coordinate][x_coordinate] = 'X';
            cout << "Current status of the guess grid thus far:" << endl;
            print_grid(guess_grid,grid_size);
            cout << "Kaboom!!" << endl;
            cout << endl;
            sleep(1);
            continue;
        }
        guess_grid[y_coordinate][x_coordinate] = 'X';
        result_grid[y_coordinate][x_coordinate] = 'X';
        print_grid(guess_grid, grid_size);
        cout << "Sploosh." << endl;
        cout << endl;
        sleep(1);
    }

    for (int j = 0; j < grid_size; j++) {
        for (int k = 0; k < grid_size; k++) {
            if (result_grid[j][k] == 'O') {
                cout << "You did not hit all of the ships." << endl;
                print_grid(result_grid, grid_size);
                goto out;
            }
        }
    }
    out:
    cout << "Congratulations!" << endl;
    cout << "You hit all of the ships!" << endl;
    print_grid(result_grid, grid_size);

    return 0;
}

char **generate_grid(int input_grid_size) {
    const char initialChar = '-';
    int i;
    char **dynamic_int_matrix = (char**)malloc(input_grid_size * sizeof(char*));
    if (dynamic_int_matrix == NULL) {
        cout << "malloc() failed!" << endl;
        return NULL;
    }
    for (i = 0; i < input_grid_size; i++) {
        dynamic_int_matrix[i] = (char *) malloc(input_grid_size * sizeof(char));
        if (dynamic_int_matrix[i] == NULL) {
            cout << "malloc() failed!" << endl;
            return NULL;
        }
    }
    for (int j = 0; j < input_grid_size; j++) {
        for (int k = 0; k < input_grid_size; k++) {
            dynamic_int_matrix[j][k] = initialChar;
        }
    }
    return dynamic_int_matrix;
}

void populate_result_grid(char ** result_grid, int input_grid_size) {
    int count = 0;
    const int rangeFrom = 0;
    const int rangeTo = input_grid_size-1;
    while (count != 10) {
        random_device rand_dev;
        mt19937 generator(rand_dev());
        uniform_int_distribution<int> distr(rangeFrom, rangeTo);
        int xCoordinate = distr(generator);
        int yCoordinate = distr(generator);
        if (result_grid[xCoordinate][yCoordinate] == 'O') {
            continue;
        }
        result_grid[xCoordinate][yCoordinate] = 'O';
        count++;
    }
}

void print_grid(char **input_grid, int input_grid_size) {
    for (int j = 0; j < input_grid_size; j++) {
        for (int k = 0; k < input_grid_size; k++) {
            cout << "  " << input_grid[j][k];
        }
        cout << endl;
    }
}
