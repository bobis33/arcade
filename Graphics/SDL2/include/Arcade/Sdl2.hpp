/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2.hpp
*/

/**
 * @file Sdl2.hpp
 * @brief File declaring Sdl2 class
 */

#ifndef ARCADE_SDL2_HPP
#define ARCADE_SDL2_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "Arcade/abstractions/IRenderer.hpp"

constexpr std::string_view WINDOW_TITLE = "Arcade - SDL2";

namespace Arcade
{

    /**
    * @brief Sdl2 class
    * @details Sdl2 class for the Arcade project
    */
	class Sdl2 : public IRenderer
    {
        public:
            ~Sdl2() override = default;

            GameEvent getEvent() override;

            void openWindow(unsigned int width, unsigned int height) override;
            void displayWindow() override { SDL_RenderPresent(_renderer); };
            void clearWindow() override { SDL_RenderClear(_renderer); };
            void closeWindow() override { SDL_DestroyWindow(_window); SDL_DestroyRenderer(_renderer); SDL_Quit(); };
            void setTitle(const std::string &title) override { SDL_SetWindowTitle(_window, title.c_str()); };

            bool loadTexture(const std::string &texture, const std::string &name) override { (void)texture; (void)name; return true;};
            bool loadFont(const std::string &filepath, const std::string &name) override { (void)filepath; (void)name; return true;};
            void createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x, float scale_y) override {(void)textureName; (void)pos_x; (void)pos_y; (void)scale_x; (void)scale_y;};
            void createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) override {(void)text; (void)fontName; (void)size; (void)pos_x; (void)pos_y;};
            void displaySprite(const std::string &spriteName) override {(void)spriteName;};
            void displayText(const std::string &textName) override {(void)textName;};

            bool isASCII() override { return false; };

        private:
            SDL_Window *_window{nullptr};
            SDL_Renderer *_renderer{nullptr};
            int _widht{0};
            int _height{0};

            static GameEvent keyboardEvent(SDL_Event event);


    }; // Sdl2

} // Arcade

#endif // ARCADE_SDL2_HPP
