#include "infotile.h"

InfoTile::InfoTile()
{

}

InfoTile::InfoTile(const sf::Vector2f &p_pos,
                   const std::vector<std::vector<std::string>> &p_texts)
{
        unsigned int max = 0;
        unsigned int nb_lines = 0;
        const unsigned int size_font = 12;

        if (!font.loadFromFile("/usr/share/fonts/truetype/ttf-liberation/LiberationSerif-Regular.ttf")){
                throw "erreur de chargement de la police";
        }

        items.clear();

        for (unsigned int i = 0; i < p_texts.size() ; ++i) {
                for (unsigned int j = 0; j < p_texts[i].size(); ++j) {
                        nb_lines++;

                        items.push_back(sf::Text(p_texts[i][j], font,size_font));
                        items.back().setPosition(p_pos.x + 2, p_pos.y + (nb_lines-1)*size_font);
                        items.back().setColor(sf::Color(0, 0, 0));

                        if (items.back().getGlobalBounds().width > max) max = items.back().getGlobalBounds().width;
                }
                nb_lines++;
        }

        cadre.setPosition(p_pos);
        cadre.setSize(sf::Vector2f(max + 3, nb_lines * size_font));


}

InfoTile::InfoTile(const sf::Vector2f &p_pos, const std::string &p_text)
{
        unsigned int max = 0;
        const unsigned int size_font = 12;

        if(!font.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationSerif-Regular.ttf")){
                throw "erreur de chargement de la police";
        }

        items.clear();
        items.push_back(sf::Text(p_text, font,size_font));
        items.back().setPosition(p_pos.x + 2,p_pos.y);
        items.back().setColor(sf::Color(0, 0, 0));

        max = items.back().getGlobalBounds().width;

        cadre.setPosition(p_pos);
        cadre.setSize(sf::Vector2f(max + 3, size_font + 2));
}

void InfoTile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
        target.draw(cadre,states);

        for (unsigned int i = 0; i < items.size(); ++i) {
                target.draw(items[i], states);
        }
}
