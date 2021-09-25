/**
 * @file utils.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief Utilities file. Static functions go here.
 * @version 0.1
 * @date 16-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdint.h>

/**
 * @brief Class that contains only static functions to perform several operations
 * 
 */
class Utils
{
    public:
    /**
     * @brief Converts a 24 bit RGB color to a 5-6-5 16bit color.
     * Conversion formula from: http://www.barth-dev.de/online/rgb565-color-picker/
     * 
     * @param rgbColor a 24 bit RGB color. The 8 most sigificant bits of the input parameter are ignored.
     * @return uint16_t a 16bit color in the 5-6-5 format.
     */
    inline static uint16_t RGBto565(uint32_t rgbColor)
    {
        return (((rgbColor & 0xf80000) >> 8) + ((rgbColor & 0xfc00) >> 5) + ((rgbColor & 0xf8) >> 3));
    }
};
