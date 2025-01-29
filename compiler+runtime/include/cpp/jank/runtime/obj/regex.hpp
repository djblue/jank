#pragma once

#include <regex>
#include <boost/regex.hpp>
#include <string>

#include <jank/runtime/object.hpp>

namespace jank::runtime::obj
{
  struct re_pattern : gc
  {
    static constexpr object_type obj_type{ object_type::re_pattern };
    static constexpr native_bool pointer_free{ false };

    re_pattern(std::string const &s);

    /* behavior::object_like */
    native_bool equal(object const &) const;
    native_persistent_string to_string() const;
    void to_string(util::string_builder &buff) const;
    native_persistent_string to_code_string() const;
    native_hash to_hash() const;

    object base{ obj_type };

    std::string s{};
    boost::regex *data{};

    mutable native_hash hash{};
  };

  using re_pattern_ptr = native_box<re_pattern>;

  struct re_matcher : gc
  {
    static constexpr object_type obj_type{ object_type::re_matcher };
    static constexpr native_bool pointer_free{ false };

    re_matcher(re_pattern_ptr re, native_persistent_string const &s);

    /* behavior::object_like */
    native_bool equal(object const &) const;
    native_persistent_string to_string() const;
    void to_string(util::string_builder &buff) const;
    native_persistent_string to_code_string() const;
    native_hash to_hash() const;
    native_bool group();

    object base{ obj_type };

    re_pattern_ptr re;
    native_persistent_string s{};

    mutable native_hash hash{};
  };
}
