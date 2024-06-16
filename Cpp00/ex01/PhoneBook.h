/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:35:48 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/16 16:39:07 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <cstdlib>


const std::string BOLD		=	"\033[1m";
const std::string RESET		=	"\033[0m";
const std::string LETTERS	=	\
	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string NUMBERS	=	"0123456789";

class PhoneBook
{
	public:
		PhoneBook(void);
		void		run(void);
		class	Contact
		{
			private:
				std::string	firstname_;
				std::string	lastname_;
				std::string	nickname_;
				std::string	number_;
				std::string	secret_;
			public:
				Contact(void);
				bool		setFirstName(std::string first_name);
				bool		setLastName(std::string last_name);
				bool		setNickname(std::string nickname);
				bool		setNumber(std::string number);
				bool		setSecret(std::string secret);
				std::string	getFirstName(void);
				std::string	getLastName(void);
				std::string	getNickname(void);
				std::string	getNumber(void);
				std::string	getSecret(void);
		};
		enum		State_e
		{
			IDLE,
			LOOKUP,
			ADD,
			SEARCH,
			A_FNAME,
			A_LNAME,
			A_NNAME,
			A_NUMBER,
			A_SECRET,
			S_INDEX,
			S_GET,
			EXIT
		};
	private:
		Contact		contacts_[8];
		State_e		state;
		int			contact_index_;
		int			initialized_;

		void		search(void);
		void		add(void);
		void		printContacts(void);
		int			isIndex(std::string &index);
};

#endif