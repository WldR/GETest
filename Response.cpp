#include "Response.h"

#include <stdio.h>
#include <sstream>

bool writeToFile(const std::vector<ResponseElement>& fullResponse, const std::string& fullPath)
{
    FILE *ft = fopen(fullPath.c_str(), "w");

    if(!ft)
    {
        printf("Could not create file %s",fullPath.c_str());
        return false;
    }

    const size_t nbElem = fullResponse.size();

    for(size_t i=0; i<nbElem; ++i)
    {
        std::ostringstream line;
        const ResponseElement& currResp=fullResponse[i];
        line << currResp._id  << ", "
             << currResp.name << ", "
             << currResp.type << ", "
             << currResp.geo_position.latitude  << ", "
             << currResp.geo_position.longitude << "\n";

        fputs(line.str().c_str(), ft);
    }

    fclose(ft);
    return true;
}

