#ifndef DASHBOARD_DATA_H
#define DASHBOARD_DATA_H

#include <time.h>

typedef struct {
    time_t timestamp;
    char trending_topic[50];
    char sentiment[20];
    int positive_posts;
    int neutral_posts;
    int negative_posts;
} DashboardData;

void get_dashboard_data(DashboardData *data);

#endif