#include "unit_aj.h"

unit_aj::unit_aj()
{
    //this->value = 0;
    this->setValue(0.0f);
}

unit_aj::unit_aj(double initialValue)
{
    this->setValue(initialValue);
}

double unit_aj::getValue() const
{
    return this->value;
}

void unit_aj::setValue(double newValue)
{
    this->value = newValue;
}
