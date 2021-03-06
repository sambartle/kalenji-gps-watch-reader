#ifndef _UTILS_H
#define _UTILS_H

#include <string>
#include <list>
#include <stdexcept>
#include <sstream>
#include <tr1/memory>
#include <stdint.h>

#ifdef WINDOWS
#include <ctime>
#include <cstring>

struct tm * localtime_r (const time_t *timer, struct tm *result);
struct tm * gmtime_r (const time_t *timer, struct tm *result);
#endif

class Point;

#define THROW_STREAM(stream) throw std::runtime_error(Formatter() << stream);

class Formatter
{
    public:
        Formatter() = default;
        ~Formatter() = default;
        Formatter(const Formatter &) = delete;
        Formatter & operator= (Formatter &) = delete;

        template <typename Type>
        Formatter & operator<< (const Type & value)
        {
            _stream << value;
            return *this;
        }

        std::string str() const;
        operator std::string() const;

    private:
        std::stringstream _stream;
};

int testDir(std::string path, bool create_if_not_exist);

void trimString(std::string &toTrim);
std::string durationAsString(double sec, bool with_millis = false);
std::list<std::string> splitString(std::string toSplit, std::string separator = ",");

uint32_t str_to_int(std::string intAsString);

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
double distanceEarth(const Point& p1, const Point& p2);

#endif
