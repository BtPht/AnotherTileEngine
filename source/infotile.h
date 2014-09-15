#ifndef INFOTILE_H_
#define INFOTILE_H_

#include <SFML/Graphics.hpp>

#include <string>

class InfoTile: public sf::Drawable {
public:
        InfoTile();
        InfoTile(const sf::Vector2f &p_pos, const std::vector<std::vector<std::string>> &p_texts);
        InfoTile(const sf::Vector2f &p_pos, const std::string& p_text);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
        std::vector<sf::Text> items;

        sf::RectangleShape cadre;
        sf::Font font;
};

#endif /* INFOTILE_H_ */
