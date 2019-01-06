#ifndef REMPRINTER_HPP_
#define REMPRINTER_HPP_

#include <Print.h>
#include <stdint.h>
#include "SimpleList.h"

class RemPrinter
{
  public:
    RemPrinter()
    {
        remprintersList.push_back(this);
    };

    virtual void print_info(Print *pr) = 0;
    virtual uint32_t get_peri_uuid() = 0;

    static SimpleList<RemPrinter *> remprintersList;

  protected:
  private:
};

#endif /* !REMPRINTER_HPP_ */
