namespace myLibs {
    /**
     * @class Utils
     * @brief A utility class that provides input functions for various types of data.
     */
    class Utils {
    public:
        /**
         * @class Utils
         * @brief A utility class that provides input functions for various types of data.
         *
         * This class provides functions for inputting integers, floats, and yes/no
         * answers from the user.
         */
        Utils() = default;

        /**
         * @brief Input an integer from the user.
         *
         * This function prompts the user to input an integer and returns the input as an integer value.
         * If the user enters an invalid input, such as a non-integer value, the function will continue to prompt for a valid input until it is received.
         *
         * @return The integer inputted by the user.
         *
         * @warning If there is an error in the input process, such as an invalid input or failure to read input, the function will output an error message and terminate the program.
         */
        static int inputInt();

        /**
         * @brief Input a floating-point number from the user.
         *
         * This function prompts the user to input a floating-point number and returns the input as a float value.
         * If the user enters an invalid input, such as a non-number value, the function will continue to prompt for a valid input until it is received.
         *
         * @return The floating-point number inputted by the user.
         *
         * @warning If there is an error in the input process, such as an invalid input or failure to read input, the function will output an error message and terminate the program.
         */
        static float inputFloat();

        /**
         * @brief Input a yes or no answer from the user.
         *
         * This static function prompts the user to input a yes or no answer ('y' or 'n') and returns
         * true if the user inputs 'y' and false if the user inputs 'n'. If the user enters an invalid input,
         * such as a string with more than one character or a character other than 'y' or 'n', the function will
         * continue to prompt for a valid input until it is received.
         *
         * @return The boolean value corresponding to the user's input. True if the user inputs 'y' and false if the user inputs 'n'.
         *
         * @note This function does not take any parameters.
         *
         * @warning If there is an error in the input process, such as failure to read input, the function will output an error message and terminate the program.
         */
        static bool inputYN();
    };
}  // namespace myLibs
