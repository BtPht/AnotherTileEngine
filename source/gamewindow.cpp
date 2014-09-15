#include "gamewindow.h"

GameWindow::GameWindow() :
        sf::RenderWindow(sf::VideoMode(400, 300), "Fenetre créée par défaut"),
        marge_scroll(100),
        m_offset(10),
        m_camera(sf::FloatRect(0,0,400,300))
{
        setFramerateLimit(60);

        setView(m_camera);

        m_frameTime.restart();

        display();
}


GameWindow::GameWindow(sf::VideoMode Mode, const std::string &Title)
        : sf::RenderWindow(Mode,Title),
          marge_scroll(100)
{
        setFramerateLimit(60);

        m_frameTime.restart();

        display();
}

void GameWindow::resize(const unsigned int width, const unsigned int height)
{
        m_camera.reset(sf::FloatRect(0,0,width,height));
        setView(m_camera);
}

void GameWindow::zoom(const int delta)
{
        if(delta > 0){
                m_camera.zoom(0.9f * delta);
        }else{
                m_camera.zoom(1.1f * -delta);
        }

        setView(m_camera);
}

void GameWindow::scrolling()
{
        m_camera.move(getHorizontalScrollingOffset(),
                      getVerticalScrollingOffset());

        setView(m_camera);
}

float GameWindow::getVerticalScrollingOffset()
{
        float result = 0 ;

        if (m_keyboard.isKeyPressed(sf::Keyboard::Up)
            && m_camera.getCenter().y - m_camera.getSize().y / 2 + marge_scroll > 0)
                result -= m_offset;

        if (m_keyboard.isKeyPressed(sf::Keyboard::Down))
                result +=  m_offset;

        return result ;
}

float GameWindow::getHorizontalScrollingOffset()
{
        float result = 0;

        if (m_keyboard.isKeyPressed(sf::Keyboard::Left)
            && m_camera.getCenter().x - m_camera.getSize().x / 2 + marge_scroll > 0)
                result -= m_offset;

        if (m_keyboard.isKeyPressed(sf::Keyboard::Right))
                result += m_offset;

        return result;
}
