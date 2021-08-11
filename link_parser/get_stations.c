#include "get_stations.h"

station get_station() {
    return stations[current_station++];
}
