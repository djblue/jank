#include <string>
#include <regex>

#include <iostream>
#include <boost/regex.hpp>

#include <jank/runtime/obj/regex.hpp>
#include <jank/runtime/rtti.hpp>

namespace jank::runtime::obj
{
  re_pattern::re_pattern(std::string const &s)
    : s{ s }
  {
    data = new boost::regex(s);
  }

  native_bool re_pattern::equal(object const &o) const
  {
    if(o.type != object_type::re_pattern)
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

  void re_pattern::to_string(util::string_builder &buff) const
  {
    to_string_impl(s, buff);
  }

  native_persistent_string re_pattern::to_string() const
  {
    util::string_builder buff;
    to_string_impl(s, buff);
    return buff.release();
  }

  native_persistent_string re_pattern::to_code_string() const
  {
    return to_string();
  }

  native_hash re_pattern::to_hash() const
  {
    if(hash)
    {
      return hash;
    }

    // return hash = boost::hash<std::tm>()(data);
    return 0;
  }

  re_matcher::re_matcher(re_pattern_ptr re, native_persistent_string const &s)
    : re{ re }
    , s{ s }
  {
  }

  native_bool re_matcher::equal(object const &o) const
  {
    if(o.type != object_type::re_matcher)
    {
      return false;
    }

    // auto const s(expect_object<inst>(&o));
    // return s->data == data;
    return true;
  }

  void re_matcher::to_string(util::string_builder &buff) const
  {
    buff("#<re_matcher>");
  }

  native_persistent_string re_matcher::to_string() const
  {
    util::string_builder buff;
    buff("#<re_matcher>");
    return buff.release();
  }

  native_persistent_string re_matcher::to_code_string() const
  {
    return to_string();
  }

  native_hash re_matcher::to_hash() const
  {
    if(hash)
    {
      return hash;
    }

    // return hash = boost::hash<std::tm>()(data);
    return 0;
  }

  native_bool re_matcher::group()
  {
    boost::smatch m;
    if (boost::regex_match(s.c_str(), m, *re->data, boost::match_extra))
    {

      return true;
    }
    return false;
  }
}
