/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:15:39 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/22 20:49:18 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class	Array
{
private:
	size_t	_size;
	T*		_buf;
public:
	Array();
	Array(unsigned int n);
	Array(const Array<T>& other);

	Array&	operator=(const Array& other);
	T&	operator[](size_t index);
	const T& operator[](size_t index) const;

	size_t	size(void);

	~Array(void);
};

template <typename T>
Array<T>::Array(): _size(0), _buf(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	_buf = new T[_size];
	for (size_t i = 0; i < _size; i ++)
		_buf[i] = T();
}

template <typename T>
Array<T>::Array(const Array<T>& other): _size(other._size)
{
	_buf = new T[_size];
	for (size_t i = 0; i < _size; i ++)
		_buf[i] = other._buf[i];
}

template <typename T>
Array<T>::~Array(void)
{
	if (_buf != NULL)
		delete [] _buf;
}

template <typename T>
size_t	Array<T>::size(void)
{
	return (_size);
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (*this != &other)
	{
		if (this->_buf != NULL)
			delete [] this->_buf;
		this->_buf = new T[this->_size];
		this->_size = other._size;
		for (size_t i = 0; i < this->_size; i ++)
			this->_buf[i] = other._buf[i];
	}
	return (*this);
}

template <type
const T&

#endif
