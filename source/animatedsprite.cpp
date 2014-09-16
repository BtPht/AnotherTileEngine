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

#include "animatedsprite.h"

AnimatedSprite::AnimatedSprite(const sf::Texture &texture, sf::Time frameTime,bool paused, bool looped) :
        m_frameTime(frameTime),
        m_currentFrame(0),
        m_isPaused(paused),
        m_isLooped(looped)
{
        setTexture(texture);
}

sf::Vector2u AnimatedSprite::getSize() const {
        return getTexture()->getSize();
}

sf::Time AnimatedSprite::getFrameTime() const
{
        return m_frameTime;
}

bool AnimatedSprite::contains(const sf::Vector2f &p_point) const
{
        return contains(p_point.x, p_point.y);
}

bool AnimatedSprite::contains(const float &p_x, const float &p_y) const
{
        return p_x >= getPosition().x &&
                        p_y >= getPosition().y &&
                        p_x <= getPosition().x + (float)getTextureRect().width &&
                        p_y <= getPosition().y + (float)getTextureRect().height;
}

bool AnimatedSprite::intersects(const sf::Rect<float> &p_rectangle) const
{
        return getPosition().x < p_rectangle.width &&
                        getPosition().x + (float)getTextureRect().width > p_rectangle.left &&
                        getPosition().y < p_rectangle.height &&
                        getPosition().y + (float)getTextureRect().height > p_rectangle.top ;
}

bool AnimatedSprite::intersects(const AnimatedSprite& p_anim) const
{
        /*return getPosition().x < p_anim.getPosition().x + p_anim.getTextureRect().width &&
            getPosition().x + getTextureRect().width > p_anim.getPosition().x &&
            getPosition().y < p_anim.getPosition().y + p_anim.getTextureRect().height &&
            getPosition().y + getTextureRect().height > p_anim.getPosition().y ;*/

        return intersects(p_anim.getRectPosition());
}

const sf::IntRect& AnimatedSprite::getTextureRect() const
{
        return m_animation[m_currentFrame];
}

const sf::FloatRect& AnimatedSprite::getRectPosition() const
{
        return m_rectposition;
}

void AnimatedSprite::addAnimation(sf::IntRect rect)
{
        m_animation.push_back(rect);
}

void AnimatedSprite::setFrameTime(sf::Time time)
{
        m_frameTime = time;
}

void AnimatedSprite::play()
{
        if (m_isPaused){
                m_currentTime = sf::Time::Zero;
                m_isPaused = false;
        }
}

void AnimatedSprite::pause()
{
        m_isPaused = true;
}

void AnimatedSprite::stop()
{
        m_isPaused = true;
        m_currentFrame = 0;
}

void AnimatedSprite::setLooped(bool looped)
{
        m_isLooped = looped;
}

void AnimatedSprite::update()
{
        // if not paused and we have a valid animation
        if (!m_isPaused && !m_animation.empty()){
                // add delta time
                m_currentTime += clock.restart();

                // if current time is bigger then the frame time advance one frame
                if (m_currentTime >= m_frameTime){
                        // reset time
                        m_currentTime = sf::Time::Zero;

                        // get next Frame index
                        if (m_currentFrame + 1 < m_animation.size())
                                ++m_currentFrame;
                        else{
                                // animation has ended
                                m_currentFrame = 0; // reset to start

                                if (!m_isLooped){
                                        m_isPaused = true;
                                }
                        }
                        updateFrame();
                }
        }
}


void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
        states.transform *= getTransform();
        states.texture = getTexture();
        target.draw(m_vertices, 4, sf::Quads, states);
}

void AnimatedSprite::updateFrame()
{
        if (!m_animation.empty()){
                sf::IntRect rect = m_animation[m_currentFrame];

                updateVerticesPosition();
                updateVerticesTextureCoordinates(rect);
        }
        m_rectposition = {getPosition().x,
                          getPosition().y,
                          getPosition().x+getTextureRect().width ,
                          getPosition().y+getTextureRect().height};
}

void AnimatedSprite::updateVerticesPosition()
{
        m_vertices[0].position = sf::Vector2f(0, 0);
        m_vertices[1].position = sf::Vector2f(0, m_animation[m_currentFrame].height);
        m_vertices[2].position = sf::Vector2f(m_animation[m_currentFrame].width, m_animation[m_currentFrame].height);
        m_vertices[3].position = sf::Vector2f(m_animation[m_currentFrame].width, 0);
}

void AnimatedSprite::updateVerticesTextureCoordinates(const sf::IntRect &rect)
{
        float left = static_cast<float>(rect.left) + 0.0001;
        float right = left + rect.width;
        float top = static_cast<float>(rect.top);
        float bottom = top + rect.height;

        m_vertices[0].texCoords = sf::Vector2f(left, top);
        m_vertices[1].texCoords = sf::Vector2f(left, bottom);
        m_vertices[2].texCoords = sf::Vector2f(right, bottom);
        m_vertices[3].texCoords = sf::Vector2f(right, top);
}
