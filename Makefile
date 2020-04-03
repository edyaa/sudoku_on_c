clean:
	/bin/rm -f sudoku

sudoku: main.c main_functions.c loners.c hidden_loners.c functions_for_hidden_loners.c function_in_arr.c clean
	gcc -o sudoku -Wall -Wextra -Werror main.c main_functions.c loners.c hidden_loners.c functions_for_hidden_loners.c function_in_arr.c
