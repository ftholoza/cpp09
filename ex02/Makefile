# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francesco <francesco@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 07:04:09 by francesco         #+#    #+#              #
#    Updated: 2024/06/22 15:14:14 by francesco        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Wshadow -Wno-shadow
SRC = main.cpp PmergeMe.cpp PmergeMeV.cpp PmergeMeL.cpp
NAME = PmergeMe
OBJ = $(SRC:.c=.o)

re :fclean $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
$(OBJ):$(SRC)
	$(CXX) -c $(CXXFLAGS) $(SRC)

clean :
	rm -f $(OBJ)
fclean: clean
	rm -rf $(NAME)