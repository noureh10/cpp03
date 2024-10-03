/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:45:51 by nechaara          #+#    #+#             */
/*   Updated: 2024/08/23 17:37:30 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main(void) {
	FragTrap Leslie("Leslie");
	std::string vilainName = "Very Big Angry Guy";

	std::cout << "The ScavTrap name : " << Leslie.getName() << std::endl;
	std::cout << "The ScavTrap HP : " << Leslie.getHitPoints() << std::endl;
	std::cout << "The ScavTrap Attack Points : " << Leslie.getAttackPoints() << std::endl;
	std::cout << "The ScavTrap Energy Points : " << Leslie.getEnergyPoints() << std::endl;
	

	// can't attack
	Leslie.setHitPoints(0);
	Leslie.attack(vilainName);
	// can attack
	Leslie.setHitPoints(1);
	Leslie.attack(vilainName);
	// can't attack
	Leslie.setEnergyPoints(0);
	Leslie.attack(vilainName);
	
	// can't attack
	Leslie.setEnergyPoints(-20);
	Leslie.attack(vilainName);

	//should attack 20 times without a hiccup
	int energy = 20;
	Leslie.setEnergyPoints(energy);
	for (int i = 0; i < energy; i++) {
		std::cout << "Attack number : " << i + 1 << std::endl;
		Leslie.attack(vilainName);
	}
	//shouldn't be able to attack due to depleted energy points
	Leslie.attack(vilainName);

	// can't repair
	Leslie.setHitPoints(0);
	Leslie.setEnergyPoints(10);
	Leslie.beRepaired(11);
	
	// can repair
	Leslie.setHitPoints(1);
	Leslie.beRepaired(11);
	
	// can't repair
	Leslie.setHitPoints(5);
	Leslie.setEnergyPoints(-10);
	Leslie.beRepaired(10);

	Leslie.highFiveGuys();
}