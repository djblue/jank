#pragma once

#include <regex>
#include <string>

#include <jank/runtime/object.hpp>

namespace jank::runtime::obj
{
  struct regex : gc
  {
    static constexpr object_type obj_type{ object_type::regex };
    static constexpr native_bool pointer_free{ false };

    regex(std::string const &s);

    /* behavior::object_like */
    native_bool equal(object const &) const;
    native_persistent_string to_string() const;
    void to_string(util::string_builder &buff) const;
    native_persistent_string to_code_string() const;
    native_hash to_hash() const;

    object base{ obj_type };

    std::string s{};
    std::regex* data{};

    mutable native_hash hash{};
  };
}
