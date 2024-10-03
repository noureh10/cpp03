/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:38:17 by nechaara          #+#    #+#             */
/*   Updated: 2024/08/25 13:33:52 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Ivy")
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->_hit_points = 101;
	this->_energy_points = 101;
	this->_attack_points = 31;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "Parametric FragTrap constructor called for " << this->_name << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_points = 30;
}


FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy){
	outputMessage("Passing trough the copy constructor of FlagTrap");
	(*this) = copy;
}


FragTrap::~FragTrap() {
	outputMessage("Passing trough the destructor of FlagTrap");
}

FragTrap& FragTrap::operator = (FragTrap const & assign) {
	outputMessage("Copy assignement operator of FlagTrap called");
	if (this != &assign) {
		this->_name = assign.getName();
		this->_hit_points = assign.getHitPoints();
		this->_energy_points = assign.getEnergyPoints();
		this->_attack_points = assign.getAttackPoints();
	}
	return (*this);
}


void FragTrap::highFiveGuys(void) {
	outputMessage("A really positive high five !");
}