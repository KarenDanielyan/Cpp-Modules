/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:29:21 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 21:47:09 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

/* AMateria */
# define AMAT_DEFAULT "[ AMateria default constructor called ]"
# define AMAT_PARAM "[ AMateria parametrized constructor called ]"
# define AMAT_COPY "[ AMateria copy-constructor called ]"
# define AMAT_ASSIGN "[ AMateria copy assignment operator called ]"
# define AMAT_DESTR "[ AMateria destructor called ]"
# define AMAT_USE "* Was I supposed to do something with "

/* Ice */
# define ICE_DEFAULT "[ Ice default constructor called ]"
# define ICE_COPY "[ Ice copy-constructor called ]"
# define ICE_ASSIGN "[ Ice copy assignment operator called ]"
# define ICE_DESTR "[ Ice destructor called ]"
# define ICE_USE "* shoots an ice bolt at "

/* Cure */
# define CURE_DEFAULT "[ Cure default constructor called ]"
# define CURE_COPY "[ Cure copy-constructor called ]"
# define CURE_ASSIGN "[ Cure copy assignment operator called ]"
# define CURE_DESTR "[ Cure destructor called ]"
# define CURE_USE1 "* heals "
# define CURE_USE2 " wounds *"

/* Character */
# define CHAR_DEFAULT "[ Character default constructor called ]"
# define CHAR_PARAM "[ Character parametrized constructor called ]"
# define CHAR_COPY "[ Character copy-constructor called ]"
# define CHAR_ASSIGN "[ Character copy assignment operator called ]"
# define CHAR_DESTR "[ Character destructor called ]"
# define CHAR_EQUIP_WARN "Warning: Inventory is full!"
# define CHAR_IDX_WARN "Warning: Index out of bounds!"

/* Materia Source */
# define MATS_DEFAULT "[ Materia Source default constructor called ]"
# define MATS_COPY "[ Materia Source copy-constructor called ]"
# define MATS_ASSIGN "[ Materia Source copy assignment operator called ]"
# define MATS_DESTR "[ Materia Source destructor called ]"
# define MATS_INV_TYPE "Warning: Unknown type!"
# define MATS_2BIG "Warning: Material source is full!"
# define MATS_LEARN "Material learned :)"

#endif

