#ifndef DISTANCE_AJ_H
#define DISTANCE_AJ_H

class distance_aj
{
public:
    distance_aj();
    distance_aj(double initialVaule);
    distance_aj(double initialValue, char *unit);
    double getDistance(char *unit) const;
    double getDistance() const;
    void setDistance(double newValue, char *unit);
    void setDistance(double newValue);
    bool operator == (const distance_aj& ) const;
    bool operator != (const distance_aj& ) const;
    distance_aj& operator+=(const distance_aj &v);
    distance_aj& operator-=(const distance_aj &v);

    distance_aj operator+(const distance_aj& v) const;
    distance_aj operator-(const distance_aj& v) const;
    distance_aj operator*(const distance_aj& v) const;
    distance_aj operator/(const distance_aj& v) const;

private:
    double distance;
    double getDistanceAsKm() const;
    double getDistanceAsMiles() const;
    void setDistanceAskm(double newVaulue);
    void setDistanceAsMiles(double newValue);
};

#endif // DISTANCE_AJ_H
