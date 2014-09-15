#ifndef TEXTURESMANAGER_H_
#define TEXTURESMANAGER_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class TexturesManager
{
public:

        static TexturesManager* getInstance();

        const sf::Texture &getTexture(const std::string &key);

        const sf::Texture &getTexture
        (
                        const std::string &key,
                        bool horizontal,
                        bool vertical,
                        sf::Color alpha,
                        sf::Uint8 level = 0
                                          );

        bool isLoaded(const std::string &key);

        void clean();

private:
        static TexturesManager *instance;
        TexturesManager();
        std::map<std::string, sf::Texture> textures;
};

#endif /* TEXTURESMANAGER_H_ */
