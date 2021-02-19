#ifndef VMIX_TASKIO_DETAIL_TASK_HPP
#define VMIX_TASKIO_DETAIL_TASK_HPP

#include <string>

namespace vmix::taskio::detail {

class task {
 public:
  int id;
  std::string title;
  std::string description;
  std::string time;
  bool completed;
};

}  // namespace vmix::taskio::detail

#endif  // VMIX_TASKIO_DETAIL_TASK_HPP
