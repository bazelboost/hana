/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/config.hpp>
#include <boost/hana/core/is_a.hpp>
#include <boost/hana/string.hpp>
namespace hana = boost::hana;


int main() {
    BOOST_HANA_CONSTEXPR_LAMBDA auto str = BOOST_HANA_STRING("abcdef");
    BOOST_HANA_CONSTANT_CHECK(str == hana::string<'a', 'b', 'c', 'd', 'e', 'f'>);
    BOOST_HANA_CONSTANT_CHECK(hana::is_a<hana::String>(str));
}
