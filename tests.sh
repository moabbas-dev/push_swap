#Examples should work:
./push_swap 1 3 5 +9 20 -4 50 60 04 08
valgrind --leak-check=full ./push_swap 1 3 5 +9 20 -4 50 60 04 08

./push_swap "3 4 6 8 9 74 -56 +495"
valgrind --leak-check=full ./push_swap "3 4 6 8 9 74 -56 +495"

./push_swap "95 99 -9 10 9"
valgrind --leak-check=full ./push_swap "95 99 -9 10 9"

./push_swap 2147483647 2 4 7
valgrind --leak-check=full ./push_swap 2147483647 2 4 7

./push_swap "2147483647 2 4 7"
valgrind --leak-check=full ./push_swap "2147483647 2 4 7"

./push_swap 99 -2147483648 23 545
valgrind --leak-check=full ./push_swap 99 -2147483648 23 545

./push_swap "99 -2147483648 23 545"
valgrind --leak-check=full ./push_swap "99 -2147483648 23 545"

#Examples must display Error\n:
./push_swap 1 3 dog 35 80 -3
valgrind --leak-check=full ./push_swap 1 3 dog 35 80 -3

./push_swap a
valgrind --leak-check=full ./push_swap a

./push_swap 1 2 3 5 67b778 947
valgrind --leak-check=full ./push_swap 1 2 3 5 67b778 947

./push_swap " 12 4 6 8 54fhd 4354"
valgrind --leak-check=full ./push_swap " 12 4 6 8 54fhd 4354"

./push_swap 1 --    45 32
valgrind --leak-check=full ./push_swap 1 --    45 32

./push_swap 1 3 58 9 3
valgrind --leak-check=full ./push_swap 1 3 58 9 3

./push_swap 3 03
valgrind --leak-check=full ./push_swap 3 03

./push_swap " 49 128     50 38   49"
valgrind --leak-check=full ./push_swap " 49 128     50 38   49"

./push_swap 54867543867438 3
valgrind --leak-check=full ./push_swap 54867543867438 3

./push_swap -2147483647765 4 5
valgrind --leak-check=full ./push_swap -2147483647765 4 5

./push_swap "214748364748385 28 47 29"
valgrind --leak-check=full ./push_swap "214748364748385 28 47 29"

# no problem what the result is
./push_swap "1" 76 90 "   348"
valgrind --leak-check=full ./push_swap "1" 76 90 "   348"

#Nothing should be happend
./push_swap