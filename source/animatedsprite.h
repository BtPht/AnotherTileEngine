////////////////////////////////////////////////////////////
//
// Copyright (C) 2013 Maximilian Wagenbach (aka. Foaly) (foaly.f@web.de)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef ANIMATEDSPRITE_INCLUDE
#define ANIMATEDSPRITE_INCLUDE

#include <vector>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Clock.hpp>

//#include "basictile.h"
#include "texturesmanager.h"

class AnimatedSprite : public sf::Sprite {
public:
        explicit AnimatedSprite(const sf::Texture &texture = sf::Texture(), sf::Time frameTime = sf::seconds(0.2), bool paused = false, bool looped = true);

        //sf::FloatRect getLocalBounds() const;
        //sf::FloatRect getGlobalBounds() const;
        bool isLooped() const;
        bool isPlaying() const;
        sf::Vector2u getSize() const;
        sf::Time getFrameTime() const;
        bool contains(const sf::Vector2f &p_point) const;
        bool contains(const float &p_x, const float &p_y) const ;
        bool intersects(const sf::Rect<float> &p_rectangle) const;
        bool intersects(const AnimatedSprite &p_anim) const;
        const sf::IntRect &getTextureRect() const;
        const sf::FloatRect &getRectPosition() const;

        void addAnimation(sf::IntRect rects);
        void setFrameTime(sf::Time time);
        void play();
        void pause();
        void stop();
        void setLooped(bool looped);
        //void setColor(const sf::Color& color);

        void update();

private:
        std::vector<sf::IntRect> m_animation;
        sf::FloatRect m_rectposition;
        sf::Time m_frameTime;
        sf::Time m_currentTime;
        std::size_t m_currentFrame;
        bool m_isPaused;
        bool m_isLooped;
        sf::Vertex m_vertices[4];
        sf::Clock clock;

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        void updateFrame();
        void updateVerticesPosition();
        void updateVerticesTextureCoordinates(const sf::IntRect &rect);
};

#endif // ANIMATEDSPRITE_INCLUDE
