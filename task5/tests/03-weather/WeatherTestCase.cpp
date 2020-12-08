//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(WeatherTestCase, BadCityTest) {
    try {
        Weather weather;
        weather.SetApiKey("ee2238d904e2ce9d79ee7c4cd739105f");

        float temperature = weather.GetTemperature("Cherepovetssssss");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const &err) {
        EXPECT_EQ(err.what(),std::string("Api error. City is bad"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
};

TEST(WeatherTestCase, AdequateTemperatureTest) {
    Weather weather;
    weather.SetApiKey("ee2238d904e2ce9d79ee7c4cd739105f");

    float temperature = weather.GetTemperature("Moscow");
    ASSERT_TRUE(temperature >= -100.0);
};

TEST(WeatherTestCase, DiffTest) {
    Weather weather;
    weather.SetApiKey("ee2238d904e2ce9d79ee7c4cd739105f");

    std::string diff_1 = weather.GetDifferenceString("Moscow", "London");
    std::string diff_2 = weather.GetDifferenceString("London", "Moscow");

    float diff_f_1 = weather.FindDiffBetweenTwoCities("Moscow", "London");
    float diff_f_2 = weather.FindDiffBetweenTwoCities("London", "Moscow");
    ASSERT_TRUE(diff_f_1 * diff_f_2 <= 0);
};