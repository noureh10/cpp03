/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:45:51 by nechaara          #+#    #+#             */
/*   Updated: 2024/10/03 14:07:03 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap Marc("Marc");
	std::string vilainName = "Big Angry Guy";

	std::cout << "The ScavTrap name : " << Marc.getName() << std::endl;
	std::cout << "The ScavTrap HP : " << Marc.getHitPoints() << std::endl;
	std::cout << "The ScavTrap Attack Points : " << Marc.getAttackPoints() << std::endl;
	std::cout << "The ScavTrap Energy Points : " << Marc.getEnergyPoints() << std::endl;
	
	// can't attack
	Marc.setHitPoints(0);
	Marc.attack(vilainName);
	// can attack
	Marc.setHitPoints(1);
	Marc.attack(vilainName);
	// can't attack
	Marc.setEnergyPoints(0);
	Marc.attack(vilainName);
	
	// can't attack
	Marc.setEnergyPoints(-20);
	Marc.attack(vilainName);

	//should attack 20 times without a hiccup
	int energy = 20;
	Marc.setEnergyPoints(energy);
	for (int i = 0; i < energy; i++) {
		std::cout << "Attack number : " << i + 1 << std::endl;
		Marc.attack(vilainName);
	}
	//shouldn't be able to attack due to depleted energy points
	Marc.attack(vilainName);
	
	// can't repair
	Marc.setHitPoints(0);
	Marc.setEnergyPoints(10);
	Marc.beRepaired(11);
	
	// can repair
	Marc.setHitPoints(1);
	Marc.beRepaired(11);
	
	// can't repair
	Marc.setHitPoints(5);
	Marc.setEnergyPoints(-10);
	Marc.beRepaired(10);

	// Checking default constructor
	ClapTrap Henry("");
	std::cout << "The ScavTrap name : " << Henry.getName() << std::endl;
	
}