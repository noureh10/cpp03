/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:50:57 by nechaara          #+#    #+#             */
/*   Updated: 2024/08/24 15:35:53 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Mark") {
	outputMessage("Passing through the default constructor of ScavTrap");
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_points = 20;
}

ScavTrap::ScavTrap(std::string name) {
	outputMessage("Passing through the constructor of ScavTrap");
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_points = 20;
}

ScavTrap::ScavTrap (const ScavTrap  &copy) : ClapTrap(copy) {
	outputMessage("Passing through the copy constructor of ScavTrap");
	(*this) = copy;
}

ScavTrap::~ScavTrap() {
	outputMessage("Passing through the destructor of ScavTrap");
}

ScavTrap& ScavTrap::operator=(const ScavTrap &assign) {
	outputMessage("Copy assignement operator of ClapTrap called");
	if (this != &assign) {
		this->_name = assign.getName();
		this->_hit_points = assign.getHitPoints();
		this->_energy_points = assign.getEnergyPoints();
		this->_attack_points = assign.getAttackPoints();
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target) {
	if (this->_energy_points <= 0 || this->_hit_points <= 0)
		std::cout << "The ScavTrap " << this->_name << " can't attack" << std::endl;
	else
	{
		std::cout << "The ScavTrap " << this->_name << " attacks " << target << std::endl;
		this->_energy_points--;
	}
}

void ScavTrap::guardGate(void){
	std::cout << this->_name << " is in Gate Keeper mode" << std::endl;
}
