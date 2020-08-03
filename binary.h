/*
 *  NUMBER CONVERTER - DECIMAL TO BINARY/BINARY TO DECIMAL - ACCURACY TO HUNDREDTHS
 *  binary.h - class file defining Binary objects
 *  Composed by Marcin Pajak - 2020
 *  Copyright 2020 AGH University of Science and Technology. All rights reserved.
 *  DON'T REMOVE THIS PART (PLEASE INCLUDE YOUR NAME BELOW IF YOU MODIFY SOMETHING)
 *
 *  The class produces objects containing binary and decimal representations of a value. The decimal values are stored
 *  with precision to the second decimal place. The binary representation is divided into integer and fractional parts.
 *  The integer part can take various lengths, while the fractional part is fixed to 7 signs. All of binary strings
 *  uploaded to the code need to be prepared in that manner for the code to work.
 *
 *  First bit of the binary string is reserved for the value's sign, following bits for the integer part and last seven
 *  bits are reserved for the fractional part.
 */

#ifndef DATA_BINARY_H
#define DATA_BINARY_H

#include <cmath>
#include <vector>
#include <string>
#include <iostream>

namespace Data {
    class Binary {
    public:
        Binary() = default;

        /* Constructor with a decimal value provided  - translates the value to a binary string immediately */
        Binary(const double& decimal) {
            decimal_ = decimal;
            this->to_binary();
        }

        /* Constructor with a decimal value provided and target binary string's length specified - translates the value
         * to a binary string immediately */
        Binary(const double& decimal, const int& L) {
            decimal_ = decimal;
            this->to_binary(L);
        }

        /* Constructor with a binary string provided - translates the string to a decimal value immediately
        * requires providing a string formatted in a specific manner - first sign represents the value's sign
        * and is followed by signs representing the integer part, while the last seven signs represent the
        * fractional part. If a number has no fractional part, it will be filled with zeros. */
        Binary(const std::string &binary) {

            int size = binary.size();

            sign_.assign(binary.begin(), binary.begin() + 1);
            bin_.assign(binary.begin() + 1, binary.begin() + (size - 7));
            bin_frac_.assign(binary.begin() + (size - 7), binary.end());

            this->to_decimal();
        }

        void to_binary();

        void to_binary(const int&);

        void to_decimal();


        double getDec() const {
            return decimal_;
        }

        // returns an integer part of the binary representation only
        std::string getBin() const {
            return bin_;
        }

        // returns the binary representation with the fractional part and sign bit
        std::string getBin_Full() const {
            return sign_ + bin_ + bin_frac_;
        }

        // returns length of the binary string's integer part
        int getL() const {
            return bin_.size();
        }

    private:
        double decimal_;                                                                                                // decimal representation of the value
        std::string sign_;                                                                                              // string holding information about the value's sign
        std::string bin_;                                                                                               // string holding the binary representation of the value's integer part
        std::string bin_frac_;                                                                                          // string holding the binary representation of the value's fractional part
    };
}
#endif //DATA_BINARY_H
