/*
 *  NUMBER CONVERTER - DECIMAL TO BINARY/BINARY TO DECIMAL - ACCURACY TO HUNDREDTHS
 *  binary.cpp - class file defining Binary methods
 *  Composed by Marcin Pajak - 2020
 *  Copyright 2020 AGH University of Science and Technology. All rights reserved.
 *  DON'T REMOVE THIS PART (PLEASE INCLUDE YOUR NAME BELOW IF YOU MODIFY SOMETHING)
 */

#include "binary.h"

namespace Data {
    // function translating decimal values to binary strings with precision to a second decimal place
    void Binary::to_binary() {
        int i;
        double val_round = decimal_ * 100;                                                                              // rounding the value to the second decimal place
        val_round = round(val_round) / 100;
        int val = static_cast<int>(val_round);
        int val_frac = static_cast<int>((val_round - val) * 100);
        if (val_frac < 0) { val_frac = -val_frac; }

        if (signbit(val_round)) {                                                                                       // saving information about the value's sign
            sign_ = '0';
            val = -val;
        } else {
            sign_ = '1';
        }

        for (i = 0; val > 0; i++) {
            bin_.append(std::to_string(val % 2));
            val = val / 2;
        }
        reverse(bin_.begin(), bin_.end());

        if (bin_.empty()) {
            bin_ = '0';
        }

        for (i = 0; val_frac > 0; i++) {
            bin_frac_.append(std::to_string(val_frac % 2));
            val_frac = val_frac / 2;
        }
        int f_size = bin_frac_.size();
        if (f_size < 7) {
            for (i = 0; i < (7 - f_size); i++) {
                bin_frac_.append("0");
            }
        }
        reverse(bin_frac_.begin(), bin_frac_.end());

        if (bin_frac_.empty()) {
            bin_frac_ = '0';
        }
    }

    // function translating decimal values to binary strings of specified length with precision to a second decimal place
    void Binary::to_binary(const int& L) {
        this->to_binary();
        int i;
        int length = bin_.size();

        // adding additional zeros at the beginning of the binary string, to match the given string length
        std::string zeros;
        if (length < L) {
            for (i = 0; i < L - length; i++) {
                zeros.append("0");
            }
            bin_.insert(0, zeros);
        }
    }

    // function translating binary strings to decimal values
    void Binary::to_decimal() {
        int i;
        std::string bin_int, bin_frac;
        bin_int = bin_;
        bin_frac = bin_frac_;

        reverse(bin_int.begin(), bin_int.end());
        reverse(bin_frac.begin(), bin_frac.end());

        int bit;
        double dec = 0;
        i = 0;
        for (auto &X : bin_int) {
            if (X == '1'){
                bit = 1;
            } else {
                bit = 0;
            }
            dec += bit * std::pow(2, i);
            i++;
        }

        double frac = 0;
        i = 0;
        for (auto &X : bin_frac) {
            if (X == '1') {
                bit = 1;
            } else {
                bit = 0;
            }
            frac += bit * std::pow(2, i);
            i++;
        }
        frac = frac / 100;

        if (sign_[0] == '1') {
            decimal_ = dec + frac;
        } else {
            decimal_ = -(dec + frac);
        }
    }
}

