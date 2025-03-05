#ifndef COLOR_HPP
#define COLOR_HPP

#include "vec3.hpp"

#include <iostream>

using Color = Vec3;

void writeColor(std::ostream& out, const Color& pixelColor);

#endif // COLOR_HPP