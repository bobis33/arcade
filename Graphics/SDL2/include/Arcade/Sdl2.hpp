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
            Sdl2() = default;
            ~Sdl2() override = default;

            Sdl2(const Sdl2 &) = delete;
            Sdl2 &operator=(const Sdl2 &) = delete;

            GameEvent getEvent() override;

            void openWindow(unsigned int width, unsigned int height) override;
            void displayWindow() override { SDL_RenderPresent(_renderer); };
            void clearWindow() override { SDL_RenderClear(_renderer); };
            void closeWindow() override { SDL_DestroyWindow(_window); SDL_Quit(); };
            void setTitle(const std::string &title) override { SDL_SetWindowTitle(_window, title.c_str()); };
            void displayMenu() override{};

        private:
            SDL_Window *_window{nullptr};
            SDL_Renderer *_renderer{nullptr};
            int _widht{0};
            int _height{0};

            static GameEvent keyboardEvent(SDL_Event event);


    }; // Sdl2

} // Arcade

#endif // ARCADE_SDL2_HPP
