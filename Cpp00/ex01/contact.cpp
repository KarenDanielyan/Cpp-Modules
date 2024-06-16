/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:52:05 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/16 15:03:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

PhoneBook::Contact::Contact(void) {}

bool	PhoneBook::Contact::setFirstName(std::string first_name)
{
	if (first_name.empty() || \
		first_name.find_first_not_of(LETTERS) != first_name.npos)
		return (false);
	this->firstname_ = first_name;
	return (true);
}

bool	PhoneBook::Contact::setLastName(std::string last_name)
{
	if (last_name.empty() || \
		last_name.find_first_not_of(LETTERS) != last_name.npos)
		return (false);
	this->lastname_ = last_name;
	return (true);
}

bool	PhoneBook::Contact::setNickname(std::string nickname)
{
	if (nickname.empty())
		return (false);
	this->nickname_ = nickname;
	return (true);
}

bool	PhoneBook::Contact::setNumber(std::string number)
{
	if (number.empty() || \
		number.find_first_not_of(NUMBERS) != number.npos)
		return (false);
	this->number_ = number;
	return (true);
}

bool	PhoneBook::Contact::setSecret(std::string secret)
{
	this->secret_ = secret;
	return (true);
}

std::string	PhoneBook::Contact::getFirstName(void)
{
	return (this->firstname_);
}

std::string	PhoneBook::Contact::getLastName(void)
{
	return (this->lastname_);
}

std::string	PhoneBook::Contact::getNickname(void)
{
	return (this->nickname_);
}

std::string	PhoneBook::Contact::getNumber(void)
{
	return (this->number_);
}

std::string	PhoneBook::Contact::getSecret(void)
{
	return (this->secret_);
}
