/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:45:16 by nechaara          #+#    #+#             */
/*   Updated: 2024/10/07 17:49:39 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string _name;
		int _hit_points;
		int _energy_points;
		int _attack_points;
		void outputMessage(std::string message);
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap & operator=(const ClapTrap &assign);
		void attack(const std::string& target);
		void takeDamage(unsigned int ammount);
		void beRepaired(unsigned int ammount);
		
		std::string getName(void) const;
		int getHitPoints(void) const;
		int getEnergyPoints(void) const;
		int getAttackPoints(void) const;

		void setName(std::string name);
		void setHitPoints(int amount);
		void setEnergyPoints(int amount);
		void setAttackPoints(int amount);
};

#endif