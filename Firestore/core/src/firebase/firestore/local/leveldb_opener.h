/*
 * Copyright 2019 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_LOCAL_LEVELDB_OPENER_H_
#define FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_LOCAL_LEVELDB_OPENER_H_

namespace firebase {
namespace firestore {

namespace core {
class DatabaseInfo;
}  // namespace core

namespace util {
class Path;

template <typename T>
class StatusOr;
}  // namespace util

namespace local {

class LevelDbOpener {
 public:
  /**
   * Finds a suitable directory to serve as the root of all Firestore local
   * storage.
   */
  static util::StatusOr<util::Path> AppDataDir();

  /**
   * Computes a unique storage directory for the given identifying components of
   * local storage.
   *
   * @param base_path The root application data directory relative to which
   *     the instance-specific storage directory will be created. Usually just
   *     `AppDataDir()`.
   * @param database_info The identifying information for the local storage
   *     instance.
   * @return A storage directory unique to the instance identified by
   *     `database_info`.
   */
  static util::Path StorageDir(const util::Path& base_path,
                               const core::DatabaseInfo& database_info);
};

}  // namespace local
}  // namespace firestore
}  // namespace firebase

#endif  // FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_LOCAL_LEVELDB_OPENER_H_
