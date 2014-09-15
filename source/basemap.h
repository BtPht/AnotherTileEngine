#ifndef BASEMAP_H_
#define BASEMAP_H_

#include <SFML/Graphics.hpp>

#include "texturesmanager.h"
#include "infotile.h"
#include "player.h"
#include "richobject.h"

#include <string>
#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

class Player ;
class BaseMapBuilder;

class BaseMap : public sf::Drawable {
public:
        BaseMap();

        void deplacement(const AnimatedSprite &p_sprite, sf::Vector2f &o_vect);

        InfoTile *getInfo(const float &p_x, const float &p_y);
        InfoTile *getInfo(sf::Vector2f p_pos);

        void update();

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
        std::vector<sf::Texture> tileset;
        std::vector<std::vector<RichObject>>  sprites;

        friend class BaseMapBuilder ;
};

#endif /* BASEMAP_H_ */
