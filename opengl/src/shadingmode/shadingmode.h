#ifndef SHADINGMODE_H
#define SHADINGMODE_H

/**
 * @brief Shading mode that specifies the different available shading modes:
 * Phong, Normal and Gouraud shading.
 */
enum ShadingMode
{
    PHONG = 0,
    NORMAL = 1,
    GOURAUD = 2,
    CELL = 3
};

#endif  // SHADINGMODE_H
