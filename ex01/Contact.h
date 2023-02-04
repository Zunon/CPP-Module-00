//
// Created by Khalifa Almheiri on 2/4/23.
//

#ifndef CPP_MODULE_00_CONTACT_H
# define CPP_MODULE_00_CONTACT_H
# include <string>
# include <iomanip>

class Contact {
	std::string			firstName;
	std::string			lastName;
	std::string			nickName;
	public:
		Contact (void);
		Contact (const Contact &);
		Contact (std::string, std::string, std::string);
		Contact			&operator= (const Contact &);
		std::string		getFirstName (void);
		std::string		getLastName (void);
		std::string		getNickName (void);
		std::string		getFirstName (void) const;
		std::string		getLastName (void) const;
		std::string		getNickName (void) const;
		~Contact (void);
};

std::ostream &operator<< (std::ostream &, const Contact &);

#endif //CPP_MODULE_00_CONTACT_H
