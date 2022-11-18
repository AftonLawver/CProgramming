/*
	Classes
	Exercise 2
	John Woods
*/

#include <cstdlib>
#include <iostream>
#include <string>

#define BOARD_SIZE 10

using namespace std;

class ship
{
	private:
		bool is_active;
		int value;

	public:
		bool get_is_active()
		{
			return is_active;
		}

		void set_is_active(bool is_active)
		{
			(*this).is_active = is_active;
		}

		int get_value()
		{
			return value;
		}

		void set_value(int value)
		{
			(*this).value = value;
		}
};

class board
{
	private:
		ship * game_board[BOARD_SIZE][BOARD_SIZE];

	public:
		void initialize_board()
		{
			for(int i = 0; i < BOARD_SIZE; i++)
			{
				for(int j = 0; j < BOARD_SIZE; j++)
				{
					game_board[i][j] = nullptr;
				}
			}

			for(int i = 0; i < 10; i++)
			{
				int temp_x = rand() % 10;
				int temp_y = rand() % 10;

				if(game_board[temp_y][temp_x] == nullptr)
				{
					game_board[temp_y][temp_x] = new ship();

					int temp_value = rand() % 3 + 1;

					(*game_board[temp_y][temp_x]).set_is_active(true);
					(*game_board[temp_y][temp_x]).set_value(temp_value);
				}
				else
				{
					i--;
				}
			}

			for(int i = 0; i < BOARD_SIZE; i++)
			{
				for(int j = 0; j < BOARD_SIZE; j++)
				{
					if(game_board[i][j] != nullptr)
					{
						cout << (*game_board[i][j]).get_value() << " ";
					}
					else
					{
						cout << "- ";
					}
				}

				cout << endl;
			}
		}

		int guess(int x, int y)
		{
			if(game_board[y][x] != nullptr)
			{
				if((*game_board[y][x]).get_is_active() == true)
				{
					return (*game_board[y][x]).get_value();
				}
				else
				{
					return -1;
				}
			}
			else
			{
				return -1;
			}
		}

		int get_possible_score()
		{
			int total_score = 0;

			for(int i = 0; i < BOARD_SIZE; i++)
			{
				for(int j = 0; j < BOARD_SIZE; j++)
				{
					if(game_board[i][j] != nullptr)
					{
						total_score = total_score + (*game_board[i][j]).get_value();
					}
				}
			}

			return total_score;
		}

		void clean_up_board()
		{
			for(int i = 0; i < BOARD_SIZE; i++)
			{
				for(int j = 0; j < BOARD_SIZE; j++)
				{
					if(game_board[i][j] != nullptr)
					{
						delete game_board[i][j];
					}
				}
			}
		}
};

int main()
{
	srand(time(NULL));

	int guess_count = 10;

	int score = 0;

	board game_board;

	game_board.initialize_board();

	while(guess_count > 0)
	{
		int x;
		int y;

		cout << "Please enter an x coordinate between 0 and " << BOARD_SIZE - 1 << ":  " << endl;
		cin >> x;

		cout << "Please enter a y coordinate between 0 and " << BOARD_SIZE - 1 << ":  " << endl;
		cin >> y;

		int guess_status = game_board.guess(x, y);

		if(guess_status != -1)
		{
			cout << "Kaboom!" << endl << endl;

			score = score + guess_status;
		}
		else
		{
			cout << "Sploosh." << endl << endl;
		}

		guess_count--;
	}

	cout << "You scored " << score << " out of " << game_board.get_possible_score() << endl << endl;

	game_board.clean_up_board();

	return EXIT_SUCCESS;
}
