/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:49:19 by dancuenc          #+#    #+#             */
/*   Updated: 2026/03/19 12:45:35 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 1;
	while (i < argc)
	{
		std::string str(argv[i]);
		int j = 0;
		while (argv[i][j])
		{
			str[j] = std::toupper(str[j]);
			j++;
		}
		std::cout << str;
		i++;
	}
	std::cout << std::endl;
	return (0);
}