/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:55:33 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/14 15:58:23 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

#define BRAINZZ ": BraiiiiiiinnnzzzZ..."

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce();
	private:
		std::string name;
};

Zombie*	newZombie(std::string name);

Zombie	*zombieHorde(int N, std::string name);

#endif