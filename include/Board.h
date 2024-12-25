
#include "Toolbar.h"
#include <SFML/Graphics.hpp>


class Board :public Toolbar
{
public:
	Board(const int i = 0,const int j = 0);
	void ran();

private:
	void insert_objects(Object& object);
	void update_window();
	std::vector<Object> m_objects;
	sf::RenderWindow m_window;
};