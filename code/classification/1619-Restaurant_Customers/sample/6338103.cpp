#define _CRT_SECURE_NO_WARNINGS
 
#include <cstdio>
#include <set>
 
using namespace std;
 
int main()
{
    unsigned nrCustomers;
 
    scanf("%u", &nrCustomers);
 
    set<unsigned> arrivals;
    set<unsigned> departures;
 
    for (unsigned c = 0; c < nrCustomers; ++c)
    {
        unsigned arrival;
        unsigned departure;
 
        scanf("%u %u", &arrival, &departure);
 
        arrivals.insert(arrival);
        departures.insert(departure);
    }
 
    unsigned nrPeople = 0;
    unsigned nrPeopleMax = 0;
 
    while (!arrivals.empty())
    {
        if (*arrivals.begin() < *departures.begin())
        {
            ++nrPeople;
            nrPeopleMax = max(nrPeopleMax, nrPeople);
            arrivals.erase(arrivals.begin());
        }
        else
        {
            --nrPeople;
            departures.erase(departures.begin());
        }
    }
 
    printf("%u\n", nrPeopleMax);
 
    return 0;
}
