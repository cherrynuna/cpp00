#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		std::string	name;
		std::string	surname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;

	public:
		// Setter methods
		void setName(const std::string& newName) { name = newName; }
		void setSurname(const std::string& newSurname) { surname = newSurname; }
		void setNickname(const std::string& newNickname) { nickname = newNickname; }
		void setPhone(const std::string& newPhone) { phone = newPhone; }
		void setSecret(const std::string& newSecret) { secret = newSecret; }

		// Getter methods
		std::string getName() const { return name; }
		std::string getSurname() const { return surname; }
		std::string getNickname() const { return nickname; }
		std::string getPhone() const { return phone; }
		std::string getSecret() const { return secret; }
};

#endif
