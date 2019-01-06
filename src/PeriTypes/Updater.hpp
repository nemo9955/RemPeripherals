#ifndef UPDATER_HPP_
#define UPDATER_HPP_

#include <stdint.h>
#include "SimpleList.h"

class Updater
{
  public:
    Updater()
    {
        updatersList.push_back(this);
    };

    virtual void update() = 0;

    static SimpleList<Updater *> updatersList;

  protected:
  private:
};

#endif /* !UPDATER_HPP_ */
