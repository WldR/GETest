#include "JsonReader.h"

namespace JsonReader
{

bool readGPSLocation(const Json::Value& jsonGPS, GPSCoordinate& gpsLocation)
{
    if (jsonGPS.isNull())
    {
        printf("\MIssing GPS location!\n");
        return false;
    }

    const Json::Value& jsonLatitude(jsonGPS["latitude"]);
    const Json::Value& jsonLongitude(jsonGPS["longitude"]);
    if (!jsonLatitude.isDouble() || !jsonLongitude.isDouble())
    {
        printf("\nInvalid GPS location!\n");
        return false;
    }

    gpsLocation.latitude = jsonLatitude.asFloat();
    gpsLocation.longitude = jsonLongitude.asFloat();
    return true;
}

bool readResponse(const Json::Value& jsonElements, std::vector<ResponseElement>& fullResponse)
{
    if(!jsonElements.isArray() || jsonElements.size()==0)
    {
        printf("Invalid json response\n");
        return false;
    }

    const Json::ArrayIndex nbElements = jsonElements.size();

    ResponseElement resp;
    fullResponse.reserve(nbElements);

    for (Json::ArrayIndex i = 0; i < nbElements; ++i)
    {
        const Json::Value& oneElement(jsonElements[i]);

        if (!readGPSLocation(oneElement["geo_position"],resp.geo_position))
            return false;

        const Json::Value& idJson(oneElement["_id"]);
        const Json::Value& nameJson(oneElement["name"]);
        const Json::Value& typeJson(oneElement["type"]);

        if (!idJson.isIntegral() || !nameJson.isString() || !typeJson.isString())
        {
            printf("invalid response");
            return false;
        }

        resp._id = idJson.asInt64();
        resp.name = nameJson.asString();
        resp.type = typeJson.asString();

        fullResponse.push_back(resp);
    }
    return true;
}


}
