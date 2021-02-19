#ifndef VMIX_TASKIO_DETAIL_IN_MEMORY_TASK_STORAGE_HPP
#define VMIX_TASKIO_DETAIL_IN_MEMORY_TASK_STORAGE_HPP

#include <vmix/taskio/detail/task.hpp>
#include <vmix/taskio/task_storage.hpp>

namespace vmix::taskio::detail {

using dtask = task;
using dtask_ptr = std::unique_ptr<dtask>;

class in_memory_task_storage : public task_storage {
 public:
  virtual dtask_ptr create() override;
  virtual void update(const dtask_ptr&) override;
  virtual void remove(int) override;
  virtual dtask_ptr find(int) override;
  virtual std::vector<dtask_ptr> all() override;

 private:
  int next_id_{0};
  std::vector<dtask> tasks_;
};

}  // namespace vmix::taskio::detail

#endif  // VMIX_TASKIO_DETAIL_IN_MEMORY_TASK_STORAGE_HPP
