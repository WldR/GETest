#include "OnlineUtils.h"
#include "JsonReader.h"
#include "Response.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    std::string ReqString;
    if (2 <= argc)
        ReqString.assign(argv[1]);
    else
    {
        printf("\n"
               "Missing parameters:\n"
               "  - request parameters"
               "  - optional: csv file (path and) name");
        return 1;
    }

    std::string fullReq = "http://api.goeuro.com/api/v2/position/suggest/en/" + ReqString;

    Json::Value jsonResponse;
    if (!OnlineUtils::getJsonResponse(fullReq,jsonResponse))
        return false;

    std::vector<ResponseElement> elements;
    JsonReader::readResponse(jsonResponse,elements);

    writeToFile(elements, argc >=3 ? argv[2] :"GE_csv.txt");

    return 0;
}
