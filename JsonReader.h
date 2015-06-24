
#ifndef JSON_READER_H
#define JSON_READER_H

#include <json/value.h>
#include <vector>

#include "Response.h"

namespace JsonReader
{
    ///@brief Reads response elements from the json
    bool readResponse(const Json::Value& jsonElements, std::vector<ResponseElement>& fullResponse);
}

#endif
