#include <vmix/taskio/detail/sqlite_task_storage.hpp>

namespace vmix::taskio::detail {

sqlite_task_storage::sqlite_task_storage()
    : db_(VMIX_TASKIO_DETAIL_SQLITE_DB_SCHEMA) {
  db_.sync_schema();
}

sqlite_task_storage::~sqlite_task_storage() = default;

dtask_ptr sqlite_task_storage::create() {
  auto task = std::make_unique<dtask>();

  task->id = db_.insert(*task);

  return task;
};

void sqlite_task_storage::update(const dtask_ptr& task) {
  db_.update(*task);
};

void sqlite_task_storage::remove(int id) {
  db_.remove<dtask>(id);
};

dtask_ptr sqlite_task_storage::find(int id) {
  if (auto task = db_.get_pointer<dtask>(id)) {
    return task;
  }

  throw std::logic_error("task not found");
};

std::vector<dtask_ptr> sqlite_task_storage::all() {
  auto ids = db_.select(&dtask::id);
  std::vector<dtask_ptr> tasks;
  tasks.reserve(ids.size());

  for (auto&& t : db_.iterate<dtask>()) {
    tasks.emplace_back(std::make_unique<dtask>(t));
  }

  return tasks;
};

}  // namespace vmix::taskio::detail
