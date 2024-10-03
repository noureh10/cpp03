/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:45:51 by nechaara          #+#    #+#             */
/*   Updated: 2024/08/23 16:26:03 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	ScavTrap Gabriel("Gabriel");
	std::string vilainName = "Very Big Angry Guy";

	std::cout << "The ScavTrap name : " << Gabriel.getName() << std::endl;
	std::cout << "The ScavTrap HP : " << Gabriel.getHitPoints() << std::endl;
	std::cout << "The ScavTrap Attack Points : " << Gabriel.getAttackPoints() << std::endl;
	std::cout << "The ScavTrap Energy Points : " << Gabriel.getEnergyPoints() << std::endl;
	

	// can't attack
	Gabriel.setHitPoints(0);
	Gabriel.attack(vilainName);
	// can attack
	Gabriel.setHitPoints(1);
	Gabriel.attack(vilainName);
	// can't attack
	Gabriel.setEnergyPoints(0);
	Gabriel.attack(vilainName);
	
	// can't attack
	Gabriel.setEnergyPoints(-20);
	Gabriel.attack(vilainName);

	//should attack 20 times without a hiccup
	int energy = 20;
	Gabriel.setEnergyPoints(energy);
	for (int i = 0; i < energy; i++) {
		std::cout << "Attack number : " << i + 1 << std::endl;
		Gabriel.attack(vilainName);
	}
	//shouldn't be able to attack due to depleted energy points
	Gabriel.attack(vilainName);

	// can't repair
	Gabriel.setHitPoints(0);
	Gabriel.setEnergyPoints(10);
	Gabriel.beRepaired(11);
	
	// can repair
	Gabriel.setHitPoints(1);
	Gabriel.beRepaired(11);
	
	// can't repair
	Gabriel.setHitPoints(5);
	Gabriel.setEnergyPoints(-10);
	Gabriel.beRepaired(10);

	Gabriel.guardGate();
}