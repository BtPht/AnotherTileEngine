#ifndef PALYER_H_
#define PALYER_H_

#include <vector>
#include <string>
#include <fstream>
#include <istream>

#include <SFML/Graphics.hpp>

#include "texturesmanager.h"
#include "animatedsprite.h"
#include "basemap.h"

class BaseMap ;

class Player : public sf::Drawable {
public:
        typedef enum {
                stand_front,
                stand_right,
                stand_left,
                stand_back,
                walking_front,
                walking_right,
                walking_left,
                walking_back
        } state;

        Player();

        bool loadFromFile(const std::string &filename);

        //virtual ~Player();

        void setCurrentMovment(const state &newMovment);
        void move(const sf::Vector2f &p_vect);
        sf::Vector2f update();

        const AnimatedSprite &getCurrentAnimation();

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
        sf::Keyboard keyboard;
        std::vector<AnimatedSprite> movements;
        state current_state;

        bool safeLoad(std::ifstream &file);
        void setStanding();
};

#endif /* PALYER_H_ */
