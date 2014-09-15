#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "player.h"
#include "basemap.h"

class GameWindow : public sf::RenderWindow {
public:
        GameWindow();
        GameWindow(sf::VideoMode Mode, const std::string &Title);

        void setCamera(){setView(m_camera);}

        void resize(const unsigned int width, const unsigned int height);

        void zoom(const int delta);

        void scrolling();

private:
        int marge_scroll;
        float m_offset;

        sf::View m_camera;
        sf::Keyboard m_keyboard;
        sf::Clock m_frameTime;

        float getHorizontalScrollingOffset() ;
        float getVerticalScrollingOffset() ;
};

#endif /* GAMEWINDOW_H_ */
