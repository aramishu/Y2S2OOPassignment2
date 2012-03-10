#ifndef UNIT_AJ_H
#define UNIT_AJ_H

class unit_aj
{
public:
    unit_aj();
    unit_aj(double initialValue);
    double getValue() const;
    void setValue(double newValue);

protected:
    double value;
};

#endif // UNIT_AJ_H
