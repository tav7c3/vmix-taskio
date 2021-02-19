#include <vmix/taskio/detail/in_memory_task_storage.hpp>

#include <stdexcept>

namespace vmix::taskio::detail {

auto find_iterator(const std::vector<task>& tasks, int id) {
  auto it = std::find_if(tasks.begin(), tasks.end(),
                         [id](const auto& t) { return id == t.id; });
  if (it == tasks.end()) {
    throw std::runtime_error("task not exists");
  }

  return it;
};

auto find_index(const std::vector<task>& tasks, int id) {
  return std::distance(tasks.begin(), find_iterator(tasks, id));
};

dtask_ptr in_memory_task_storage::create() {
  auto task = std::make_unique<dtask>();
  task->id = next_id_;

  // безопасно, т.к. все конструкторы detail::task noexcept
  tasks_.push_back(*task);

  ++next_id_;

  return task;
};

void in_memory_task_storage::update(const dtask_ptr& task) {
  tasks_[find_index(tasks_, task->id)] = *task;
};

void in_memory_task_storage::remove(int id) {
  tasks_.erase(find_iterator(tasks_, id));
};

dtask_ptr in_memory_task_storage::find(int id) {
  return std::make_unique<dtask>(tasks_[find_index(tasks_, id)]);
};

std::vector<dtask_ptr> in_memory_task_storage::all() {
  std::vector<dtask_ptr> tasks;
  tasks.reserve(tasks_.size());
  for (const auto& t : tasks_) {
    tasks.emplace_back(std::make_unique<dtask>(t));
  };
  return tasks;
};

}  // namespace vmix::taskio::detail
