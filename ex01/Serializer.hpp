#ifndef Serializer_HPP
# define Serializer_HPP

# include <iostream>
# include <string>

typedef struct{
	std::string name;
	int			age;
}Data;

class Serializer
{

	private:

		Serializer();
		Serializer( Serializer const & src );
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif /* *************************************************** Serializer_H */