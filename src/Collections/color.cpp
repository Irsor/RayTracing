#include "color.hpp"

void writeColor(std::ostream& out, const Color& pixelColor)
{
    auto r = pixelColor.x();
    auto g = pixelColor.y();
    auto b = pixelColor.z();

    // Преобразование значения компонента из диапазона [0,1] в диапазон байтов [0,255].
    auto rByte = int(255.999 * r);
    auto gByte = int(255.999 * g);
    auto bByte = int(255.999 * b);

    // Запись компонента цвета пикселя.
    out << rByte << ' ' << gByte << ' ' << bByte << std::endl;
}