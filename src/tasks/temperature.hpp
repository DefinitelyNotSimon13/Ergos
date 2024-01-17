namespace myTemperature {
class Temperature {
 public:
  Temperature(bool run);
  int run();

 private:
  static float convertToFahrenheit(float celsius);
  static float convertToCelsius(float fahrenheit);
  static inline int offset = 32;
  static inline float factor = 1.8;
};
}  // namespace myTemperature
