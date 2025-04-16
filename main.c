#include "api_client.h"
#include <stdio.h>
#include <string.h>

#define RESPONSE_SIZE 5000

int main() {
    char search_term[100];
    char response[RESPONSE_SIZE] = {0};

    printf("Twitter Tweet Fetcher\n");
    printf("Enter a search term: ");
    
    fgets(search_term, sizeof(search_term), stdin);
    search_term[strcspn(search_term, "\n")] = '\0';

    if(strlen(search_term) == 0) {
        printf("Error: Please enter a search term\n");
        return 1;
    }

    printf("\nFetching tweets about: %s\n", search_term);
    
    if(fetch_tweets(search_term, response, RESPONSE_SIZE) == 0) {
        show_tweet_texts(response);
    } else {
        printf("Error fetching tweets\n");
    }

    return 0;
}