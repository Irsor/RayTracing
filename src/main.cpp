#include <iostream>

#include "Collections/vec3.hpp"
#include "Collections/color.hpp"

#include "Ray.hpp"

bool hitSphere(const Point3& center, double radius, const Ray& ray)
{
    Vec3 oc = center - ray.getOrigin();
    auto a = dot(ray.getDirection(), ray.getDirection());
    auto b = -2.0 * dot(ray.getDirection(), oc);
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant >= 0);
}

Color rayColor(const Ray& ray)
{
    if (hitSphere(Point3(0, 0, -1), 0.5, ray))
    {
        return Color(1, 0, 0);
    }

    Vec3 unitDirecton = unitVector(ray.getDirection());
    auto a = 0.5 * (unitDirecton.y() + 1.0);
    return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}

int main()
{
    // Изображение
    auto aspectRatio = 16.0 / 9.0;
    int imageWidth = 400;

    // Вычисление высоты изображения и убеждение что оно хотя бы равно 1.
    int imageHeight = int(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

    // Камера
    auto focalLength = 1.0;
    auto viewportHeight = 2.0; 
    auto viewportWidth = viewportHeight * (double(imageWidth) / imageHeight);
    auto cameraCenter = Point3(0, 0, 0);

    // Расчет граней области просмотра (правый верхний угол и левый нижний).
    auto viewportU = Vec3(viewportWidth, 0, 0);
    auto viewportV = Vec3(0, -viewportHeight, 0);

    // Расчет горизонтальный и вертикальный дельты от пикселя к пикселю.
    auto pixelDeltaU = viewportU / imageWidth;
    auto pixelDeltaV = viewportV / imageHeight;

    // Вычисление расположения левого верхнего пикселя.
    auto viewportUpperLeft = cameraCenter - Vec3(0, 0, focalLength) - viewportU / 2 - viewportV / 2;
    auto pixel00Location = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

    // Рендер
    std::cout << "P3" << std::endl << imageWidth << ' ' << imageHeight << std::endl << "255" << std::endl;

    for (int i = 0; i < imageHeight; i++)
    {
        std::clog << "Scanlines remaining: " << (imageHeight - i) << ' ' << std::endl;
        for (int j = 0; j < imageWidth; j++)
        {
            auto pixelCenter = pixel00Location + (i * pixelDeltaV) + (j * pixelDeltaU);
            auto rayDirection = pixelCenter - cameraCenter;
            Ray r(cameraCenter, rayDirection);

            Color pixelColor = rayColor(r);
            writeColor(std::cout, pixelColor);
        }
    }

    std::clog << "Done";
}