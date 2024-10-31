#include "Contact.hpp"

// Setter methods
void Contact::setName(const std::string& newName) {
	name = newName;
}

void Contact::setSurname(const std::string& newSurname) {
	surname = newSurname;
}

void Contact::setNickname(const std::string& newNickname) {
	nickname = newNickname;
}

void Contact::setPhone(const std::string& newPhone) {
	phone = newPhone;
}

void Contact::setSecret(const std::string& newSecret) {
	secret = newSecret;
}

// Getter methods
std::string Contact::getName() const {
	return name;
}

std::string Contact::getSurname() const {
	return surname;
}

std::string Contact::getNickname() const {
	return nickname;
}

std::string Contact::getPhone() const {
	return phone;
}

std::string Contact::getSecret() const {
	return secret;
}