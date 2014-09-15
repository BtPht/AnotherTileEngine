#include "basictile.h"

BasicTile::BasicTile()
        : crossable(true)
{
        // TODO Auto-generated constructor stub
}

/*BasicTile::BasicTile(const BasicTile& tocp)
: crossable(tocp.crossable)
{
    setTexture(*tocp.getTexture());
    setTextureRect(tocp.getTextureRect());
}*/

/*BasicTile& BasicTile::operator =(const BasicTile& tocp) {

    setTexture(*tocp.getTexture());
    setTextureRect(tocp.getTextureRect());

    crossable = tocp.crossable;

    return *this;
}*/

BasicTile::BasicTile(const sf::Texture &texture)
        : sf::Sprite(texture),
          crossable(true)
{
}

BasicTile::BasicTile(const sf::Texture &texture, const sf::IntRect &rectangle)
        :sf::Sprite(texture,rectangle),
          crossable(true)
{
}

BasicTile::~BasicTile()
{
        // TODO Auto-generated destructor stub
}

void BasicTile::update()
{
}

void BasicTile::setCrossable()
{
        crossable = true;
}

void BasicTile::setUncrossable()
{
        crossable = false;
}

const bool &BasicTile::isCrossable()
{
        return crossable;
}

