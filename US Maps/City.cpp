#include "City.h"

string City:: get_state()
{
    return state;
}
string City:: get_name()
{
    return name;
}
Coordinate City:: get_coordinate()
{
    return coordinate;
}
istream& operator >>(istream& ins, City& city)
{
    string name,state,lat,lon;
    getline(ins,name,',');
    getline(ins,state,',');
    getline(ins,lat,',');
    getline(ins,lon,'\n');
    city.name = name;
    city.state = state;
    city.coordinate.set_latitude(stod(lat));
    city.coordinate.set_longitude(stod(lon));
    return ins;
}


City :: ~City()
{

}