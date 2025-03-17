#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int i = 0; i < 4; i++)
	{
        if (other.learnedMaterias[i])
            learnedMaterias[i] = other.learnedMaterias[i]->clone();
        else
            learnedMaterias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other)
	{
        for (int i = 0; i < 4; i++)
		{
            if (learnedMaterias[i] != NULL)
			{
                delete learnedMaterias[i];
                learnedMaterias[i] = NULL;
            }
            if (other.learnedMaterias[i] != NULL)
                learnedMaterias[i] = other.learnedMaterias[i]->clone();
            else
                learnedMaterias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete learnedMaterias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
		return;
    for (int i = 0; i < 4; i++)
	{
        if (!learnedMaterias[i])
		{
            learnedMaterias[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << " at slot " << i << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource is full, cannot learn more materias!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    
    for (int i = 0; i < 4; i++)
	{
        if (learnedMaterias[i] && learnedMaterias[i]->getType() == type)
		{
            std::cout << "MateriaSource created " << type << std::endl;
            return learnedMaterias[i]->clone();
        }
    }
    std::cout << "MateriaSource doesn't know " << type << std::endl;
    return NULL;
}