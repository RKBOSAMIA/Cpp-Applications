#include "Coordinate.h"
#include<fstream>
#include<string>

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;


double Coordinate :: get_latitude() const
{
    return this->latitude;
}
double Coordinate :: get_longitude() const
{
    return this->longitude;
}
double Coordinate :: set_latitude(double lat)
{
    this->latitude = lat;
}
double Coordinate :: set_longitude(double lon)
{
    this->longitude = lon;
}
istream& operator >>(istream& ins, Coordinate& coordinate)
{
    string lat,lon;
    getline(ins,lat,',');
    getline(ins,lon,'\r');
    coordinate.latitude = stod(lat);
    coordinate.longitude = stod(lon);
    return ins;
}

Coordinate :: ~Coordinate()
{
    
}