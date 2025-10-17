/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:33:09 by agorski           #+#    #+#             */
/*   Updated: 2025/10/17 13:55:41 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>  // for size_t

template <typename Arr, typename Fx>
void iter (Arr* a, size_t len, Fx f) {
    while (len--)
        f(*a++);
}

#endif