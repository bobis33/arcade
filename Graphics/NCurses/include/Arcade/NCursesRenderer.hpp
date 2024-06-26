/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCursesRenderer.hpp
*/

/**
 * @file NCursesRenderer.hpp
 * @brief File declaring NCursesRenderer
 */

#ifndef ARCADE_NCURSES_RENDERER_HPP
#define ARCADE_NCURSES_RENDERER_HPP

#include <ncurses.h>
#include <map>

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/NCursesWindow.hpp"

namespace Arcade
{

    /**
    * @brief NCursesRenderer class
    * @details NCursesRenderer class for the Arcade project
    */
    class NCursesRenderer : public IRenderer
    {
        public:
            ~NCursesRenderer() override = default;

            KeyboardEvents getEvent() override;

            bool loadTexture(const std::string &texture, const std::string &name) override { (void)texture; (void)name; return true;};
            void createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x, float scale_y) override {(void)textureName; (void)pos_x; (void)pos_y; (void)scale_x; (void)scale_y;};
            void displaySprite(const std::string &spriteName) override {(void)spriteName;};

            bool loadFont(const std::string &filepath, const std::string &name) override {(void) filepath; (void) name; return true;};
            void createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) override;
            void displayText(const std::string &textName) override;
            void moveText(const std::string &textName, int pos_x, int pos_y) override;

            bool isASCII() override { return true; };
            IWindow *getWindow() override { return &_window; };

            void loadSound(const std::string &filePath) override { (void) filePath; };
            void stopSound() override {};

            void moveSprite(const std::string &spriteName, float pos_x, float pos_y) override {(void)spriteName; (void)pos_x; (void)pos_y;};
            void rotateSprite(const std::string &spriteName, float angle) override {(void)spriteName; (void)angle;};

            std::string updateTextBox() override;
            void setSize(float x, float y) override {_size = std::make_pair(x, y);};

            void deleteRessources() override {};

        private:

            /**
             * @brief The NCursesWindow
             */
            NCursesWindow _window;

            struct Text {
                std::string text;
                int pos_x;
                int pos_y;
            };

            std::map<std::string, Text> _texts;

            std::pair<float, float> _size;

            std::string _userName;

            bool _isLogged{false};

	}; // NCursesRenderer

} // namespace Arcade

#endif // ARCADE_NCURSES_RENDERER_HPP
