#include "UIOption.h"

#include <utility>

UIOption::UIOption(const std::string &text, const sf::Font &font, UIOption::Fill_Outline unselected, UIOption::Fill_Outline selected,
                   unsigned int characterSize, std::function<WorldInterface::TickResult()> callback)
 : unselectedColor(std::move(unselected)), selectedColor(std::move(selected)), callback(std::move(callback)), selectedState(false) {
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(characterSize);
    this->text.setOutlineThickness(2);
    interestingEvents = {sf::Event::KeyPressed};
}

sf::Vector2f UIOption::getLayoutSize() {
    return text.getGlobalBounds().getSize();
}

void UIOption::draw(sf::RenderWindow &window, sf::Vector2f position) {
    auto colors = (selectedState ? selectedColor : unselectedColor);
    text.setFillColor(colors.first);
    text.setOutlineColor(colors.second);
    text.setPosition(position);
    window.draw(text);
}

void UIOption::selected() {
    selectedState = true;
}

void UIOption::deselected() {
    selectedState = false;
}

bool UIOption::isSelectable() const {
    return true;
}

WorldInterface::TickResult UIOption::handleEvent(sf::Event &event) {
    if(selectedState && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
        return callback();
    }
    return WorldInterface::CONTINUE();
}
