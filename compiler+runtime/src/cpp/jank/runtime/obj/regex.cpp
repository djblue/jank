#include <string>
#include <regex>

#include <jank/runtime/obj/regex.hpp>
#include <jank/runtime/rtti.hpp>

namespace jank::runtime::obj
{
  regex::regex(std::string const &s)
    : s{ s }
  {
    data = new std::regex(s);
  }

  native_bool regex::equal(object const &o) const
  {
    if(o.type != object_type::regex)
    {
      return false;
    }

    // auto const s(expect_object<inst>(&o));
    // return s->data == data;
    return true;
  }

  static void to_string_impl(std::string const &s, util::string_builder &buff)
  {
    buff("#\"");
    buff(s);
    buff('"');
  }

  void regex::to_string(util::string_builder &buff) const
  {
    to_string_impl(s, buff);
  }

  native_persistent_string regex::to_string() const
  {
    util::string_builder buff;
    to_string_impl(s, buff);
    return buff.release();
  }

  native_persistent_string regex::to_code_string() const
  {
    return to_string();
  }

  native_hash regex::to_hash() const
  {
    if(hash)
    {
      return hash;
    }

    // return hash = boost::hash<std::tm>()(data);
    return 0;
  }
}
