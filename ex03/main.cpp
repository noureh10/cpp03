/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara.student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:45:51 by nechaara          #+#    #+#             */
/*   Updated: 2024/10/07 11:42:01 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap Veronica("V");
	std::string vilainName = "The Boss";

	std::cout << "The DiamondTrap name : " << Veronica.getName() << std::endl;
	std::cout << "The DiamondTrap HP : " << Veronica.getHitPoints() << std::endl;
	std::cout << "The DiamondTrap Energy Points : " << Veronica.getEnergyPoints() << std::endl;
	std::cout << "The DiamondTrap Attack Points : " << Veronica.getAttackPoints() << std::endl;
	
	// can't attack
	Veronica.setHitPoints(0);
	Veronica.attack(vilainName);
	// can attack
	Veronica.setHitPoints(1);
	Veronica.attack(vilainName);
	// can't attack
	Veronica.setEnergyPoints(0);
	Veronica.attack(vilainName);
	
	// can't attack
	Veronica.setEnergyPoints(-20);
	Veronica.attack(vilainName);

	//should attack 20 times without a hiccup
	int energy = 20;
	Veronica.setEnergyPoints(energy);
	for (int i = 0; i < energy; i++) {
		std::cout << "Attack number : " << i + 1 << std::endl;
		Veronica.attack(vilainName);
	}
	//shouldn't be able to attack due to depleted energy points
	Veronica.attack(vilainName);

	// can't repair
	Veronica.setHitPoints(0);
	Veronica.setEnergyPoints(10);
	Veronica.beRepaired(11);
	
	// can repair
	Veronica.setHitPoints(1);
	Veronica.beRepaired(11);
	
	// can't repair
	Veronica.setHitPoints(5);
	Veronica.setEnergyPoints(-10);
	Veronica.beRepaired(10);

	 Veronica.whoAmI();
}