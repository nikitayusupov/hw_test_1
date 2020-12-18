//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

cpr::Response make_fake_response(const std::string& temp, std::int32_t status_code) {
    cpr::Response response;
    response.status_code = status_code;
    response.text = R"({"list" : [{"main": {"temp": )" + temp + R"(}}]})";
    return response;
}

TEST(WeatherTestCase, BadCityTest) {
   WeatherMock weatherMock;
   cpr::Response response = make_fake_response("228", 404);

   EXPECT_CALL(weatherMock, Get("Cherepovetssssss")).WillOnce(testing::Return(response));
   ASSERT_THROW(weatherMock.GetTemperature("Cherepovetssssss"), std::invalid_argument);
};

TEST(WeatherTestCase, AdequateTemperatureTest) {
    WeatherMock weatherMock;
    cpr::Response response = make_fake_response("28", 200);

    EXPECT_CALL(weatherMock, Get("Moscow")).WillOnce(testing::Return(response));
    ASSERT_EQ(28, weatherMock.GetTemperature("Moscow"));
};

TEST(WeatherTestCase, DiffTest) {
    WeatherMock weatherMock;

    cpr::Response responseMoscow = make_fake_response("28", 200);
    cpr::Response responseDubai = make_fake_response("58", 200);

    EXPECT_CALL(weatherMock, Get("Moscow")).WillRepeatedly(testing::Return(responseMoscow));
    EXPECT_CALL(weatherMock, Get("Dubai")).WillRepeatedly(testing::Return(responseDubai));

    ASSERT_EQ(30, weatherMock.FindDiffBetweenTwoCities("Dubai", "Moscow"));

    std::string diffString = weatherMock.GetDifferenceString("Dubai", "Moscow");
    ASSERT_EQ("Weather in Dubai is warmer than in Moscow by 30 degrees", diffString);

    diffString = weatherMock.GetDifferenceString("Moscow", "Dubai");
    ASSERT_EQ("Weather in Moscow is colder than in Dubai by 30 degrees", diffString);
};

TEST(WeatherTestCase, SetApiKeyTest) {
    WeatherMock weatherMock;
    ASSERT_NO_THROW(weatherMock.SetApiKey("bruh"));
};
