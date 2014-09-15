/*
 * Palyer.cpp
 *
 *  Created on: 26 juin 2013
 *      Author: bertrand
 */

#include "player.h"

Player::Player()
        :current_state(stand_front)
{
}

bool Player::loadFromFile(const std::string &filename)
{
        std::ifstream file(filename.c_str());

        if (file.is_open())
                return safeLoad(file);
        else return false;
}

bool Player::safeLoad(std::ifstream &file)
{
        std::string str, name;

        int nb;
        unsigned int x, y, w, h;

        TexturesManager* manager = TexturesManager::getInstance();

        file >> str;

        std::map<std::string,state> correspondance;

        correspondance["stay-front"] = stand_front;
        correspondance["walk-front"] = walking_front;
        correspondance["stay-back"] = stand_back;
        correspondance["walk-back"] = walking_back;
        correspondance["stay-right"] = stand_right;
        correspondance["walk-right"] = walking_right;
        correspondance["stay-left"] = stand_left;
        correspondance["walk-left"] = walking_left;

        movements.resize(10);

        while(!file.eof())
        {
                file >> name >> nb;
                if (nb>0) {
                        movements[correspondance[name]] = AnimatedSprite(manager->getTexture(str, false, false, sf::Color(0, 128, 128)), sf::seconds(0.2), false, true);

                        for (int i = 0; i < abs(nb); ++i) {
                                file >> x >> y >> w >> h;
                                movements[correspondance[name]].addAnimation(sf::IntRect(x, y, w, h));
                                movements[correspondance[name]].setPosition(50, 50);
                        }
                } else {
                        movements[correspondance[name]] = AnimatedSprite(manager->getTexture(str, true, false, sf::Color(0, 128, 128)), sf::seconds(0.2), false, true);

                        for (int i = 0; i < abs(nb); ++i){
                                file >> x >> y >> w >> h;
                                movements[correspondance[name]].addAnimation(
                                                        sf::IntRect(movements[correspondance[name]].getSize().x - x - w, y, w, h)
                                                );
                                movements[correspondance[name]].setPosition(50, 50);
                        }
                }
        }
        return true;
}

void Player::setCurrentMovment(const state &newMovment)
{
        current_state=newMovment;
}

void Player::move(const sf::Vector2f &p_vect)
{
        movements[current_state].move(p_vect);
}

const AnimatedSprite &Player::getCurrentAnimation()
{
        return movements[current_state];
}

sf::Vector2f Player::update()
{
        sf::Vector2f depl_vector = {0, 0};
        const auto old_position = movements[current_state].getPosition();

        if (keyboard.isKeyPressed(sf::Keyboard::S)){
                current_state = walking_front;
                depl_vector +=  {0, 1};
        }
        if (keyboard.isKeyPressed(sf::Keyboard::W)){
                current_state = walking_back;
                depl_vector +=  {0, -1};
        }
        if (keyboard.isKeyPressed(sf::Keyboard::D)){
                current_state = walking_right;
                depl_vector +=  {1, 0};
        }
        if (keyboard.isKeyPressed(sf::Keyboard::A)){
                current_state = walking_left;
                depl_vector +=  {-1, 0};
        }
        // cas où aucune touche n'est appuyée on met à jour l'état mais le vecteur de déplacement est {0,0}
        if (depl_vector == sf::Vector2f{0, 0}){
                setStanding();
        }

        movements[current_state].setPosition(old_position);
        movements[current_state].update();
        return depl_vector;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        target.draw(movements[current_state],states);
}

void Player::setStanding()
{
        switch (current_state) {
        case walking_back :
                current_state=stand_back;
                break;
        case walking_front :
                current_state=stand_front;
                break;
        case walking_left :
                current_state=stand_left;
                break;
        case walking_right :
                current_state=stand_right;
                break;
        default:
                current_state=stand_front;
                break;
        }
}
