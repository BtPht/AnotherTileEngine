/*
 * BasicTile.h
 *
 *  Created on: 5 juil. 2013
 *      Author: bertrand
 */

#ifndef BASICTILE_H_
#define BASICTILE_H_

#include <SFML/Graphics.hpp>

class BasicTile : public sf::Sprite {
public:
        BasicTile();
        //BasicTile(BasicTile const& tocp);
        //BasicTile& operator=(BasicTile const& tocp);
        explicit BasicTile(const sf::Texture &texture);
        explicit BasicTile(const sf::Texture &texture, const sf::IntRect &rectangle);
        virtual ~BasicTile();

        void update();

        void setCrossable();
        void setUncrossable();

        const bool& isCrossable();

private:
        bool crossable;
};

#endif /* BASICTILE_H_ */
