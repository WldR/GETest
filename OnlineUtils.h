#ifndef ONLINE_UTILS_H
#define ONLINE_UTILS_H

#include <string>

#include <json/value.h>

namespace OnlineUtils
{
    ///@brief Gets the Json response from server
    bool getJsonResponse(const std::string &request, Json::Value& jsonResponse);
}

#endif
