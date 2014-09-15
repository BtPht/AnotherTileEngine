#include "basemap.h"

BaseMap::BaseMap()
{
}

void BaseMap::deplacement(const AnimatedSprite &p_sprite, sf::Vector2f &o_vect)
{
        if(o_vect == sf::Vector2f{0,0}) return;

        sf::Rect<float> pos_sprite = p_sprite.getRectPosition();

        pos_sprite.top += o_vect.x;

        for (int var = sprites.size() - 1; var >= 0; --var) {
                for (auto& var2 : sprites[var]) {
                        if (var2.intersects(pos_sprite)) {
                                o_vect.x *= var2.getPractibility();
                                return;
                        }
                }
        }
}

InfoTile *BaseMap::getInfo(const float &p_x, const float &p_y)
{
        for (int var = sprites.size() - 1; var >= 0; --var) {
                for (auto& var2 : sprites[var]) {
                        if (var2.contains(p_x,p_y)) {
                                return new InfoTile(sf::Vector2f(p_x, p_y),var2.getName());
                        }
                }
        }
        return nullptr;
}

InfoTile *BaseMap::getInfo(sf::Vector2f p_pos)
{
        return getInfo(p_pos.x, p_pos.y);
}

void BaseMap::update()
{
        for (auto &var : sprites) {
                for (auto &var2 : var) {
                        var2.update();
                }
        }
}

void BaseMap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
        for (auto &var : sprites) {
                for (auto &var2 : var) {
                        target.draw(var2, states);
                }
        }
}

