/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/one.hpp>
namespace hana = boost::hana;


BOOST_HANA_CONSTANT_CHECK(hana::one<hana::IntegralConstant<int>>() == hana::int_<1>);
static_assert(hana::one<long>() == 1l, "");

int main() { }
