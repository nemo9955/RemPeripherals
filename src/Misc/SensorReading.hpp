#ifndef SENSORREADING_HPP_
#define SENSORREADING_HPP_

#include <Print.h>

enum class ReadingType
{
    _int,
    _float
};

union ReadingValue {
    int _int;
    float _float;
};

class SensorReading
{
  public:
    SensorReading(char *_reading_name);
    ~SensorReading();

    void set_int_value(int);
    void set_float_value(float);

    void print_name(Print *pr);
    void print_value(Print *pr);

    void operator=(int _int) { set_int_value(_int); }
    void operator=(float _float) { set_float_value(_float); }

  private:
    char *reading_name;
    ReadingType reading_type;
    ReadingValue reading_value;

  protected:
};

#endif /* !SENSORREADING_HPP_ */
