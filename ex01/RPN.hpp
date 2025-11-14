/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:51:10 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/14 14:22:27 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <climits>


class newStack : std::stack<int>
{
	public:
		void checkInput(char input);
		using std::stack<int>::top;
		using std::stack<int>::size;
};

#endif