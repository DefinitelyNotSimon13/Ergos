#pragma once

#include <cstdint>

namespace myTasks {
    class Temperature {
    public:
        explicit Temperature(bool run);

        static int16_t run();

    private:
        static float convertToFahrenheit(float celsius);

        static float convertToCelsius(float fahrenheit);

        static inline int offset = 32;
        static inline float factor = 1.8;
    };
}  // namespace myTasks
