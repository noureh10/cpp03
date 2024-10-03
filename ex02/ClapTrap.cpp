/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:45:25 by nechaara          #+#    #+#             */
/*   Updated: 2024/08/22 15:57:32 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	ClapTrap("Henry");
}

ClapTrap::ClapTrap(std::string name) {
	outputMessage("Passing trough constructor of ClapTrap");
	this->setName(name);
	this->setHitPoints(10);
	this->setEnergyPoints(10);
	this->setAttackPoints(0);
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	outputMessage("Passing through copy constructor of ClapTrap");
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &assign) {
	outputMessage("Copy assignement operator of ClapTrap called");
	if (this != &assign) {
		this->_name = assign.getName();
		this->_hit_points = assign.getHitPoints();
		this->_energy_points = assign.getEnergyPoints();
		this->_attack_points = assign.getAttackPoints();
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	outputMessage("Passing through destructor of ClapTrap");
}

void ClapTrap::outputMessage(std::string message) {
	std::cout << message << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_energy_points <= 0 || this->_hit_points <= 0)
		std::cout << "The ClapTrap " << this->_name << " can't attack" << std::endl;
	else
	{
		std::cout << "The ClapTrap " << this->_name << " attacks " << target << std::endl;
		this->_energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	int damage_value = (int) amount;
	if (damage_value > this->_hit_points)
		this->_hit_points = 0;
	else
		_hit_points -= damage_value;
	std::cout << "The ClapTrap " << this->_name << "took " << amount << " of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	int repair_value = (int) amount;
	if (this->_energy_points <= 0 || this->_hit_points <= 0) {
		std::cout << "The ClapTrap " << this->_name << " can't repair" <<std::endl;
	} else {
		if (repair_value >= this->_energy_points) {
			repair_value = this->_energy_points;
			this->_hit_points += repair_value;
			this->_energy_points -= repair_value;
			std::cout << "The ClapTrap " << this->_name << " has restored the max value of hit points which was " << repair_value << " HP" << std::endl;
		} else {
			this->_hit_points += repair_value;
			this->_energy_points -= repair_value;
			std::cout << "The ClapTrap " << this->_name << " has restored " << repair_value << " of HP" << std::endl;
		}
	}
}

std::string ClapTrap::getName(void) const {
	return (this->_name);
}

int ClapTrap::getHitPoints(void) const {
	return (this->_hit_points);
}

int ClapTrap::getEnergyPoints(void) const {
	return (this->_energy_points);
}

int ClapTrap::getAttackPoints(void) const {
	return (this->_attack_points);
}

void ClapTrap::setName(std::string name) {
	if (!name.empty())
		this->_name = name;
	else
		this->_name = "Henry";
}

void ClapTrap::setHitPoints(int amount) {
	this->_hit_points = amount;
}

void ClapTrap::setEnergyPoints(int amount) {
	this->_energy_points = amount;
}

void ClapTrap::setAttackPoints(int amount) {
	this->_attack_points = amount;
}