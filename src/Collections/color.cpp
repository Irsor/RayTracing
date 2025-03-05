#include "color.hpp"

void writeColor(std::ostream& out, const Color& pixelColor)
{
    auto r = pixelColor.x();
    auto g = pixelColor.y();
    auto b = pixelColor.z();

    // �������������� �������� ���������� �� ��������� [0,1] � �������� ������ [0,255].
    auto rByte = int(255.999 * r);
    auto gByte = int(255.999 * g);
    auto bByte = int(255.999 * b);

    // ������ ���������� ����� �������.
    out << rByte << ' ' << gByte << ' ' << bByte << std::endl;
}