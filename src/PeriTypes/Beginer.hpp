#ifndef BEGINER_HPP_
#define BEGINER_HPP_

#include <stdint.h>
#include "SimpleList.h"

class Beginer
{
  public:
    Beginer()
    {
        beginersList.push_back(this);
    };

    virtual void begin() = 0;

    static SimpleList<Beginer *> beginersList;

  protected:
  private:
};

#endif /* !BEGINER_HPP_ */
