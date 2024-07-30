/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:29:21 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 19:53:58 by kdaniely         ###   ########.fr       */
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

/* Animal */
# define ANIMAL_DFLT "[ Animal default constructor called ]"
# define ANIMAL_PARAM "[ Animal parametrized constructor called ]"
# define ANIMAL_COPY "[ Animal copy-constructor called ]"
# define ANIMAL_ASSGN "[ Animal assignment operator called ]"
# define ANIMAL_DESTR "[ Animal destructor called ]"
# define ANIMAL_SOUND "* GENERIC ANIMAL SOUNDS *"

/* Dog */
# define DOG_DFLT "[ Dog default constructor called ]"
# define DOG_COPY "[ Dog copy constructor called ]"
# define DOG_ASSGN "[ Dog copy assignment operator called ]"
# define DOG_DESTR "[ Dog destructor called ]"
# define DOG_SOUND "* BARK *"

/* CAT */
# define CAT_DFLT "[ Cat default constructor called ]"
# define CAT_COPY "[ Cat copy constructor called ]"
# define CAT_ASSGN "[ Cat copy assignment operator called ]"
# define CAT_DESTR "[ Cat destructor called ]" 
# define CAT_SOUND "* MEOW *"

/* Wrong Animal */
# define WANIMAL_DFLT "[ WrongAnimal default constructor called ]"
# define WANIMAL_PARAM "[ WrongAnimal parametrized constructor called ]" 
# define WANIMAL_COPY "[ WrongAnimal copy-constructor called ]"
# define WANIMAL_ASSGN "[ WrongAnimal assignment operator called ]"
# define WANIMAL_DESTR "[ WrongAnimal destructor called ]"
# define WANIMAL_SOUND "* GENERIC WRONG ANIMAL SOUNDS *"

/* Wrong Cat */
# define WCAT_DFLT "[ WrongCat default constructor called ]"
# define WCAT_COPY "[ WrongCat copy-constructor called ]"
# define WCAT_ASSGN "[ WrongCat copy assignment operator called ]"
# define WCAT_DESTR "[ WrongCat destructor called ]"
# define WCAT_SOUND "* WRONG MEOW *"

/* Brain */
# define BRAIN_DFLT "[ Brain default constructor called ]"
# define BRAIN_COPY "[ Brain copy-constructor called ]"
# define BRAIN_ASSGN "[ Brain copy assignment operator called ]"
# define BRAIN_DESTR "[ Brain destructor called ]"

# define DEFAULT_IDEAS "* GIBBERISH *"

#endif

