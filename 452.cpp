#include <iostream>
#include <vector>
#include <string>

// Nepali month names in Unicode
const std::string nepali_months[12] = {
    "वैशाख", "जेठ", "असार", "साउन", "भदौ", "असोज",
    "कार्तिक", "मंसिर", "पौष", "माघ", "फाल्गुन", "चैत्र"
};

std::string toNepaliDigits(int num) {
    std::string s = std::to_string(num);
    for (auto &c : s) {
        c = char(0x0966 + (c - '0')); // Unicode mapping ०–९
    }
    return s;
}

int main() {
    int yearBS = 2082;
    int nepali_month_days[12] = {31,32,32,31,31,30,30,29,30,29,30,30};
    int start_weekday = /* compute weekday of yearBS/1/1 via conversion logic */ 3; // Example: Wednesday

    for(int m = 0; m < 12; ++m) {
        std::cout << "\n" << nepali_months[m] << " " << toNepaliDigits(yearBS) << "\n";
        std::cout << "आइत  सोम  मंगल  बुध  बिही  शुक्रबार  शनिबार\n";

        int day = 1;
        int wd = start_weekday;
        for(int i = 0; i < wd; ++i) std::cout << "     ";
        for(; day <= nepali_month_days[m]; ++day) {
            std::cout << toNepaliDigits(day) << "   ";
            if (++wd > 6) {
                wd = 0;
                std::cout << "\n";
            }
        }
        start_weekday = wd;
    }
    return 0;
}
