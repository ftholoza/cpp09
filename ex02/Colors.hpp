/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:41:29 by francesco         #+#    #+#             */
/*   Updated: 2024/06/22 16:41:36 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

# define BOLD "\e[1m"
# define THIN "\e[2m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"
# define INVERSE "\e[7m"
# define STRIKETHROUGH "\e[9m"

# define BLACK "\e[30m"
# define RED "\e[31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"

# define TITLE BOLD INVERSE

# define END_STYLE "\e[0m"

#endif
