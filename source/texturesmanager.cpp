/*
 * TexturesManager.cpp
 *
 *  Created on: 24 juin 2013
 *      Author: bertrand
 */

#include "texturesmanager.h"

TexturesManager* TexturesManager::instance=NULL;

TexturesManager::TexturesManager()
{
}

TexturesManager *TexturesManager::getInstance()
{
        if(TexturesManager::instance != NULL)
                return TexturesManager::instance;
        else
                return new TexturesManager();
}

const sf::Texture& TexturesManager::getTexture(const std::string &key)
{
        if (!textures.count(key)) {
                sf::Texture tmp;
                if(!tmp.loadFromFile(key)) throw("Le gestionnaire d'images n'a pas réussi à charger l'image");
                textures[key] = tmp;
        }
        return textures[key];
}

const sf::Texture &TexturesManager::getTexture(
                const std::string &key,
                bool horizontal,
                bool vertical,
                sf::Color alpha,
                sf::Uint8 level
                )
{
        std::string alt_key = key;
        alt_key += horizontal;
        alt_key += vertical;
        alt_key += alpha.r;
        alt_key += alpha.g;
        alt_key += alpha.b;
        alt_key += level;
        if (!textures.count(alt_key)) {
                sf::Image img;
                img.loadFromFile(key);
                if(horizontal) img.flipHorizontally();
                if(vertical) img.flipVertically();
                img.createMaskFromColor(alpha,level);

                sf::Texture tmp;
                if(!tmp.loadFromImage(img)) throw("Le gestionnaire d'images n'a pas réussi à charger l'image");
                textures[alt_key] = tmp;
        }
        return textures[alt_key];
}

