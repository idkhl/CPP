#ifndef MATERIA_SOURCE
# define MATERIA_SOURCE
# include <iostream>
# include "Materia.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource: public IMateriaSource
{
	private:
        AMateria* learnedMaterias[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		MateriaSource &operator=(MateriaSource const &copy);
		~MateriaSource();

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif