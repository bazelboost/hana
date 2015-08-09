/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/greater.hpp>
#include <boost/hana/integral_constant.hpp>
namespace hana = boost::hana;


static_assert(hana::greater(4, 1), "");
BOOST_HANA_CONSTANT_CHECK(!hana::greater(hana::int_<1>, hana::int_<3>));

int main() { }
