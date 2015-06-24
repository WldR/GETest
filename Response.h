#ifndef GE_RESPONSE_H
#define GE_RESPONSE_H
#include <string>
#include <vector>

struct GPSCoordinate
{
    float latitude;
    float longitude;

    GPSCoordinate(): latitude(0.0f), longitude(0.0f) {}
};

struct ResponseElement
{
    long _id;
    long location_id;

    // key
    std::string name;
    std::string fullName;
    std::string iata_airport_code;
    std::string type;
    std::string country;
    std::string countryCode;

    GPSCoordinate geo_position;

    bool inEurope;
    bool coreCountry;
    int  distance;

    ResponseElement()
    :_id(0)
    ,location_id(0)
    ,name()
    ,fullName()
    ,iata_airport_code()
    ,type()
    ,country()
    ,countryCode()
    ,geo_position()
    ,inEurope(true)
    ,coreCountry(false)
    ,distance(0)
    {}

};

///@Writes the response in a CSV file. The initial content of the file is lost.s
bool writeToFile(const std::vector<ResponseElement>& fullResponse, const std::string& fullPath);

#endif
