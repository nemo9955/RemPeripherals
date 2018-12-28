#ifndef REMPRINTER_HPP_
#define REMPRINTER_HPP_

#include <Print.h>
#include <stdint.h>

class RemPrinter
{
  public:
    // RemPrinter();
    // ~RemPrinter();


    virtual void print_info(Print * pr) = 0;

  protected:
  private:
};

#endif /* !REMPRINTER_HPP_ */
