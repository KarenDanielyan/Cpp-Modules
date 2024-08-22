/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:18:24 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/08 16:48:14 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"
#include <fstream>
#include <iostream>

const std::string ShrubberyCreationForm::_shrubbery = \
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣤⡶⣟⠛⠛⠛⢷⣞⡛⠛⣻⠷⣦⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⠟⠋⠀⠀⠀⣀⠀⠀⠀⠀⠀⠘⠀⠀⠀⣀⠀⠀⠀⠉⠛⢷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡿⢉⠿⣷⣤⠤⠶⣶⠞⠉⠀⠀⠀⠀⠀⢠⣤⡤⠀⠈⠙⢶⠖⠂⠀⣸⠿⣏⠻⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⢟⣿⠀⠉⣠⠎⠀⠀⢠⠇⠀⢀⠀⠀⠀⢤⡤⠞⠁⠀⠀⠀⠀⠈⣧⠀⠀⠀⢠⡈⠆⢸⡛⢷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣾⣇⢀⡠⣶⣾⠁⠀⠀⠀⠀⢀⠀⢸⣄⣀⡄⠀⠀⠀⠀⣀⣀⣼⠄⣄⠈⠀⠀⠀⠀⢹⣶⢬⣀⠈⣿⣦⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⠟⠁⢸⠃⠙⠉⠀⡯⠈⠓⠀⠀⠠⢦⡏⠀⠀⢈⣷⣀⡀⠀⢀⣀⣸⣏⠀⠀⠘⣧⠤⠀⠀⠀⠋⠈⡇⠈⠙⠉⢻⡀⠙⢷⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⢀⣴⡟⠱⠇⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡙⠀⢰⡉⣀⡿⠙⠛⠋⠙⣇⠀⣰⠖⠛⣵⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢷⡀⠈⢣⠹⣷⣀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⣀⣤⣴⡟⠹⠏⠀⠠⢼⣇⠀⠀⠀⠀⠀⢶⡀⢀⡤⠶⠲⠾⣷⣤⡤⠟⠉⠀⠀⠀⠀⠀⠈⠙⠧⣄⣴⡟⠦⡲⠤⣄⠀⣰⠆⠀⠀⠀⠀⢀⣷⠤⠄⠠⠟⠹⣷⣤⣄⡀⠀⠀\
⠀⢀⣾⠋⠁⠩⣷⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⡀⠀⢙⣿⣥⣶⣤⠾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠦⡽⣄⣼⣏⠁⢀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⢰⠏⠁⠉⢷⡄⠀\
⣴⠾⠃⠀⣀⣤⣿⡀⠀⠀⠀⢀⡴⠀⠀⢀⢀⣹⠖⠛⠁⠀⠀⠀⠀⢠⡀⠀⡄⠀⠀⣤⠞⢠⠀⠀⢀⠀⠀⣤⠀⠀⠀⠀⠀⠙⠓⢾⣀⢀⠀⠀⠰⡄⠀⠀⠀⠀⣸⣦⡄⠀⠈⠛⢦\
⣿⣄⣴⠞⠁⠀⠈⠳⠀⠘⠒⢛⣧⣤⠶⠋⠉⠀⠀⠀⠀⠀⠀⣠⠀⢼⣷⡤⠿⠯⢵⡟⠲⢻⡶⢤⡼⠯⣤⡏⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠳⢦⣤⡞⠓⠚⢀⡼⠋⠀⠀⠀⢢⡀⣼\
⣿⣼⠁⠀⠀⠀⠀⣠⡾⣶⡖⠋⠁⠀⠀⠀⠀⠀⠀⠰⠤⠾⠶⠿⣟⣉⣽⣷⢦⣠⠀⢷⠀⣸⠁⢀⣶⣰⠟⢈⡻⢛⣲⡶⠤⠴⠀⠀⠀⠀⠀⠀⠀⠈⠓⣶⠾⣦⠀⠀⠀⠀⠀⢻⡼\
⣿⠻⠀⠈⠓⠒⠛⠁⠀⠼⣧⠤⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠹⣿⢿⣆⢸⡄⡇⢀⣿⣿⡟⠋⠉⠉⠉⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⢬⡿⡄⠈⠙⠒⠖⠋⠀⠈⣷\
⠘⢧⣀⣆⠀⠀⠀⡄⠀⠀⠉⠇⠀⠛⠲⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⣷⣿⠈⣧⠀⣼⣽⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠛⠁⠰⠏⠃⡀⠰⡄⠀⠀⠀⣄⣠⠟\
⠀⠀⠈⠻⠦⢤⣄⠄⠘⠀⠀⣀⡀⠀⠀⠀⡿⣤⠤⠀⠀⠀⠀⠀⠀⣀⣀⣠⠾⢿⡉⠀⠟⠀⠯⣾⠑⢦⣀⣀⠀⠀⠀⠀⠀⠀⠤⢴⣻⡅⠀⠀⠀⢀⡀⠀⠙⠀⢠⣤⡤⠿⠋⠀⠀\
⠀⠀⠀⠀⠀⠀⠙⠻⠶⠖⠺⢭⣄⣀⣀⡼⠁⠀⠀⡀⠀⠀⠴⢦⢀⡄⠉⡀⠀⢸⣧⡀⠀⠀⣖⡟⠀⢀⠈⠁⣄⢠⠶⠄⠀⠀⡀⠀⠉⠸⣤⣀⣀⣬⠟⠒⠶⠾⠛⠁⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠧⠤⠴⠞⣅⣠⢾⣀⣨⢷⣀⣠⠿⠦⠾⣿⢷⣶⣾⣿⡷⠤⠞⢧⣀⣠⣧⣈⣰⢤⣀⡿⠶⠤⠴⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠉⠀⠀⠀⠀⣿⢸⢻⣿⣿⠁⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠘⢸⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣶⡾⣿⠿⠀⠘⣿⠳⣶⠶⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡶⠿⣿⣧⣿⣿⣾⣿⢰⣴⡄⣻⣇⣺⣿⣄⡉⠻⢶⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣿⣅⠸⢿⣻⣟⠘⠷⢏⡉⠙⠉⠙⠉⢈⢲⣇⠘⣧⣘⠿⠀⣿⡧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠓⠒⠻⠦⠴⢷⣄⣮⣿⣦⣤⣤⣿⣤⣄⣼⠧⠤⠿⠒⠚⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⡟⠀⢸⣸⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⡇⠀⡎⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣶⠖⠒⢶⣤⣤⠶⢦⡿⢃⡟⠀⡇⡇⠈⣯⢻⣶⠶⢦⣤⡴⠖⠓⢶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡶⠾⣿⠀⠀⠀⠴⠋⢀⡴⠋⢀⡿⠀⢀⣧⡇⠀⢻⣎⠙⠢⣄⠈⠱⠀⠀⠀⢹⠟⠶⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⡏⠀⠀⢹⣿⣀⣀⡽⠿⠿⣄⢀⢞⣡⣤⣸⠃⢳⣠⢤⣙⣆⢀⡾⠿⠿⣕⣀⣿⣟⠀⠀⠈⣿⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣾⠿⠉⠳⢴⠊⠙⠷⠤⠀⠀⠀⢀⠟⠉⠉⠳⡴⠞⠛⠛⠦⡔⠋⠉⠙⣇⠀⠀⠀⠠⠼⠏⠈⢷⠶⠋⠉⢿⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣼⠏⠟⠀⣆⠀⠈⠦⢤⠤⠄⠀⢀⣴⠷⠒⠀⠀⠀⠲⣤⠤⢤⡴⠂⠀⠀⠀⠲⢷⡄⠀⠠⠤⢤⠴⡇⠀⢠⠆⠸⠇⢤⢹⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⣾⣯⠵⠻⣤⣀⣀⣼⣉⡀⣧⡀⠀⠀⣶⠀⠳⣤⠀⠀⠀⠀⣠⠇⠀⠘⢧⠀⠀⠀⠀⣄⡼⠃⢀⡆⠀⠀⣠⡇⣈⣹⣄⣀⣤⡾⠷⢽⣿⡄⠀⠀⠀⠀⠀⠀⠀\
⠀⠀⠀⠀⠀⠀⠀⠀⠉⣀⡀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠛⠉⣛⠷⠦⢾⠦⠤⠤⠶⣧⡤⠤⢤⣬⠷⠤⠤⢤⣞⡤⠴⢛⠁⠛⠋⠉⣉⠉⠉⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀";



ShrubberyCreationForm::ShrubberyCreationForm(): \
		AForm("ShrubberyCreationForm", 145, 137), _target("Carl") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): \
		AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm( \
		const ShrubberyCreationForm& other):
		AForm(other), _target(other._target)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(\
		const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::ofstream	out(_target + "_shrubberry");
	out << _shrubbery << std::endl;
	out.close();
}
