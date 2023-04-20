#ifndef OOP_UILABEL_H
#define OOP_UILABEL_H

#include "menu/UIItem.h"
#include <optional>

class UILabel : public UIItem {
    sf::Text text;
public:
    UILabel();
    explicit UILabel(const sf::Font &font);
    explicit UILabel(sf::Text text);
    UILabel(const std::string &text, const sf::Font &font, unsigned int characterSize,
            sf::Color textColor = sf::Color::Black,
            sf::Color fillColor = sf::Color::Transparent);
    sf::Vector2f getLayoutSize() override;
    void draw(sf::RenderWindow &window, sf::Vector2f position) override;
    [[maybe_unused]] void setText(const sf::Text &text);
    void setString(const std::string &string);
    void setText(const std::string &text);
    void setFillColor(sf::Color color);
    void setOutlineColor(sf::Color color);
    void setCharacterSize(unsigned int size);
    void setFont(const sf::Font &font);
    void setStyle(sf::Uint32 style);
};


#endif //OOP_UILABEL_H
