#include "api_client.h"
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define BEARER_TOKEN "AAAAAAAAAAAAAAAAAAAAAJ%2Ff0QEAAAAAUJXIfARrNeOzHgubkxrbZH3sBqE%3DezWgYu7GPdJqPWUb1WE9TCNSKMA4gsAdWvYq4YlK7tA15Go97R"
#define API_URL "https://api.twitter.com/2/tweets/search/recent?query="

size_t write_callback(void *data, size_t size, size_t nmemb, char *output) {
    size_t total = size * nmemb;
    strncat(output, data, total);
    return total;
}

int fetch_tweets(const char *search, char *response, size_t max_size) {
    CURL *curl = curl_easy_init();
    if(!curl) {
        printf("Error: Could not initialize cURL\n");
        return 1;
    }

    char url[256];
    snprintf(url, sizeof(url), "%s%s&max_results=10", API_URL, search);

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Authorization: Bearer " BEARER_TOKEN);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
        printf("cURL error: %s\n", curl_easy_strerror(res));
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    
    return res != CURLE_OK;
}

void show_tweet_texts(const char *json) {
    const char *ptr = json;
    int tweet_count = 0;
    
    while((ptr = strstr(ptr, "\"text\":")) != NULL) {
        ptr += 7;
        if(*ptr == '"') ptr++;
        
        const char *end = strchr(ptr, '"');
        if(!end) break;
        
        printf("Tweet %d: %.*s\n", ++tweet_count, (int)(end-ptr), ptr);
        ptr = end + 1;
    }
    
    if(tweet_count == 0) {
        printf("No tweets found in response\n");
    }
}