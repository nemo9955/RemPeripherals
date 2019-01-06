#ifndef PERIMANAGER_HPP_
#define PERIMANAGER_HPP_

#include <Print.h>

class PeriManager
{
  public:
    PeriManager();
    ~PeriManager();

    void begin();
    void update();

    void print_info(Print *pr);

  protected:
  private:
};

#endif /* !PERIMANAGER_HPP_ */
