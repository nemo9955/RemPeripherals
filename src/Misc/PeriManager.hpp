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

    void print_info_all(Print *pr);
    void print_info_uuid(uint32_t per_uuid, Print *pr);

  protected:
  private:
};

#endif /* !PERIMANAGER_HPP_ */
