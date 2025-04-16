#include "dashboard_data.h"
#include <time.h>
#include <string.h>

void get_dashboard_data(DashboardData *data) {
    // Simple static data for demonstration
    time(&data->timestamp);
    strcpy(data->trending_topic, "Programming");
    strcpy(data->sentiment, "Positive");
    
    data->positive_posts = 42;
    data->neutral_posts = 15;
    data->negative_posts = 3;
}