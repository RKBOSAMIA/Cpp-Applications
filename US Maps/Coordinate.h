#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate
{
    public:
        
        /**
         * Overloaded input stream extraction operator
         * to read a coordinate from an input stream.
         * @param ins the input stream.
         * @param coordinate the coordinate to read.
         * @return the input stream.
         */
        friend istream& operator >>(istream& ins, Coordinate& coordinate);

        //getters for latitude and longitude
        double get_latitude() const;
        double get_longitude() const;

        //setters for latitude and longitude
        double set_latitude(double lat);
        double set_longitude(double lon);
        
        // Constants for this app's input data.
        static const double MAX_LATITUDE;
        static const double MIN_LONGITUDE;

        // destructor

        ~Coordinate();

    private:
        double latitude;
        double longitude;
};

#endif /* COORDINATE_H_ */