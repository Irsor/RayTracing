#include <iostream>

#include "Collections/vec3.hpp"
#include "Collections/color.hpp"

int main()
{
    // Изображение
    const int IMAGE_WIDTH = 256;
    const int IMAGE_HEIGHT = 256;

    // Рендер
    std::cout << "P3" << std::endl << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << std::endl << "255" << std::endl;

    for (int i = 0; i < IMAGE_HEIGHT; i++)
    {
        std::clog << "Scanlines remaining: " << (IMAGE_HEIGHT - i) << ' ' << std::endl;
        for (int j = 0; j < IMAGE_WIDTH; j++)
        {
            auto pixelColor = Color(double(j) / (IMAGE_WIDTH - 1), double(i) / (IMAGE_HEIGHT - 1), 0);
            writeColor(std::cout, pixelColor);
        }
    }

    std::clog << "Done";
}