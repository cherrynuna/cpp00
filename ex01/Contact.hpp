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
		void setName(const std::string& newName);
		void setSurname(const std::string& newSurname);
		void setNickname(const std::string& newNickname);
		void setPhone(const std::string& newPhone);
		void setSecret(const std::string& newSecret);

		// Getter methods
		std::string getName() const;
		std::string getSurname() const;
		std::string getNickname() const;
		std::string getPhone() const;
		std::string getSecret() const;
};

#endif
