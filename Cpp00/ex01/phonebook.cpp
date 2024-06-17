/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 03:07:50 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/17 13:40:38 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

static std::string	truncate(const std::string &str, size_t length);
static void			intro(void);
static std::string	getInput(void);

PhoneBook::PhoneBook(): state(IDLE), contact_index_(0), initialized_(0) {}

void	PhoneBook::run()
{
	std::string input;

	intro();
	while (true)
	{
		switch (state)
		{
			case IDLE:
				input = getInput();
				state = LOOKUP;
				continue ;
			case LOOKUP:
				if (input == "ADD")
					state = ADD;
				else if (input == "SEARCH")
					state = SEARCH;
				else if (input == "EXIT")
					state = EXIT;
				else
					state = IDLE;
				continue ;
			case ADD:
				add();
				continue ;
			case SEARCH:
				search();
				continue ;
			case EXIT:
				return ;
			default:
				return ;
		}
	}
}

void	PhoneBook::add()
{
	std::string	input;

	if (contact_index_ == 8)
		contact_index_ = 0;
	Contact &c = contacts_[contact_index_];
	while (true)
	{
		switch(state)
		{
			case ADD:
				state = A_FNAME;
				continue ;
			case A_FNAME:
				std::cout << "Please enter your first name." << std::endl;
				input = getInput();
				if (c.setFirstName(input) == true)
					state = A_LNAME;
				else
					std::cout << "Invalid first name." << std::endl;
				continue ;
			case A_LNAME:
				std::cout << "Please enter your last name." << std::endl;
				input = getInput();
				if (c.setLastName(input) == true)
					state = A_NNAME;
				else
					std::cout << "Invalid last name." << std::endl;
				continue ;
			case A_NNAME:
				std::cout << "Please enter your nickname." << std::endl;
				input = getInput();
				if (c.setNickname(input) == true)
					state = A_NUMBER;
				else
					std::cout << "Invalid nickname." << std::endl;
				continue ;
			case A_NUMBER:
				std::cout << "Please enter you phone number." << std::endl;
				input = getInput();
				if (c.setNumber(input) == true)
					state = A_SECRET;
				else
					std::cout << "Invalid number." << std::endl;
				continue ;
			case A_SECRET:
				std::cout << "Please enter your darkest secret." << std::endl;
				input = getInput();
				c.setSecret(input);
				if (initialized_ < 8)
					initialized_ ++;
				contact_index_ ++;
				state = IDLE;
				continue ;
			default:
				return ;
		}
	}
}

void	PhoneBook::search(void)
{
	std::string	index;
	int			i;

	while(true)
	{
		switch(state)
		{
			case SEARCH:
				if (initialized_ == 0)
				{
					std::cout << "Phonebook is empty." << std::endl;
					state = IDLE;
					continue ;
				}
				printContacts();
				std::cout << "Please enter contact index for more details." \
					<< std::endl;
				state = S_INDEX;
				continue ;
			case S_INDEX:
				index = getInput();
				i = isIndex(index);
				if (i == -1)
					std::cout << "Invalid index. Please try again." \
						<< std::endl;
				else
					state = S_GET;
				continue ;
			case S_GET:
				std::cout << "First Name: " \
					<< contacts_[i].getFirstName() << std::endl;
				std::cout << "Last Name: " \
					<< contacts_[i].getLastName() << std::endl;
				std::cout << "Nickname: " \
					<< contacts_[i].getNickname() << std::endl;
				std::cout << "Phone Number: " \
					<< contacts_[i].getNumber() << std::endl;
				std::cout << "Darkest Secret: " \
					<< contacts_[i].getSecret() << std::endl;
				state = IDLE;
				continue ;
			default:
				return ;
		}
	}
}

void	PhoneBook::printContacts()
{
	int			i;
	std::string	tmp;

	i = 0;
	std::cout << " ---------- ---------- ---------- ---------- " << \
		std::endl;
	std::cout << '|' << std::setw(10) << "index" << '|' << \
				std::setw(10) << "first name" << '|' << \
				std::setw(10) << "last name" << '|' << \
				std::setw(10) << "nickname" << '|' << std::endl;
	while (i < this->initialized_)
	{
		std::cout << '|' << std::setw(10) << i << '|';
		tmp = truncate(this->contacts_[i].getFirstName(), 10);
		std::cout << std::setw(10) << tmp << '|';
		tmp = truncate(this->contacts_[i].getLastName(), 10);
		std::cout << std::setw(10) << tmp << '|';
		tmp = truncate(this->contacts_[i].getNickname(), 10);
		std::cout << std::setw(10) << tmp << '|';
		std::cout << std::endl;
		i ++;
	}
	std::cout << " ---------- ---------- ---------- ---------- " << \
		std::endl;
}

static std::string	truncate(const std::string &str, size_t length)
{
	std::string	trunc;

	if (str.length() >= length)
	{
		trunc = str.substr(0, length - 1);
		trunc.append(".");
	}
	else
		trunc = std::string(str);
	return (trunc);
}

static void	intro()
{
	std::cout << "Welcome to the awesome Phonebook." << \
			"Thank you for choosing our service." << std::endl;
	std::cout << "Here is the list of available commands: " << std::endl;
	std::cout << "\t1. " << BOLD << "ADD" <<\
				RESET << ": Add a new contact." << std::endl;
	std::cout << "\t2. " << BOLD << "SEARCH" << \
				RESET << ": Search a contact." << std::endl;
	std::cout << "\t3. " << BOLD << "EXIT" << \
				RESET << ": Terminate the program" << \
				" and lose your contacts forever." << std::endl;
}

int	PhoneBook::isIndex(std::string &index)
{
	int	i;

	if (index.find_first_not_of(NUMBERS) != index.npos)
		return (-1);
	i = std::atoi(index.c_str());
	if (i < 0 || i >= initialized_)
		return (-1);
	return (i);
}

static std::string	getInput(void)
{
	std::string input;

	std::cout << "> ";
	if (std::getline(std::cin, input))
		return (input);
	else
		exit(EXIT_FAILURE);
}
