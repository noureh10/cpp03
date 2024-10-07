/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:00:00 by nechaara          #+#    #+#             */
/*   Updated: 2024/10/07 18:48:18 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void) 
	: ClapTrap("Veronica_clap_name")
{
	this->_name = "Veronica";
	FragTrap::_hit_points = 100;
	ScavTrap::_energy_points = 50;
	FragTrap::_attack_points = 30;
	outputMessage("DiamondTrap default constructor called");
}

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name")
{
	this->_name = name;
	FragTrap::_hit_points = 100;
	ScavTrap::_energy_points = 50;
	FragTrap::_attack_points = 30;
	outputMessage("DiamondTrap parameterized constructor called");
}


DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy) {
	outputMessage("Passing trough the copy constructor of DiamondTrap");
	(*this) = copy;
}

DiamondTrap::~DiamondTrap() {
	outputMessage("Passing through destructor of ClapTrap");
}

DiamondTrap& DiamondTrap::operator = (DiamondTrap const & assign) {
	outputMessage("Copy assignement operator of DiamondTrap called");
	if (this != &assign) {
		this->_name = assign.getName();
		this->_hit_points = assign.getHitPoints();
		this->_energy_points = assign.getEnergyPoints();
		this->_attack_points = assign.getAttackPoints();
	}
	return (*this);
}

void DiamondTrap::attack(std::string target) {
	ScavTrap::attack(target);
}


void DiamondTrap::whoAmI(void) {
	std::cout << "You don't know me ? I am " + ClapTrap::_name << std::endl;
	std::cout << "but you little guy can call me " + this->_name << std::endl;
}


