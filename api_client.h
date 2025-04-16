#ifndef API_CLIENT_H
#define API_CLIENT_H

#include <stddef.h>

int fetch_tweets(const char *search_term, char *response, size_t max_size);
void show_tweet_texts(const char *json);

#endif