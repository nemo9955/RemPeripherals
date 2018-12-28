#ifndef UPDATER_HPP_
#define UPDATER_HPP_

#include <stdint.h>

class Updater
{
  public:
    // Updater();
    // ~Updater();

    virtual void begin() = 0;
    virtual void update() = 0;

  protected:
  private:
};

#endif /* !UPDATER_HPP_ */
