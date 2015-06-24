#include "OnlineUtils.h"

#include <json/reader.h>
#include <curl/curl.h>

namespace OnlineUtils
{

static size_t write_data(void *ptr, size_t size, size_t nmemb, std::string *stream)
{
    stream->append((char*)ptr,size*nmemb);
    return size*nmemb;
}

int getBody(const std::string &request, std::string &response)
{
  CURL *curl_handle;

  curl_global_init(CURL_GLOBAL_ALL);

  /* init the curl session */
  curl_handle = curl_easy_init();

  /* set URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_URL, request.c_str());

  /* no progress meter please */
  curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

  /* we want the body be written to this file handle instead of stdout */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &response);

  /* get it! */
  curl_easy_perform(curl_handle);

  /* cleanup curl stuff */
  curl_easy_cleanup(curl_handle);

  return 0;
}

bool getJsonResponse(const std::string &request, Json::Value& jsonResponse)
{
    std::string strResponse;
    getBody(request, strResponse);

//Test the answer:
//    printf("Response size: %d \n\n%s\n\n", strResponse.size(), strResponse.c_str());

//Test parsing and later printing:
//    strResponse.assign("[{\"_id\": 410978,\"name\": \"Potsdam\", \"fullName\": \"Potsdam, USA\", \"type\": \"location\",\"country\": \"USA\", \"geo_position\": {\"latitude\": 44.66978,\"longitude\": -74.98131 },\"location_id\": 410978, \"countryCode\": \"US\"},{\"_id\": 410978,\"name\": \"Potsdam\", \"fullName\": \"Potsdam, USA\", \"type\": \"location\",\"country\": \"USA\", \"geo_position\": {\"latitude\": 44.66978,\"longitude\": -74.98131 },\"location_id\": 410978, \"countryCode\": \"US\"},{\"_id\": 410978,\"name\": \"Potsdam\", \"fullName\": \"Potsdam, USA\", \"type\": \"location\",\"country\": \"USA\", \"geo_position\": {\"latitude\": 44.66978,\"longitude\": -74.98131 },\"location_id\": 410978, \"countryCode\": \"US\"}]\n");

    jsonResponse.clear();
    Json::Reader jsonReader;

    if(!jsonReader.parse(strResponse.c_str(), strResponse.c_str()+strResponse.size(), jsonResponse, false))
    {
        printf("\nCould not parse the json answer.\n");
        return false;
    }

    return true;
}

}
