/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:02:28 by agorski           #+#    #+#             */
/*   Updated: 2025/10/17 13:33:57 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template <typename T> 
T min(T x, T y) {
    return (x < y) ? x : y;
}

template <typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}

#endif
