#ifndef TaskLooperLite_HPP_
#define TaskLooperLite_HPP_

#include <stdint.h>

class TaskLooperLite
{
  public:
    TaskLooperLite();
    ~TaskLooperLite();

    void begin();
    void set(uint16_t milis);
    void set_slow();
    void set_norm();
    void set_fast();
    bool check();
    void start();
    void stop();
    void now();

  protected:
  private:
    uint32_t next_ts;
    uint16_t tl_interval;
};

#endif /* !TaskLooperLite_HPP_ */
