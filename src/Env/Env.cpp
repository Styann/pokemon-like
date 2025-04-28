#include "Env.hpp"

namespace Env {
    const std::filesystem::path path = std::filesystem::current_path().parent_path();
    const std::filesystem::path resourcesPath = Env::path / "resources";
};
