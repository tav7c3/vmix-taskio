#ifndef VMIX_TASKIO_DETAIL_SQLITE_TASK_STORAGE_HPP
#define VMIX_TASKIO_DETAIL_SQLITE_TASK_STORAGE_HPP

#include <vmix/taskio/detail/task.hpp>
#include <vmix/taskio/task_storage.hpp>

//#note Alternative operator representations
#define and &&
#include <sqlite_orm/sqlite_orm.h>

namespace vmix::taskio::detail {

using dtask = task;
using dtask_ptr = std::unique_ptr<dtask>;

// Не самый удачный вариант выбора sqlite_orm
// Переделать на шаблонный класс с выводом типа результата make_storage
#define VMIX_TASKIO_DETAIL_SQLITE_DB_SCHEMA                           \
  sqlite_orm::make_storage(                                           \
      "tasks.db",                                                     \
      sqlite_orm::make_table(                                         \
          "task",                                                     \
          sqlite_orm::make_column("id", &dtask::id,                   \
                                  sqlite_orm::autoincrement(),        \
                                  sqlite_orm::primary_key()),         \
          sqlite_orm::make_column("title", &dtask::title,             \
                                  sqlite_orm::default_value("")),     \
          sqlite_orm::make_column("description", &dtask::description, \
                                  sqlite_orm::default_value("")),     \
          sqlite_orm::make_column("time", &dtask::time,               \
                                  sqlite_orm::default_value("")),     \
          sqlite_orm::make_column("completed", &dtask::completed,     \
                                  sqlite_orm::default_value(false)),  \
          sqlite_orm::make_column("important", &dtask::important,     \
                                  sqlite_orm::default_value(false))))

using db_t = decltype(VMIX_TASKIO_DETAIL_SQLITE_DB_SCHEMA);

class sqlite_task_storage : public task_storage {
 public:
  sqlite_task_storage();
  ~sqlite_task_storage();

  virtual dtask_ptr create() override;
  virtual void update(const dtask_ptr&) override;
  virtual void remove(int) override;
  virtual dtask_ptr find(int) override;
  virtual std::vector<dtask_ptr> all() override;

 private:
  db_t db_;
};

}  // namespace vmix::taskio::detail

#endif  // VMIX_TASKIO_DETAIL_SQLITE_TASK_STORAGE_HPP
