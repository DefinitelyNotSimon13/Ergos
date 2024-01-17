#pragma once

namespace myTasks{
class Temperature {
 public:
  Temperature(bool run);
  static int run();

 private:
  static float convertToFahrenheit(float celsius);
  static float convertToCelsius(float fahrenheit);
  static inline int offset = 32;
  static inline float factor = 1.8;
};
}  // namespace myTasks
